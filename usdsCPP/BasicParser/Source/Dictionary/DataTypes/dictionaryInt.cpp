#include "dictionary\dataTypes\dictionaryInt.h"

using namespace usds;

DictionaryInt::DictionaryInt(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryInt::additionalInitType()
{
	isBigendian = false;
};

