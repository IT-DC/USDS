%{
	#include "usdsBasicParser.h"
	#include "dictionary\usdsDictionary.h"

	#include "dictionary\dataTypes\dictionaryArray.h"
	#include "dictionary\dataTypes\dictionaryBaseType.h"
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
%define api.prefix dictionary_text
%define namespace "usds"
%define parser_class_name "BisonDictionaryTextParser"
%locations


%parse-param {class BasicParser* usdsParser}
%parse-param {class FlexDictionaryTextScanner* scanner}
%parse-param {std::stringstream* error_message}
%parse-param {class Dictionary* dict}
%parse-param {class DictionaryBaseType* tag}
%parse-param {class DictionaryBaseType* field}

%error-verbose

%union {
    bool  			boolVal;
	int  			intVal;
    double 			doubleVal;
    char*			stringVal;
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
%token<typeVal> TYPE_UNSIGNED_VARINT "UNSIGNED VARINT"
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

%destructor { delete [] $$; } TEXT_NAME

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
		dict = usdsParser->addNewDictionary($3, $5, $7);
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
		tag = dict->addTag($3, $1, $4, 0);
		delete [] $4;
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
		((DictionaryStruct*)tag)->addField($3, $1, $4, 0);
		delete [] $4;
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_INT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, $4, 0);
		delete [] $4;
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_LONG TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, $4, 0);
		delete [] $4;
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_DOUBLE TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, $4, 0);
		delete [] $4;
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_UNSIGNED_VARINT TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, $4, 0);
		delete [] $4;
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_STRING TEXT_NAME ';'
	{
		((DictionaryStruct*)tag)->addField($3, $1, $4, 0);
		delete [] $4;
	}	
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_STRING '<' STRING_ENCODE '>' TEXT_NAME ';'
	{
		field = ((DictionaryStruct*)tag)->addField($3, $1, $7, 0);
		((DictionaryString*)field)->setEncode($5);
		delete [] $7;
	}
	|UNSIGNED_INTEGER_NUMBER ':' TYPE_ARRAY '<' TEXT_NAME '>' TEXT_NAME ';'
	{
		field = ((DictionaryStruct*)tag)->addField($3, $1, $7, 0);
		DictionaryTagLink* element = (DictionaryTagLink*)(((DictionaryArray*)field)->setElementType(USDS_TAG));
		element->setTag($5, 0);
		delete [] $5;
		delete [] $7;
	}
	;


%%
//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	*error_message << "Error in Text Dictionary!\n";
	*error_message << loc.begin.line;
	*error_message << ".";
	*error_message << loc.begin.column;
	*error_message << ": ";
	*error_message << msg;
}

