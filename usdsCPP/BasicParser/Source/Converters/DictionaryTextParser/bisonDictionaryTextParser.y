%{
	#include "usdsBasicParser.h"
	#include "dictionary\usdsDictionary.h"

	#include "dictionary\dictionaryBaseType.h"
	#include "dictionary\dataTypes\dictionaryArray.h"
	#include "dictionary\dataTypes\dictionaryBoolean.h"
	#include "dictionary\dataTypes\dictionaryDouble.h"
	#include "dictionary\dataTypes\dictionaryInt.h"
	#include "dictionary\dataTypes\dictionaryLong.h"
	#include "dictionary\dataTypes\dictionaryString.h"
	#include "dictionary\dataTypes\dictionaryUVarint.h"
	#include "dictionary\dataTypes\dictionaryStruct.h"
	#include "dictionary\dataTypes\dictionaryTagLink.h"
	
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
	int8_t  		Int8Val;
	uint8_t  		UInt8Val;
	int32_t  		Int32Val;
	uint32_t  		UInt32Val;
    double 			doubleVal;
    size_t			stringVal[2];
	usdsEncodes		encodeVal;
	usdsTypes		typeVal;
}

// Tokens
%token USDS
%token DICTIONARY_VERSION

%token<typeVal> SIMPLE_TYPE "Simple type"
%token<typeVal> TYPE_STRING "STRING"

%token<encodeVal> STRING_ENCODE "<Text encode>"

%token<boolVal> BOOLEAN_VALUE "true or false"
%token<Int8Val> POSITIVE_NUMBER "Digit"
%token<Int8Val> NEGATIVE_NUMBER "-Digit"
%token NULL_VALUE

%token<stringVal> TEXT_NAME "object name"

// restrictions
%token USDS_RESTRICT
%token NOT_ROOT_TAG "notRoot"

%token '{'
%token '}'
%token ':'
%token ';'
%token '='
%token '.'

%type<UInt8Val> UINT8_T "uint8_t"
%type<Int32Val> INT32_T "int32_t"
%type<UInt32Val> UINT32_T "uint32_t"

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
// Simple types

tags: tag | tag tags;
	
tag: INT32_T ':' SIMPLE_TYPE TEXT_NAME ';'
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
	;
	
//=================================================================================================
// Struct fields

fields: field | field fields;

field:
	INT32_T ':' SIMPLE_TYPE TEXT_NAME ';'
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
// Nullable fields

	|INT32_T ':' SIMPLE_TYPE TEXT_NAME '=' NULL_VALUE ';'
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
	|INT32_T ':' TEXT_NAME TEXT_NAME '=' NULL_VALUE  ';'
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
	;
	
struct_begin:
	INT32_T ':' TEXT_NAME '{'
	{
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, $1, input_text + $3[0], $3[1]);
	}
	;
	
//=================================================================================================
// Digits

UINT8_T:
	POSITIVE_NUMBER
	{
		$$ = (uint8_t)$1;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = (uint8_t)$1 * (uint8_t)10 + (uint8_t)$2;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to uint8_t: too big value";

		$$ = (uint8_t)$2  * (uint8_t)10 + (uint8_t)$3;
		
		if ($1 == (int8_t)2 && $$ >= (uint8_t)56)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << " to uint8_t: too big value";
		
		$$ = (uint8_t)$1 * (uint8_t)100 + $$;
		
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << "... to uint8_t: too big value";
	}
	;

UINT32_T:
	POSITIVE_NUMBER
	{
		$$ = (uint32_t)$1;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)10 + 
		(uint32_t)$2;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)100 + 
		(uint32_t)$2 * (uint32_t)10 + 
		(uint32_t)$3;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)1000 + 
		(uint32_t)$2 * (uint32_t)100 + 
		(uint32_t)$3 * (uint32_t)10 + 
		(uint32_t)$4;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)10000 + 
		(uint32_t)$2 * (uint32_t)1000 + 
		(uint32_t)$3 * (uint32_t)100 + 
		(uint32_t)$4 * (uint32_t)10 + 
		(uint32_t)$5;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint32_t)$1 * (uint32_t)100000 + 
		(uint32_t)$2 * (uint32_t)10000 + 
		(uint32_t)$3 * (uint32_t)1000 + 
		(uint32_t)$4 * (uint32_t)100 + 
		(uint32_t)$5 * (uint32_t)10 + 
		(uint32_t)$6;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
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
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
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
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
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
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
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
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << "... to uint32_t: too big value";
	}
	;
	
INT32_T:
	POSITIVE_NUMBER
	{
		$$ = (int32_t)$1;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)10 + 
		(int32_t)$2;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)100 + 
		(int32_t)$2 * (int32_t)10 + 
		(int32_t)$3;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)1000 + 
		(int32_t)$2 * (int32_t)100 + 
		(int32_t)$3 * (int32_t)10 + 
		(int32_t)$4;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)10000 + 
		(int32_t)$2 * (int32_t)1000 + 
		(int32_t)$3 * (int32_t)100 + 
		(int32_t)$4 * (int32_t)10 + 
		(int32_t)$5;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(int32_t)$1 * (int32_t)100000 + 
		(int32_t)$2 * (int32_t)10000 + 
		(int32_t)$3 * (int32_t)1000 + 
		(int32_t)$4 * (int32_t)100 + 
		(int32_t)$5 * (int32_t)10 + 
		(int32_t)$6;
	}
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
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
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
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
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
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
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
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
	| POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << "... to int32_t: too big value";
	}
	;
	
digits: POSITIVE_NUMBER | digits POSITIVE_NUMBER

%%
//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

