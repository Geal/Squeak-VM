//
//  sqSqueakOSXApplication+attributes.m
//  SqueakPureObjc
//
//  Created by John M McIntosh on 09-11-11.
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

#import "sqSqueakOSXApplication+attributes.h"
#import "sqSqueakMainApplication+attributes.h"
#import "sqSqueakMainApplication+vmAndImagePath.h"

extern struct VirtualMachine* interpreterProxy;

@implementation sqSqueakOSXApplication (attributes) 

- (char *) getAttribute:(sqInt)indexNumber {
	//indexNumber is a postive/negative number
#warning to test
	switch (indexNumber) {
		case 1001: /* OS type: "unix", "win32", "mac", ... */
			return "Mac OS";
			 
		case 1002:  { /* OS name: "solaris2.5" on unix, "win95" on win32, ... */
			SInt32 myattr;
			static char data[32];
			
			Gestalt(gestaltSystemVersion, &myattr);
			sprintf(data,"%X",(unsigned int) myattr);
			return data;
		}
		case 1003: { /* processor architecture: "68k", "x86", "PowerPC", ...  */
			SInt32 myattr;
			
			Gestalt(gestaltSysArchitecture, &myattr);
			if (myattr == gestalt68k) 
				return "68K";
			if (myattr == gestaltPowerPC) 
				return "powerpc";
			if (myattr == gestaltIntel) 
				return "intel";
			
			return "unknown";
		}
			
		case 1006: /* vm build string also info.plist */
#if (SQ_VI_BYTES_PER_WORD == 4)
			
			return "Mac Cocoa 5.7b1 15-Jun-10 >34286DE5-3BD3-40D8-9700-4C41C772B16B<";
//			return "Mac Cocoa 5.6b1 02-Mar-10 >9E99B1C2-0B6B-4944-8B6F-74030D14F3C6<";
//			return "Mac Cocoa 5.5b1 16-Feb-10 >2EE2964B-462A-4F66-92AF-C810216EF798<";
//			return "Mac Cocoa 5.4b2 24-Jan-10 >2EE2964B-462A-4F66-92AF-C810216EF798<";
//			return "Mac Cocoa 5.4b1 20-Jan-10 >F0EB07E3-7805-4C09-8419-D8316F7ADC21<";
//			return "Mac Cocoa 5.3b1 06-Jan-10 >0DADC752-8E86-48FC-8D6B-CC97482C6851<";
//			return "Mac Cocoa 5.2b3 05-Jan-10 >1618879A-3D07-427F-A8CB-5B3DF73ED840<";
//			return "Mac Cocoa 5.2b2 04-Jan-10 >94E27C49-8575-4604-A2C4-0A5C659CC734<";
//			return "Mac Cocoa 5.2b1 02-Jan-10 >D94A0034-7415-4AA1-AA7C-B35BBCDBA0D4<";
//			return "Mac Cocoa 5.1b1 25-Dec-09 >C0908D0B-4D97-47CA-9FAB-479AFC6BA978<";
//			return "Mac Cocoa 5.0b9 02-Dec-09 >C8598ABA-DA73-4A71-836C-62C4369D5A0F<";
#else
			return "Mac Cocoa 5.7b1 64/64 bits 15-Jun-10 >34286DE5-3BD3-40D8-9700-4C41C772B16B<";
//			return "Mac Cocoa 5.6b1 64/64 bits 02-Mar-10 >9E99B1C2-0B6B-4944-8B6F-74030D14F3C6<";
//			return "Mac Cocoa 5.5b1 64/64 bits 16-Feb-10 >70984CDA-9482-4E7F-BCF0-08C635E0A7BF<";
//			return "Mac Cocoa 5.4b2 64/64 bits 24-Jan-10 >70984CDA-9482-4E7F-BCF0-08C635E0A7BF<";
//			return "Mac Cocoa 5.4b1 64/64 bits 20-Jan-10 >E27846BC-15A7-4BE8-B467-B645E9D37163<";
//			return "Mac Cocoa 5.3b1 64/64 bits 06-Jan-10 >0DADC752-8E86-48FC-8D6B-CC97482C6851<";
//			return "Mac Cocoa 5.2b3 64/64 bits 05-Jan-10 >1618879A-3D07-427F-A8CB-5B3DF73ED840<";
//			return "Mac Cocoa 5.2b2 64/64 bits 04-Jan-10 >94E27C49-8575-4604-A2C4-0A5C659CC734<";
//			return "Mac Cocoa 5.2b1 64/64 bits 02-Jan-10 >D94A0034-7415-4AA1-AA7C-B35BBCDBA0D4<";
//			return "Mac Cocoa 5.1b1 64/64 bits 25-Dec-09 >C0908D0B-4D97-47CA-9FAB-479AFC6BA978<";
//			return "Mac Cocoa 5.0b9 64/64 bits 02-Dec-09 >C8598ABA-DA73-4A71-836C-62C4369D5A0F<";
//			return "Mac Cocoa 5.0b8 01-Dec-09 >2329A610-327B-403D-960E-EEF3C369D032<";
//			return "Mac Cocoa 5.0b7 29-Nov-09 >1215B15B-9463-4D53-BA13-AA989DAB5C01<";
//			return "Mac Cocoa 5.0b6 27-Nov-09 >CF087523-A432-4427-9AD3-4ACF26336A08<";
//			return "Mac Cocoa 5.0b5 26-Nov-09 >9C6EF973-CECF-4E38-B5E0-BB9986A03D5D<";
//			return "Mac Cocoa 5.0b4 26-Nov-09 >DA33132E-D7E6-48C4-8363-EB7408E3124B<";
//			return "Mac Cocoa 5.0.0b1 11-Nov-09 >40BF8061-CC65-4E5E-9841-6BB5E809A688<";
#endif
			default: 
			break;
	}
	
	return (char *) [super getAttribute: indexNumber];
}
@end
