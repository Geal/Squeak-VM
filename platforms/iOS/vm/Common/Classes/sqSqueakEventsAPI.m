//
//  sqSqueakEventsAPI.m
//  
//
//  Created by John M McIntosh on 6/14/08.
//
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
#import "sqSqueakAppDelegate.h"
#import "sqSqueakEventsAPI.h"
#import "sqSqueakMainApplication+events.h"
#import "sqSqueakScreenAndWindow.h"
#import "sqaio.h"

extern sqSqueakAppDelegate *gDelegateApp;
extern struct	VirtualMachine* interpreterProxy;
extern BOOL gQuitNowRightNow;
extern sqSqueakScreenAndWindow *getMainWindowDelegate();

sqInt ioProcessEvents(void) {
	//API Documented
	
	aioPoll(0);		
	
	if ([getMainWindowDelegate() forceUpdateFlush]) {
		[getMainWindowDelegate() ioForceDisplayUpdate];
	}
	/* This the carbon logic model 
	 described by http://developer.apple.com/qa/qa2001/qa1061.html
	 but fails on device, bug tracking number  5971848 */
	
/*	extern struct VirtualMachine* interpreterProxy;
	if (interpreterProxy->methodPrimitiveIndex() != 0) {
		//	limitDateForMode:
		
		BOOL processedEvent;
		// NSDate *now = [[NSDate alloc] init];
		NSDate *now = [[NSDate alloc] initWithTimeIntervalSinceNow: 0.500];
		//processedEvent = [[NSRunLoop mainRunLoop] runMode: NSDefaultRunLoopMode  beforeDate: now];
		
		//[now release];
		[[NSRunLoop mainRunLoop] runUntilDate: now];
		[now release];
	} */
	
	
	if (gQuitNowRightNow) {
		ioExit();  //This might not return, might call exittoshell
	}
	
	return 0;
}

sqInt ioSetInputSemaphore(sqInt semaIndex) {
	//API Documented
	
	gDelegateApp.squeakApplication.inputSemaphoreIndex = semaIndex;
	return 0;
}

sqInt ioGetNextEvent( sqInputEvent *evt) {
	//API Documented
	
	[gDelegateApp.squeakApplication ioGetNextEvent: evt];
/*	if (evt->type != 0) {
		NSLog(@"evt.type %i keyboard pc %i cc %i uc %i m %i",evt->type,((sqKeyboardEvent *)evt)->pressCode,((sqKeyboardEvent *) evt)->charCode,((sqKeyboardEvent *) evt)->utf32Code,((sqKeyboardEvent *) evt)->modifiers);
	} */
	return 0;
}