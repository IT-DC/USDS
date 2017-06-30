#include "dictionary\dataTypes\dictionaryUInt.h"

using namespace usds;

DictionaryUInt::DictionaryUInt(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryUInt::additionalInitType()
{
	isBigendian = false;
};

