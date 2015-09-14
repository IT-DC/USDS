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

%error-verbose

%union {
    int  			integerVal;
    double 			doubleVal;
    std::string*		stringVal;
}


// Tokens
%token USDS_Dictionary_ID
%token INTEGER

%{
#undef yylex
#define yylex scanner->scan
%}

%%
dictionary: USDS_Dictionary_ID '=' INTEGER 'v' '.' INTEGER '.' INTEGER
{

}



%%

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	std::cout << loc << ":" << msg << std::endl;
}

