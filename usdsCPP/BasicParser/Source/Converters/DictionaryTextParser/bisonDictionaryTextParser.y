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

%token<typeVal> SIMPLE_TYPE "Simple type"
%token<typeVal> TYPE_STRING "STRING"

%token<encodeVal> STRING_ENCODE "<Text encode>"

%token<boolVal> BOOLEAN_VALUE "true or false"
%token<intVal> POSITIVE_INT32_NUMBER "positive int32 [0, 2147483647]"
%token<intVal> NEGATIVE_INT32_NUMBER "negative int32 [-2147483648, -1]"
%token<intVal> UNSIGNED_INT32_NUMBER "unsigned int32 [0, 4294967295]"
%token<intVal> POSITIVE_INT64_NUMBER "positive int64 [0, (2^63–1)]"
%token<intVal> NEGATIVE_INT64_NUMBER "negative int64 [-(2^63), -1]"
%token<intVal> UNSIGNED_INT64_NUMBER "unsigned int64 [0, (2^64-1)]"

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

%{
#undef yylex
#define yylex scanner->scan
%}

//=================================================================================================
// Rules
%%
dictionary: 
	USDS TEXT_NAME POSITIVE_INT32_NUMBER '.' POSITIVE_INT32_NUMBER '.' POSITIVE_INT32_NUMBER
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
	
tag: POSITIVE_INT32_NUMBER ':' SIMPLE_TYPE TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|POSITIVE_INT32_NUMBER ':' TYPE_STRING TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	|POSITIVE_INT32_NUMBER ':' TYPE_STRING '<' STRING_ENCODE '>' TEXT_NAME ';'
	{
		tag = dict->addTag($3, $1, input_text + $7[0], $7[1]);
		((DictionaryString*)tag)->setDefaultEncode($5);
	}
	|POSITIVE_INT32_NUMBER ':' TEXT_NAME '{'
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
	POSITIVE_INT32_NUMBER ':' SIMPLE_TYPE TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|POSITIVE_INT32_NUMBER ':' TYPE_STRING TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}	
	|POSITIVE_INT32_NUMBER ':' TYPE_STRING '<' STRING_ENCODE '>' TEXT_NAME ';'
	{
		field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $7[0], $7[1]);
		((DictionaryString*)field)->setDefaultEncode($5);
	}
	|POSITIVE_INT32_NUMBER ':' TEXT_NAME TEXT_NAME ';'
	{
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, $1, input_text + $4[0], $4[1]);
		((DictionaryTagLink*)field)->setTag(input_text + $3[0], $3[1]);
	}
	|POSITIVE_INT32_NUMBER ':' TEXT_NAME '{'
	{
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, $1, input_text + $3[0], $3[1]);
	}
	fields '}' ';'
	{
		tag = tag->getParent();
	}
	;


%%
//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

