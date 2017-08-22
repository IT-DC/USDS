#ifndef USDS_DICTIONARY_TEXT_PARSER_H
#define USDS_DICTIONARY_TEXT_PARSER_H

#include "usdsTypes.h"
#include "usdsErrors.h"

namespace usds
{
	class Dictionary;

	class DictionaryTextParser
	{
	public:
		DictionaryTextParser() {};
		~DictionaryTextParser() {};

		void parse(const char* text_dict, usdsEncode encode, Dictionary* dict) throw (...);

	};
	

};
#endif