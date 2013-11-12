// Copyright (С) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>


typedef enum tagTMocrWordVariantType {
	// Original word as it was recognized. This variant always exist.
	MWVT_Original,
	// Primary word form
	MWVT_PrimaryForm,
} TMocrWordVariantType;


// Word variant.
@interface CMocrTextWordVariant : NSObject<NSCopying> {
	NSString* _text;
	TMocrWordVariantType _type;
}

@property(retain) NSString* text;
@property TMocrWordVariantType type;

// Returns a new NSString object with copy of CMocrTextWordVariant text. Should be released.
- (NSString*) copyString;
// Returns autoreleased NSString object with CMocrTextWordVariant text.
- (NSString*) getString;

@end
