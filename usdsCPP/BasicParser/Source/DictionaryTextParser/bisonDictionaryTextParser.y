%{
	#include "base\usdsDictionary.h"
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
	DicBaseField*	fieldVal;
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
%token TYPE_STRUCT
%token TYPE_ARRAY
%token TYPE_STRING

%token<encodeVal> STRING_ENCODE "utf-8"

%token<intVal> INTEGER_NUMBER "integer"
%token<stringVal> FIELD_NAME "string"

%type<fieldVal> field_boolean field_int field_long field_double field_varint field_array field_string

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
	USDS_Dictionary_ID '=' INTEGER_NUMBER DICTIONARY_VERSION INTEGER_NUMBER '.' INTEGER_NUMBER '{' tags '}'
	{
		std::cout << "DictID = " << $3 << " Major = " << $5 << " Minor = " << $7 << "\n";
		dict->setID($3, $5, $7);
	}
	;

tags: tag | tag tags;
	
tag: 
	INTEGER_NUMBER ':' TYPE_STRUCT FIELD_NAME '{' fields '}' ';'
	{
		dict->addStructTag($4, $1, false);
		delete [] $4;
	}
	| INTEGER_NUMBER ':' ROOT_TAG TYPE_STRUCT FIELD_NAME '{' fields '}' ';'
	{
		dict->addStructTag($5, $1, true);
		delete [] $5;
	}
	;

//=================================================================================================
// Struct fields

fields: field | field fields;

field: field_boolean | field_int | field_long | field_double | field_varint | field_array | field_string ;

field_boolean:
	INTEGER_NUMBER ':' TYPE_BOOLEAN FIELD_NAME ';'
	{
		$$ = dict->addBooleanField($4, $1, false);
		delete [] $4;
	}
	;

field_int:
	INTEGER_NUMBER ':' TYPE_INT FIELD_NAME ';'
	{
		$$ = dict->addIntField($4, $1, false);
		delete [] $4;
	}
	;

field_long:
	INTEGER_NUMBER ':' TYPE_LONG FIELD_NAME ';'
	{
		$$ = dict->addLongField($4, $1, false);
		delete [] $4;
	}
	;

field_double:
	INTEGER_NUMBER ':' TYPE_DOUBLE FIELD_NAME ';'
	{
		$$ = dict->addDoubleField($4, $1, false);
		delete [] $4;
	}
	;

field_varint:
	INTEGER_NUMBER ':' TYPE_VARINT FIELD_NAME ';'
	{
		$$ = dict->addUVarintField($4, $1, false);
		delete [] $4;
	}
	;
	
field_array:
	INTEGER_NUMBER ':' TYPE_ARRAY '<' FIELD_NAME '>' FIELD_NAME ';'
	{
		$$ = dict->addArrayField($7, $1, false, $5);
		delete [] $5;
		delete [] $7;
	}
	;

field_string:
	INTEGER_NUMBER ':' TYPE_STRING '(' STRING_ENCODE ')' FIELD_NAME ';'
	{
		$$ = dict->addStringField($7, $1, false);
		//((DicStringField*)$$)->setEncode($5);
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

