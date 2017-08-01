%{
	#include "usdsBasicParser.h"
	#include "dictionary\usdsDictionary.h"

	#include "dictionary\dictionaryBaseType.h"
	#include "dictionary\dataTypes\dictionaryTagLink.h"
	#include "dictionary\dataTypes\dictionaryBoolean.h"
	#include "dictionary\dataTypes\dictionaryByte.h"
	#include "dictionary\dataTypes\dictionaryUByte.h"
	#include "dictionary\dataTypes\dictionaryShort.h"
	#include "dictionary\dataTypes\dictionaryUShort.h"
	#include "dictionary\dataTypes\dictionaryInt.h"
	#include "dictionary\dataTypes\dictionaryUint.h"
	#include "dictionary\dataTypes\dictionaryLong.h"
	#include "dictionary\dataTypes\dictionaryULong.h"
	#include "dictionary\dataTypes\dictionaryFloat.h"
	#include "dictionary\dataTypes\dictionaryDouble.h"
	#include "dictionary\dataTypes\dictionaryVarint.h"
	#include "dictionary\dataTypes\dictionaryUVarint.h"
	#include "dictionary\dataTypes\dictionaryString.h"
	#include "dictionary\dataTypes\dictionaryArray.h"	
	#include "dictionary\dataTypes\dictionaryStruct.h"

	#include "usdsTypes.h"
	
	#include "flexDictionaryTextScanner.h"
	#include <string>
	
%}

%require "3.0.4"
%skeleton "lalr1.cc"
%debug
%defines
%define api.prefix {dictionary_text}
%define api.namespace {usds}
%define parser_class_name {BisonDictionaryTextParser}
%locations

%parse-param {const char* input_text}
%parse-param {class Dictionary* dict}
%parse-param {class FlexDictionaryTextScanner* scanner}
%parse-param {class DictionaryBaseType* tag}
%parse-param {class DictionaryBaseType* field}

%error-verbose

%union {
    bool  			boolVal;
	int8_t  		int8Val;
	uint8_t  		uInt8Val;
	int16_t  		int16Val;
	uint16_t  		uInt16Val;
	int32_t  		int32Val;
	uint32_t  		uInt32Val;
	int64_t  		int64Val;
	uint64_t  		uInt64Val;
	float 			floatVal;
    double 			doubleVal;
    size_t			stringVal[2];
	usdsEncodes		encodeVal;
	usdsTypes		typeVal;
	struct			floatDigits { double value; double digits; } floatDigits;
}

// Tokens
%token USDS
%token DICTIONARY_VERSION

%token<typeVal> TYPE_BOOLEAN "BOOLEAN"
%token<typeVal> TYPE_BYTE "BYTE"
%token<typeVal> TYPE_UBYTE "UBYTE"
%token<typeVal> TYPE_SHORT "SHORT"
%token<typeVal> TYPE_USHORT "USHORT"
%token<typeVal> TYPE_INT "INT"
%token<typeVal> TYPE_UINT "UINT"
%token<typeVal> TYPE_LONG "LONG"
%token<typeVal> TYPE_ULONG "ULONG"
%token<typeVal> TYPE_INT128 "INT128"
%token<typeVal> TYPE_UINT128 "UINT128"
%token<typeVal> TYPE_FLOAT "FLOAT"
%token<typeVal> TYPE_DOUBLE "DOUBLE"
%token<typeVal> TYPE_VARINT "VARINT"
%token<typeVal> TYPE_UVARINT "UVARINT"
%token<typeVal> TYPE_STRING "STRING"

%token<encodeVal> STRING_ENCODE "<Text encode>"

%token<boolVal> BOOLEAN_VALUE "true or false"
%token<int8Val> POSITIVE_NUMBER "Digit"
%token<int8Val> NEGATIVE_NUMBER "-Digit"
%token NULL_VALUE "NULL"
%token<stringVal> TEXT_STRING "Text string"

%token<stringVal> TEXT_NAME "Object name"

// restrictions
%token USDS_RESTRICT
%token NOT_ROOT_TAG "notRoot"

%token '{'
%token '}'
%token ':'
%token ';'
%token '='
%token '.'

%type<int8Val> INT8_T "int8_t"
%type<uInt8Val> UINT8_T "uint8_t"
%type<int16Val> INT16_T "int16_t"
%type<uInt16Val> UINT16_T "uint16_t"
%type<int32Val> INT32_T "int32_t"
%type<uInt32Val> UINT32_T "uint32_t"
%type<int64Val> INT64_T "int64_t"
%type<uInt64Val> UINT64_T "uint64_t"

%type<doubleVal> FLOAT_VALUE "Float value"
%type<doubleVal> positive_major_float_digits "Positive major float value"
%type<doubleVal> negative_major_float_digits "Negative major float value"
%type<floatDigits> minor_float_digits "Minor float value"
%token<int8Val> POSITIVE_EXPONENT_NUMBER "Positive float exponent digit"
%token<int8Val> NEGATIVE_EXPONENT_NUMBER "Negative float exponent digit"
%type<doubleVal> float_exponent "Float exponent"

%type<uInt32Val> array_dimension "Array declaration"
%type<uInt32Val> array_of_struct_begin "Array of struct declaration"

%{
#undef yylex
#define yylex scanner->scan
%}

//=================================================================================================
// Rules
%%
dictionary: 
	USDS TEXT_NAME UINT32_T '.' UINT8_T '.' UINT8_T
	{
		dict->setID(input_text + $2[0], $2[1], $3, $5, $7);
	}
	'{' tags '}'
	{
		// Finilize dictionary
		dict->finalizeDictionary();
	}
	;

	
//=================================================================================================
// Tags

tags: tag |tag tags;
	
tag: INT32_T ':' TYPE_BOOLEAN TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_BYTE TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_UBYTE TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_SHORT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_USHORT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_INT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_UINT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_LONG TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_ULONG TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_INT128 TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_UINT128 TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_FLOAT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_DOUBLE TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_VARINT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_UVARINT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_STRING TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_STRING '<' STRING_ENCODE '>' TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $7[0], $7[1]);
		((DictionaryString*)tag)->setDefaultEncode($5);
	}
	|INT32_T ':' TEXT_NAME '{'
	{
		tag = dict->addTag(USDS_STRUCT, $1, input_text + $3[0], $3[1]);
	}
	fields '}' ';'
	{
	
	}
//=================================================================================================
// Arrays
	|INT32_T ':' TYPE_BOOLEAN array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_BYTE array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_UBYTE array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_SHORT array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_USHORT array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_INT array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_UINT array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_LONG array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_ULONG array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_INT128 array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_UINT128 array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_FLOAT array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_DOUBLE array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_VARINT array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_UVARINT array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_STRING array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType($3);
	}
	|INT32_T ':' TYPE_STRING '<' STRING_ENCODE '>' array_dimension TEXT_NAME ';'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $8[0], $8[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $7; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		usds::DictionaryString* string_element = (usds::DictionaryString*)arr_tag->setElementType($3);
		string_element->setDefaultEncode($5);
	}
	|INT32_T ':' TEXT_NAME array_dimension '{'
	{
		tag = dict->addTag(usds::USDS_ARRAY, $1, input_text + $3[0], $3[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		// for fields
		tag = arr_tag->setElementType(USDS_STRUCT);
	}
	fields '}' ';'
	{
	
	}
	;
	
//=================================================================================================
// Struct fields

fields: field |field fields;

field:
	INT32_T ':' TYPE_BOOLEAN TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_BYTE TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_UBYTE TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_SHORT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_USHORT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_INT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_UINT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_LONG TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_ULONG TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_INT128 TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_UINT128 TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_FLOAT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_DOUBLE TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_VARINT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_UVARINT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|INT32_T ':' TYPE_STRING TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}	
	|INT32_T ':' TYPE_STRING '<' STRING_ENCODE '>' TEXT_NAME ';'
	{
		field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $7[0], $7[1]);
		((DictionaryString*)field)->setDefaultEncode($5);
	}
	|INT32_T ':' TEXT_NAME TEXT_NAME ';'
	{
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, $1, input_text + $4[0], $4[1]);
		((DictionaryTagLink*)field)->setTag(input_text + $3[0], $3[1]);
	}
	|struct_begin fields '}' ';'
	{
		tag = tag->getParent();
	}
//=================================================================================================
// Array fields
	|INT32_T ':' TYPE_BOOLEAN array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_BYTE array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_UBYTE array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_SHORT array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_USHORT array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_INT array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_UINT array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_LONG array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_ULONG array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_INT128 array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_UINT128 array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_FLOAT array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_DOUBLE array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_VARINT array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_UVARINT array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_STRING array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}	
	|INT32_T ':' TYPE_STRING '<' STRING_ENCODE '>' array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $8[0], $8[1]);
		for (uint32_t i = 1; i < $7; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryString* element = (DictionaryString*)arr_field->setElementType($3);	
		element->setDefaultEncode($5);
	}
	|array_of_struct_begin fields '}' ';'
	{
		for (uint32_t i = 0; i <= $1; i++)
		{
			tag = tag->getParent();
		}
	}
	|INT32_T ':' TEXT_NAME array_dimension TEXT_NAME ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryTagLink* element = (DictionaryTagLink*)arr_field->setElementType(usds::USDS_TAG);
		element->setTag(input_text + $3[0], $3[1]);
	}
//=================================================================================================
// Nullable fields

	|INT32_T ':' TYPE_BOOLEAN TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_BYTE TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_UBYTE TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_SHORT TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_USHORT TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_INT TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_UINT TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_LONG TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_ULONG TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_INT128 TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_UINT128 TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_FLOAT TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_DOUBLE TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_VARINT TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_UVARINT TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TYPE_STRING TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
		dict_field->setNullable(true);
	}	
	|INT32_T ':' TYPE_STRING '<' STRING_ENCODE '>' TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $7[0], $7[1]);
		((DictionaryString*)dict_field)->setDefaultEncode($5);
		dict_field->setNullable(true);
	}
	|INT32_T ':' TEXT_NAME TEXT_NAME '=' NULL_VALUE ';'
	{
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, $1, input_text + $4[0], $4[1]);
		((DictionaryTagLink*)field)->setTag(input_text + $3[0], $3[1]);
		field->setNullable(true);
	}
	|struct_begin fields '}' '=' NULL_VALUE ';'
	{
		tag->setNullable(true);
		tag = tag->getParent();
	}
//=================================================================================================
// Nullable array fields
	|INT32_T ':' TYPE_BOOLEAN array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_BYTE array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_UBYTE array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_SHORT array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_USHORT array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_INT array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_UINT array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_LONG array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_ULONG array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_INT128 array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_UINT128 array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_FLOAT array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_DOUBLE array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_VARINT array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_UVARINT array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}
	|INT32_T ':' TYPE_STRING array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType($3);
	}	
	|INT32_T ':' TYPE_STRING '<' STRING_ENCODE '>' array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $8[0], $8[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $7; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryString* element = (DictionaryString*)arr_field->setElementType($3);	
		element->setDefaultEncode($5);
	}
	|array_of_struct_begin fields '}' '=' NULL_VALUE ';'
	{
		for (uint32_t i = 0; i < $1; i++)
		{
			tag = tag->getParent();
		}
		tag->setNullable(true);
		tag = tag->getParent();
	}
	|INT32_T ':' TEXT_NAME array_dimension TEXT_NAME '=' NULL_VALUE ';'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $5[0], $5[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryTagLink* element = (DictionaryTagLink*)arr_field->setElementType(usds::USDS_TAG);
		element->setTag(input_text + $3[0], $3[1]);
	}
//=================================================================================================
// Fields with default value
	|INT32_T ':' TYPE_BOOLEAN TEXT_NAME '=' BOOLEAN_VALUE ';'
	{
		usds::DictionaryBoolean* dict_field = (usds::DictionaryBoolean*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_BYTE TEXT_NAME '=' INT8_T ';'
	{
		usds::DictionaryByte* dict_field = (usds::DictionaryByte*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_UBYTE TEXT_NAME '=' UINT8_T ';'
	{
		usds::DictionaryUByte* dict_field = (usds::DictionaryUByte*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_SHORT TEXT_NAME '=' INT16_T ';'
	{
		usds::DictionaryShort* dict_field = (usds::DictionaryShort*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_USHORT TEXT_NAME '=' UINT16_T ';'
	{
		usds::DictionaryUShort* dict_field = (usds::DictionaryUShort*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_INT TEXT_NAME '=' INT32_T ';'
	{
		usds::DictionaryInt* dict_field = (usds::DictionaryInt*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_UINT TEXT_NAME '=' UINT32_T ';'
	{
		usds::DictionaryUInt* dict_field = (usds::DictionaryUInt*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_LONG TEXT_NAME '=' INT64_T ';'
	{
		usds::DictionaryLong* dict_field = (usds::DictionaryLong*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_ULONG TEXT_NAME '=' UINT64_T ';'
	{
		usds::DictionaryULong* dict_field = (usds::DictionaryULong*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_FLOAT TEXT_NAME '=' FLOAT_VALUE ';'
	{
		usds::DictionaryFloat* dict_field = (usds::DictionaryFloat*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue((float)$6);
	}
	|INT32_T ':' TYPE_DOUBLE TEXT_NAME '=' FLOAT_VALUE ';'
	{
		usds::DictionaryDouble* dict_field = (usds::DictionaryDouble*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_VARINT TEXT_NAME '=' INT64_T ';'
	{
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_UVARINT TEXT_NAME '=' UINT64_T ';'
	{
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValue($6);
	}
	|INT32_T ':' TYPE_STRING TEXT_NAME '=' TEXT_STRING ';'
	{
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]));
		dict_field->setDefaultValueFromUTF8(input_text + $6[0], $6[1]);
	}	
	|INT32_T ':' TYPE_STRING '<' STRING_ENCODE '>' TEXT_NAME '=' TEXT_STRING ';'
	{
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField($3, $1, input_text + $7[0], $7[1]));
		dict_field->setDefaultEncode($5);
		dict_field->setDefaultValueFromUTF8(input_text + $9[0], $9[1]);
	}
	;
	
struct_begin:
	INT32_T ':' TEXT_NAME '{'
	{
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, $1, input_text + $3[0], $3[1]);
	}
	;
	
array_of_struct_begin:
	INT32_T ':' TEXT_NAME array_dimension '{'
	{
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, $1, input_text + $3[0], $3[1]);
		for (uint32_t i = 1; i < $4; i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_STRUCT);
		$$ = $4;
	}
	;
	
array_dimension:
	'[' ']'
	{
		$$ = 1;
	}
	|array_dimension '[' ']'
	{
		$$ = $$ + 1;
	}
	;
	

//=================================================================================================
// Digits 8 bit

INT8_T:
	POSITIVE_NUMBER
	{
		$$ = (int8_t)$1;
	}
	|NEGATIVE_NUMBER
	{
		$$ = (int8_t)$1;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = (int8_t)$1 * (int8_t)10 + (int8_t)$2;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = (int8_t)$1 * (int8_t)10 - (int8_t)$2;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 > (int8_t)1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to int8_t: too big value";

		$$ = (int8_t)$2  * (int8_t)10 + (int8_t)$3;
		
		if ($1 == (int8_t)1 && $$ >= (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to int8_t: too big value";
		
		$$ = (int8_t)$1 * (int8_t)100 + $$;
		
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 < (int8_t)-1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to int8_t: too big value";

		$$ = (int8_t)$2  * (int8_t)10 + (int8_t)$3;
		
		if ($1 == (int8_t)-1 && $$ > (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to int8_t: too big value";
		
		$$ = (int8_t)$1 * (int8_t)100 - $$;
		
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << "... to int8_t: too big value";
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << "... to int8_t: too big value";
	}
	;

UINT8_T:
	POSITIVE_NUMBER
	{
		$$ = (uint8_t)$1;
	}
	|NEGATIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << " to uint8_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = (uint8_t)$1 * (uint8_t)10 + (uint8_t)$2;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << " to uint8_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to uint8_t: too big value";

		$$ = (uint8_t)$2  * (uint8_t)10 + (uint8_t)$3;
		
		if ($1 == (int8_t)2 && $$ >= (uint8_t)56)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to uint8_t: too big value";
		
		$$ = (uint8_t)$1 * (uint8_t)100 + $$;
		
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to uint8_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << "... to uint8_t: too big value";
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << "... to uint8_t: too big value";
	}
	;

//=================================================================================================
// Digits 16 bit

INT16_T:
	POSITIVE_NUMBER
	{
		$$ = (int16_t)$1;
	}
	|NEGATIVE_NUMBER
	{
		$$ = (int16_t)$1;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int16_t)$1 * (int16_t)10 + 
		(int16_t)$2;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int16_t)$1 * (int16_t)10 - 
		(int16_t)$2;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int16_t)$1 * (int16_t)100 + 
		(int16_t)$2 * (int16_t)10 + 
		(int16_t)$3;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int16_t)$1 * (int16_t)100 - 
		(int16_t)$2 * (int16_t)10 - 
		(int16_t)$3;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int16_t)$1 * (int16_t)1000 + 
		(int16_t)$2 * (int16_t)100 + 
		(int16_t)$3 * (int16_t)10 + 
		(int16_t)$4;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int16_t)$1 * (int16_t)1000 - 
		(int16_t)$2 * (int16_t)100 - 
		(int16_t)$3 * (int16_t)10 - 
		(int16_t)$4;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 > (int8_t)3)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to int16_t: too big value";
		
		$$ = 
		(int16_t)$2 * (int16_t)1000 + 
		(int16_t)$3 * (int16_t)100 + 
		(int16_t)$4 * (int16_t)10 + 
		(int16_t)$5;

		if ($1 == (int8_t)3 && $$ >= (int16_t)2768)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to int16_t: too big value";
			
		$$ = $$ + (int16_t)$1 * (int16_t)10000;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 < (int8_t)-3)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to int16_t: too big value";
		
		$$ = 
		(int16_t)$2 * (int16_t)1000 + 
		(int16_t)$3 * (int16_t)100 + 
		(int16_t)$4 * (int16_t)10 + 
		(int16_t)$5;

		if ($1 == (int8_t)-3 && $$ > (int16_t)2768)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to int16_t: too big value";
			
		$$ = (int16_t)$1 * (int16_t)10000 - $$;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << "... to int16_t: too big value";
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << "... to int16_t: too big value";
	}
	;

UINT16_T:
	POSITIVE_NUMBER
	{
		$$ = (uint16_t)$1;
	}
	|NEGATIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << " to uint16_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint16_t)$1 * (uint16_t)10 + 
		(uint16_t)$2;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << " to uint16_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint16_t)$1 * (uint16_t)100 + 
		(uint16_t)$2 * (uint16_t)10 + 
		(uint16_t)$3;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to uint16_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint16_t)$1 * (uint16_t)1000 + 
		(uint16_t)$2 * (uint16_t)100 + 
		(uint16_t)$3 * (uint16_t)10 + 
		(uint16_t)$4;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << " to uint16_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 > (int8_t)6)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to uint16_t: too big value";
		
		$$ = 
		(uint16_t)$2 * (uint16_t)1000 + 
		(uint16_t)$3 * (uint16_t)100 + 
		(uint16_t)$4 * (uint16_t)10 + 
		(uint16_t)$5;

		if ($1 == (int8_t)6 && $$ >= (uint16_t)5536)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to uint16_t: too big value";
			
		$$ = $$ + (uint16_t)$1 * (uint16_t)10000;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to uint16_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << "... to uint16_t: too big value";
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << "... to uint16_t: too big value";
	}
	;
	
//=================================================================================================
// Digits 32 bit

INT32_T:
	POSITIVE_NUMBER
	{
		$$ = (int32_t)$1;
	}
	|NEGATIVE_NUMBER
	{
		$$ = (int32_t)$1;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)10 + 
		(int32_t)$2;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)10 - 
		(int32_t)$2;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)100 + 
		(int32_t)$2 * (int32_t)10 + 
		(int32_t)$3;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)100 - 
		(int32_t)$2 * (int32_t)10 - 
		(int32_t)$3;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)1000 + 
		(int32_t)$2 * (int32_t)100 + 
		(int32_t)$3 * (int32_t)10 + 
		(int32_t)$4;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)1000 - 
		(int32_t)$2 * (int32_t)100 - 
		(int32_t)$3 * (int32_t)10 - 
		(int32_t)$4;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)10000 + 
		(int32_t)$2 * (int32_t)1000 + 
		(int32_t)$3 * (int32_t)100 + 
		(int32_t)$4 * (int32_t)10 + 
		(int32_t)$5;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)10000 - 
		(int32_t)$2 * (int32_t)1000 - 
		(int32_t)$3 * (int32_t)100 - 
		(int32_t)$4 * (int32_t)10 - 
		(int32_t)$5;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)100000 + 
		(int32_t)$2 * (int32_t)10000 + 
		(int32_t)$3 * (int32_t)1000 + 
		(int32_t)$4 * (int32_t)100 + 
		(int32_t)$5 * (int32_t)10 + 
		(int32_t)$6;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)100000 - 
		(int32_t)$2 * (int32_t)10000 - 
		(int32_t)$3 * (int32_t)1000 - 
		(int32_t)$4 * (int32_t)100 - 
		(int32_t)$5 * (int32_t)10 - 
		(int32_t)$6;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)1000000 + 
		(int32_t)$2 * (int32_t)100000 + 
		(int32_t)$3 * (int32_t)10000 + 
		(int32_t)$4 * (int32_t)1000 + 
		(int32_t)$5 * (int32_t)100 + 
		(int32_t)$6 * (int32_t)10 + 
		(int32_t)$7;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)1000000 - 
		(int32_t)$2 * (int32_t)100000 - 
		(int32_t)$3 * (int32_t)10000 - 
		(int32_t)$4 * (int32_t)1000 - 
		(int32_t)$5 * (int32_t)100 - 
		(int32_t)$6 * (int32_t)10 - 
		(int32_t)$7;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)10000000 + 
		(int32_t)$2 * (int32_t)1000000 + 
		(int32_t)$3 * (int32_t)100000 + 
		(int32_t)$4 * (int32_t)10000 + 
		(int32_t)$5 * (int32_t)1000 + 
		(int32_t)$6 * (int32_t)100 + 
		(int32_t)$7 * (int32_t)10 + 
		(int32_t)$8;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)10000000 - 
		(int32_t)$2 * (int32_t)1000000 - 
		(int32_t)$3 * (int32_t)100000 - 
		(int32_t)$4 * (int32_t)10000 - 
		(int32_t)$5 * (int32_t)1000 - 
		(int32_t)$6 * (int32_t)100 - 
		(int32_t)$7 * (int32_t)10 - 
		(int32_t)$8;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)100000000 + 
		(int32_t)$2 * (int32_t)10000000 + 
		(int32_t)$3 * (int32_t)1000000 + 
		(int32_t)$4 * (int32_t)100000 + 
		(int32_t)$5 * (int32_t)10000 + 
		(int32_t)$6 * (int32_t)1000 + 
		(int32_t)$7 * (int32_t)100 + 
		(int32_t)$8 * (int32_t)10 + 
		(int32_t)$9;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)100000000 - 
		(int32_t)$2 * (int32_t)10000000 - 
		(int32_t)$3 * (int32_t)1000000 - 
		(int32_t)$4 * (int32_t)100000 - 
		(int32_t)$5 * (int32_t)10000 - 
		(int32_t)$6 * (int32_t)1000 - 
		(int32_t)$7 * (int32_t)100 - 
		(int32_t)$8 * (int32_t)10 - 
		(int32_t)$9;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to int32_t: too big value";
		
		$$ = 
		(int32_t)$2 * (int32_t)100000000 + 
		(int32_t)$3 * (int32_t)10000000 + 
		(int32_t)$4 * (int32_t)1000000 + 
		(int32_t)$5 * (int32_t)100000 + 
		(int32_t)$6 * (int32_t)10000 + 
		(int32_t)$7 * (int32_t)1000 + 
		(int32_t)$8 * (int32_t)100 + 
		(int32_t)$9 * (int32_t)10 + 
		(int32_t)$10;

		if ($1 == (int8_t)2 && $$ >= (int32_t)147483648)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to int32_t: too big value";
			
		$$ = $$ + (int32_t)$1 * (int32_t)1000000000;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 < (int8_t)-2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to int32_t: too big value";
		
		$$ = 
		(int32_t)$2 * (int32_t)100000000 + 
		(int32_t)$3 * (int32_t)10000000 + 
		(int32_t)$4 * (int32_t)1000000 + 
		(int32_t)$5 * (int32_t)100000 + 
		(int32_t)$6 * (int32_t)10000 + 
		(int32_t)$7 * (int32_t)1000 + 
		(int32_t)$8 * (int32_t)100 + 
		(int32_t)$9 * (int32_t)10 + 
		(int32_t)$10;

		if ($1 == (int8_t)-2 && $$ > (int32_t)147483648)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to int32_t: too big value";
			
		$$ = (int32_t)$1 * (int32_t)1000000000 - $$;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << "... to int32_t: too big value";
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << "... to int32_t: too big value";
	}
	;
		
UINT32_T:
	POSITIVE_NUMBER
	{
		$$ = (uint32_t)$1;
	}
	|NEGATIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << " to uint32_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)10 + 
		(uint32_t)$2;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << " to uint32_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)100 + 
		(uint32_t)$2 * (uint32_t)10 + 
		(uint32_t)$3;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to uint32_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)1000 + 
		(uint32_t)$2 * (uint32_t)100 + 
		(uint32_t)$3 * (uint32_t)10 + 
		(uint32_t)$4;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << " to uint32_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)10000 + 
		(uint32_t)$2 * (uint32_t)1000 + 
		(uint32_t)$3 * (uint32_t)100 + 
		(uint32_t)$4 * (uint32_t)10 + 
		(uint32_t)$5;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to uint32_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)100000 + 
		(uint32_t)$2 * (uint32_t)10000 + 
		(uint32_t)$3 * (uint32_t)1000 + 
		(uint32_t)$4 * (uint32_t)100 + 
		(uint32_t)$5 * (uint32_t)10 + 
		(uint32_t)$6;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << " to uint32_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)1000000 + 
		(uint32_t)$2 * (uint32_t)100000 + 
		(uint32_t)$3 * (uint32_t)10000 + 
		(uint32_t)$4 * (uint32_t)1000 + 
		(uint32_t)$5 * (uint32_t)100 + 
		(uint32_t)$6 * (uint32_t)10 + 
		(uint32_t)$7;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << " to uint32_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)10000000 + 
		(uint32_t)$2 * (uint32_t)1000000 + 
		(uint32_t)$3 * (uint32_t)100000 + 
		(uint32_t)$4 * (uint32_t)10000 + 
		(uint32_t)$5 * (uint32_t)1000 + 
		(uint32_t)$6 * (uint32_t)100 + 
		(uint32_t)$7 * (uint32_t)10 + 
		(uint32_t)$8;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << " to uint32_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)100000000 + 
		(uint32_t)$2 * (uint32_t)10000000 + 
		(uint32_t)$3 * (uint32_t)1000000 + 
		(uint32_t)$4 * (uint32_t)100000 + 
		(uint32_t)$5 * (uint32_t)10000 + 
		(uint32_t)$6 * (uint32_t)1000 + 
		(uint32_t)$7 * (uint32_t)100 + 
		(uint32_t)$8 * (uint32_t)10 + 
		(uint32_t)$9;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << " to uint32_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 > (int8_t)4)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to uint32_t: too big value";
		
		$$ = 
		(uint32_t)$2 * (uint32_t)100000000 + 
		(uint32_t)$3 * (uint32_t)10000000 + 
		(uint32_t)$4 * (uint32_t)1000000 + 
		(uint32_t)$5 * (uint32_t)100000 + 
		(uint32_t)$6 * (uint32_t)10000 + 
		(uint32_t)$7 * (uint32_t)1000 + 
		(uint32_t)$8 * (uint32_t)100 + 
		(uint32_t)$9 * (uint32_t)10 + 
		(uint32_t)$10;

		if ($1 == (int8_t)4 && $$ >= (uint32_t)294967296)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to uint32_t: too big value";
			
		$$ = $$ + (uint32_t)$1 * (uint32_t)1000000000;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to uint32_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << "... to uint32_t: too big value";
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << "... to uint32_t: negative value";
	}
	;

//=================================================================================================
// Digits 64 bit

INT64_T:
	POSITIVE_NUMBER
	{
		$$ = (int64_t)$1;
	}
	|NEGATIVE_NUMBER
	{
		$$ = (int64_t)$1;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10 + 
		(int64_t)$2;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10 - 
		(int64_t)$2;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100 + 
		(int64_t)$2 * (int64_t)10 + 
		(int64_t)$3;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100 - 
		(int64_t)$2 * (int64_t)10 - 
		(int64_t)$3;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)1000 + 
		(int64_t)$2 * (int64_t)100 + 
		(int64_t)$3 * (int64_t)10 + 
		(int64_t)$4;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)1000 - 
		(int64_t)$2 * (int64_t)100 - 
		(int64_t)$3 * (int64_t)10 - 
		(int64_t)$4;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10000 + 
		(int64_t)$2 * (int64_t)1000 + 
		(int64_t)$3 * (int64_t)100 + 
		(int64_t)$4 * (int64_t)10 + 
		(int64_t)$5;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10000 - 
		(int64_t)$2 * (int64_t)1000 - 
		(int64_t)$3 * (int64_t)100 - 
		(int64_t)$4 * (int64_t)10 - 
		(int64_t)$5;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100000 + 
		(int64_t)$2 * (int64_t)10000 + 
		(int64_t)$3 * (int64_t)1000 + 
		(int64_t)$4 * (int64_t)100 + 
		(int64_t)$5 * (int64_t)10 + 
		(int64_t)$6;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100000 - 
		(int64_t)$2 * (int64_t)10000 - 
		(int64_t)$3 * (int64_t)1000 - 
		(int64_t)$4 * (int64_t)100 - 
		(int64_t)$5 * (int64_t)10 - 
		(int64_t)$6;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)1000000 + 
		(int64_t)$2 * (int64_t)100000 + 
		(int64_t)$3 * (int64_t)10000 + 
		(int64_t)$4 * (int64_t)1000 + 
		(int64_t)$5 * (int64_t)100 + 
		(int64_t)$6 * (int64_t)10 + 
		(int64_t)$7;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)1000000 - 
		(int64_t)$2 * (int64_t)100000 - 
		(int64_t)$3 * (int64_t)10000 - 
		(int64_t)$4 * (int64_t)1000 - 
		(int64_t)$5 * (int64_t)100 - 
		(int64_t)$6 * (int64_t)10 - 
		(int64_t)$7;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10000000 + 
		(int64_t)$2 * (int64_t)1000000 + 
		(int64_t)$3 * (int64_t)100000 + 
		(int64_t)$4 * (int64_t)10000 + 
		(int64_t)$5 * (int64_t)1000 + 
		(int64_t)$6 * (int64_t)100 + 
		(int64_t)$7 * (int64_t)10 + 
		(int64_t)$8;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10000000 - 
		(int64_t)$2 * (int64_t)1000000 - 
		(int64_t)$3 * (int64_t)100000 - 
		(int64_t)$4 * (int64_t)10000 - 
		(int64_t)$5 * (int64_t)1000 - 
		(int64_t)$6 * (int64_t)100 - 
		(int64_t)$7 * (int64_t)10 - 
		(int64_t)$8;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100000000 + 
		(int64_t)$2 * (int64_t)10000000 + 
		(int64_t)$3 * (int64_t)1000000 + 
		(int64_t)$4 * (int64_t)100000 + 
		(int64_t)$5 * (int64_t)10000 + 
		(int64_t)$6 * (int64_t)1000 + 
		(int64_t)$7 * (int64_t)100 + 
		(int64_t)$8 * (int64_t)10 + 
		(int64_t)$9;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100000000 - 
		(int64_t)$2 * (int64_t)10000000 - 
		(int64_t)$3 * (int64_t)1000000 - 
		(int64_t)$4 * (int64_t)100000 - 
		(int64_t)$5 * (int64_t)10000 - 
		(int64_t)$6 * (int64_t)1000 - 
		(int64_t)$7 * (int64_t)100 - 
		(int64_t)$8 * (int64_t)10 - 
		(int64_t)$9;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)1000000000 + 
		(int64_t)$2 * (int64_t)100000000 + 
		(int64_t)$3 * (int64_t)10000000 + 
		(int64_t)$4 * (int64_t)1000000 + 
		(int64_t)$5 * (int64_t)100000 + 
		(int64_t)$6 * (int64_t)10000 + 
		(int64_t)$7 * (int64_t)1000 + 
		(int64_t)$8 * (int64_t)100 + 
		(int64_t)$9 * (int64_t)10 + 
		(int64_t)$10;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)1000000000 - 
		(int64_t)$2 * (int64_t)100000000 - 
		(int64_t)$3 * (int64_t)10000000 - 
		(int64_t)$4 * (int64_t)1000000 - 
		(int64_t)$5 * (int64_t)100000 - 
		(int64_t)$6 * (int64_t)10000 - 
		(int64_t)$7 * (int64_t)1000 - 
		(int64_t)$8 * (int64_t)100 - 
		(int64_t)$9 * (int64_t)10 - 
		(int64_t)$10;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10000000000 + 
		(int64_t)$2 * (int64_t)1000000000 + 
		(int64_t)$3 * (int64_t)100000000 + 
		(int64_t)$4 * (int64_t)10000000 + 
		(int64_t)$5 * (int64_t)1000000 + 
		(int64_t)$6 * (int64_t)100000 + 
		(int64_t)$7 * (int64_t)10000 + 
		(int64_t)$8 * (int64_t)1000 + 
		(int64_t)$9 * (int64_t)100 + 
		(int64_t)$10 * (int64_t)10 + 
		(int64_t)$11;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10000000000 - 
		(int64_t)$2 * (int64_t)1000000000 - 
		(int64_t)$3 * (int64_t)100000000 - 
		(int64_t)$4 * (int64_t)10000000 - 
		(int64_t)$5 * (int64_t)1000000 - 
		(int64_t)$6 * (int64_t)100000 - 
		(int64_t)$7 * (int64_t)10000 - 
		(int64_t)$8 * (int64_t)1000 - 
		(int64_t)$9 * (int64_t)100 - 
		(int64_t)$10 * (int64_t)10 - 
		(int64_t)$11;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100000000000 + 
		(int64_t)$2 * (int64_t)10000000000 + 
		(int64_t)$3 * (int64_t)1000000000 + 
		(int64_t)$4 * (int64_t)100000000 + 
		(int64_t)$5 * (int64_t)10000000 + 
		(int64_t)$6 * (int64_t)1000000 + 
		(int64_t)$7 * (int64_t)100000 + 
		(int64_t)$8 * (int64_t)10000 + 
		(int64_t)$9 * (int64_t)1000 + 
		(int64_t)$10 * (int64_t)100 + 
		(int64_t)$11 * (int64_t)10 + 
		(int64_t)$12;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100000000000 - 
		(int64_t)$2 * (int64_t)10000000000 - 
		(int64_t)$3 * (int64_t)1000000000 - 
		(int64_t)$4 * (int64_t)100000000 - 
		(int64_t)$5 * (int64_t)10000000 - 
		(int64_t)$6 * (int64_t)1000000 - 
		(int64_t)$7 * (int64_t)100000 - 
		(int64_t)$8 * (int64_t)10000 - 
		(int64_t)$9 * (int64_t)1000 - 
		(int64_t)$10 * (int64_t)100 - 
		(int64_t)$11 * (int64_t)10 - 
		(int64_t)$12;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)1000000000000 + 
		(int64_t)$2 * (int64_t)100000000000 + 
		(int64_t)$3 * (int64_t)10000000000 + 
		(int64_t)$4 * (int64_t)1000000000 + 
		(int64_t)$5 * (int64_t)100000000 + 
		(int64_t)$6 * (int64_t)10000000 + 
		(int64_t)$7 * (int64_t)1000000 + 
		(int64_t)$8 * (int64_t)100000 + 
		(int64_t)$9 * (int64_t)10000 + 
		(int64_t)$10 * (int64_t)1000 + 
		(int64_t)$11 * (int64_t)100 + 
		(int64_t)$12 * (int64_t)10 + 
		(int64_t)$13;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)1000000000000 - 
		(int64_t)$2 * (int64_t)100000000000 - 
		(int64_t)$3 * (int64_t)10000000000 - 
		(int64_t)$4 * (int64_t)1000000000 - 
		(int64_t)$5 * (int64_t)100000000 - 
		(int64_t)$6 * (int64_t)10000000 - 
		(int64_t)$7 * (int64_t)1000000 - 
		(int64_t)$8 * (int64_t)100000 - 
		(int64_t)$9 * (int64_t)10000 - 
		(int64_t)$10 * (int64_t)1000 - 
		(int64_t)$11 * (int64_t)100 - 
		(int64_t)$12 * (int64_t)10 - 
		(int64_t)$13;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10000000000000 + 
		(int64_t)$2 * (int64_t)1000000000000 + 
		(int64_t)$3 * (int64_t)100000000000 + 
		(int64_t)$4 * (int64_t)10000000000 + 
		(int64_t)$5 * (int64_t)1000000000 + 
		(int64_t)$6 * (int64_t)100000000 + 
		(int64_t)$7 * (int64_t)10000000 + 
		(int64_t)$8 * (int64_t)1000000 + 
		(int64_t)$9 * (int64_t)100000 + 
		(int64_t)$10 * (int64_t)10000 + 
		(int64_t)$11 * (int64_t)1000 + 
		(int64_t)$12 * (int64_t)100 + 
		(int64_t)$13 * (int64_t)10 + 
		(int64_t)$14;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10000000000000 - 
		(int64_t)$2 * (int64_t)1000000000000 - 
		(int64_t)$3 * (int64_t)100000000000 - 
		(int64_t)$4 * (int64_t)10000000000 - 
		(int64_t)$5 * (int64_t)1000000000 - 
		(int64_t)$6 * (int64_t)100000000 - 
		(int64_t)$7 * (int64_t)10000000 - 
		(int64_t)$8 * (int64_t)1000000 - 
		(int64_t)$9 * (int64_t)100000 - 
		(int64_t)$10 * (int64_t)10000 - 
		(int64_t)$11 * (int64_t)1000 - 
		(int64_t)$12 * (int64_t)100 - 
		(int64_t)$13 * (int64_t)10 - 
		(int64_t)$14;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100000000000000 + 
		(int64_t)$2 * (int64_t)10000000000000 + 
		(int64_t)$3 * (int64_t)1000000000000 + 
		(int64_t)$4 * (int64_t)100000000000 + 
		(int64_t)$5 * (int64_t)10000000000 + 
		(int64_t)$6 * (int64_t)1000000000 + 
		(int64_t)$7 * (int64_t)100000000 + 
		(int64_t)$8 * (int64_t)10000000 + 
		(int64_t)$9 * (int64_t)1000000 + 
		(int64_t)$10 * (int64_t)100000 + 
		(int64_t)$11 * (int64_t)10000 + 
		(int64_t)$12 * (int64_t)1000 + 
		(int64_t)$13 * (int64_t)100 + 
		(int64_t)$14 * (int64_t)10 + 
		(int64_t)$15;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100000000000000 - 
		(int64_t)$2 * (int64_t)10000000000000 - 
		(int64_t)$3 * (int64_t)1000000000000 - 
		(int64_t)$4 * (int64_t)100000000000 - 
		(int64_t)$5 * (int64_t)10000000000 - 
		(int64_t)$6 * (int64_t)1000000000 - 
		(int64_t)$7 * (int64_t)100000000 - 
		(int64_t)$8 * (int64_t)10000000 - 
		(int64_t)$9 * (int64_t)1000000 - 
		(int64_t)$10 * (int64_t)100000 - 
		(int64_t)$11 * (int64_t)10000 - 
		(int64_t)$12 * (int64_t)1000 - 
		(int64_t)$13 * (int64_t)100 - 
		(int64_t)$14 * (int64_t)10 - 
		(int64_t)$15;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)1000000000000000 + 
		(int64_t)$2 * (int64_t)100000000000000 + 
		(int64_t)$3 * (int64_t)10000000000000 + 
		(int64_t)$4 * (int64_t)1000000000000 + 
		(int64_t)$5 * (int64_t)100000000000 + 
		(int64_t)$6 * (int64_t)10000000000 + 
		(int64_t)$7 * (int64_t)1000000000 + 
		(int64_t)$8 * (int64_t)100000000 + 
		(int64_t)$9 * (int64_t)10000000 + 
		(int64_t)$10 * (int64_t)1000000 + 
		(int64_t)$11 * (int64_t)100000 + 
		(int64_t)$12 * (int64_t)10000 + 
		(int64_t)$13 * (int64_t)1000 + 
		(int64_t)$14 * (int64_t)100 + 
		(int64_t)$15 * (int64_t)10 + 
		(int64_t)$16;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)1000000000000000 - 
		(int64_t)$2 * (int64_t)100000000000000 - 
		(int64_t)$3 * (int64_t)10000000000000 - 
		(int64_t)$4 * (int64_t)1000000000000 - 
		(int64_t)$5 * (int64_t)100000000000 - 
		(int64_t)$6 * (int64_t)10000000000 - 
		(int64_t)$7 * (int64_t)1000000000 - 
		(int64_t)$8 * (int64_t)100000000 - 
		(int64_t)$9 * (int64_t)10000000 - 
		(int64_t)$10 * (int64_t)1000000 - 
		(int64_t)$11 * (int64_t)100000 - 
		(int64_t)$12 * (int64_t)10000 - 
		(int64_t)$13 * (int64_t)1000 - 
		(int64_t)$14 * (int64_t)100 - 
		(int64_t)$15 * (int64_t)10 - 
		(int64_t)$16;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10000000000000000 + 
		(int64_t)$2 * (int64_t)1000000000000000 + 
		(int64_t)$3 * (int64_t)100000000000000 + 
		(int64_t)$4 * (int64_t)10000000000000 + 
		(int64_t)$5 * (int64_t)1000000000000 + 
		(int64_t)$6 * (int64_t)100000000000 + 
		(int64_t)$7 * (int64_t)10000000000 + 
		(int64_t)$8 * (int64_t)1000000000 + 
		(int64_t)$9 * (int64_t)100000000 + 
		(int64_t)$10 * (int64_t)10000000 + 
		(int64_t)$11 * (int64_t)1000000 + 
		(int64_t)$12 * (int64_t)100000 + 
		(int64_t)$13 * (int64_t)10000 + 
		(int64_t)$14 * (int64_t)1000 + 
		(int64_t)$15 * (int64_t)100 + 
		(int64_t)$16 * (int64_t)10 + 
		(int64_t)$17;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)10000000000000000 - 
		(int64_t)$2 * (int64_t)1000000000000000 - 
		(int64_t)$3 * (int64_t)100000000000000 - 
		(int64_t)$4 * (int64_t)10000000000000 - 
		(int64_t)$5 * (int64_t)1000000000000 - 
		(int64_t)$6 * (int64_t)100000000000 - 
		(int64_t)$7 * (int64_t)10000000000 - 
		(int64_t)$8 * (int64_t)1000000000 - 
		(int64_t)$9 * (int64_t)100000000 - 
		(int64_t)$10 * (int64_t)10000000 - 
		(int64_t)$11 * (int64_t)1000000 - 
		(int64_t)$12 * (int64_t)100000 - 
		(int64_t)$13 * (int64_t)10000 - 
		(int64_t)$14 * (int64_t)1000 - 
		(int64_t)$15 * (int64_t)100 - 
		(int64_t)$16 * (int64_t)10 - 
		(int64_t)$17;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100000000000000000 + 
		(int64_t)$2 * (int64_t)10000000000000000 + 
		(int64_t)$3 * (int64_t)1000000000000000 + 
		(int64_t)$4 * (int64_t)100000000000000 + 
		(int64_t)$5 * (int64_t)10000000000000 + 
		(int64_t)$6 * (int64_t)1000000000000 + 
		(int64_t)$7 * (int64_t)100000000000 + 
		(int64_t)$8 * (int64_t)10000000000 + 
		(int64_t)$9 * (int64_t)1000000000 + 
		(int64_t)$10 * (int64_t)100000000 + 
		(int64_t)$11 * (int64_t)10000000 + 
		(int64_t)$12 * (int64_t)1000000 + 
		(int64_t)$13 * (int64_t)100000 + 
		(int64_t)$14 * (int64_t)10000 + 
		(int64_t)$15 * (int64_t)1000 + 
		(int64_t)$16 * (int64_t)100 + 
		(int64_t)$17 * (int64_t)10 + 
		(int64_t)$18;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$1 * (int64_t)100000000000000000 - 
		(int64_t)$2 * (int64_t)10000000000000000 - 
		(int64_t)$3 * (int64_t)1000000000000000 - 
		(int64_t)$4 * (int64_t)100000000000000 - 
		(int64_t)$5 * (int64_t)10000000000000 - 
		(int64_t)$6 * (int64_t)1000000000000 - 
		(int64_t)$7 * (int64_t)100000000000 - 
		(int64_t)$8 * (int64_t)10000000000 - 
		(int64_t)$9 * (int64_t)1000000000 - 
		(int64_t)$10 * (int64_t)100000000 - 
		(int64_t)$11 * (int64_t)10000000 - 
		(int64_t)$12 * (int64_t)1000000 - 
		(int64_t)$13 * (int64_t)100000 - 
		(int64_t)$14 * (int64_t)10000 - 
		(int64_t)$15 * (int64_t)1000 - 
		(int64_t)$16 * (int64_t)100 - 
		(int64_t)$17 * (int64_t)10 - 
		(int64_t)$18;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$2 * (int64_t)100000000000000000 + 
		(int64_t)$3 * (int64_t)10000000000000000 + 
		(int64_t)$4 * (int64_t)1000000000000000 + 
		(int64_t)$5 * (int64_t)100000000000000 + 
		(int64_t)$6 * (int64_t)10000000000000 + 
		(int64_t)$7 * (int64_t)1000000000000 + 
		(int64_t)$8 * (int64_t)100000000000 + 
		(int64_t)$9 * (int64_t)10000000000 + 
		(int64_t)$10 * (int64_t)1000000000 + 
		(int64_t)$11 * (int64_t)100000000 + 
		(int64_t)$12 * (int64_t)10000000 + 
		(int64_t)$13 * (int64_t)1000000 + 
		(int64_t)$14 * (int64_t)100000 + 
		(int64_t)$15 * (int64_t)10000 + 
		(int64_t)$16 * (int64_t)1000 + 
		(int64_t)$17 * (int64_t)100 + 
		(int64_t)$18 * (int64_t)10 + 
		(int64_t)$19;

		if ($1 == (int8_t)9 && $$ >= (int64_t)223372036854775808)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				$1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << " to int64_t: too big value";
			
		$$ = $$ + (int64_t)$1 * (int64_t)1000000000000000000;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int64_t)$2 * (int64_t)100000000000000000 + 
		(int64_t)$3 * (int64_t)10000000000000000 + 
		(int64_t)$4 * (int64_t)1000000000000000 + 
		(int64_t)$5 * (int64_t)100000000000000 + 
		(int64_t)$6 * (int64_t)10000000000000 + 
		(int64_t)$7 * (int64_t)1000000000000 + 
		(int64_t)$8 * (int64_t)100000000000 + 
		(int64_t)$9 * (int64_t)10000000000 + 
		(int64_t)$10 * (int64_t)1000000000 + 
		(int64_t)$11 * (int64_t)100000000 + 
		(int64_t)$12 * (int64_t)10000000 + 
		(int64_t)$13 * (int64_t)1000000 + 
		(int64_t)$14 * (int64_t)100000 + 
		(int64_t)$15 * (int64_t)10000 + 
		(int64_t)$16 * (int64_t)1000 + 
		(int64_t)$17 * (int64_t)100 + 
		(int64_t)$18 * (int64_t)10 + 
		(int64_t)$19;

		if ($1 == (int8_t)-9 && $$ > (int64_t)223372036854775808)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				$1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << " to int64_t: too big value";
			
		$$ = (int64_t)$1 * (int64_t)1000000000000000000 - $$;
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				$1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << "... to int64_t: too big value";
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				$1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << "... to int64_t: too big value";
	}
	;
	
UINT64_T:
	POSITIVE_NUMBER
	{
		$$ = (uint64_t)$1;
	}
	|NEGATIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10 + 
		(uint64_t)$2;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100 + 
		(uint64_t)$2 * (uint64_t)10 + 
		(uint64_t)$3;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000 + 
		(uint64_t)$2 * (uint64_t)100 + 
		(uint64_t)$3 * (uint64_t)10 + 
		(uint64_t)$4;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10000 + 
		(uint64_t)$2 * (uint64_t)1000 + 
		(uint64_t)$3 * (uint64_t)100 + 
		(uint64_t)$4 * (uint64_t)10 + 
		(uint64_t)$5;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100000 + 
		(uint64_t)$2 * (uint64_t)10000 + 
		(uint64_t)$3 * (uint64_t)1000 + 
		(uint64_t)$4 * (uint64_t)100 + 
		(uint64_t)$5 * (uint64_t)10 + 
		(uint64_t)$6;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000000 + 
		(uint64_t)$2 * (uint64_t)100000 + 
		(uint64_t)$3 * (uint64_t)10000 + 
		(uint64_t)$4 * (uint64_t)1000 + 
		(uint64_t)$5 * (uint64_t)100 + 
		(uint64_t)$6 * (uint64_t)10 + 
		(uint64_t)$7;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10000000 + 
		(uint64_t)$2 * (uint64_t)1000000 + 
		(uint64_t)$3 * (uint64_t)100000 + 
		(uint64_t)$4 * (uint64_t)10000 + 
		(uint64_t)$5 * (uint64_t)1000 + 
		(uint64_t)$6 * (uint64_t)100 + 
		(uint64_t)$7 * (uint64_t)10 + 
		(uint64_t)$8;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100000000 + 
		(uint64_t)$2 * (uint64_t)10000000 + 
		(uint64_t)$3 * (uint64_t)1000000 + 
		(uint64_t)$4 * (uint64_t)100000 + 
		(uint64_t)$5 * (uint64_t)10000 + 
		(uint64_t)$6 * (uint64_t)1000 + 
		(uint64_t)$7 * (uint64_t)100 + 
		(uint64_t)$8 * (uint64_t)10 + 
		(uint64_t)$9;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000000000 + 
		(uint64_t)$2 * (uint64_t)100000000 + 
		(uint64_t)$3 * (uint64_t)10000000 + 
		(uint64_t)$4 * (uint64_t)1000000 + 
		(uint64_t)$5 * (uint64_t)100000 + 
		(uint64_t)$6 * (uint64_t)10000 + 
		(uint64_t)$7 * (uint64_t)1000 + 
		(uint64_t)$8 * (uint64_t)100 + 
		(uint64_t)$9 * (uint64_t)10 + 
		(uint64_t)$10;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10000000000 + 
		(uint64_t)$2 * (uint64_t)1000000000 + 
		(uint64_t)$3 * (uint64_t)100000000 + 
		(uint64_t)$4 * (uint64_t)10000000 + 
		(uint64_t)$5 * (uint64_t)1000000 + 
		(uint64_t)$6 * (uint64_t)100000 + 
		(uint64_t)$7 * (uint64_t)10000 + 
		(uint64_t)$8 * (uint64_t)1000 + 
		(uint64_t)$9 * (uint64_t)100 + 
		(uint64_t)$10 * (uint64_t)10 + 
		(uint64_t)$11;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100000000000 + 
		(uint64_t)$2 * (uint64_t)10000000000 + 
		(uint64_t)$3 * (uint64_t)1000000000 + 
		(uint64_t)$4 * (uint64_t)100000000 + 
		(uint64_t)$5 * (uint64_t)10000000 + 
		(uint64_t)$6 * (uint64_t)1000000 + 
		(uint64_t)$7 * (uint64_t)100000 + 
		(uint64_t)$8 * (uint64_t)10000 + 
		(uint64_t)$9 * (uint64_t)1000 + 
		(uint64_t)$10 * (uint64_t)100 + 
		(uint64_t)$11 * (uint64_t)10 + 
		(uint64_t)$12;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000000000000 + 
		(uint64_t)$2 * (uint64_t)100000000000 + 
		(uint64_t)$3 * (uint64_t)10000000000 + 
		(uint64_t)$4 * (uint64_t)1000000000 + 
		(uint64_t)$5 * (uint64_t)100000000 + 
		(uint64_t)$6 * (uint64_t)10000000 + 
		(uint64_t)$7 * (uint64_t)1000000 + 
		(uint64_t)$8 * (uint64_t)100000 + 
		(uint64_t)$9 * (uint64_t)10000 + 
		(uint64_t)$10 * (uint64_t)1000 + 
		(uint64_t)$11 * (uint64_t)100 + 
		(uint64_t)$12 * (uint64_t)10 + 
		(uint64_t)$13;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10000000000000 + 
		(uint64_t)$2 * (uint64_t)1000000000000 + 
		(uint64_t)$3 * (uint64_t)100000000000 + 
		(uint64_t)$4 * (uint64_t)10000000000 + 
		(uint64_t)$5 * (uint64_t)1000000000 + 
		(uint64_t)$6 * (uint64_t)100000000 + 
		(uint64_t)$7 * (uint64_t)10000000 + 
		(uint64_t)$8 * (uint64_t)1000000 + 
		(uint64_t)$9 * (uint64_t)100000 + 
		(uint64_t)$10 * (uint64_t)10000 + 
		(uint64_t)$11 * (uint64_t)1000 + 
		(uint64_t)$12 * (uint64_t)100 + 
		(uint64_t)$13 * (uint64_t)10 + 
		(uint64_t)$14;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100000000000000 + 
		(uint64_t)$2 * (uint64_t)10000000000000 + 
		(uint64_t)$3 * (uint64_t)1000000000000 + 
		(uint64_t)$4 * (uint64_t)100000000000 + 
		(uint64_t)$5 * (uint64_t)10000000000 + 
		(uint64_t)$6 * (uint64_t)1000000000 + 
		(uint64_t)$7 * (uint64_t)100000000 + 
		(uint64_t)$8 * (uint64_t)10000000 + 
		(uint64_t)$9 * (uint64_t)1000000 + 
		(uint64_t)$10 * (uint64_t)100000 + 
		(uint64_t)$11 * (uint64_t)10000 + 
		(uint64_t)$12 * (uint64_t)1000 + 
		(uint64_t)$13 * (uint64_t)100 + 
		(uint64_t)$14 * (uint64_t)10 + 
		(uint64_t)$15;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000000000000000 + 
		(uint64_t)$2 * (uint64_t)100000000000000 + 
		(uint64_t)$3 * (uint64_t)10000000000000 + 
		(uint64_t)$4 * (uint64_t)1000000000000 + 
		(uint64_t)$5 * (uint64_t)100000000000 + 
		(uint64_t)$6 * (uint64_t)10000000000 + 
		(uint64_t)$7 * (uint64_t)1000000000 + 
		(uint64_t)$8 * (uint64_t)100000000 + 
		(uint64_t)$9 * (uint64_t)10000000 + 
		(uint64_t)$10 * (uint64_t)1000000 + 
		(uint64_t)$11 * (uint64_t)100000 + 
		(uint64_t)$12 * (uint64_t)10000 + 
		(uint64_t)$13 * (uint64_t)1000 + 
		(uint64_t)$14 * (uint64_t)100 + 
		(uint64_t)$15 * (uint64_t)10 + 
		(uint64_t)$16;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10000000000000000 + 
		(uint64_t)$2 * (uint64_t)1000000000000000 + 
		(uint64_t)$3 * (uint64_t)100000000000000 + 
		(uint64_t)$4 * (uint64_t)10000000000000 + 
		(uint64_t)$5 * (uint64_t)1000000000000 + 
		(uint64_t)$6 * (uint64_t)100000000000 + 
		(uint64_t)$7 * (uint64_t)10000000000 + 
		(uint64_t)$8 * (uint64_t)1000000000 + 
		(uint64_t)$9 * (uint64_t)100000000 + 
		(uint64_t)$10 * (uint64_t)10000000 + 
		(uint64_t)$11 * (uint64_t)1000000 + 
		(uint64_t)$12 * (uint64_t)100000 + 
		(uint64_t)$13 * (uint64_t)10000 + 
		(uint64_t)$14 * (uint64_t)1000 + 
		(uint64_t)$15 * (uint64_t)100 + 
		(uint64_t)$16 * (uint64_t)10 + 
		(uint64_t)$17;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << $17 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100000000000000000 + 
		(uint64_t)$2 * (uint64_t)10000000000000000 + 
		(uint64_t)$3 * (uint64_t)1000000000000000 + 
		(uint64_t)$4 * (uint64_t)100000000000000 + 
		(uint64_t)$5 * (uint64_t)10000000000000 + 
		(uint64_t)$6 * (uint64_t)1000000000000 + 
		(uint64_t)$7 * (uint64_t)100000000000 + 
		(uint64_t)$8 * (uint64_t)10000000000 + 
		(uint64_t)$9 * (uint64_t)1000000000 + 
		(uint64_t)$10 * (uint64_t)100000000 + 
		(uint64_t)$11 * (uint64_t)10000000 + 
		(uint64_t)$12 * (uint64_t)1000000 + 
		(uint64_t)$13 * (uint64_t)100000 + 
		(uint64_t)$14 * (uint64_t)10000 + 
		(uint64_t)$15 * (uint64_t)1000 + 
		(uint64_t)$16 * (uint64_t)100 + 
		(uint64_t)$17 * (uint64_t)10 + 
		(uint64_t)$18;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000000000000000000 + 
		(uint64_t)$2 * (uint64_t)100000000000000000 + 
		(uint64_t)$3 * (uint64_t)10000000000000000 + 
		(uint64_t)$4 * (uint64_t)1000000000000000 + 
		(uint64_t)$5 * (uint64_t)100000000000000 + 
		(uint64_t)$6 * (uint64_t)10000000000000 + 
		(uint64_t)$7 * (uint64_t)1000000000000 + 
		(uint64_t)$8 * (uint64_t)100000000000 + 
		(uint64_t)$9 * (uint64_t)10000000000 + 
		(uint64_t)$10 * (uint64_t)1000000000 + 
		(uint64_t)$11 * (uint64_t)100000000 + 
		(uint64_t)$12 * (uint64_t)10000000 + 
		(uint64_t)$13 * (uint64_t)1000000 + 
		(uint64_t)$14 * (uint64_t)100000 + 
		(uint64_t)$15 * (uint64_t)10000 + 
		(uint64_t)$16 * (uint64_t)1000 + 
		(uint64_t)$17 * (uint64_t)100 + 
		(uint64_t)$18 * (uint64_t)10 + 
		(uint64_t)$19;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 > (int8_t)1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				$1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << $20 << " to uint64_t: too big value";

		$$ = 
		(uint64_t)$2 * (uint64_t)1000000000000000000 + 
		(uint64_t)$3 * (uint64_t)100000000000000000 + 
		(uint64_t)$4 * (uint64_t)10000000000000000 + 
		(uint64_t)$5 * (uint64_t)1000000000000000 + 
		(uint64_t)$6 * (uint64_t)100000000000000 + 
		(uint64_t)$7 * (uint64_t)10000000000000 + 
		(uint64_t)$8 * (uint64_t)1000000000000 + 
		(uint64_t)$9 * (uint64_t)100000000000 + 
		(uint64_t)$10 * (uint64_t)10000000000 + 
		(uint64_t)$11 * (uint64_t)1000000000 + 
		(uint64_t)$12 * (uint64_t)100000000 + 
		(uint64_t)$13 * (uint64_t)10000000 + 
		(uint64_t)$14 * (uint64_t)1000000 + 
		(uint64_t)$15 * (uint64_t)100000 + 
		(uint64_t)$16 * (uint64_t)10000 + 
		(uint64_t)$17 * (uint64_t)1000 + 
		(uint64_t)$18 * (uint64_t)100 + 
		(uint64_t)$19 * (uint64_t)10 + 
		(uint64_t)$20;

		if ($1 == (int8_t)1 && $$ >= (uint64_t)8446744073709551616)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				$1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << $20 << " to uint64_t: too big value";
			
		$$ = $$ + (uint64_t)$1 * (uint64_t)10000000000000000000;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << $20 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				$1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << $20 << "... to uint64_t: too big value";
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << $20 << "... to uint64_t: negative value";
	}
	;

digits: POSITIVE_NUMBER |digits POSITIVE_NUMBER
	
	
//=================================================================================================
// Float types

FLOAT_VALUE:
	positive_major_float_digits
	{
		$$ = $1;
	}
	|negative_major_float_digits
	{
		$$ = $1;
	}
	|positive_major_float_digits '.' minor_float_digits
	{
		$$ = $1 + $3.value/$3.digits;
	}
	|negative_major_float_digits '.' minor_float_digits
	{
		$$ = $1 - $3.value/$3.digits;
	}
	|'-' '.' minor_float_digits
	{
		$$ = - $3.value/$3.digits;	
	}
	|'.' minor_float_digits
	{
		$$ = $2.value/$2.digits;
	}
	|positive_major_float_digits '.' minor_float_digits float_exponent
	{
		$$ = ($1 + $3.value/$3.digits) * pow(10.0, $4);
	}
	|negative_major_float_digits '.' minor_float_digits float_exponent
	{
		$$ = ($1 - $3.value/$3.digits) * pow(10.0, $4);
	}
	|'-' '.' minor_float_digits float_exponent
	{
		$$ = (- $3.value/$3.digits) * pow(10.0, $4);	
	}
	|'.' minor_float_digits float_exponent
	{
		$$ = ($2.value/$2.digits) * pow(10.0, $3);
	}
	;

positive_major_float_digits: 
	POSITIVE_NUMBER
	{
		$$ = (double)$1;
	}
	|positive_major_float_digits POSITIVE_NUMBER
	{
		$$ = $$ * 10.0 + (double)$2;
	}
	;
	
negative_major_float_digits: 
	NEGATIVE_NUMBER
	{
		$$ = (double)$1;
	}
	|negative_major_float_digits POSITIVE_NUMBER
	{
		$$ = $$ * 10.0 - (double)$2;
	}
	;
	
minor_float_digits: 
	POSITIVE_NUMBER
	{
		$$.value = (double)$1;
		$$.digits = 10.0;
	}
	|minor_float_digits POSITIVE_NUMBER
	{
		$$.value = $$.value * 10.0 + (double)$2;
		$$.digits = $$.digits * 10.0;
	}
	;

float_exponent: 
	POSITIVE_EXPONENT_NUMBER
	{
		$$ = (double)$1;
	}
	|NEGATIVE_EXPONENT_NUMBER
	{
		$$ = (double)$1;
	}
	|POSITIVE_EXPONENT_NUMBER POSITIVE_NUMBER
	{
		$$ = (double)$1 * (double)10.0 + (double)$2;
	}
	|NEGATIVE_EXPONENT_NUMBER POSITIVE_NUMBER
	{
		$$ = (double)$1 * (double)10.0 - (double)$2;
	}
	|POSITIVE_EXPONENT_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = (double)$1 * (double)100.0 + (double)$2 * (double)10.0 + (double)$3;
	}
	|NEGATIVE_EXPONENT_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = (double)$1 * (double)100.0 - (double)$2 * (double)10.0 - (double)$3;
	}
	;


%%
//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

