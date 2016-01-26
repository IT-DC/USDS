#include "body\dataTypes\usdsArray.h"

#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryArray.h"

using namespace usds;

UsdsArray::UsdsArray(Body* parent_body) : UsdsBaseType(parent_body)
{
	objectType = USDS_ARRAY;
}

UsdsArray::~UsdsArray()
{
}

//====================================================================================================================

size_t UsdsArray::getElementNumber() throw(...)
{

	return elementNumber;
};

usdsTypes UsdsArray::getElementType() throw(...)
{

	return elementType;
};


//====================================================================================================================

void UsdsArray::addElement(int value) throw (...)
try
{
	switch (elementType)
	{
	case USDS_INT:
		elementValues.writeInt(value);
		elementNumber++;
		break;


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from Int to " << typeName(elementType);

	}

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::addElement") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::addElement") << value;
	throw;
};

void UsdsArray::addElement(long long value) throw (...)
{


};

void UsdsArray::addElement(unsigned long long value) throw (...)
{


};

void UsdsArray::addElement(double value) throw (...)
{


};

void UsdsArray::addElement(const char* value) throw (...)
{


};

void UsdsArray::addElement(const char* value, size_t size) throw (...)
{


};

void UsdsArray::addElement(bool value) throw (...)
{


};

UsdsBaseType* UsdsArray::addTagElement() throw(...)
try
{
	if (elementType != USDS_TAG)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_TAG) << "Array elements must be TAG, current value " << typeName(elementType);
	
	UsdsBaseType* element = parentBody->addField(arrayDictionaryElement, this);
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



//====================================================================================================================

int UsdsArray::getElementIntValue(size_t number) throw (...)
try
{
	if (number > elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << number << "], element number = " << elementNumber;

	int value;

	switch (elementType)
	{
	case USDS_INT:
		elementValues.readInt(number * USDS_INT_SIZE, &value);
		return value;

	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from Int to " << typeName(elementType);

	}

return value;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getElementIntValue") << number << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getElementIntValue") << number;
	throw;
};

long long UsdsArray::getElementLongValue(size_t number) throw (...)
{
	long long value = 0;




	return value;
};

unsigned long long UsdsArray::getElementULongValue(size_t number) throw (...)
{
	unsigned long long value = 0;




	return value;
};

double UsdsArray::getElementDoubleValue(size_t number) throw (...)
{
	double value = 0;




	return value;
};

const char* UsdsArray::getElementStringValue(size_t number) throw (...)
{
	const char* value = 0;




	return value;
};

const char* UsdsArray::getElementStringValue(size_t number, size_t* size) throw (...)
{
	const char* value = 0;




	return value;
};

bool UsdsArray::getElementBooleanValue(size_t number) throw (...)
{
	bool value = false;




	return value;
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



//====================================================================================================================
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

//====================================================================================================================

void UsdsArray::initType()
try
{
	elementType = ((DictionaryArray*)parentDictionaryObject)->getElementType();
	arrayDictionaryElement = ((DictionaryArray*)parentDictionaryObject)->getElement();

	elementNumber = 0;
	elementValues.clear();

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::initType") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::initType");
	throw;
};