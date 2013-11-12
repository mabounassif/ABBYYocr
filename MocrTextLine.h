// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

#if defined( TARGET_OS_IPHONE ) && ( TARGET_OS_IPHONE > 0 )
#import <CoreGraphics/CoreGraphics.h>
#endif

// Recognized line
@interface CMocrTextLine : NSObject<NSCopying> {
	@private
	CGRect _lineRect;
	NSArray* _characters;
	NSArray* _words;
}

@property CGRect lineRect;
// Array of CMocrCharacter objects. Contain text line characters information.
@property(retain) NSArray* characters;
// Array of CMocrTextWord objects.
@property(retain) NSArray* words;

// Returns a new NSString object that contains recognized text. Should be released.
- (NSString*) copyString;

@end
