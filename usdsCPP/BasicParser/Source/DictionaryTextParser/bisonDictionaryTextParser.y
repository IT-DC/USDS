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
    int  			integerVal;
    double 			doubleVal;
    std::string*		stringVal;
}

// Tokens
%token USDS_Dictionary_ID
%token DICTIONARY_VERSION
%token ROOT_TAG

%token INTEGER_NUMBER

%token TYPE_BOOLEAN
%token TYPE_INT
%token TYPE_LONG
%token TYPE_DOUBLE
%token TYPE_VARINT
%token TYPE_STRUCT
%token TYPE_ARRAY
%token TYPE_STRING

%token STRING_ENCODE

%token FIELD_NAME

%token '{'
%token '}'
%token ':'
%token ';'
%token '='

%{
#undef yylex
#define yylex scanner->scan
%}

//=================================================================================================
// Rules
%%
dictionary: 
	USDS_Dictionary_ID '=' INTEGER_NUMBER DICTIONARY_VERSION INTEGER_NUMBER '.' INTEGER_NUMBER 
	{
		std::cout << "USDS_Dictionary_ID\n";
	}
	'{' tags '}'
	;

tags: tag
	{
		std::cout << "Last tag\n";
	}
	| tag tags
	{
		std::cout << "Next tag\n";
	}
	;
	
tag: 
	INTEGER_NUMBER ':' TYPE_STRUCT FIELD_NAME '{'
	{
		std::cout << "Struct\n";
	}
	fields '}' ';'
	| INTEGER_NUMBER ':' ROOT_TAG TYPE_STRUCT FIELD_NAME '{'
	{
		std::cout << "Root struct\n";
	}
	fields '}' ';'
	;

//=================================================================================================
// Struct fields

fields: field
	{
		std::cout << "Last field\n";
	
	}
	| field fields
	{
		std::cout << "Next field\n";
	}
	;

field: field_boolean | field_int | field_long| field_double | field_varint | field_array | field_string ;

field_boolean:
	INTEGER_NUMBER ':' TYPE_BOOLEAN FIELD_NAME ';'
	{
		std::cout << "Boolean field\n";
	}
	;

field_int:
	INTEGER_NUMBER ':' TYPE_INT FIELD_NAME ';'
	{
		std::cout << "Int field\n";
	}
	;

field_long:
	INTEGER_NUMBER ':' TYPE_LONG FIELD_NAME ';'
	{
		std::cout << "Long field\n";
	}
	;

field_double:
	INTEGER_NUMBER ':' TYPE_DOUBLE FIELD_NAME ';'
	{
		std::cout << "Double field\n";
	}
	;

field_varint:
	INTEGER_NUMBER ':' TYPE_VARINT FIELD_NAME ';'
	{
		std::cout << "Varint field\n";
	}
	;
	
field_array:
	INTEGER_NUMBER ':' TYPE_ARRAY '<' FIELD_NAME '>' FIELD_NAME ';'
	{
		std::cout << "'Array of tags' field\n";
	}
	;

field_string:
	INTEGER_NUMBER ':' TYPE_STRING '(' STRING_ENCODE ')' FIELD_NAME ';'
	{
		std::cout << "String field\n";
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

