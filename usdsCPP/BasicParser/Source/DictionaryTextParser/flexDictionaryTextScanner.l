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

%s TAG

%%
%{
    // reset location
    yylloc->step();
%}

"USDS Dictionary ID"	{
							return (token::USDS_Dictionary_ID);
						}
						
"struct"				{
							return (token::USDS_STRUCT);
						}

"varint"				{
							return (token::USDS_VARINT);
						}
						
<TAG>[a-zA-Z]+			{
							return (token::USDS_NAME);
						}
						
[0-9]+					{
							return token::INTEGER;
						}

"{"						{
							BEGIN(TAG);
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

						
[ \t\r]+				{yylloc->step();}

\n 						{yylloc->lines(yyleng); yylloc->step();}

. 						{
							return static_cast<token_type>(*yytext);
						}

%%