#include "base\usdsDictionary.h"

using namespace usds;

Dictionary::Dictionary()
{
	dictionaryID = 0;
	majorVersion = 0;
	minorVersion = 0;
	dictionaryEncode = NO_ENCODE;

};
Dictionary::~Dictionary()
{


};

void Dictionary::clean()
{
	dictionaryID = 0;
	majorVersion = 0;
	minorVersion = 0;

};

//====================================================================================================================
// Dictionary constructors
//====================================================================================================================
// Create dictionary from classes
DicStructTag* Dictionary::addStructTag(const char* name, int id, bool root) throw (...)
{
	DicStructTag* tag = 0;
	return tag;
};

void Dictionary::finalizeDictionary() throw(...)
{

};
//====================================================================================================================
// Create dictionary from objects
void Dictionary::initFromText(const char * text_dictionary, int size) throw(...)
try
{
	DictionaryTextParser* textParser = 0;
//	textParser = new DictionaryTextParser(text_dictionary, size, encode);

	//initDictionary(textParser);

}
catch (ErrorMessage& msg)
{
	msg.addPath(L"Dictionary::initFromText");
	throw msg;
};

/*void Dictionary::initDictionary(DictionaryBaseParser* parser) throw(...)
try
{
	// try to read Head
	// parser returns error if HEAD isn't found
	dictionaryTokens token = parser->readFirstToken();
	parser->getTokenValue(&dictionaryID);
	// next token must be Version
	parser->readNextToken();
	parser->getTokenValue(&majorVersion);
	parser->readNextToken();
	parser->getTokenValue(&minorVersion);







}
catch (ErrorMessage& msg)
{
	msg.addPath(L"Dictionary::initDictionary");
	throw msg;
};*/