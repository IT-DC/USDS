#ifndef FLEX_DICTIONARY_TEXT_SCANNER
#define FLEX_DICTIONARY_TEXT_SCANNER

#include "dictionary\usdsDictionary.h"

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif
#undef YY_DECL
#define YY_DECL int FlexDictionaryTextScanner::scan(BisonDictionaryTextParser::semantic_type * yylval, BisonDictionaryTextParser::location_type* yylloc)
#include "bisonDictionaryTextParser.hh"

#include <sstream>

namespace usds
{
	class FlexDictionaryTextScanner : public yyFlexLexer
	{
	public:
		FlexDictionaryTextScanner(std::stringstream* input, std::stringstream* output) : yyFlexLexer(input, output) { offset = 0; };
		~FlexDictionaryTextScanner() {};

		virtual int scan(BisonDictionaryTextParser::semantic_type * yylval, BisonDictionaryTextParser::location_type* yylloc);

	};


};
#endif