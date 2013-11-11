// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>
#import <MocrDefs.h>
#import <MocrTextLine.h>

// Recognized barcode
@interface CMocrBarcode : NSObject<NSCopying> {
	@private
	TMocrBarcodeTypeFlags _type;
	CMocrTextLine* _text;
}

@property TMocrBarcodeTypeFlags type;
@property(retain) CMocrTextLine* text;

@end
