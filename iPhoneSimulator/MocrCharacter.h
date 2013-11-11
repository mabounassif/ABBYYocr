// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

#if defined( TARGET_OS_IPHONE ) && ( TARGET_OS_IPHONE > 0 )
#import <CoreGraphics/CoreGraphics.h>
#endif

// Character attribute flags.
typedef enum tagMocrCharacterAttributes{
	MCA_Italic = ( 1 << 0 ),
	MCA_Bold = ( 1 << 1 ),
	MCA_Underlined = ( 1 << 2 ),
	MCA_StrikeThrough = ( 1 << 3 ),
	MCA_Smallcaps = ( 1 << 4 ),
	MCA_Superscript = ( 1 << 5 ),
	MCA_Uncertain = ( 1 << 16 )
} TMocrCharacterAttributes;


// Represents a recognized character with additional information
@interface CMocrCharacter : NSObject<NSCopying> {
	@private
	unichar _unicode;
	CGRect _charRect;
	unsigned int _attributes; 
	unsigned int _smallLetterHeight;
}

@property unichar unicode;
@property CGRect charRect;
@property unsigned int attributes;
@property unsigned int smallLetterHeight;

// Returns YES if current character is uncertain.
- (BOOL) isUncertain;
// Returns YES if current character is bold.
- (BOOL) isBold;
// Returns YES if current character is italic.
- (BOOL) isItalic;

@end
