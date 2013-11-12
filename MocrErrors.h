// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

// Exceptions can be harmful in objective-c
// (see <https://developer.apple.com/library/ios/#documentation/Cocoa/Conceptual/Exceptions/Exceptions.html>).
// So they are thrown (when error  occures) only in the next methods:
//   CMocrEngine class:
//     +createSharedEngineWithDataSources:license:
//     +createSharedEngineWithDataSources:license:dataFilesExtensions:
//     +destroySharedInstance
//   CMocrConfiguration class:
//     -initWithImageResolution:imageProcessingOptions:recognitionMode:recognitionConfidenceLevel:barcodeTypes:defaultCodePage:unknownLetter:recognitionLanguages:
//     -setUserRecognitionLanguages:patternsDataFileName:
//     -enableMicrModeWithLanguage:patternsDataFileName:
// All memory allocated during the method call is released before the exception is thrown.
//
// The CMocrEngine class implements "last error" mechanism (see -getLastError:message: method of the CMocrEngine class).
// There are two cases:
// 1. Method should return a pointer type.
//    When error occures the "nil" value is returned and the "last error" is set.
// 2. Method should return BOOL.
//    When error occures the "NO" value is returned and the "last error" is set.
// More information can be found in the documentation.

// Error codes which can be observed by -getLastError:message: method of the CMocrEngine class.
typedef enum tagMocrErrorCode {
	// Codes of errors which are raised by iOS wrapper.
	MEC_NoError,
	MEC_InvalidArgument,					// Invalid argument was passed to method
	MEC_MemoryAllocationFailed,				// malloc failed
	MEC_FileNotFound,						// File was not found
	MEC_RecognitionInProgress,				// Previous recognition is in progress
	MEC_EngineInstanceExists,               // CMocrEngine singleton instance already exists
	MEC_EngineNotInitialized,               // No CMocrEngine instance exists

	// Codes of errors which are raised by MobileOCR native library.
	MEC_FineErrNotInitialized,
	MEC_FineErrLicenseError,
	MEC_FineErrInvalidArgument,
	MEC_FineErrNotEnoughMemory,
	MEC_FineErrInternalFailure,
	MEC_FineErrTerminatedByCallback
} TMocrErrorCode;
