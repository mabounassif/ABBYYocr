// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

#if defined( TARGET_OS_IPHONE ) && ( TARGET_OS_IPHONE > 0 )
#import <CoreGraphics/CoreGraphics.h>
#endif

// Object wrapper for CGRect.
@interface CMocrRect : NSObject<NSCopying> {
	@private
	CGRect _rect;
}

@property CGRect rect;

+ (CMocrRect*) rectWithCgRect:(CGRect*)cgRect;

@end
