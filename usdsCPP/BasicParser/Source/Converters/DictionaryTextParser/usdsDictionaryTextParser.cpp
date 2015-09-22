#include "converters\usdsDictionaryTextParser.h"
#include "flexDictionaryTextScanner.h"

using namespace usds;

void DictionaryTextParser::parse(const char* text_dict, usdsEncodes encode, Dictionary* dict) throw (...)
{
	if (encode != USDS_UTF8)
		throw ErrorMessage(TEXT_DICTIONARY_PARSER_UNSUPPORTABLE_ENCODE, L"Unsupportable encode for text dictionary", L"DictionaryTextParser::parse");

	dict->clear();

	std::stringstream input;
	std::stringstream output;
	input << text_dict;
	FlexDictionaryTextScanner scanner(&input, &output);
	
	std::stringstream errors;
	errors.clear();

	BisonDictionaryTextParser parser(dict, &scanner, &errors);
	int ret = parser.parse();

	dict->setEncode(encode);

	if (ret != 0)
	{
		dict->clear();
		throw ErrorMessage(TEXT_DICTIONARY_PARSER_ERROR, &errors, L"DictionaryTextParser::parse");
	}

};