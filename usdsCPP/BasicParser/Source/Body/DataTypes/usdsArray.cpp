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

	elementValues.writeByteArray(element, sizeof(size_t));


	return element;
};