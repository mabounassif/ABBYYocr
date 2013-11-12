// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

#if defined( TARGET_OS_IPHONE ) && ( TARGET_OS_IPHONE > 0 )
#import <CoreGraphics/CoreGraphics.h>
#endif

// Region of image. Set of rectangles on image.
// Object wrapper for CGRect.
@interface CMocrImageRegion : NSObject<NSCopying> {
	@private
	NSMutableArray* _rectangles;
}

@property(assign) NSMutableArray* rectangles;

+ (CMocrImageRegion*) imageRegionWithCgRect:(CGRect*)rect;

@end
