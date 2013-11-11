// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

// Text recognition results
@interface CMocrLayout:NSObject<NSCopying> {
	@private
	// Array of CMocrTextBlock objects
	NSArray* _blocks;
}

@property(retain) NSArray* blocks;

// Returns new array with NSString objects. This array contains recognized text from layout.
- (NSArray*) copyStrings;

@end
