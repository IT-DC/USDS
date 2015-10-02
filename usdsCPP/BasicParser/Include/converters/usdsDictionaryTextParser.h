#ifndef USDS_DICTIONARY_TEXT_PARSER
#define USDS_DICTIONARY_TEXT_PARSER

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"
#include "dictionary\usdsDictionary.h"
#include "usdsBasicParser.h"

#include <sstream>
#include <list>

namespace usds
{
	class DictionaryTextParser
	{
	public:
		DictionaryTextParser() {};
		~DictionaryTextParser() {};

		void parse(const char* text_dict, usdsEncodes encode, BasicParser* usdsParser) throw (...);

	};
	

};
#endif