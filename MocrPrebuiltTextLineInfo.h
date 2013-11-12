// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

#if defined( TARGET_OS_IPHONE ) && ( TARGET_OS_IPHONE > 0 )
#import <CoreGraphics/CoreGraphics.h>
#endif

// Information about text line layout which is available before the textual recognition
@interface CMocrPrebuiltTextLineInfo : NSObject<NSCopying> {
	@private
	CGRect _lineRect;
	NSArray* _wordRects;
}

@property CGRect lineRect;
// Array of CMocrRect objects.
@property(retain) NSArray* wordRects;

@end
