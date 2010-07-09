//
//  SqueakOSXAppDelegate.m
//  SqueakOSXApp
//
//  Created by John M McIntosh on 09-11-10.
//
/*
 Some of this code was funded via a grant from the European Smalltalk User Group (ESUG)
 Copyright (c) 2009 Corporate Smalltalk Consulting Ltd. All rights reserved.
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

#import "SqueakOSXAppDelegate.h"
#import "sqSqueakOSXApplication.h"
#import "sqSqueakOSXScreenAndWindow.h"
#import "sqMacHostWindow.h"
#import "sqSqueakOSXInfoPlistInterface.h"

SqueakOSXAppDelegate *gDelegateApp;

@implementation SqueakOSXAppDelegate

@synthesize window,mainView,possibleImageNameAtLaunchTime,checkForFileNameOnFirstParm;

- (sqSqueakMainApplication *) makeApplicationInstance {
	return [sqSqueakOSXApplication new];
}

- (void)applicationWillFinishLaunching:(NSNotification *)aNotification {
	self.checkForFileNameOnFirstParm = YES;
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
	NSAutoreleasePool * pool = [NSAutoreleasePool new];
	gDelegateApp = self;	
	squeakApplication = [self makeApplicationInstance];
	sqSqueakOSXScreenAndWindow *windowHandler = [sqSqueakOSXScreenAndWindow new];
	windowHandler.mainViewOnWindow = self.mainView;
	self.mainView.windowLogic = windowHandler;
	windowHandler.windowIndex = 1;
	[windowHandler.mainViewOnWindow initializeVariables];
	self.window.delegate =  windowHandler;

	[self.squeakApplication setupEventQueue];

	// Run the squeak process in a worker thread
	
	[NSThread detachNewThreadSelector: @selector(runSqueak)
							 toTarget:	self.squeakApplication
						   withObject:	NULL]; 

	/* This the carbon logic model 
	 described by http://developer.apple.com/qa/qa2001/qa1061.html */
	
	
/*
	[[NSRunLoop mainRunLoop] performSelector: @selector(runSqueak) 
									  target: self.squeakApplication
									argument: nil 
									   order: 1 
									   modes: [NSArray arrayWithObject: NSDefaultRunLoopMode]];
*/	
	
	
	[pool drain];
	
}

- (id) createPossibleWindow {
	sqInt width,height;
	extern sqInt getSavedWindowSize(void); //This is VM Callback
	width  = ((unsigned) getSavedWindowSize()) >> 16;
	height = getSavedWindowSize() & 0xFFFF;
	NSSize sizeOfWindowContent;
	sizeOfWindowContent.width = width;
	sizeOfWindowContent.height = height;
	
	[gDelegateApp.window setContentSize: sizeOfWindowContent];
	NSRect resetFrame;
	resetFrame.origin.x = 0.0f;
	resetFrame.origin.y	= 0.0f;
	resetFrame.size.width = width;
	resetFrame.size.height = height;
	[gDelegateApp.window setAcceptsMouseMovedEvents: YES];
	[gDelegateApp.window useOptimizedDrawing: YES];
	[gDelegateApp.window setTitle: [[self.squeakApplication.imageNameURL path] lastPathComponent]];
	[gDelegateApp.window setRepresentedURL: self.squeakApplication.imageNameURL];
	[gDelegateApp.window setInitialFirstResponder: gDelegateApp.mainView];
	[gDelegateApp.window setShowsResizeIndicator: NO];
	extern sqInt getFullScreenFlag(void);

#if (SQ_VI_BYTES_PER_WORD == 4)
	NSPanel *panel;
	if (sizeof(void*) == 8) {
		panel= NSGetAlertPanel(@"About this Alpha Version of Cocoa Squeak 64/32 bits 5.7b2 (20)",
												 @"Only use this VM for testing, it lacks mac menu integration.",
												 @"Dismiss",
												 nil,
												 nil);
	} else {
			return self.window;
	}
#else
#if COGVM
#error bad
#endif
	NSPanel *panel;
	if (sizeof(long) == 8) {
		panel= NSGetAlertPanel(@"About this Alpha Version of Cocoa Squeak 64/64 bits 5.7b2 (20)",
									@"Only use this VM for testing, it lacks mac menu integration.",
									@"Dismiss",
									nil,
									nil);
	} else {
		panel= NSGetAlertPanel(@"About this Alpha Version of Cocoa Squeak 32/64 bits 5.7b2 (20)",
							   @"Only use this VM for testing, it lacks mac menu integration.",
							   @"Dismiss",
							   nil,
							   nil);
	}
	
#endif
	
	NSRect frame= [panel frame];
	frame.size.width *= 1.5f;
	[panel setFrame: frame display: NO];
	[NSApp runModalForWindow: panel];
	[panel close]; 
	
	return self.window;
}

- (BOOL)application:(NSApplication *)theApplication openFile:(NSString *)fileName {
//	NSLog(@"openFile state %i with file %@",checkForFileNameOnFirstParm,fileName);

	if (self.checkForFileNameOnFirstParm == YES) {
		self.checkForFileNameOnFirstParm = NO;
		self.possibleImageNameAtLaunchTime = fileName;
		return YES;
	} else {
		if ([(sqSqueakOSXApplication*)self.squeakApplication isImageFile: fileName] == YES) {
			NSURL *url = [NSURL fileURLWithPath:[[NSBundle mainBundle] bundlePath]];
			LSLaunchURLSpec launchSpec;
			launchSpec.appURL = (CFURLRef)url;
			launchSpec.passThruParams = NULL;
			launchSpec.itemURLs = (CFArrayRef)[NSArray arrayWithObject:[NSURL fileURLWithPath: fileName]];
			launchSpec.launchFlags = kLSLaunchDefaults | kLSLaunchNewInstance;
			launchSpec.asyncRefCon = NULL;
		
			OSErr err = LSOpenFromURLSpec(&launchSpec, NULL);
//			NSLog(@"error %i",err);
		}
	}
		
	return NO;
}

- (NSTimeInterval) squeakUIFlushPrimaryDeferNMilliseconds {
	return ((sqSqueakOSXInfoPlistInterface*) self.squeakApplication.infoPlistInterfaceLogic).SqueakUIFlushPrimaryDeferNMilliseconds;
}


@end
