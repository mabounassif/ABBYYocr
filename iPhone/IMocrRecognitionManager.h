// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>
#import <MocrDefs.h>
#import <MocrLayout.h>
#import <MocrPrebuiltLayoutInfo.h>
#import <MocrBusinessCard.h>
#import <MocrBarcode.h>
#import <MocrImageRegion.h>

#if !defined(TARGET_OS_IPHONE) || !TARGET_OS_IPHONE
#	define UIImage NSImage
#endif

@class UIImage;

// IRecognitionCallback protocol defines callback function
// Must be implemented on the client side
// Delivers to the client the information about recognition process
@protocol IMocrRecognitionCallback

- (BOOL) calledWithProgress:(int)progress warning:(TMocrWarningCode)warning;

// If the MIPO_DetectPageOrientation flag is set then onRotationTypeDetected:
// is called when the rotation type is detected.
- (void) onRotationTypeDetected:(TMocrRotationType)rotationType;

// If the MIPO_PrebuildWordsInfo flag is set then onPrebuiltWordsInfoReady:
// is called when the prerecognition information about the document layout is ready.
// If both MIPO_DetectPageOrientation and MIPO_PrebuildWordsInfo flags are set then
// onPrebuiltWordsInfoReady: is called after onRotationTypeDetected:
// layoutInfo argument is passed the the ownership and should be release.
- (void) onPrebuiltWordsInfoReady:(CMocrPrebuiltLayoutInfo*)layoutInfo;

@end

@protocol IMocrRecognitionManager

// Recognize image as text.
- (BOOL) recognizeTextOnImage:(UIImage*)image
				 withCallback:(NSObject<IMocrRecognitionCallback>*)callbackObject
				  storeLayout:(CMocrLayout**)layout
					 rotation:(TMocrRotationType*)rotation;

// Recognize image region as text.
- (BOOL) recognizeTextOnImage:(UIImage*)image
				   withRegion:(CMocrImageRegion*)region
					 callback:(NSObject<IMocrRecognitionCallback>*)callbackObject
				  storeLayout:(CMocrLayout**)layout
					 rotation:(TMocrRotationType*)rotation;

// Recognize image as business card.
- (BOOL) recognizeBusinessCardOnImage:(UIImage*)image
						 withCallback:(NSObject<IMocrRecognitionCallback>*)callbackObject
					storeBusinessCard:(CMocrBusinessCard**)businessCard
							 rotation:(TMocrRotationType*)rotation;

// Recognize image as barcode.
- (BOOL) recognizeBarcodeOnImage:(UIImage*)image
					withCallback:(NSObject<IMocrRecognitionCallback>*)callbackObject
					storeBarcode:(CMocrBarcode**)barcode;

@end
