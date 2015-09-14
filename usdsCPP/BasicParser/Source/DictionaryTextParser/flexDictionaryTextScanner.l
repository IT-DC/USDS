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

%%
%{
    // reset location
    yylloc->step();
%}

"USDS Dictionary ID"	{
							std::cout << "USDS Dictionary ID" << std::endl;
							return (token::USDS_Dictionary_ID);
						}
[0-9]+					{
							std::cout << "INTEGER" << std::endl;
							return token::INTEGER;
						}

[ \t\r]+				{yylloc->step();}

\n 						{ yylloc->lines(yyleng); yylloc->step(); }

. {
	std::cout << *yytext << std::endl;
    return static_cast<token_type>(*yytext);
}

%%