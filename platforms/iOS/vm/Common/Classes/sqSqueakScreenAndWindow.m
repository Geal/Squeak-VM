//
//  sqSqueakScreenAndWindow.m
//  
//
//  Created by John M McIntosh on 6/14/08.
/*
Some of this code was funded via a grant from the European Smalltalk User Group (ESUG)
 Copyright (c) 2008 Corporate Smalltalk Consulting Ltd. All rights reserved.
 MIT License
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 
 The end-user documentation included with the redistribution, if any, must include the following acknowledgment: 
 "This product includes software developed by Corporate Smalltalk Consulting Ltd (http://www.smalltalkconsulting.com) 
 and its contributors", in the same place and form as other third-party acknowledgments. 
 Alternately, this acknowledgment may appear in the software itself, in the same form and location as other 
 such third-party acknowledgments.
 */

//

#import "sqSqueakScreenAndWindow.h"
#import "sqSqueakMainApplication+screen.h"
#import "sqMacHostWindow.h"
#ifdef BUILD_FOR_OSX
#import "SqueakOSXAppDelegate.h"
extern SqueakOSXAppDelegate *gDelegateApp;
#else
#import "SqueakNoOGLIPhoneAppDelegate.h"
SqueakNoOGLIPhoneAppDelegate *gDelegateApp;
#endif

void MyProviderReleaseData (
							void *info,
							const void *data,
							size_t size
							);
void MyProviderReleaseData (
							void *info,
							const void *data,
							size_t size
							) {
}

@implementation sqSqueakScreenAndWindow
@synthesize windowIndex;
@synthesize blip,squeakUIFlushPrimaryDeferNMilliseconds,forceUpdateFlush;

- (id)init {
    self = [super init];
    if (self) {
        // Initialization code here.
		squeakUIFlushPrimaryDeferNMilliseconds = 0.0f;
		forceUpdateFlush = NO;
	}
    return self;
}

- (id) getMainView {
	return NULL;
}

- (void)  ioSetFullScreen: (sqInt) fullScreen {
}

- (sqInt) ioScreenSize {
	sqInt w, h;
	
#if BUILD_FOR_OSX
		NSRect screenSize = [gDelegateApp.mainView bounds];
#else
		CGRect screenSize = [gDelegateApp.mainView bounds];
#endif
		
		w = (sqInt) screenSize.size.width;
		h = (sqInt) screenSize.size.height;

	return (w << 16) | (h & 0xFFFF);  /* w is high 16 bits; h is low 16 bits */
	
}

- (sqInt) ioScreenDepth {
	return 32;
}

- (sqInt) ioHasDisplayDepth: (sqInt) depth {
	if (depth == 32) 
		return true;
	return false;
}

- (void) ioForceDisplayUpdateActual {
	self.forceUpdateFlush = NO;
	[[self getMainView] performSelectorOnMainThread: @selector(drawThelayers) withObject: nil waitUntilDone: YES];
}

- (void) ioForceDisplayUpdate {
	@synchronized(self) {
		if (self.blip) {
			//NSLog(@"Timmer deleted");
			[self.blip invalidate];
			self.blip = NULL;
		}
	}
	[self ioForceDisplayUpdateActual];
}

- (int)   ioShowDisplayOnWindowActual: (unsigned char*) dispBitsIndex
						  width: (int) width 
						 height: (int) height
						  depth: (int) depth
					  affectedL: (int) affectedL
					  affectedR: (int) affectedR
					  affectedT: (int) affectedT
					  affectedB: (int) affectedB
					windowIndex: (int) passedWindowIndex {
	
	static CGColorSpaceRef colorspace = NULL;
	sqInt 		pitch;
	windowDescriptorBlock *targetWindowBlock = windowBlockFromIndex(passedWindowIndex);	
	
	if (colorspace == NULL) {
		colorspace = CGColorSpaceCreateDeviceRGB();
		//Special case of first draw
		[self ioShowDisplayOnWindow:dispBitsIndex width:width height: height depth: depth affectedL: 0 affectedR: width affectedT: 0 affectedB: height windowIndex: passedWindowIndex];
//		[self ioForceDisplayUpdate];
		return 0;
	}
		
	if (affectedL < 0) affectedL = 0;
	if (affectedT < 0) affectedT = 0;
	if (affectedR > width) affectedR = width;
	if (affectedB > height) affectedB = height;
	
	if ((targetWindowBlock->handle == nil) || ((affectedR - affectedL) <= 0) || ((affectedB - affectedT) <= 0)){
		return 0;
	}
	
	pitch = ((((width)*(depth) + 31) >> 5) << 2);
		
	CGRect clip = CGRectMake((CGFloat)affectedL,(CGFloat)(height-affectedB), (CGFloat)(affectedR-affectedL), (CGFloat)(affectedB-affectedT));
	[gDelegateApp.mainView drawImageUsingClip: clip];
	
	if ((targetWindowBlock->width != width || targetWindowBlock->height  != height)) {
		targetWindowBlock->width = width;
		targetWindowBlock->height = height; 
	}
	
	return 0;	
}

- (void) ioForceDisplayUpdateFlush: (NSTimer*)theTimer {
	//NSLog(@"ioForceDisplayUpdateFlush");
	@synchronized(self) {
		self.blip = NULL;
	}
	self.forceUpdateFlush = YES;
}

- (int)   ioShowDisplayOnWindow: (unsigned char*) dispBitsIndex
						  width: (int) width 
						 height: (int) height
						  depth: (int) depth
					  affectedL: (int) affectedL
					  affectedR: (int) affectedR
					  affectedT: (int) affectedT
					  affectedB: (int) affectedB
					windowIndex: (int) passedWindowIndex {
	int value;
	value = [self ioShowDisplayOnWindowActual:dispBitsIndex width: width height: height depth:depth affectedL:affectedL affectedR:affectedR affectedT:affectedT affectedB:affectedB windowIndex: passedWindowIndex];
	@synchronized(self) {
		if (!self.blip) {
			if (squeakUIFlushPrimaryDeferNMilliseconds == 0.0f) 
				squeakUIFlushPrimaryDeferNMilliseconds =  [gDelegateApp squeakUIFlushPrimaryDeferNMilliseconds];
			
			NSAutoreleasePool * pool = [NSAutoreleasePool new];
			self.blip = [NSTimer timerWithTimeInterval: squeakUIFlushPrimaryDeferNMilliseconds target:self selector:@selector(ioForceDisplayUpdateFlush:) userInfo:nil repeats:NO];
			[[NSRunLoop mainRunLoop] addTimer: self.blip forMode: NSDefaultRunLoopMode];
			[pool drain];
		}
	}
	return value;
}

- (void)dealloc {
	[super dealloc];
}
@end
