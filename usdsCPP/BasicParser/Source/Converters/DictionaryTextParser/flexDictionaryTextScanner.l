%{
/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

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
#define YY_USER_ACTION  yylloc->columns(yyleng); offset += yyleng;
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
"USDS"					{
							offset = yyleng;
							return (token::USDS);
						}

%{
/* =============================================================================== */
/* Data types */ 
%}
"BOOLEAN"				{
							yylval->typeVal = USDS_BOOLEAN;
							return (token::SIMPLE_TYPE);
						}

"BYTE"					{
							yylval->typeVal = USDS_BYTE;
							return (token::SIMPLE_TYPE);
						}

"UBYTE"					{
							yylval->typeVal = USDS_UBYTE;
							return (token::SIMPLE_TYPE);
						}

"SHORT"					{
							yylval->typeVal = USDS_SHORT;
							return (token::SIMPLE_TYPE);
						}

"USHORT"				{
							yylval->typeVal = USDS_USHORT;
							return (token::SIMPLE_TYPE);
						}
						
"INT"					{
							yylval->typeVal = USDS_INT;
							return (token::SIMPLE_TYPE);
						}

"UINT"					{
							yylval->typeVal = USDS_UINT;
							return (token::SIMPLE_TYPE);
						}
						
"LONG"					{
							yylval->typeVal = USDS_LONG;
							return (token::SIMPLE_TYPE);
						}

"ULONG"					{
							yylval->typeVal = USDS_ULONG;
							return (token::SIMPLE_TYPE);
						}

"FLOAT"				{
							yylval->typeVal = USDS_FLOAT;
							return (token::SIMPLE_TYPE);
						}
						
"DOUBLE"				{
							yylval->typeVal = USDS_DOUBLE;
							return (token::SIMPLE_TYPE);
						}

"VARINT"				{
							yylval->typeVal = USDS_VARINT;
							return (token::SIMPLE_TYPE);
						}

"UVARINT" {
							yylval->typeVal = USDS_UVARINT;
							return (token::SIMPLE_TYPE);
						}

"STRING"				{
							yylval->typeVal = USDS_STRING;
							return (token::TYPE_STRING);
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
							yylval->stringVal[0] = offset - yyleng;
							yylval->stringVal[1] = yyleng;
							return (token::TEXT_NAME);
						}

%{
/* =============================================================================== */
/* Numbers */
%}
"0"						{
							yylval->intVal = 0;
							return token::POSITIVE_INT32_NUMBER;
						}

"1"						{
							yylval->intVal = 1;
							return token::POSITIVE_INT32_NUMBER;
						}
						
"2"						{
							yylval->intVal = 2;
							return token::POSITIVE_INT32_NUMBER;
						}

"3"						{
							yylval->intVal = 3;
							return token::POSITIVE_INT32_NUMBER;
						}

"4"						{
							yylval->intVal = 4;
							return token::POSITIVE_INT32_NUMBER;
						}

"5"						{
							yylval->intVal = 5;
							return token::POSITIVE_INT32_NUMBER;
						}
						
"6"						{
							yylval->intVal = 6;
							return token::POSITIVE_INT32_NUMBER;
						}
						
"7"						{
							yylval->intVal = 7;
							return token::POSITIVE_INT32_NUMBER;
						}
						
"8"						{
							yylval->intVal = 8;
							return token::POSITIVE_INT32_NUMBER;
						}
						
"9"						{
							yylval->intVal = 9;
							return token::POSITIVE_INT32_NUMBER;
						}

[0-9]{2,9}				{
							yylval->intVal = atoi(yytext);
							return token::POSITIVE_INT32_NUMBER;
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

"["						{
							return '[';
						}

"]"						{
							return ']';
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