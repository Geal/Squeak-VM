//
//  sqSqueakOSXApplication+events.m
//  SqueakPureObjc
//
//  Created by John M McIntosh on 09-11-15.
/*
 Some of this code was funded via a grant from the European Smalltalk User Group (ESUG)
 Copyright 2009 Corporate Smalltalk Consulting Ltd. All rights reserved.
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

#import "sqSqueakOSXApplication+events.h"
#import "SqueakOSXAppDelegate.h"
#import "sqSqueakOSXScreenAndWindow.h"
#import "sqMacV2Browser.h"
#import "sqSqueakOSXInfoPlistInterface.h"
#import "keyBoardStrokeDetails.h"
#import "sqSqueakOSXNSView.h"

extern struct	VirtualMachine* interpreterProxy;
extern SqueakOSXAppDelegate *gDelegateApp;

/* This table maps the 5 Macintosh modifier key bits to 4 Squeak modifier
 bits. (The Mac shift and caps lock keys are both mapped to the single
 Squeak shift bit).  This was true for squeak upto 3.0.7. Then in 3.0.8 we 
 decided to not map the cap lock key to shift
 
 Mac bits: <control><option><caps lock><shift><command>
 ST bits:  <command><option><control><shift>
 */
char modifierMap[256] = {	
	0, 8, 1, 9, 0, 8, 1, 9, 4, 12, 5, 13, 4, 12, 5, 13, //Track left and right shift keys
	2, 10, 3, 11, 2, 10, 3, 11, 6, 14, 7, 15, 6, 14, 7, 
	15, 1, 9, 1, 9, 1, 9, 1, 9, 5, 13, 5, 13, 5, 13, 5, 
	13, 3, 11, 3, 11, 3, 11, 3, 11, 7, 15, 7, 15, 7, 15,
	7, 15, 4, 12, 5, 13, 4, 12, 5, 13, 4, 12, 5, 13, 4,
	12, 5, 13, 6, 14, 7, 15, 6, 14, 7, 15, 6, 14, 7, 15, 
	6, 14, 7, 15, 5, 13, 5, 13, 5, 13, 5, 13, 5, 13, 5,
	13, 5, 13, 5, 13, 7, 15, 7, 15, 7, 15, 7, 15, 7, 15, 
	7, 15, 7, 15, 7, 15, 2, 10, 3, 11, 2, 10, 3, 11, 6, 
	14, 7, 15, 6, 14, 7, 15, 2, 10, 3, 11, 2, 10, 3, 11, 
	6, 14, 7, 15, 6, 14, 7, 15, 3, 11, 3, 11, 3, 11, 3, 
	11, 7, 15, 7, 15, 7, 15, 7, 15, 3, 11, 3, 11, 3, 11, 
	3, 11, 7, 15, 7, 15, 7, 15, 7, 15, 6, 14, 7, 15, 6, 
	14, 7, 15, 6, 14, 7, 15, 6, 14, 7, 15, 6, 14, 7, 15, 
	6, 14, 7, 15, 6, 14, 7, 15, 6, 14, 7, 15, 7, 15, 7, 
	15, 7, 15, 7, 15, 7, 15, 7, 15, 7, 15, 7, 15, 7, 15, 
	7, 15, 7, 15, 7, 15, 7, 15, 7, 15, 7, 15, 7, 15 };


enum {
	/* modifiers */
	activeFlagBit                 = 0,    /* activate? (activateEvt and mouseDown)*/
	btnStateBit                   = 7,    /* state of button?*/
	cmdKeyBit                     = 8,    /* command key down?*/
	shiftKeyBit                   = 9,    /* shift key down?*/
	alphaLockBit                  = 10,   /* alpha lock down?*/
	optionKeyBit                  = 11,   /* option key down?*/
	controlKeyBit                 = 12,   /* control key down?*/
	rightShiftKeyBit              = 13,   /* right shift key down? Not supported on Mac OS X.*/
	rightOptionKeyBit             = 14,   /* right Option key down? Not supported on Mac OS X.*/
	rightControlKeyBit            = 15    /* right Control key down? Not supported on Mac OS X.*/
};

enum {
	activeFlag                    = 1 << activeFlagBit,
	btnState                      = 1 << btnStateBit,
	cmdKey                        = 1 << cmdKeyBit,
	shiftKey                      = 1 << shiftKeyBit,
	alphaLock                     = 1 << alphaLockBit,
	optionKey                     = 1 << optionKeyBit,
	controlKey                    = 1 << controlKeyBit,
	rightShiftKey                 = 1 << rightShiftKeyBit, /* Not supported on Mac OS X.*/
	rightOptionKey                = 1 << rightOptionKeyBit, /* Not supported on Mac OS X.*/
	rightControlKey               = 1 << rightControlKeyBit /* Not supported on Mac OS X.*/
};

static int buttonState=0;

@implementation sqSqueakOSXApplication (events) 

- (void ) processAsOldEventOrComplexEvent: (id) event placeIn: (sqInputEvent *) evt {
	if ([[event objectAtIndex: 0] intValue] == 1) {
		[(NSData *)[event objectAtIndex: 1] getBytes: evt length: sizeof(sqInputEvent)];
		if (evt->type == EventTypeKeyboard) {
//			NSLog(@"keyboard pc %i cc %i uc %i m %i",((sqKeyboardEvent *)evt)->pressCode,((sqKeyboardEvent *) evt)->charCode,((sqKeyboardEvent *) evt)->utf32Code,((sqKeyboardEvent *) evt)->modifiers);
		}
		return;
	}
}

- (void) pushEventToQueue: (sqInputEvent *) evt {	
	NSMutableArray* data = [NSMutableArray new];
	[data addObject: [NSNumber numberWithInteger: 1]];
	[data addObject: [NSData  dataWithBytes:(const void *) evt length: sizeof(sqInputEvent)]];
	[eventQueue addItem: data];
	[data release];	
}

- (void) recordCharEvent:(NSString *) unicodeString fromView: (sqSqueakOSXNSView *) mainView {
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
			if (mainView.lastSeenKeyBoardStrokeDetails) {
				evt.modifiers = [self translateCocoaModifiersToSqueakModifiers: mainView.lastSeenKeyBoardStrokeDetails.modifierFlags];
				evt.charCode = mainView.lastSeenKeyBoardStrokeDetails.keyCode;
			} else {
				evt.modifiers = 0;
				evt.charCode = 0;
			}
		unsigned short keyCodeRemembered = evt.charCode;
		evt.utf32Code = 0;
		evt.reserved1 = 0;
		evt.windowIndex = (int)  mainView.windowLogic.windowIndex;
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
		
		[self pushEventToQueue: (sqInputEvent *) &evt];
		if (i > 1 || !mainView.lastSeenKeyBoardStrokeDetails) {
			evt.pressCode = EventKeyUp;
			evt.charCode = keyCodeRemembered;
			evt.utf32Code = 0;
			[self pushEventToQueue: (sqInputEvent *) &evt];
		}
	}
	
	interpreterProxy->signalSemaphoreWithIndex(gDelegateApp.squeakApplication.inputSemaphoreIndex);

}

- (void) recordKeyUpEvent:(NSEvent *)theEvent fromView: (sqSqueakOSXNSView*) aView {
	sqKeyboardEvent evt;
	
	evt.type = EventTypeKeyboard;
	evt.timeStamp = (int) ioMSecs();
	evt.charCode =	[theEvent keyCode];
	evt.pressCode = EventKeyUp;
	evt.modifiers = [self translateCocoaModifiersToSqueakModifiers: [theEvent modifierFlags]];
	evt.utf32Code = 0;
	evt.reserved1 = 0;
	evt.windowIndex = (int) aView.windowLogic.windowIndex;
	[self pushEventToQueue: (sqInputEvent *) &evt];

	interpreterProxy->signalSemaphoreWithIndex(gDelegateApp.squeakApplication.inputSemaphoreIndex);
}

- (void) recordMouseEvent:(NSEvent *)theEvent fromView: (sqSqueakOSXNSView *) aView{
	sqMouseEvent evt;
	
	evt.type = EventTypeMouse;
	evt.timeStamp = (int) ioMSecs();
	
	NSPoint local_point = [aView convertPoint: [theEvent locationInWindow] fromView:nil];
	
	evt.x = (int) lrintf(local_point.x); 
	evt.y = (int) lrintf(local_point.y);
	
	int buttonAndModifiers = [self mapMouseAndModifierStateToSqueakBits: theEvent];
	evt.buttons = buttonAndModifiers & 0x07;
	evt.modifiers = buttonAndModifiers >> 3;
#if COGVM
	evt.nrClicks = 0;
#else
	evt.reserved1 = 0;
#endif 
	evt.windowIndex = (int) aView.windowLogic.windowIndex;
	
	[self pushEventToQueue:(sqInputEvent *) &evt];
//NSLog(@"mouse hit x %i y %i buttons %i mods %i",evt.x,evt.y,evt.buttons,evt.modifiers);
	interpreterProxy->signalSemaphoreWithIndex(gDelegateApp.squeakApplication.inputSemaphoreIndex);
}
						   
- (void) recordWheelEvent:(NSEvent *) theEvent fromView: (sqSqueakOSXNSView *) aView{
		
	[self recordMouseEvent: theEvent fromView: aView];
	CGFloat x = [theEvent deltaX];
	CGFloat y = [theEvent deltaY];

	if (x != 0.0f) {
		[self fakeMouseWheelKeyboardEventsKeyCode: (x < 0 ? 124 : 123) ascii: (x < 0 ? 29 : 28) windowIndex:  (int) aView.windowLogic.windowIndex];
	}
	if (y != 0.0f) {
		[self fakeMouseWheelKeyboardEventsKeyCode: (y < 0 ? 125 : 126) ascii: (y < 0 ? 31 : 30) windowIndex: (int) aView.windowLogic.windowIndex];
	}
}
		  
- (void) fakeMouseWheelKeyboardEventsKeyCode: (int) keyCode ascii: (int) ascii windowIndex: (int) windowIndex {
	sqKeyboardEvent evt;

	evt.type = EventTypeKeyboard;
	evt.timeStamp = (int) ioMSecs();
	evt.pressCode = EventKeyDown;
	evt.charCode = keyCode;
	evt.utf32Code = 0;
	evt.reserved1 = 0;
	evt.modifiers = modifierMap[(controlKey >> 8)];
	evt.windowIndex = windowIndex;
	[self pushEventToQueue:(sqInputEvent *) &evt];

	evt.pressCode = EventKeyChar;
	evt.charCode = ascii;
	evt.utf32Code = ascii;
	[self pushEventToQueue:(sqInputEvent *) &evt];
	
	evt.pressCode = EventKeyUp;
	evt.charCode =	keyCode;
	evt.utf32Code = 0;
	[self pushEventToQueue:(sqInputEvent *) &evt];
	
}

- (int) translateCocoaModifiersToSqueakModifiers: (NSUInteger) modifiers {
	NSUInteger keyBoardModifiers = [self translateCocoaModifiersToCarbonModifiers: modifiers];
	return ((modifierMap[((keyBoardModifiers & 0xFFFF) >> 8)]));
}

- (NSUInteger) translateCocoaModifiersToCarbonModifiers: (NSUInteger) modifiers {
	NSUInteger keyBoardModifiers=0;
	if (modifiers & NSAlphaShiftKeyMask) 
		keyBoardModifiers |= alphaLock;
	if (modifiers & NSShiftKeyMask)
		keyBoardModifiers |= shiftKey;
	if (modifiers & NSControlKeyMask)
		keyBoardModifiers |= controlKey;
	if (modifiers & NSAlternateKeyMask)
		keyBoardModifiers |= optionKey;
	if (modifiers & NSCommandKeyMask)
		keyBoardModifiers |= cmdKey;
	return keyBoardModifiers;
		
}
		
- (int) mapMouseAndModifierStateToSqueakBits: (NSEvent *) event {
	/* On a two- or three-button mouse, the left button is normally considered primary and the 
	 right button secondary, 
	 but left-handed users can reverse these settings as a matter of preference. 
	 The middle button on a three-button mouse is always the tertiary button. '
	 
	 But mapping assumes 1,2,3  red, yellow, blue
	 */
	
	NSInteger stButtons,modifier,mappedButton;
	NSInteger mouseButton=0;
	
	static NSInteger buttonStateBits[4] = {0,0,0,0};
	
	stButtons = buttonState;
	NSUInteger keyBoardCarbonModifiers = [self translateCocoaModifiersToCarbonModifiers: [event modifierFlags]];
	NSInteger whatHappened = [event type];
  	if (whatHappened != NSMouseMoved  && whatHappened != NSScrollWheel) {
		stButtons = 0;
		mouseButton = 0;
		if (whatHappened == NSLeftMouseUp || whatHappened == NSLeftMouseDown)
			mouseButton = 1;
		if (whatHappened == NSRightMouseUp || whatHappened == NSRightMouseDown)
			mouseButton = 2;
		if (!mouseButton)
			mouseButton = [event buttonNumber] + 1; //buttonNumber seems to count from 0.
		
		if (mouseButton > 0 && mouseButton < 4) {
			
			modifier = 0;
			if (keyBoardCarbonModifiers & cmdKey  )
				modifier = 1;
			if (keyBoardCarbonModifiers & optionKey)
				modifier = 2;
			if (keyBoardCarbonModifiers & controlKey)
				modifier = 3;
			
			if (browserActiveAndDrawingContextOkAndNOTInFullScreenMode())
				mappedButton = [(sqSqueakOSXInfoPlistInterface *) self.infoPlistInterfaceLogic getSqueakBrowserMouseMappingsAt: modifier by: mouseButton];
			else
				mappedButton = [(sqSqueakOSXInfoPlistInterface *) self.infoPlistInterfaceLogic getSqueakMouseMappingsAt: modifier by: mouseButton];
			buttonStateBits[mappedButton] = 
				(whatHappened == NSLeftMouseUp || 
				 whatHappened == NSRightMouseUp || 
				 whatHappened == NSOtherMouseUp) ? 0 : 1;
			stButtons |= mappedButton == 1 ? (buttonStateBits[mappedButton] ? RedButtonBit : 0) : 0;
			stButtons |= mappedButton == 2 ? (buttonStateBits[mappedButton] ? YellowButtonBit : 0) : 0;
			stButtons |= mappedButton == 3 ? (buttonStateBits[mappedButton] ? BlueButtonBit : 0)  : 0;
		}
	}
	
	// button state: low three bits are mouse buttons; next 8 bits are modifier bits
	buttonState = (int) (modifierMap[((keyBoardCarbonModifiers & 0xFFFF) >> 8)] << 3) | (int) (stButtons & 0x7);
	return buttonState;
}

- (void) recordDragEvent: (int) dragType numberOfFiles: (int) numFiles where: (NSPoint) local_point windowIndex: (sqInt) windowIndex {
	sqDragDropFilesEvent evt;
	
	evt.type= EventTypeDragDropFiles;
	evt.timeStamp= (int) ioMSecs();
	evt.dragType= dragType;
	evt.x = (int) lrintf(local_point.x); 
	evt.y = (int) lrintf(local_point.y);
	evt.modifiers= (buttonState >> 3);
	evt.numFiles= numFiles;
	evt.windowIndex = (int) windowIndex;
	[self pushEventToQueue: (sqInputEvent *) &evt];
	
	interpreterProxy->signalSemaphoreWithIndex(gDelegateApp.squeakApplication.inputSemaphoreIndex);
}

@end
