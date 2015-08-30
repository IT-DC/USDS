%{
#include "usdsDictionaryParser.h"
%}

"USDS Dictionary ID"	return (USDS_Dictionary_ID);
[0-9]+					{
							int len = strlen(yytext);
							yylval.sval = new char[len];
							strncpy(yylval.sval, yytext, len);
							return (return INTEGER);
						}