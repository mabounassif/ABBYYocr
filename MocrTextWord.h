// Copyright (С) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

#if defined( TARGET_OS_IPHONE ) && ( TARGET_OS_IPHONE > 0 )
#import <CoreGraphics/CoreGraphics.h>
#endif

// Information related to one of the parts of text, obtained after splitting the text by words
@interface CMocrTextWord : NSObject<NSCopying> {
	NSArray* _variants;
	CGRect _wordRect;
	int _attributes;
}

// Array of CMocrTextWordVariant objects.
@property(retain) NSArray* variants;
// Rectangle of the word.
@property CGRect wordRect;

// Returns YES if this is a piece of text which is not a word. Can be a gap between words (space, comma), number or
// a punct set, etc.
// In this case there should be the only one word variant - with MWVT_Original type. */
- (BOOL) isNotWord;
// Returns YES if the word is a piece of text which is not a word.
// Can be a gap between words (space, comma), number or a punct set.
// In this case there should be the only one word variant - with MWVT_Original type.
- (BOOL) isSplit;
// Returns YES if the word was obtained by cutting the longer word.
- (BOOL) isHyphenated;

// Returns a new NSString object that contains CMocrTextWord text. Should be released.
// NOTE! Returns recognized text, not a primary form.
- (NSString*) copyString;
// Returns autoreleased NSString object with CMocrTextWord text.
// NOTE! Returns recognized text, not a primary form.
- (NSString*) getString;

@end
