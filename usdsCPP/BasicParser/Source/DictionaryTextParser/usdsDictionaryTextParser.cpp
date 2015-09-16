#include "internalParsers\usdsDictionaryTextParser.h"
#include "flexDictionaryTextScanner.h"

using namespace usds;

void DictionaryTextParser::parse(const char* text_dict, Dictionary* dict) throw (...)
{
	std::stringstream input;
	std::stringstream output;
	input << text_dict;
	FlexDictionaryTextScanner scanner(&input, &output);
	
	std::stringstream errors;
	errors.clear();

	BisonDictionaryTextParser parser(dict, &scanner, &errors);
	
	int ret = parser.parse();

	if (ret != 0)
		throw ErrorMessage(TEXT_DICTIONARY_PARSER_ERROR, &errors, L"DictionaryTextParser::parse");


};