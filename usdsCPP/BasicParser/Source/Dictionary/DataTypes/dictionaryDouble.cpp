#include "dictionary\dataTypes\dictionaryDouble.h"

using namespace usds;

DictionaryDouble::DictionaryDouble(Dictionary* dict) : DictionaryBaseType(dict)
{

};

void DictionaryDouble::additionalInitType()
{
	isBigendian = false;
};

