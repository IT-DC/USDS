%{
/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

#pragma warning(disable : 4996)

#include "flexDictionaryTextScanner.h"
using namespace usds;

typedef BisonDictionaryTextParser::token token;
typedef BisonDictionaryTextParser::token_type token_type;

%}

%option c++
%option noyywrap
%option yyclass="FlexDictionaryTextScanner"
%option stack
%option nodefault

%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

/* the manual says "somewhat more optimized" */
%option batch

%%
%{
    yylloc->step();
%}

%{ 
/* =============================================================================== */
/* Key words */ 
%}
"USDS"[ \t\r]+"Dictionary"[ \t\r]+"ID" {
							return (token::USDS_Dictionary_ID);
						}

"v."					{
							return (token::DICTIONARY_VERSION);
						}

"root"					{
							return (token::ROOT_TAG);
						}
			
%{
/* =============================================================================== */
/* Data types */ 
%}
"boolean"				{
							return (token::TYPE_BOOLEAN);
						}

"int"					{
							return (token::TYPE_INT);
						}

"long"					{
							return (token::TYPE_LONG);
						}

"double"				{
							return (token::TYPE_DOUBLE);
						}

"varint"				{
							return (token::TYPE_VARINT);
						}

"struct"				{
							return (token::TYPE_STRUCT);
						}

"array"					{
							return (token::TYPE_ARRAY);
						}

"string"				{
							return (token::TYPE_STRING);
						}
%{
/* =============================================================================== */
/* String encodes */ 
%}

[uU][tT][fF]"-8"		{
							yylval->encodeVal = USDS_UTF8;
							return (token::STRING_ENCODE);
						}


%{ 
/* =============================================================================== */
/* Field and tag names */ 
%}
[_a-zA-Z][_0-9a-zA-Z]*	{
							yylval->stringVal = new char[yyleng+1];
							strcpy(yylval->stringVal, yytext);
							yytext[yyleng] = 0;
							return (token::FIELD_NAME);
						}

%{
/* =============================================================================== */
/* Numbers */
%}

[0-9]+					{
							yylval->intVal = atoi(yytext);
							return token::INTEGER_NUMBER;
						}

%{ 
/* =============================================================================== */
/* Punctuation */ 
%}

"{"						{
							return '{';
						}

"}"						{
							return '}';
						}

"="						{
							return '=';
						}

":"						{
							return ':';
						}

";"						{
							return ';';
						}

"."						{
							return '.';
						}

"("						{
							return '(';
						}
						
")"						{
							return ')';
						}
						
"<"						{
							return '<';
						}
						
">"						{
							return '>';
						}
%{ 
/* =============================================================================== */
/* Spaces */ 
%}
[ \t\r]+				{yylloc->step();}

\n 						{yylloc->lines(yyleng); yylloc->step();}

%{ 
/* Unregistered symbols */ 
%}
. 						{
							std::cout << "!!!Unregistered symbol: " << *yytext << " !!!\n";
							return static_cast<token_type>(*yytext);
						}

%%