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
	int  			intVal;
    double 			doubleVal;
    size_t			stringVal[2];
	usdsEncodes		encodeVal;
	usdsTypes		typeVal;
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
%token<typeVal> TYPE_FLOAT "FLOAT"
%token<typeVal> TYPE_DOUBLE "DOUBLE"
%token<typeVal> TYPE_VARINT "VARINT"
%token<typeVal> TYPE_UVARINT "UVARINT"
%token<typeVal> TYPE_STRING "STRING"

%token<encodeVal> STRING_ENCODE "<Text encode>"

// restrictions
%token USDS_RESTRICT
%token NOT_ROOT_TAG "notRoot"

%token<boolVal> BOOLEAN_VALUE "true or false"
%token<intVal> UNSIGNED_INTEGER_NUMBER "unsigned integer number"
%token<stringVal> TEXT_NAME "object name"

%token '{'
%token '}'
%token ':'
%token ';'
%token '='
%token '.'

%{
#undef yylex
#define yylex scanner->scan
%}

//=================================================================================================
// Rules
%%
dictionary: 
	USDS TEXT_NAME UNSIGNED_INTEGER_NUMBER '.' UNSIGNED_INTEGER_NUMBER '.' UNSIGNED_INTEGER_NUMBER
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
	
tag: 
	boolean_tag
	| byte_tag
	| ubyte_tag
	| short_tag
	| ushort_tag
	| int_tag
	| uint_tag
	| long_tag
	| ulong_tag
	| float_tag
	| double_tag
	| varint_tag
	| uvarint_tag
	| string_tag
	| struct_tag
	;

boolean_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_BOOLEAN TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;
	
byte_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_BYTE TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;
	
ubyte_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_UBYTE TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;

short_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_SHORT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;
	
ushort_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_USHORT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;

int_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_INT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;
	
uint_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_UINT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;

long_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_LONG TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;
	
ulong_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_ULONG TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;

float_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_FLOAT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;

double_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_DOUBLE TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;

varint_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_VARINT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;
	
uvarint_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_UVARINT TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;

//=================================================================================================
// String

string_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_STRING TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;

string_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_STRING '<' STRING_ENCODE '>' TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $7[0], $7[1]);
		((DictionaryString*)tag)->setDefaultEncode($5);
	}
	;
	
//=================================================================================================
// Struct

struct_tag: UNSIGNED_INTEGER_NUMBER ':' TEXT_NAME '{'
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
	UNSIGNED_INTEGER_NUMBER ':' TYPE_BOOLEAN TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_BYTE TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_UBYTE TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_SHORT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_USHORT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_INT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_UINT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_LONG TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_ULONG TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_FLOAT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_DOUBLE TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_VARINT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_UVARINT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_STRING TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}	
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_STRING '<' STRING_ENCODE '>' TEXT_NAME ';'
	{
		field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $7[0], $7[1]);
		((DictionaryString*)field)->setDefaultEncode($5);
	}
	;


%%
//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

