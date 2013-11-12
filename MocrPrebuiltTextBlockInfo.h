// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

#if defined( TARGET_OS_IPHONE ) && ( TARGET_OS_IPHONE > 0 )
#import <CoreGraphics/CoreGraphics.h>
#endif

// Information about text block layout which is available before the textual recognition
@interface CMocrPrebuiltTextBlockInfo : NSObject<NSCopying> {
	@private
	// Array of the CMocrPrebuiltTextLineInfo objects.
	NSArray* _linesInfo;
	// Array of the CMocrRect objects.
	NSArray* _blockRegion;
}

@property(retain) NSArray* linesInfo;
@property(retain) NSArray* blockRegion;

@end
