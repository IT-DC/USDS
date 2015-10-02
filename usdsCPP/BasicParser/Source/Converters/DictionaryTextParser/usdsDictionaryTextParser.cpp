#include "converters\usdsDictionaryTextParser.h"
#include "flexDictionaryTextScanner.h"

using namespace usds;

void DictionaryTextParser::parse(const char* text_dict, usdsEncodes encode, BasicParser* usdsParser) throw (...)
{
	if (encode != USDS_UTF8)
		throw ErrorMessage(TEXT_DICTIONARY_PARSER_UNSUPPORTABLE_ENCODE, L"Unsupportable encode for text dictionary", L"DictionaryTextParser::parse");

	// Creating scanner and parser
	std::stringstream input;
	std::stringstream output;
	input << text_dict;
	FlexDictionaryTextScanner scanner(&input, &output);
	
	std::stringstream errors;
	errors.clear();
	BisonDictionaryTextParser textParser(usdsParser, &scanner, &errors, encode, 0, 0, 0);

	// Parse!
	int ret = textParser.parse();
	if (ret != 0)
		throw ErrorMessage(TEXT_DICTIONARY_PARSER_ERROR, &errors, L"DictionaryTextParser::parse");

};