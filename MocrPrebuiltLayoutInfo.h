// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

// Information about document layout which is available before the textual recognition
@interface CMocrPrebuiltLayoutInfo : NSObject<NSCopying> {
	@private
	// Array of CMocrPrebuiltTextBlockInfo objects
	NSArray* _blocksInfo;
}

@property(retain) NSArray* blocksInfo;

@end
