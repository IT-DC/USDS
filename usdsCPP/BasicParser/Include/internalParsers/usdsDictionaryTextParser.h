#ifndef USDS_DICTIONARY_TEXT_PARSER
#define USDS_DICTIONARY_TEXT_PARSER

#include "base\usdsDictionary.h"

#if ! defined(yyFlexLexerOnce)
#include "FlexLexer.h"
#endif
#undef YY_DECL
#define YY_DECL int DictionaryTextParser::yylex()
#include "..\Source\DictionaryTextParser\bisonDictionaryTextParser.h"

#include <sstream>

namespace usds
{
	class DictionaryTextParser : public yyFlexLexer
	{
	public:
		DictionaryTextParser() {};
		~DictionaryTextParser() {};

		void parse(const char* text_dict, Dictionary* dict) throw (...)
		{
			std::stringstream input;
			std::stringstream output;
			input << text_dict;
			yyFlexLexer scanner(&input, &output);
			BisonDictionaryTextParser parser(dict, this);

			parser.parse();

		};

		int scan(BisonDictionaryTextParser::semantic_type * lval) { yylval = lval; return yylex(); }

	private:
		BisonDictionaryTextParser::semantic_type * yylval;
		int yylex();

	};
	

};
#endif