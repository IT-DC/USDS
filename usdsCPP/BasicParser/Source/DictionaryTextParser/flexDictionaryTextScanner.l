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
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

/* the manual says "somewhat more optimized" */
%option batch

%s STATE_TAG

%%
%{
    yylloc->step();
%}

%{ 
/* =============================================================================== */
/* Key words */ 
%}
<INITIAL>"USDS"[ \t\r]+"Dictionary"[ \t\r]+"ID" {
							return (token::USDS_Dictionary_ID);
						}

<INITIAL>"v."			{
							return (token::DICTIONARY_VERSION);
						}
<INITIAL>[0-9]+			{
							return token::INTEGER_NUMBER;
						}


<STATE_TAG>"root"		{
							return (token::ROOT_TAG);
						}
			
%{
/* =============================================================================== */
/* Data types */ 
%}
<STATE_TAG>"boolean"	{
							return (token::TYPE_BOOLEAN);
						}

<STATE_TAG>"int"		{
							return (token::TYPE_INT);
						}

<STATE_TAG>"long"		{
							return (token::TYPE_LONG);
						}

<STATE_TAG>"double"		{
							return (token::TYPE_DOUBLE);
						}

<STATE_TAG>"varint"		{
							return (token::TYPE_VARINT);
						}

<STATE_TAG>"struct"		{
							return (token::TYPE_STRUCT);
						}

<STATE_TAG>"array"		{
							return (token::TYPE_ARRAY);
						}

<STATE_TAG>"string"		{
							return (token::TYPE_STRING);
						}
%{
/* =============================================================================== */
/* String encodes */ 
%}

<STATE_TAG>[uU][tT][fF]"-8"	{
							return (token::STRING_ENCODE);
						}


%{ 
/* =============================================================================== */
/* Field and tag names */ 
%}
<STATE_TAG>[a-zA-Z]+	{
							return (token::FIELD_NAME);
						}

%{
/* =============================================================================== */
/* Numbers */
%}

<STATE_TAG>[0-9]+		{
							return token::INTEGER_NUMBER;
						}

%{ 
/* =============================================================================== */
/* Punctuation */ 
%}

<INITIAL>"{"			{
							std::cout << "up: old state" << yy_top_state() << "\n";
							yy_push_state(STATE_TAG);
							std::cout << "up: new state" << yy_top_state() << "\n";
							return '{';
						}

"}"						{
							std::cout << "old state" << yy_top_state() << "\n";
							yy_pop_state();
							std::cout << "new state" << yy_top_state() << "\n";
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