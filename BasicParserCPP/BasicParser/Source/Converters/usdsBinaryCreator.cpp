#include "converters\usdsBinaryCreator.h"
#include "binary\usdsBinaryOutput.h"
#include "dictionary\usdsDictionary.h"

#include "usdsTypes.h"
#include "usdsErrors.h"

using namespace usds;

BinaryCreator::BinaryCreator()
{

};

BinaryCreator::~BinaryCreator()
{

};

void BinaryCreator::generate(BinaryOutput* buff, Dictionary* dict, Body* body) throw(...)
try
{
	binary = buff;
	dictionary = dict;

	size_t dict_size = 0;
	const uint8_t* dict_binary = dict->getBinary(&dict_size);
	binary->writeSignature(USDS_DICTIONARY_SIGNATURE_WITH_SIZE);
	binary->writeUVarint(dict_size);
	binary->writeByteArray(dict_binary, dict_size);

	binary->writeSignature(USDS_BODY_SIGNATURE);
	bodyBinaryCreator.generate(binary, body);
	
	addHeadToBinary();
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryCreator::generate") << (void*)buff << (void*)dict << (void*)body;
	throw;
};

void BinaryCreator::addHeadToBinary() throw(...)
try
{
	// add document size
	binary->pushFrontSize();

	// add head
	binary->pushFrontUByte(dictionary->getMinorVersion());
	binary->pushFrontUByte(dictionary->getMajorVersion());
	binary->pushFrontUInt(dictionary->getDictionaryID());
	binary->pushFrontSignature(USDS_MINOR_VERSION);
	binary->pushFrontSignature(USDS_MAJOR_VERSION);
	binary->pushFrontSignature(USDS_MINOR_SIGNATURE);
	binary->pushFrontSignature(USDS_MAJOR_SIGNATURE);
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryCreator::addHeadToBinary");
	throw;
};