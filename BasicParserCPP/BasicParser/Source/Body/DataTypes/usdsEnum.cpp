#include "body\dataTypes\usdsEnum.h"

#include "dictionary\dataTypes\dictionaryEnum.h"

#include "binary/usdsTypeConverter.h"

using namespace usds;

UsdsEnum::UsdsEnum(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsEnum::~UsdsEnum()
{

}

void UsdsEnum::setValue(int8_t value) throw (...)
try
{
	usdsTypeWrite(value, subType, (uint8_t*)(&objectValue));
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsEnum::setValue") << value;
	throw;
};




void UsdsEnum::additionalInitObject()
{
	if (((DictionaryEnum*)parentDictionaryObject)->hasDefaultValue())
		objectValue = ((DictionaryEnum*)parentDictionaryObject)->getDefaultValue();

	subType = ((DictionaryEnum*)parentDictionaryObject)->getSubtype();
};

usdsType UsdsEnum::getSubtype()
{
	return subType;
}

bool UsdsEnum::isSubtypeBigendian()
{
	return ((DictionaryEnum*)parentDictionaryObject)->isSubtypeBigendian();
}

