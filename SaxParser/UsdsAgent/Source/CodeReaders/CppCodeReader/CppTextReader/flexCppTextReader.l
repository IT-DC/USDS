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
								return (token::DIRECTIVES);
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



