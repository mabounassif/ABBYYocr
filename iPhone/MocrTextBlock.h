// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

#if defined( TARGET_OS_IPHONE ) && ( TARGET_OS_IPHONE > 0 )
#import <CoreGraphics/CoreGraphics.h>
#endif

// Block of recognized text lines
@interface CMocrTextBlock : NSObject<NSCopying> {
@private
	// Array of the CMocrTextLine objects.
	NSArray* _lines;
	CGRect _blockRect;
	unsigned int _attributes;
}

@property(retain) NSArray* lines;
@property CGRect blockRect;

// Returns new array with NSString objects. This array contains recognized text from current block.
- (NSArray*) copyStrings;

// Returns YES if current object represents block of inverted text (white text, black background).
- (BOOL) isInverted;
// Returns YES if current object contains vertical CJK text lines.
- (BOOL) isVerticalCjk;

@end
