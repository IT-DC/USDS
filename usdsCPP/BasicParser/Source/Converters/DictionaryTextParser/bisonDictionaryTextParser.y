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

%require "2.4.3"
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
%token USDS_DICTIONARY_ID
%token DICTIONARY_VERSION

%token<typeVal> TYPE_BOOLEAN "BOOLEAN"
%token<typeVal> TYPE_INT "INT"
%token<typeVal> TYPE_LONG "LONG"
%token<typeVal> TYPE_DOUBLE "DOUBLE"
%token<typeVal> TYPE_VARINT "VARINT"
%token<typeVal> TYPE_UVARINT "UVARINT"
%token<typeVal> TYPE_STRING "STRING"
%token<typeVal> TYPE_STRUCT "STRUCT"
%token<typeVal> TYPE_ARRAY "ARRAY"

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
	USDS_DICTIONARY_ID '=' UNSIGNED_INTEGER_NUMBER DICTIONARY_VERSION UNSIGNED_INTEGER_NUMBER '.' UNSIGNED_INTEGER_NUMBER 
	{
		dict->setID($3, $5, $7);
	}
	'{' tags '}'
	{
		// Finilize dictionary
		dict->finalizeDictionary();
	}
	;

tags: tag | tag tags;
	
tag: 
	struct_tag '{' fields '}'
	| struct_tag '{' fields '}' USDS_RESTRICT '{' struct_restricts '}'
	;

struct_tag: UNSIGNED_INTEGER_NUMBER ':' TYPE_STRUCT TEXT_NAME 
	{
		tag = dict->addTag($3, $1, input_text + $4[0], $4[1]);
	}
	;

struct_restricts: struct_restrict | struct_restrict struct_restricts;

struct_restrict:
	NOT_ROOT_TAG ';'
	{
		tag->setRoot(false);
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
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_INT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_LONG TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, input_text + $4[0], $4[1]);
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_DOUBLE TEXT_NAME ';'
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
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_ARRAY '<' TEXT_NAME '>' TEXT_NAME ';'
	{
		field = ((DictionaryStruct*)tag)->addField($3, $1, input_text + $7[0], $7[1]);
		DictionaryTagLink* element = (DictionaryTagLink*)(((DictionaryArray*)field)->setElementType(USDS_TAG));
		element->setTag(input_text + $5[0], $5[1]);
	}
	;


%%
//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

