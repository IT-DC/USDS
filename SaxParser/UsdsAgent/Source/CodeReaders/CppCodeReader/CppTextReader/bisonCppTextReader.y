%{
	#include "BasicParser/Include/usdsBasicParser.h"
	#include "flexCppTextReader.h"

%}

%require "3.0.4"
%skeleton "lalr1.cc"
%debug

%define api.prefix {cpp_text}
%define api.namespace {cppTextReader}
%define parser_class_name {BisonCppTextReader}
%locations

%parse-param {class FlexCppTextReader* scanner}

%error-verbose

%union {
    size_t			stringVal[2];
}

// Tokens
%token DIRECTIVES


%{
#undef yylex
#define yylex scanner->scan
%}

//=================================================================================================
// Rules
%%

code: block | block code;

block:
	DIRECTIVES
	{
	
	}
	;



%%
//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

