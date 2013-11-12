// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

typedef enum tagMocrRotationType {
	MRT_NoRotation,
	MRT_Clockwise,			// 90 degrees clockwise
	MRT_UpsideDown,			// 180 degrees
	MRT_Counterclockwise,	// 90 degrees counterclockwise
} TMocrRotationType;

typedef enum tagMocrRecognitionMode {
	MRM_Fast = 0,
	MRM_Full = 1
} TMocrRecognitionMode;

typedef enum tagMocrRecognitionConfidenceLevel {
	MRCL_Level0 = 0, // Don't mark characters as uncertain
	MRCL_Level1 = 1,
	MRCL_Level2 = 2,
	MRCL_Level3 = 3, // Default level
	MRCL_Level4 = 4  // Mark all suspicious characters as uncertain
} TMocrRecognitionConfidenceLevel;

typedef enum tagMocrImageProcessingOptionsFlags {
	MIPO_Default = 0,
	
	MIPO_DisableDeskew = 1 << 0,
	
	MIPO_DisableImageGeometricTransform = MIPO_DisableDeskew,
	
	// Specifies whether the page orientation should be detected. 
	// If this flag is set then the rotation parameter of the
	// [IRecognitionManager recognizeTextOnImage:withCallback:storeLayout:rotation:],
	// [IRecognitionManager recognizeTextOnImage:withRegion:callback:storeLayout:rotation:],
	// [IRecognitionManager recognizeBusinessCardOnImage:withCallback:storeBusinessCard:rotation:],
	// [IRecognitionManager recognizeBarcodeOnImage:withCallback:storeBarcode:]
	// methods return the TMocrRotationType enumeration value which represents the rotation angle
	// multiple of 90 degrees.
	// These methods return the recognized text coordinates corresponded to a rotated image.
	// If this flag is set then the [IMocrRecognitionCallback onRotationTypeDetected:] callback is called
	// before the text recognition.
	// Note. Setting this flag decreases recognition speed.		
	MIPO_DetectPageOrientation = 1 << 1,
	
	// Specifies whether the input image has hieroglyphic characters (Chinese, Japanese or Korean).
	// This constant is automatically added into the input parameters of the recognition functions
	// if the input list of the recognition languages of these functions contains an hieroglyphic language.
	MIPO_HasCjk = 1 << 4,
	
	// If this constant is set, the program will find all text on image. 
	// Pictures and garbage will be analyzed and recognized. 
	MIPO_FindAllText = 1 << 5,
	
	// Specifies whether the input image has text that is written in an European and an hieroglyphic languages. 
	// This constant is automatically added into input parameters of the FineRecognizeBusinessCard function 
	// if the input list of recognition languages of this function contains an hieroglyphic language.
	MIPO_IsEuropeanWithSomeCjk = 1 << 6,
	
	// If this constant is set, the program will recognize only a horizontal hieroglyphic text on image, 
	// a vertical hieroglyphic text will be ignored.
	MIPO_ProhibitVerticalCjkText = 1 << 7,

	// If this flag is set then after recognition CMocrTextLine.words will point to an array of CMocrTextWord
	// objects.
	MIPO_BuildWordsInfo = 1 << 9,

	// This flag is used to obtain approximate document layout before the text recognition.
	// If this flag is set then the [IMocrRecognitionCallback onPrebuiltWordsInfoReady:] callback is called
	// before the text recognition.
	MIPO_PrebuildWordsInfo = 1 << 10
} TMocrImageProcessingOptionsFlags;

// Supported codepages
typedef enum tagMocrSupportedCodePage {
	MSCP_Arabic = 1256,
	MSCP_ArabicIso = 28596,
	MSCP_BalticIso = 28594,
	MSCP_Cyrillic = 1251,
	MSCP_CyrillicIso = 28595,
	MSCP_EasternEuropean = 1250,
	MSCP_EasternEuropeanIso = 28592,
	MSCP_GreekIso = 28597,
	MSCP_HebrewIso = 28598,
	MSCP_JapanSjis = 932,
	MSCP_Latin = 1252,
	MSCP_Latin5Iso = 28599,
	MSCP_LatinIso = 28591,
	MSCP_TurkishIso = 28593,
	MSCP_UsMsdos = 437,
	MSCP_Utf8 = 65001
} TMocrSupportedCodePage;

// Type of barcode
typedef enum tagMocrBarcodeTypeFlags {
	// Type of unrecognized barcode
	MBT_UNRECOGNIZED = 0,
	// Code 39
	MBT_CODE39 = 1 << 0,
	// Interleaved 2 of 5
	MBT_INTERLEAVED25 = 1 << 1,
	// EAN-13
	MBT_EAN13 = 1 << 2,	
	// Code 128	
	MBT_CODE128 = 1 << 3,
	// EAN-8
	MBT_EAN8 = 1 << 4,
	// PDF417
	MBT_PDF417 = 1 << 5,
	// Codabar
	MBT_CODABAR = 1 << 6,
	// UPC-E
	MBT_UPCE = 1 << 7,
	// Industrial 2 of 5
	MBT_INDUSTRIAL25 = 1 << 8,
	// IATA 2 of 5
	MBT_IATA25 = 1 << 9,
	// Matrix 2 of 5	
	MBT_MATRIX25 = 1 << 10,
	// Code 93
	MBT_CODE93 = 1 << 11,
	// Postnet
	MBT_POSTNET = 1 << 12,
	// UCC-128
	MBT_UCC128 = 1 << 13,
	// Patch
	MBT_PATCH = 1 << 14,
	// Aztec
	MBT_AZTEC = 1 << 15,
	// DataMatrix
	MBT_DATAMATRIX = 1 << 16,
	// QRCode
	MBT_QRCODE = 1 << 17,
	// UPC-A
	MBT_UPCA = 1 << 18,
	// MaxiCode
	MBT_MAXICODE = 1 << 19,
	
	// All one dimensional barcode types
	MBT_ANY1D = MBT_CODE39 | MBT_INTERLEAVED25 |
	MBT_EAN13 | MBT_CODE128 | MBT_EAN8 | MBT_CODABAR | MBT_UPCE | MBT_INDUSTRIAL25 | MBT_IATA25 | 
	MBT_MATRIX25 | MBT_CODE93 | MBT_UCC128 | MBT_PATCH | MBT_POSTNET | MBT_UPCA,
	// All two dimensional barcode types
	MBT_SQUARE2D = MBT_AZTEC | MBT_DATAMATRIX | MBT_QRCODE | MBT_MAXICODE,
	// All one dimensional barcode types, which can have supplement
	MBT_ANY1D_WITH_SUPPLEMENT = MBT_EAN13 | MBT_EAN8 | MBT_UPCE | MBT_UPCA
} TMocrBarcodeTypeFlags;

// Warning codes of callback function
typedef enum tagMocrWarningCode {
	MWC_NoWarning,
	MWC_SlowRecognition,
	MWC_ProbablyBadImage,
	MWC_ProbablyWrongLanguages,
	MWC_SureWrongLanguages
} TMocrWarningCode;
