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

void BinaryCreator::generate(BinaryOutput* buff, Dictionary* dict) throw(...)
try
{
	binary = buff;
	dictionary = dict;

	size_t dict_size = 0;
	const unsigned char* dict_binary = dict->getBinary(&dict_size);
	binary->writeByte(USDS_DICTIONARY_SIGNATURE_WITH_SIZE);
	binary->writeUVarint(dict_size);
	binary->writeByteArray(dict_binary, dict_size);

	addHeadToBinary();

}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BinaryCreator::generate(BinaryOutput*,Dictionary*");
	throw msg;
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
	binary->pushFrontUByte(0); // USDS minor version
	binary->pushFrontUByte(1); // USDS major version
	binary->pushFrontUByte('S'); // USDS signature
	binary->pushFrontUByte('$');
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BinaryCreator::addHeadToBinary");
	throw msg;
};