%{
	#include "Dictionary.h"
	using namespace usds;
%}

// Tokens
%token USDS_Dictionary_ID
%token INTEGER

%%
dictionary: USDS_Dictionary_ID '=' INTEGER 'v' '.' INTEGER '.' INTEGER
{

}



%%

void yyerror(char *s) {
  throw ErrorMessage(0, s);
}

int main(void) {
  yyparse();
}

