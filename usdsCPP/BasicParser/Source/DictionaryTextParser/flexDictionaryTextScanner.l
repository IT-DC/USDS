%{
/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

#include "usdsDictionaryTextParser.h"

using namespace usds;

%}

%option c++
%option noyywrap
%option yyclass="DictionaryTextParser"
%option stack
%option nodefault

/* the manual says "somewhat more optimized" */
%option batch

%%

"USDS Dictionary ID"	return (BisonDictionaryTextParser::token::USDS_Dictionary_ID);
[0-9]+					{
							return BisonDictionaryTextParser::token::INTEGER;
						}

[ \t\n]+				{/* ignore */}

%%