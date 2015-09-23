%{
	#include "base\usdsDictionary.h"
	#include "tags\dicStructFields.h"
	#include "tags\dicStructTag.h"
	
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


%parse-param {class Dictionary* dict}
%parse-param {class FlexDictionaryTextScanner* scanner}
%parse-param {std::stringstream* error_message}

%error-verbose

%union {
    int  			intVal;
    double 			doubleVal;
    char*			stringVal;
	class DicBaseField*	fieldVal;
	usdsEncodes		encodeVal;
}

// Tokens
%token USDS_Dictionary_ID
%token DICTIONARY_VERSION
%token ROOT_TAG

%token TYPE_BOOLEAN
%token TYPE_INT
%token TYPE_LONG
%token TYPE_DOUBLE
%token TYPE_VARINT
%token TYPE_UNSIGNED_VARINT
%token TYPE_STRUCT
%token TYPE_ARRAY
%token TYPE_STRING

%token<encodeVal> STRING_ENCODE "utf-8"

%token<intVal> UNSIGNED_INTEGER_NUMBER "unsigned integer"
%token<stringVal> FIELD_NAME "string"

%type<fieldVal> field fields field_boolean field_int field_long field_double field_uvarint field_array field_string

%destructor { delete [] $$; } FIELD_NAME

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
	USDS_Dictionary_ID '=' UNSIGNED_INTEGER_NUMBER DICTIONARY_VERSION UNSIGNED_INTEGER_NUMBER '.' UNSIGNED_INTEGER_NUMBER 
	{
		dict->setID($3, $5, $7);
	}
	'{' tags '}'
	;

tags: tag | tag tags;
	
tag: 
	UNSIGNED_INTEGER_NUMBER ':' TYPE_STRUCT FIELD_NAME '{' fields '}'
	{
		DicStructTag* object = dict->addStructTag($4, $1, false);
		object->setFields($6);
		delete [] $4;
	}
	| UNSIGNED_INTEGER_NUMBER ':' ROOT_TAG TYPE_STRUCT FIELD_NAME '{' fields '}'
	{
		DicStructTag* object = dict->addStructTag($5, $1, true);
		object->setFields($7);
		delete [] $5;
	}
	;

//=================================================================================================
// Struct fields

fields: field 
	{
		$$ = $1;	
	}
	| field fields
	{
		$1->setNextField($2);
		$2->setPreviousField($1);
	}
	;

field: field_boolean | field_int | field_long | field_double | field_uvarint | field_array | field_string ;

field_boolean:
	UNSIGNED_INTEGER_NUMBER ':' TYPE_BOOLEAN FIELD_NAME ';'
	{
		$$ = dict->addBooleanField($4, $1, false);
		delete [] $4;
	}
	;

field_int:
	UNSIGNED_INTEGER_NUMBER ':' TYPE_INT FIELD_NAME ';'
	{
		$$ = dict->addIntField($4, $1, false);
		delete [] $4;
	}
	;

field_long:
	UNSIGNED_INTEGER_NUMBER ':' TYPE_LONG FIELD_NAME ';'
	{
		$$ = dict->addLongField($4, $1, false);
		delete [] $4;
	}
	;

field_double:
	UNSIGNED_INTEGER_NUMBER ':' TYPE_DOUBLE FIELD_NAME ';'
	{
		$$ = dict->addDoubleField($4, $1, false);
		delete [] $4;
	}
	;

field_uvarint:
	UNSIGNED_INTEGER_NUMBER ':' TYPE_UNSIGNED_VARINT FIELD_NAME ';'
	{
		$$ = dict->addUVarintField($4, $1, false);
		delete [] $4;
	}
	;
	
field_array:
	UNSIGNED_INTEGER_NUMBER ':' TYPE_ARRAY '<' FIELD_NAME '>' FIELD_NAME ';'
	{
		$$ = dict->addArrayField($7, $1, false, $5);
		delete [] $5;
		delete [] $7;
	}
	;

field_string:
	UNSIGNED_INTEGER_NUMBER ':' TYPE_STRING '(' STRING_ENCODE ')' FIELD_NAME ';'
	{
		$$ = dict->addStringField($7, $1, false, $5);
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

