/*
 *  sqMacExtendedClipboard.m
 *  SqueakClipboardExtendedxcodeproj
 *
 *  Created by John Sterling Mcintosh on 4/21/06.
 *  Copyright 2006-2010 Corporate Smalltalk Consulting ltd. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following
 *  conditions:
 *  
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *  OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "sqMacExtendedClipboard.h"
#import <Cocoa/Cocoa.h>


extern struct VirtualMachine* interpreterProxy;

void sqPasteboardClear(void *inPasteboard )
{
	NSArray *arrayOfTypes = [[NSArray alloc] init];
	
	[(NSPasteboard*) inPasteboard declareTypes: arrayOfTypes owner: nil];
	[arrayOfTypes release];

}

sqInt sqPasteboardGetItemCount (void *inPasteboard )
{
	return [[(NSPasteboard *)inPasteboard types] count];
}

sqInt sqPasteboardCopyItemFlavorsitemNumber (  void *inPasteboard, sqInt formatNumber )
{

	sqInt formatTypeLength;
	sqInt flavorCount;
	
	flavorCount =  [[(NSPasteboard *)inPasteboard types] count];
	if (formatNumber > flavorCount) {
		return interpreterProxy->nilObject();
	}
	
	NSString *formatType = [[(NSPasteboard *)inPasteboard types] objectAtIndex: formatNumber-1];
	
	const char *utf8data = [formatType UTF8String];
	formatTypeLength = strlen(utf8data);
	sqInt outData = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), formatTypeLength);
	unsigned char* formatConverted = interpreterProxy->firstIndexableField(outData);
	memcpy(formatConverted,utf8data,formatTypeLength);
	
	return outData;
}

void * sqCreateClipboard( void )
{
	return (void*) [NSPasteboard generalPasteboard];
}

void sqPasteboardPutItemFlavordatalengthformatTypeformatLength ( void *inPasteboard, char* inData, sqInt dataLength, char* format, sqInt formatLength)
{	
	NSString *formatType = [[NSString alloc] initWithBytes: format length: formatLength encoding:  NSUTF8StringEncoding];
	NSData* data = [[NSData alloc ] initWithBytes: inData length: dataLength];
	NSArray *arrayOfTypes = [[NSArray alloc] initWithObjects: formatType,nil];

	[(NSPasteboard *)inPasteboard declareTypes: arrayOfTypes owner: nil];
	[(NSPasteboard *)inPasteboard setData: data forType: formatType];

	[arrayOfTypes release];
	[data release];
	[formatType release];
}
	
sqInt sqPasteboardCopyItemFlavorDataformatformatLength ( void *inPasteboard, char* format, sqInt formatLength)
{
	NSString *formatType = [[NSString alloc] initWithBytes: format length: formatLength encoding:  NSUTF8StringEncoding];
	NSArray *arrayOfTypes = [[NSArray alloc] initWithObjects: formatType,nil];
	NSString     *type= [(NSPasteboard *)inPasteboard availableTypeFromArray: arrayOfTypes];
														
	if (type == NULL) {
		[formatType  release];
		[arrayOfTypes release];
		return interpreterProxy->nilObject();
	}		

	NSData *dataBuffer = [(NSPasteboard *)inPasteboard dataForType: type];
	sqInt dataLength = [dataBuffer length];
	sqInt outData = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), dataLength );
	char *outDataPtr = (char *) interpreterProxy->firstIndexableField(outData);
	[dataBuffer getBytes: outDataPtr];

	[formatType release];
	[arrayOfTypes release];
	return outData;
}