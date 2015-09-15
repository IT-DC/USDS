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
%token INTEGER
%token USDS_STRUCT
%token USDS_VARINT
%token USDS_NAME
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
	USDS_Dictionary_ID '=' INTEGER 'v' '.' INTEGER '.' INTEGER 
	{
		std::cout << "USDS_Dictionary_ID\n";
	}
	'{' tag '}'
	;

tag: 
	INTEGER ':' USDS_STRUCT USDS_NAME '{'
	{
		std::cout << "Struct\n";
	}
	fields '}'
	;

fields:
	INTEGER ':' USDS_VARINT USDS_NAME ';'




%%
//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	*error_message << "Error in Text Dictionary!\n";
	*error_message << loc.begin.column;
	*error_message << ".";
	*error_message << loc.begin.line;
	*error_message << ": ";
	*error_message << msg;
}

