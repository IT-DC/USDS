#ifndef USDS_DICTIONARY_TEXT_PARSER
#define USDS_DICTIONARY_TEXT_PARSER

#include "base\usdsDictionary.h"

#include <sstream>

namespace usds
{
	class DictionaryTextParser
	{
	public:
		DictionaryTextParser() {};
		~DictionaryTextParser() {};

		void parse(const char* text_dict, Dictionary* dict) throw (...);

	};
	

};
#endif