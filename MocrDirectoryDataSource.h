// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>
#import <IMocrDataSource.h>

@interface CMocrDirectoryDataSource : NSObject<IMocrDataSource> {
	NSString* _directoryPath;
}
// Get directory path.
- (NSString*) directoryPath;

// Create autoreleased instance.
+ (CMocrDirectoryDataSource*) dataSourceWithDirectoryPath:(NSString*)path;

// Constructor.
- (id) initWithDirectoryPath:(NSString*)path;

// Get file contents.
// Returns nil if file doesn't exist.
// Returned data should be manually released.
- (NSData*) dataWithPath:(NSString*)path;

// Returns YES if file exists in data sources.
- (BOOL) fileExistsWithPath:(NSString*)path;

@end