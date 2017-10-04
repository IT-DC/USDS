%{
/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

#include "flexCppTextReader.h"
using namespace cppTextReader;

typedef BisonCppTextReader::token token;
typedef BisonCppTextReader::token_type token_type;

%}

%option c++
%option yyclass="FlexCppTextReader"
%option noyywrap
%option stack
%option nodefault
/* the manual says "somewhat more optimized" */
%option batch

%x MULTILINE_COMMENT

%{
#define YY_USER_ACTION  yylloc->columns(yyleng); offset += yyleng;
%}

%%
%{
    yylloc->step();
%}

%{ 
/* =============================================================================== */
/* Key words */ 
%}

#([\xc2-\xdf][\x80-\xbf]|[\xe0-\xef][\x80-\xbf][\x80-\xbf]|[\xf0-\xf4][\x80-\xbf][\x80-\xbf][\x80-\xbf]|[^\n])*\n	{
							yylloc->lines(1); yylloc->step();
							return (token::DIRECTIVES);
}

\/\/\n					{
							yylloc->lines(1); yylloc->step();
							return (token::COMMENTS);
}

\/\/[^\n]\n				{
							yylloc->lines(1); yylloc->step();
							return (token::COMMENTS);
}

\/\/[^\$^\n][^S^\n]([\xc2-\xdf][\x80-\xbf]|[\xe0-\xef][\x80-\xbf][\x80-\xbf]|[\xf0-\xf4][\x80-\xbf][\x80-\xbf][\x80-\xbf]|[^\n])*\n	{
							yylloc->lines(1); yylloc->step();
							return (token::COMMENTS);
}

\/\/\$[^S^\n]([\xc2-\xdf][\x80-\xbf]|[\xe0-\xef][\x80-\xbf][\x80-\xbf]|[\xf0-\xf4][\x80-\xbf][\x80-\xbf][\x80-\xbf]|[^\n])*\n	{
							yylloc->lines(1); yylloc->step();
							return (token::COMMENTS);
}

\/\*					{	
							BEGIN(MULTILINE_COMMENT);
}

<MULTILINE_COMMENT>\*\/ {
							BEGIN(INITIAL);
							return (token::COMMENTS);
}

<MULTILINE_COMMENT>\n	{
							yylloc->lines(1); yylloc->step();
}

<MULTILINE_COMMENT>.    ;

"namespace"				{
							return (token::NAMESPACE);
}

"struct"				{
							return (token::STRUCT);
}

%{ 
/* =============================================================================== */
/* USDS annotations */ 
%}

\/\/\$S					{
							return (token::USDS_ANNOTATION);
}

"ENCODE"				{
							return (token::USDS_ENCODE);
}

"UTF-8"					{
							yylval->encodeVal = usds::USDS_UTF8;
							return (token::STRING_ENCODE);
}

%{ 
/* =============================================================================== */
/* Type names */ 
%}
[_a-zA-Z][_0-9a-zA-Z]*	{
							yylval->stringVal[0] = offset - yyleng;
							yylval->stringVal[1] = yyleng;
							return (token::TEXT_NAME);
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
						
"};"					{
							return '}';
						}

";"						{
							return ';';
						}

":"						{
							return ':';
						}

"*"						{
							return '*';
						}

"["						{
							return '[';
						}
						
"]"						{
							return ']';
						}


%{
/* =============================================================================== */
/* Numbers */
%}
"0"						{
							yylval->int8Val = 0;
							return token::POSITIVE_NUMBER;
						}

"1"						{
							yylval->int8Val = 1;
							return token::POSITIVE_NUMBER;
						}
						
"2"						{
							yylval->int8Val = 2;
							return token::POSITIVE_NUMBER;
						}

"3"						{
							yylval->int8Val = 3;
							return token::POSITIVE_NUMBER;
						}

"4"						{
							yylval->int8Val = 4;
							return token::POSITIVE_NUMBER;
						}

"5"						{
							yylval->int8Val = 5;
							return token::POSITIVE_NUMBER;
						}
						
"6"						{
							yylval->int8Val = 6;
							return token::POSITIVE_NUMBER;
						}
						
"7"						{
							yylval->int8Val = 7;
							return token::POSITIVE_NUMBER;
						}
						
"8"						{
							yylval->int8Val = 8;
							return token::POSITIVE_NUMBER;
						}
						
"9"						{
							yylval->int8Val = 9;
							return token::POSITIVE_NUMBER;
						}

"-0"					{
							yylval->int8Val = 0;
							return token::NEGATIVE_NUMBER;
						}

"-1"					{
							yylval->int8Val = -1;
							return token::NEGATIVE_NUMBER;
						}
						
"-2"					{
							yylval->int8Val = -2;
							return token::NEGATIVE_NUMBER;
						}

"-3"					{
							yylval->int8Val = -3;
							return token::NEGATIVE_NUMBER;
						}

"-4"					{
							yylval->int8Val = -4;
							return token::NEGATIVE_NUMBER;
						}

"-5"					{
							yylval->int8Val = -5;
							return token::NEGATIVE_NUMBER;
						}
						
"-6"					{
							yylval->int8Val = -6;
							return token::NEGATIVE_NUMBER;
						}
						
"-7"					{
							yylval->int8Val = -7;
							return token::NEGATIVE_NUMBER;
						}
						
"-8"					{
							yylval->int8Val = -8;
							return token::NEGATIVE_NUMBER;
						}
						
"-9"					{
							yylval->int8Val = -9;
							return token::NEGATIVE_NUMBER;
						}

[eE][+]?"1"				{
							yylval->int8Val = 1;
							return token::POSITIVE_EXPONENT_NUMBER;
						}

[eE][+]?"2"				{
							yylval->int8Val = 2;
							return token::POSITIVE_EXPONENT_NUMBER;
						}

[eE][+]?"3"				{
							yylval->int8Val = 3;
							return token::POSITIVE_EXPONENT_NUMBER;
						}

[eE][+]?"4"				{
							yylval->int8Val = 4;
							return token::POSITIVE_EXPONENT_NUMBER;
						}

[eE][+]?"5"				{
							yylval->int8Val = 5;
							return token::POSITIVE_EXPONENT_NUMBER;
						}

[eE][+]?"6"				{
							yylval->int8Val = 6;
							return token::POSITIVE_EXPONENT_NUMBER;
						}
						
[eE][+]?"7"				{
							yylval->int8Val = 7;
							return token::POSITIVE_EXPONENT_NUMBER;
						}
						
[eE][+]?"8"				{
							yylval->int8Val = 8;
							return token::POSITIVE_EXPONENT_NUMBER;
						}
						
[eE][+]?"9"				{
							yylval->int8Val = 9;
							return token::POSITIVE_EXPONENT_NUMBER;
						}

[eE]"-1"				{
							yylval->int8Val = -1;
							return token::NEGATIVE_EXPONENT_NUMBER;
						}

[eE]"-2"				{
							yylval->int8Val = -2;
							return token::NEGATIVE_EXPONENT_NUMBER;
						}

[eE]"-3"				{
							yylval->int8Val = -3;
							return token::NEGATIVE_EXPONENT_NUMBER;
						}

[eE]"-4"				{
							yylval->int8Val = -4;
							return token::NEGATIVE_EXPONENT_NUMBER;
						}

[eE]"-5"				{
							yylval->int8Val = -5;
							return token::NEGATIVE_EXPONENT_NUMBER;
						}

[eE]"-6"				{
							yylval->int8Val = -6;
							return token::NEGATIVE_EXPONENT_NUMBER;
						}
						
[eE]"-7"				{
							yylval->int8Val = -7;
							return token::NEGATIVE_EXPONENT_NUMBER;
						}
						
[eE]"-8"				{
							yylval->int8Val = -8;
							return token::NEGATIVE_EXPONENT_NUMBER;
						}
						
[eE]"-9"				{
							yylval->int8Val = -9;
							return token::NEGATIVE_EXPONENT_NUMBER;
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



