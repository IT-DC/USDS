#include "body\dataTypes\usdsArray.h"

#include "base\objectPool\bodyObjectPool.h"
#include "dictionary\dataTypes\dictionaryArray.h"

using namespace usds;

UsdsArray::UsdsArray(BodyObjectPool* object_pool) : UsdsBaseType(object_pool)
{
	objectType = USDS_ARRAY;
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
try
{
	if (elementType != USDS_TAG)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_TAG) << "Array elements must be TAG, current value " << typeName(elementType);
	
	UsdsBaseType* element = objectPool->addObject(tagElement, this);
	elementValues.writeByteArray(&element, sizeof(size_t));
	elementNumber++;

	return element;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::addTagElement") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::addTagElement");
	throw;
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
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << number << "], element number = " << elementNumber;

	UsdsBaseType* tag;
	elementValues.readByteArray(number * sizeof(size_t), &tag, sizeof(size_t));
	return tag;

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getTagElement") << number << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getTagElement") << number;
	throw;
};

const void* UsdsArray::getArrayBinary() throw(...)
{

	return elementValues.getBinary();
};

size_t UsdsArray::getArrayBinarySize() throw(...)
{

	return elementValues.getSize();
};

void UsdsArray::setArrayBinary(const void* binary, size_t binary_size) throw(...)
try
{
	int element_size = typeSize(elementType);
	if (element_size == 0)
		throw ErrorMessage(BODY_ARRAY__UNFIXED_ELEMENT_SIZE) << "Element type '" << typeName(elementType) << "' is unfixed";
	elementValues.writeByteArray(binary, binary_size);
	elementNumber = binary_size / element_size;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::setArrayBinary") << binary << binary_size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::setArrayBinary") << binary << binary_size;
	throw;
};