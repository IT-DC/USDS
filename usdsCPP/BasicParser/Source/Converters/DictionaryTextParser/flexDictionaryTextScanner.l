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
"USDS"[ \t\r]+"DICTIONARY"[ \t\r]+"ID" {
							return (token::USDS_DICTIONARY_ID);
						}

"v."					{
							return (token::DICTIONARY_VERSION);
						}

%{
/* =============================================================================== */
/* Data types */ 
%}
"BOOLEAN"				{
							yylval->typeVal = USDS_BOOLEAN;
							return (token::TYPE_BOOLEAN);
						}

"INT"					{
							yylval->typeVal = USDS_INT;
							return (token::TYPE_INT);
						}

"LONG"					{
							yylval->typeVal = USDS_LONG;
							return (token::TYPE_LONG);
						}

"DOUBLE"				{
							yylval->typeVal = USDS_DOUBLE;
							return (token::TYPE_DOUBLE);
						}

"VARINT"				{
							yylval->typeVal = USDS_VARINT;
							return (token::TYPE_VARINT);
						}

"UVARINT" {
							yylval->typeVal = USDS_UVARINT;
							return (token::TYPE_UVARINT);
						}

"STRING"				{
							yylval->typeVal = USDS_STRING;
							return (token::TYPE_STRING);
						}

"STRUCT"				{
							yylval->typeVal = USDS_STRUCT;
							return (token::TYPE_STRUCT);
						}

"ARRAY"					{
							yylval->typeVal = USDS_ARRAY;
							return (token::TYPE_ARRAY);
						}

%{
/* =============================================================================== */
/* String encodes */ 
%}

"UTF-8"					{
							yylval->encodeVal = USDS_UTF8;
							return (token::STRING_ENCODE);
						}
%{
/* =============================================================================== */
/* Restrictions */ 
%}

"RESTRICT"				{
							return (token::USDS_RESTRICT);
						}
						
"notRoot"					{
							return (token::NOT_ROOT_TAG);
						}

%{
/* =============================================================================== */
/* Boolean values */
%}

"true"					{
							yylval->boolVal = true;
							return (token::BOOLEAN_VALUE);
						}

"false"					{
							yylval->boolVal = false;
							return (token::BOOLEAN_VALUE);
						}
						
%{ 
/* =============================================================================== */
/* Field and tag names */ 
%}
[_a-zA-Z][_0-9a-zA-Z]*	{
							yylval->stringVal = new char[yyleng+1];
							strcpy(yylval->stringVal, yytext);
							yytext[yyleng] = 0;
							return (token::TEXT_NAME);
						}

%{
/* =============================================================================== */
/* Numbers */
%}

[0-9]+					{
							yylval->intVal = atoi(yytext);
							return token::UNSIGNED_INTEGER_NUMBER;
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