//
//  sqSqueakMainApplication+imageReadWrite.m
//
//  Created by John M McIntosh on 5/22/08.
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

#import "sqSqueakMainApplication+imageReadWrite.h"
#import "sqMacV2Memory.h"

@implementation sqSqueakMainApplication (imageReadWrite) 
- (void) findImageViaBundleOrPreferences {
}

- (BOOL) readImageIntoMemory {
	NSAutoreleasePool * pool = [NSAutoreleasePool new];
	const char * characterPathForImage = (const char *) [[NSFileManager defaultManager] fileSystemRepresentationWithPath: [self.imageNameURL path]];
	sqImageFile f;
	if (!characterPathForImage)  {
		[pool drain];
		return NO;
	}
	f = sqImageFileOpen(characterPathForImage, "rb");
	#warning sqGetAvailableMemory returns unsigned but readImageFromFileHeapSizeStartingAt is wrong
	readImageFromFileHeapSizeStartingAt(f, sqGetAvailableMemory(), (squeakFileOffsetType) 0);  //This is a VM Callback
	sqImageFileClose(f);
	[pool drain];
	return YES;
}
@end
