#include "body\dataTypes\usdsArray.h"

#include "base\objectPool\bodyObjectPool.h"
#include "dictionary\dataTypes\dictionaryArray.h"

using namespace usds;

UsdsArray::UsdsArray(BodyObjectPool* object_pool) : UsdsBaseType(object_pool)
{
}

UsdsArray::~UsdsArray()
{
}

void UsdsArray::clear()
{
	elementType = ((DictionaryArray*)parentDictionaryObject)->getElementType();

	switch (elementType)
	{
	case USDS_TAG:
		tagElement = ((DictionaryArray*)parentDictionaryObject)->getElementTag();



	}

	elementNumber = 0;
	elementValues.clear();

}

UsdsBaseType* UsdsArray::addTagElement() throw(...)
{
	if (elementType != USDS_TAG)
	{
		std::stringstream msg;
		msg << "Array elements must be TAG, current value " << typeName(elementType);
		throw ErrorMessage(USDS_ARRAY_ELEMENT_NOT_TAG, &msg, L"UsdsArray::addTagElement");
	}
	
	UsdsBaseType* element = objectPool->addObject(tagElement, this);
	elementValues.writeByteArray(&element, sizeof(size_t));
	elementNumber++;

	return element;
};

size_t UsdsArray::getElementNumber() throw(...)
{

	return elementNumber;
};

usdsTypes UsdsArray::getElementType() throw(...)
{

	return elementType;
};

UsdsBaseType* UsdsArray::getTagElement(size_t number) throw(...)
try
{
	if (number > elementNumber)
	{
		std::stringstream msg;
		msg << "Can not find element [" << number << "], element number = " << elementNumber;
		throw ErrorMessage(USDS_ARRAY_ELEMENT_NOT_TAG, &msg);
	}

	UsdsBaseType* tag;
	elementValues.readByteArray(number * sizeof(size_t), &tag, sizeof(size_t));
	return tag;

}
catch (ErrorMessage &msg)
{
	msg.addPath(L"UsdsArray::getTagElement");
	throw msg;
};

const void* UsdsArray::getArrayBinary() throw(...)
{

	return elementValues.getBinary();
};

size_t UsdsArray::getArrayBinarySize() throw(...)
{

	return elementValues.getSize();
};