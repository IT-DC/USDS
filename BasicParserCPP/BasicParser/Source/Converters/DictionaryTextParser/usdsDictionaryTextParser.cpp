#include "converters\usdsDictionaryTextParser.h"
#include "flexDictionaryTextScanner.h"

#include "dictionary\usdsDictionary.h"

#include <sstream>


using namespace usds;

void DictionaryTextParser::parse(const char* text_dict, usdsEncode encode, Dictionary* dict) throw (...)
try
{
	if (encode != USDS_UTF8)
		throw ErrorMessage(DICTIONARY_TEXT_PARSER__UNSUPPORTABLE_ENCODE, "Unsupportable encode for text dictionary: ") << encode;

	// remove UTF-8 BOM
	if (text_dict[0] == '\xEF' && text_dict[1] == '\xBB' && text_dict[2] == '\xBF')
		text_dict = text_dict + 3;

	// Creating scanner and parser
	std::stringstream input;
	std::stringstream output;
	input << text_dict;
	FlexDictionaryTextScanner scanner(&input, &output);
	
	BisonDictionaryTextParser textParser(text_dict, dict, &scanner, 0, 0);
	// Parse!
	textParser.parse();
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryTextParser::parse") << (void*)text_dict << encode << (void*)dict << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryTextParser::parse") << (void*)text_dict << encode << (void*)dict;
	throw;
}