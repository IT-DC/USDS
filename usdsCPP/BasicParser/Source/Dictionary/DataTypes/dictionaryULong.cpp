#include "dictionary\dataTypes\dictionaryULong.h"

using namespace usds;

DictionaryULong::DictionaryULong(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryULong::additionalInitType()
{
	isBigendian = false;
};

