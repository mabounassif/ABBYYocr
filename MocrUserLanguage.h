// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>
#import <IMocrLanguage.h>

// User-provided recognition language.
@interface CMocrUserLanguage : NSObject<IMocrLanguage> {
	@private
	TMocrLanguageId _languageId;
}

// Get language ID.
- (TMocrLanguageId) languageId;

// Create autoreleased instance.
// languageId should be between 1024 and 65535.
+ (CMocrUserLanguage*) languageWithId:(TMocrLanguageId)languageId;

// Constructor.
- (id) initWithId:(TMocrLanguageId)languageId;

@end
