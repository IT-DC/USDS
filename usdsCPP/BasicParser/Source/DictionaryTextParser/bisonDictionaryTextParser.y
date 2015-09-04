%{
	#include "base\usdsDictionary.h"
	#include "usdsDictionaryTextParser.h"
	#include <string>
	
%}

%require "2.4.3"
%skeleton "lalr1.cc"
%defines
%define api.prefix dictionary_text
%define namespace "usds"
%define parser_class_name "BisonDictionaryTextParser"

%parse-param {class Dictionary* dict}
%parse-param {class DictionaryTextParser* scanner}

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

void yyerror(char *s) {
  
}


