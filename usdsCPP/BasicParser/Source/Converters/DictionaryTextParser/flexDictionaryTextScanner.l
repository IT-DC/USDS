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
							return (token::TYPE_BOOLEAN);
						}

"BYTE"					{
							yylval->typeVal = USDS_BYTE;
							return (token::TYPE_BYTE);
						}

"UBYTE"					{
							yylval->typeVal = USDS_UBYTE;
							return (token::TYPE_UBYTE);
						}

"SHORT"					{
							yylval->typeVal = USDS_SHORT;
							return (token::TYPE_SHORT);
						}

"USHORT"				{
							yylval->typeVal = USDS_USHORT;
							return (token::TYPE_USHORT);
						}
						
"INT"					{
							yylval->typeVal = USDS_INT;
							return (token::TYPE_INT);
						}

"UINT"					{
							yylval->typeVal = USDS_UINT;
							return (token::TYPE_UINT);
						}
						
"LONG"					{
							yylval->typeVal = USDS_LONG;
							return (token::TYPE_LONG);
						}

"ULONG"					{
							yylval->typeVal = USDS_ULONG;
							return (token::TYPE_ULONG);
						}

"INT128"				{
							yylval->typeVal = USDS_INT128;
							return (token::TYPE_INT128);
						}

"UINT128"				{
							yylval->typeVal = USDS_UINT128;
							return (token::TYPE_UINT128);
						}

						
"FLOAT"					{
							yylval->typeVal = USDS_FLOAT;
							return (token::TYPE_FLOAT);
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
						
"notRoot"				{
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
/* Null value */
%}

"NULL"					{
							return (token::NULL_VALUE);
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
							yylval->Int8Val = 0;
							return token::POSITIVE_NUMBER;
						}

"1"						{
							yylval->Int8Val = 1;
							return token::POSITIVE_NUMBER;
						}
						
"2"						{
							yylval->Int8Val = 2;
							return token::POSITIVE_NUMBER;
						}

"3"						{
							yylval->Int8Val = 3;
							return token::POSITIVE_NUMBER;
						}

"4"						{
							yylval->Int8Val = 4;
							return token::POSITIVE_NUMBER;
						}

"5"						{
							yylval->Int8Val = 5;
							return token::POSITIVE_NUMBER;
						}
						
"6"						{
							yylval->Int8Val = 6;
							return token::POSITIVE_NUMBER;
						}
						
"7"						{
							yylval->Int8Val = 7;
							return token::POSITIVE_NUMBER;
						}
						
"8"						{
							yylval->Int8Val = 8;
							return token::POSITIVE_NUMBER;
						}
						
"9"						{
							yylval->Int8Val = 9;
							return token::POSITIVE_NUMBER;
						}

"-1"					{
							yylval->Int8Val = -1;
							return token::NEGATIVE_NUMBER;
						}
						
"-2"					{
							yylval->Int8Val = -2;
							return token::NEGATIVE_NUMBER;
						}

"-3"					{
							yylval->Int8Val = -3;
							return token::NEGATIVE_NUMBER;
						}

"-4"					{
							yylval->Int8Val = -4;
							return token::NEGATIVE_NUMBER;
						}

"-5"					{
							yylval->Int8Val = -5;
							return token::NEGATIVE_NUMBER;
						}
						
"-6"					{
							yylval->Int8Val = -6;
							return token::NEGATIVE_NUMBER;
						}
						
"-7"					{
							yylval->Int8Val = -7;
							return token::NEGATIVE_NUMBER;
						}
						
"-8"					{
							yylval->Int8Val = -8;
							return token::NEGATIVE_NUMBER;
						}
						
"-9"					{
							yylval->Int8Val = -9;
							return token::NEGATIVE_NUMBER;
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