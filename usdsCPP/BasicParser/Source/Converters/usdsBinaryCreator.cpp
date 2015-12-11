#include "converters\usdsBinaryCreator.h"
#include "base\binary\usdsBinaryOutput.h"
#include "dictionary\usdsDictionary.h"

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

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
	const unsigned char* dict_binary = dict->getBinary(&dict_size);
	binary->writeByte(USDS_DICTIONARY_SIGNATURE_WITH_SIZE);
	binary->writeUVarint(dict_size);
	binary->writeByteArray(dict_binary, dict_size);

	binary->writeByte(USDS_BODY_SIGNATURE);
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
	binary->pushFrontInt(dictionary->getDictionaryID());
	binary->pushFrontUByte(USDS_MINOR_VERSION);
	binary->pushFrontUByte(USDS_MAJOR_VERSION);
	binary->pushFrontUByte(USDS_MINOR_SIGNATURE);
	binary->pushFrontUByte(USDS_MAJOR_SIGNATURE);
}
catch (ErrorStack& err)
{
	err.addLevel("BinaryCreator::addHeadToBinary");
	throw;
};