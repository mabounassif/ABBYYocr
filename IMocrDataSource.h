// Copyright (С) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

@protocol IMocrDataSource

// Get file contents.
// Returns nil if file doesn't exist.
// Returned data should be manually released.
- (NSData*) dataWithPath:(NSString*)path;

// Returns YES if file exists in data sources. Otherwise returns NO.
- (BOOL) fileExistsWithPath:(NSString*)path;

@end