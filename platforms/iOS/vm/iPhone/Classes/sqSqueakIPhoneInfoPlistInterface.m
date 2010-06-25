//
//  sqSqueakIPhoneInfoPlistInterface
//  SqueakNoOGLIPhone
//
//  Created by John M McIntosh on 9/1/08.
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

Sept-02-08  1.03b1  setup useScrollingView
*/
//

#import "sqSqueakIPhoneInfoPlistInterface.h"

NSString * kwriteable_preferenceKey = @"writeable_preference";
NSString * kscrollableView_preferenceKey = @"scrollableView_preference";
NSString * kmemorySize_preferenceKey = @"memorySize_preference";

 extern int gSqueakUseFileMappedMMAP;

@implementation sqSqueakIPhoneInfoPlistInterface
- (void) parseInfoPlist {
	NSAutoreleasePool * pool = [NSAutoreleasePool new];

	[super parseInfoPlist];
	
	self.SqueakUseFileMappedMMAP = YES;
	gSqueakUseFileMappedMMAP = 1;
	
	NSString *testValue = [defaults stringForKey: kwriteable_preferenceKey];
	
	if (testValue == nil) {
		// no default values have been set, create them here based on what's in our Settings bundle info
        //
        NSString *pathStr = [[NSBundle mainBundle] bundlePath];
        NSString *settingsBundlePath = [pathStr stringByAppendingPathComponent:@"Settings.bundle"];
        NSString *finalPath = [settingsBundlePath stringByAppendingPathComponent:@"Root.plist"];
		
        NSDictionary *settingsDict = [NSDictionary dictionaryWithContentsOfFile:finalPath];
        NSArray *prefSpecifierArray = [settingsDict objectForKey:@"PreferenceSpecifiers"];

        NSDictionary *prefItem;
		NSString	*writeable_preferenceDefault = @"NO";
		NSString	*scrollableView_preferenceDefault= @"NO";
		NSString	*memorySize_preferenceDefault=@"31457280";
        for (prefItem in prefSpecifierArray)	{
			NSString *keyValueStr = [prefItem objectForKey:@"Key"];
			id defaultValue = [prefItem objectForKey:@"DefaultValue"];
		
			if ([keyValueStr isEqualToString: kwriteable_preferenceKey]) {
				writeable_preferenceDefault = defaultValue;
			}

			if ([keyValueStr isEqualToString: kscrollableView_preferenceKey]) {
				scrollableView_preferenceDefault = defaultValue;
			}

			if ([keyValueStr isEqualToString: kmemorySize_preferenceKey]) {
				memorySize_preferenceDefault = defaultValue;
			}
		}
		
        // since no default values have been set (i.e. no preferences file created), create it here
        NSDictionary *appDefaults =  [NSDictionary dictionaryWithObjectsAndKeys: writeable_preferenceDefault,  kwriteable_preferenceKey,
									  scrollableView_preferenceDefault,  kscrollableView_preferenceKey,
									  memorySize_preferenceDefault,  kmemorySize_preferenceKey,
									  nil];
        
        [[NSUserDefaults standardUserDefaults] registerDefaults: appDefaults];
        [[NSUserDefaults standardUserDefaults] synchronize];
	}
	[pool drain];
	
}

- (BOOL) imageIsWriteable {
	return [defaults boolForKey: kwriteable_preferenceKey];
}

- (BOOL) useScrollingView {
	return [defaults boolForKey: kscrollableView_preferenceKey];
}

- (NSInteger) memorySize {
	return [defaults integerForKey: kmemorySize_preferenceKey];
}
@end
