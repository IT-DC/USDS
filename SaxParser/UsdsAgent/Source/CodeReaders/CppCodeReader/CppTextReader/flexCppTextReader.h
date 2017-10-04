#ifndef FLEX_CPP_TEXT_READER
#define FLEX_CPP_TEXT_READER

#if ! defined(yyFlexLexerOnce)
#include "FlexLexerCppTextReader.h"
#endif
#undef YY_DECL
#define YY_DECL int FlexCppTextReader::scan(BisonCppTextReader::semantic_type * yylval, BisonCppTextReader::location_type* yylloc)
#include "bisonCppTextReader.hh"

#include <sstream>

namespace cppTextReader
{
	class FlexCppTextReader : public yyFlexLexerCppTextReader
	{
	public:
		FlexCppTextReader(std::stringstream* input, std::stringstream* output) : yyFlexLexerCppTextReader(input, output) { offset = 0; };
		~FlexCppTextReader() {};

		virtual int scan(BisonCppTextReader::semantic_type * yylval, BisonCppTextReader::location_type* yylloc);

	};


};
#endif