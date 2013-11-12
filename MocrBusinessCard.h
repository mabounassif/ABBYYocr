// Copyright (C) ABBYY (BIT Software), 1993 - 2012. All rights reserved.

#import <Foundation/Foundation.h>

// Types of business card field components
typedef enum tagTMocrBcrFieldComponentType {
	MBFCT_FirstName,
	MBFCT_MiddleName,
	MBFCT_LastName,
	MBFCT_ExtraName,
	MBFCT_Title,
	MBFCT_Degree,
	
	MBFCT_PhonePrefix,
	MBFCT_PhoneCountryCode,
	MBFCT_PhoneCode,
	MBFCT_PhoneBody,
	MBFCT_PhoneExtension,
	
	MBFCT_ZipCode,
	MBFCT_Country,
	MBFCT_City,
	MBFCT_StreetAddress,
	MBFCT_Region,
	
	MBFCT_JobPosition,
	MBFCT_JobDepartment,
	
	MBFCT_Count
} TMocrBcrFieldComponentType;

// Types of business card fields
typedef enum tagTMocrBcrFieldType {
	MBFT_Phone,
	MBFT_Fax,
	MBFT_Mobile,
	MBFT_Email,
	MBFT_Web,
	MBFT_Address,
	MBFT_Name,
	MBFT_Company,
	MBFT_Job,
	MBFT_Text,
	
	MBFT_Count
} TMocrBcrFieldType;


// Represents a field of a business card. 
@interface CMocrBusinessCardFieldComponent : NSObject<NSCopying> {
	@private
	// An array of CMocrTextLine objects which contains text from a field component.
	NSArray* _lines;
	// The type of the component of the business card field
	TMocrBcrFieldComponentType _componentType;
}

@property(retain) NSArray* lines;
@property TMocrBcrFieldComponentType componentType;

- (NSArray*) copyStrings;

@end


// Represents a field of business card. 
@interface CMocrBusinessCardField : NSObject<NSCopying> {
	@private
	// Array of CMocrTextLine objects which contain text from a field
	NSArray* _lines;
	// Type of a business card field
	TMocrBcrFieldType _fieldType;
	// Array of CMocrBusinessCardFieldComponent objects. If field contains no components, Components is nil.
	NSArray* _components;
}

@property(retain) NSArray* lines;
@property TMocrBcrFieldType fieldType;
@property(retain) NSArray* components;

- (NSArray*) copyStrings;

@end


// Recognized business card
@interface CMocrBusinessCard : NSObject<NSCopying> {
@private
	NSArray* _fields;
}

@property(retain) NSArray* fields;

@end
