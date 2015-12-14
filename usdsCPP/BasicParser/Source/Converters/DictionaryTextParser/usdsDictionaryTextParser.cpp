#include "converters\usdsDictionaryTextParser.h"
#include "flexDictionaryTextScanner.h"

#include "dictionary\usdsDictionary.h"
#include "usdsBasicParser.h"

using namespace usds;

void DictionaryTextParser::parse(const char* text_dict, usdsEncodes encode, BasicParser* usdsParser) throw (...)
try
{
	if (encode != USDS_UTF8)
		throw ErrorMessage(DICTIONARY_TEXT_PARSER__UNSUPPORTABLE_ENCODE, "Unsupportable encode for text dictionary: ") << encode;

	// Creating scanner and parser
	std::stringstream input;
	std::stringstream output;
	input << text_dict;
	FlexDictionaryTextScanner scanner(&input, &output);
	
	std::stringstream errors;
	BisonDictionaryTextParser textParser(usdsParser, &scanner, &errors, 0, 0, 0);

	// Parse!
	int ret = textParser.parse();
	if (ret != 0)
		throw ErrorMessage(DICTIONARY_TEXT_PARSER__ERROR, errors.str().c_str());

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryTextParser::parse") << (void*)text_dict << encode << (void*)usdsParser << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryTextParser::parse") << (void*)text_dict << encode << (void*)usdsParser;
	throw;
}