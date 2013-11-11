// Copyright (С) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

#import <IMocrDataSource.h>
#import <MocrDirectoryDataSource.h>
#import <MocrLicense.h>
#import <IMocrRecognitionManager.h>
#import <MocrRecognitionConfiguration.h>
#import <MocrDefs.h>
#import <MocrErrors.h>
#import <MocrTextWordVariant.h>
#import <MocrTextWord.h>
#import <MocrCharacter.h>
#import <MocrTextLine.h>
#import <MocrTextBlock.h>

// Stores extensions for MobileOCR resource files.
@interface CMocrDataFilesExtensions : NSObject {
	@private
	NSString* _patternsFileExtension;
	NSString* _dictionaryFileExtension;
	NSString* _keywordsFileExtension;
}

@property(readonly) NSString* patternsFileExtension;
@property(readonly) NSString* dictionaryFileExtension;
@property(readonly) NSString* keywordsFileExtension;

// Create autoreleased instance.
+ (CMocrDataFilesExtensions*) extensionsForPatterns:(NSString*)patternsFileExtension
									   dictionaries:(NSString*)dictionaryFileExtension
										   keywords:(NSString*)keywordsFileExtension;

// Constructor.
- (id) initExtensionsForPatterns:(NSString*)patternsFileExtension
					dictionaries:(NSString*)dictionaryFileExtension
						keywords:(NSString*)keywordsFileExtension;

@end

// Singleton class. The CMocrEngine instance is created to begin working with MobileOCR engine for iOS.
// The CMocrEngine class implements the following operations:
//  * License validation.
//    License data (see CMocrLicense) are given to the CMocrEngine constructor.
//
//  * Recognition resources data input.
//    The CMocrEngine constructor takes as argument the list of
//    objects implementing IMocrDataSource protocol (in the MobileOCR engine there is implemention of IMocrDataSource
//    protocol: CMocrDirectoryDataSource).
//    Resource file input is performed by relative URI. This URI is provided for each data source object
//    from the list one by one until the file is found.
//
//  * Recognition managers factory.
//    Recognition manager implements IMocrRecognitionManager interface and
//    stores the recognition configuration (see CMocrRecognitionConfiguration).
//
//  * Resource availability check.
//
//  * Error handling.
//    See <MocrErrors.h> header file.
@interface CMocrEngine : NSObject {
	@private
	// Data sources.
	NSArray* _dataSources;
	// License data.
	CMocrLicense* _license;
	// Data files extensions.
	CMocrDataFilesExtensions* _dataFilesExtensions;
	// Predicates.
	NSPredicate* _languageAvailableForOcrPredicate;
	NSPredicate* _languageAvailableForBcrPredicate;
}

// Get existing CMocrEngine singleton instance or nil.
+ (CMocrEngine*) getSharedEngine;

// Create CMocrEngine singleton instance.
// Data files extensions are initialized by default values:
//  patterns     - @".rom"
//  dictionaries - @".edc"
//  keywords     - @".akw"
// If CMocrEngine instance already exists then NSException is thrown.
+ (CMocrEngine*) createSharedEngineWithDataSources:(NSArray*)dataSources
										   license:(CMocrLicense*)license;

// Create CMocrEngine singleton instance.
// If CMocrEngine instance already exists then NSException is thrown.
+ (CMocrEngine*) createSharedEngineWithDataSources:(NSArray*)dataSources
										   license:(CMocrLicense*)license
							   dataFilesExtensions:(CMocrDataFilesExtensions*)dataFilesExtensions;

// Destroy CMocrEngine singleton instance.
+ (BOOL) destroySharedInstance;

// Create new recognition manager with the given configuration.
- (NSObject<IMocrRecognitionManager>*) newRecognitionManagerWithConfiguration:(CMocrRecognitionConfiguration*)configuration;

// Get the set of languages (CMocrLanguage objects) available for text recognition.
- (NSSet*) languagesAvailableForOcr;

// Get the set of languages (CMocrLanguage objects) available for business card recognition.
- (NSSet*) languagesAvailableForBcr;

// Returns YES if language is available for text recognition. Otherwise returns NO.
- (BOOL) isLanguageAvailableForOcr:(NSString*)language;

// Returns YES if language is available for business card recognition. Otherwise returns NO.
- (BOOL) isLanguageAvailableForBcr:(NSString*)language;

// Get last error code and message. errorMessage is assigned with retained error message.
// Don't forget to release errorMessage when it is no more needed.
+ (void) getLastError:(TMocrErrorCode*)errorCode message:(NSString**)errorMessage;

@end
