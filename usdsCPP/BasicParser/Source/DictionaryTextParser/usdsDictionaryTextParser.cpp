#include "internalParsers\usdsDictionaryTextParser.h"
#include "flexDictionaryTextScanner.h"

using namespace usds;

void DictionaryTextParser::parse(const char* text_dict, Dictionary* dict) throw (...)
{
	std::stringstream input;
	std::stringstream output;
	input << text_dict;
	FlexDictionaryTextScanner scanner(&input, &output);
	
	BisonDictionaryTextParser parser(dict, &scanner);
	int ret = parser.parse();
//	if (ret != 0)


};