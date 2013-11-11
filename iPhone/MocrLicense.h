// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

// Stores MobileOCR license data.
@interface CMocrLicense : NSObject {
	@private
	NSData* _licenseData;
	NSString* _applicationId;
}

// Create autoreleased instance.
+ (CMocrLicense*) licenseWithLicenseData:(NSData*)data applicationId:(NSString*)applicationId;

// Constructor.
- (id) initWithLicenseData:(NSData*)data applicationId:(NSString*)applicationId;

@end
