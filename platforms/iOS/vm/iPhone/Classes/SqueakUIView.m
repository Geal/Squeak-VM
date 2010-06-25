//
//  SqueakUIView.m
//  SqueakNoOGLIPhone
//
//  Created by John M McIntosh on 5/20/08.
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
#import <QuartzCore/QuartzCore.h>

#import "SqueakUIView.h"
#import "sqSqueakMainApplication.h"
#import "SqueakNoOGLIPhoneAppDelegate.h"
#import "sqSqueakIPhoneApplication+events.h"
#import "sqiPhoneScreenAndWindow.h"
#import "sq.h"

extern struct	VirtualMachine* interpreterProxy;
extern SqueakNoOGLIPhoneAppDelegate *gDelegateApp;

static void MyProviderReleaseData (
							void *info,
							const void *data,
							size_t size
							) {
}


@implementation SqueakUIView : UIView ;
@synthesize squeakTheDisplayBits;

- (id)initWithFrame:(CGRect) aFrame {
	self = [super initWithFrame: aFrame];
	self.autoresizingMask = UIViewAutoresizingFlexibleRightMargin|UIViewAutoresizingFlexibleBottomMargin|UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleWidth;
	colorspace = CGColorSpaceCreateDeviceRGB();
	self.multipleTouchEnabled = YES;
	return self;
}

- (void)layoutSubviews {
	CGRect ff = self.frame;
	CGRect aFrame = self.bounds;
	dividedWidth = aFrame.size.width/4.0;
	dividedHeight = aFrame.size.height/4.0;
	for (int v=0;v<4;v++) {
		for (int h=0;h<4;h++) {
			CALayer *setupLayer = [CALayer layer];
			[setupLayer setOpaque: YES];
			setupLayer.frame = CGRectMake(dividedWidth*h, dividedHeight*v, dividedWidth, dividedHeight);
			if (myLayer[v][h]) {
				[self.layer replaceSublayer: myLayer[v][h] with: setupLayer];
				myLayer[v][h] = setupLayer;
			} else {
				myLayer[v][h] = setupLayer;
				[self.layer addSublayer: setupLayer];
			}
			frameForQuartz[v][h] = CGRectMake(dividedWidth*h,dividedHeight*(3-v), dividedWidth, dividedHeight);
			dirty[v][h] = NO;
		}
	}
}


- (void) dealloc {
    [super dealloc];
//	if (colorspace)
//		CGColorSpaceRelease(colorspace);	
}

- (CGImageRef) createImageFrom: (void *) dispBitsIndex affectedT: (int) affectedT affectedB: (int) affectedB affectedL: (int) affectedL affectedR: (int) affectedR height: (int) height width: (int) width {
	const size_t depth = 32;
	size_t 	pitch = ((((width)*(depth) + 31) >> 5) << 2);

	size_t totalSize = pitch * (affectedB-affectedT)-affectedL*4;
	CGDataProviderRef provider =  CGDataProviderCreateWithData (NULL,(void*)dispBitsIndex+ pitch*affectedT + affectedL*4,(size_t) totalSize,MyProviderReleaseData);
	
	CGImageRef image = CGImageCreate((size_t) affectedR-affectedL,(size_t) affectedB-affectedT, (size_t) 8 /* bitsPerComponent */,
						  (size_t) depth /* bitsPerPixel */, 
						  (size_t) pitch, colorspace, 
						  (CGBitmapInfo) kCGImageAlphaNoneSkipFirst | kCGBitmapByteOrder32Host , 
						  provider, NULL, (bool) 0, kCGRenderingIntentDefault);
	
	CGDataProviderRelease(provider);
	return image;
}


- (void) drawImageUsingClip: (CGRect) clip {
	for (int v=0;v<4;v++) {
		for (int h=0;h<4;h++) {
			dirty[v][h] = dirty[v][h] || CGRectIntersectsRect(frameForQuartz[v][h],clip);
		}
	}
}

- (void) drawThelayers {	
	[CATransaction begin];
	[CATransaction setValue: [NSNumber numberWithBool:YES] forKey: kCATransactionDisableActions];
	for (int v=0;v<4;v++) {
		for (int h=0;h<4;h++) {
			if (dirty[v][h]) {
				CGRect rect = myLayer[v][h].frame;
				CGImageRef x= [self createImageFrom: squeakTheDisplayBits 
							affectedT: rect.origin.y 
							affectedB: rect.origin.y+rect.size.height 
							affectedL: rect.origin.x 
							affectedR: rect.origin.x+rect.size.width 
							   height: (int) dividedHeight*4 
								width: (int) dividedWidth*4];
				myLayer[v][h].contents = (id)x; 
				CGImageRelease(x);
				dirty[v][h] = NO;
			}
		}
	}
	[CATransaction commit];
}

// Handles the start of a touch
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
	//Called by Main Thread, beware of calling Squeak routines in Squeak Thread
	[(sqSqueakIPhoneApplication *) gDelegateApp.squeakApplication recordTouchEvent: touches type: UITouchPhaseBegan];
}

// Handles the continuation of a touch.
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event 
{  
	//Called by Main Thread, beware of calling Squeak routines in Squeak Thread
	[(sqSqueakIPhoneApplication *) gDelegateApp.squeakApplication recordTouchEvent: touches type: UITouchPhaseMoved];
	
}

// Handles the end of a touch event.
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event 
{
	//Called by Main Thread, beware of calling Squeak routines in Squeak Thread
	[(sqSqueakIPhoneApplication *) gDelegateApp.squeakApplication recordTouchEvent: touches type: UITouchPhaseEnded];
}

- (void) touchesCancelled: (NSSet *) touches withEvent: (UIEvent *) event {
}

- (BOOL)canBecomeFirstResponder {
	return YES;
}

- (BOOL)hasText {
	return YES;
}

- (void)insertText:(NSString *)text {
	[self recordCharEvent: text];
}

- (void)deleteBackward {
	unichar delete[1];
	delete[0] =  0x08;

	[self recordCharEvent:[NSString stringWithCharacters: delete length: 1]];
}

- (void) pushEventToQueue: (sqInputEvent *) evt {	
	NSMutableArray* data = [NSMutableArray new];
	[data addObject: [NSNumber numberWithInteger: 7]];
	[data addObject: [NSData  dataWithBytes:(const void *) evt length: sizeof(sqInputEvent)]];
	[[gDelegateApp.squeakApplication eventQueue]  addItem: data];
	[data release];	
}

- (int) figureOutKeyCode: (unichar) unicode {
	static int unicodeToKeyCode[] = {54, 115, 11, 52, 119, 114, 3, 5, 51, 48, 38, 116, 121, 36, 45, 31, 
		96, 12, 15, 1, 17, 32, 9, 13, 7, 16, 6, 53, 123, 124, 126, 125, 49, 18, 39, 20, 21, 23, 26, 39, 
		25, 29, 67, 69, 43, 27, 47, 44, 29, 18, 19, 20, 21, 23, 22, 26, 28, 25, 41, 41, 43, 24, 47, 
		44, 19, 0, 11, 8, 2, 14, 3, 5, 4, 34, 38, 40, 37, 46, 45, 31, 35, 12, 15, 1, 17, 32, 9, 13, 
		7, 16, 6, 33, 42, 30, 22, 27, 50, 0, 11, 8, 2, 14, 3, 5, 4, 34, 38, 40, 37, 46, 45, 31, 35, 
		12, 15, 1, 17, 32, 9, 13, 7, 16, 6, 33, 42, 30, 50, 117};
	if (unicode > 127) 
		return 0;
	return unicodeToKeyCode[unicode];
	
}

- (void) recordCharEvent:(NSString *) unicodeString {
	sqKeyboardEvent evt;
	unichar unicode;
	unsigned char macRomanCharacter;
	NSInteger	i;
	NSRange picker;
	NSUInteger totaLength;
	
	evt.type = EventTypeKeyboard;
	evt.timeStamp = (int) ioMSecs();
	picker.location = 0;
	picker.length = 1;
	totaLength = [unicodeString length];
	for (i=0;i < totaLength;i++) {
		
		unicode = [unicodeString characterAtIndex: i];
		NSString *lookupString = [[NSString alloc] initWithCharacters: &unicode length: 1];
		[lookupString getBytes: &macRomanCharacter maxLength: 1 usedLength: NULL encoding: NSMacOSRomanStringEncoding
					   options: 0 range: picker remainingRange: NULL];
		[lookupString release];
		
		evt.pressCode = EventKeyDown;
		BOOL isUppercase = [[NSCharacterSet uppercaseLetterCharacterSet] characterIsMember: unicode];
		evt.modifiers = isUppercase ? ShiftKeyBit : 0;
		evt.charCode = [self figureOutKeyCode: unicode];

		unsigned int keyCodeRemembered = evt.charCode;
		evt.utf32Code = 0;
		evt.reserved1 = 0;
		evt.windowIndex = 1;
		[self pushEventToQueue: (sqInputEvent *)&evt];
		
		evt.charCode =	macRomanCharacter;
		evt.pressCode = EventKeyChar;
		evt.modifiers = evt.modifiers;
		if ((evt.modifiers & CommandKeyBit) && (evt.modifiers & ShiftKeyBit)) {  /* command and shift */
            if ((unicode >= 97) && (unicode <= 122)) {
				/* convert ascii code of command-shift-letter to upper case */
				unicode = unicode - 32;
            }
		}
		
		evt.utf32Code = unicode;
		evt.timeStamp++; 
		[self pushEventToQueue: (sqInputEvent *) &evt];
		if (YES) {
			evt.pressCode = EventKeyUp;
			evt.charCode = keyCodeRemembered;
			evt.utf32Code = 0;
			evt.timeStamp++; 
			[self pushEventToQueue: (sqInputEvent *) &evt];
		}
	}
	
	interpreterProxy->signalSemaphoreWithIndex(gDelegateApp.squeakApplication.inputSemaphoreIndex);
	
}
 
@end

