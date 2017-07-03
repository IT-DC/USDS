#include "body\dataTypes\usdsArray.h"

#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryTagLink.h"

#include "dictionary\dataTypes\dictionaryShort.h"
#include "dictionary\dataTypes\dictionaryUShort.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryUInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryULong.h"
#include "dictionary\dataTypes\dictionaryFloat.h"
#include "dictionary\dataTypes\dictionaryDouble.h"

using namespace usds;

UsdsArray::UsdsArray(Body* parent_body) : UsdsBaseType(parent_body), elementValues(0)
{

}

UsdsArray::~UsdsArray()
{
}

//====================================================================================================================

size_t UsdsArray::getSize()
{
	return elementNumber;
};

void UsdsArray::setBufferSize(size_t buffer_size) throw(...)
try
{
	if (elementType == USDS_UVARINT || elementType == USDS_VARINT)
	{
		elementValues.setBufferSize(USDS_ULONG_SIZE * buffer_size);
	}
	else
	{
		if (elementSize == 0)
			elementValues.setBufferSize(sizeof(void*) * buffer_size);
		else
			elementValues.setBufferSize(elementSize * buffer_size);
	}
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::setBufferSize");
	throw;
};

size_t UsdsArray::getBufferSize()
{
	if (elementType == USDS_UVARINT || elementType == USDS_VARINT)
	{
		return elementValues.getBufferSize() / USDS_ULONG_SIZE;
	}
	else
	{
		if (elementSize == 0)
			return elementValues.getBufferSize() / sizeof(void*);
		else
			return elementValues.getBufferSize() / elementSize;
	}
}

usdsTypes UsdsArray::getElementType()
{

	return elementType;
};

const char* UsdsArray::getElementName()
{
	return arrayDictionaryElement->getName();
}

size_t UsdsArray::getElementNameSize()
{
	return arrayDictionaryElement->getNameSize();
}

int32_t UsdsArray::getElementId()
{
	return arrayDictionaryElement->getID();
}

bool UsdsArray::isBigendianElement()
{
	switch (elementType)
	{
	case USDS_SHORT:
		return ((DictionaryShort*)arrayDictionaryElement)->getBigendian();
	case USDS_USHORT:
		return ((DictionaryUShort*)arrayDictionaryElement)->getBigendian();
	case USDS_INT:
		return ((DictionaryInt*)arrayDictionaryElement)->getBigendian();
	case USDS_UINT:
		return ((DictionaryUInt*)arrayDictionaryElement)->getBigendian();
	case USDS_LONG:
		return ((DictionaryLong*)arrayDictionaryElement)->getBigendian();
	case USDS_ULONG:
		return ((DictionaryULong*)arrayDictionaryElement)->getBigendian();
	case USDS_FLOAT:
		return ((DictionaryFloat*)arrayDictionaryElement)->getBigendian();
	case USDS_DOUBLE:
		return ((DictionaryDouble*)arrayDictionaryElement)->getBigendian();
	default:
		return false;
	}

}

//====================================================================================================================
// pushBack

void UsdsArray::pushBack(bool value) throw (...)
try
{
	if (elementSize != 0)
		elementValues.write(elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.write(USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.write(USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Boolean, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";

	elementNumber++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value;
	throw;
};

void UsdsArray::pushBack(int8_t value) throw (...)
try
{
	if (elementSize != 0)
		elementValues.write(elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.write(USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.write(USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Boolean, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";

	elementNumber++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value;
	throw;
};

void UsdsArray::pushBack(uint8_t value) throw (...)
try
{
	if (elementSize != 0)
		elementValues.write(elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.write(USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.write(USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Boolean, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";

	elementNumber++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value;
	throw;
};

void UsdsArray::pushBack(int16_t value) throw (...)
try
{
	if (elementSize != 0)
		elementValues.write(elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.write(USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.write(USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Boolean, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";

	elementNumber++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value;
	throw;
};

void UsdsArray::pushBack(uint16_t value) throw (...)
try
{
	if (elementSize != 0)
		elementValues.write(elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.write(USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.write(USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Boolean, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";

	elementNumber++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value;
	throw;
};

void UsdsArray::pushBack(int32_t value) throw (...)
try
{
	if (elementSize != 0)
		elementValues.write(elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.write(USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.write(USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Boolean, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";

	elementNumber++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value;
	throw;
};

void UsdsArray::pushBack(uint32_t value) throw (...)
try
{
	if (elementSize != 0)
		elementValues.write(elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.write(USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.write(USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Boolean, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";

	elementNumber++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value;
	throw;
};

void UsdsArray::pushBack(int64_t value) throw (...)
try
{
	if (elementSize != 0)
		elementValues.write(elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.write(USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.write(USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Boolean, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";

	elementNumber++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value;
	throw;
};

void UsdsArray::pushBack(uint64_t value) throw (...)
try
{
	if (elementSize != 0)
		elementValues.write(elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.write(USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.write(USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Boolean, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";

	elementNumber++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value;
	throw;
};

void UsdsArray::pushBack(float value) throw (...)
try
{
	if (elementSize != 0)
		elementValues.write(elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.write(USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.write(USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Boolean, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";

	elementNumber++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value;
	throw;
};

void UsdsArray::pushBack(double value) throw (...)
try
{
	if (elementSize != 0)
		elementValues.write(elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.write(USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.write(USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Boolean, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";

	elementNumber++;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value;
	throw;
};

//====================================================================================================================
// getValue

void UsdsArray::getValue(size_t position, bool* value) throw (...)
try
{
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	if (elementSize != 0)
		elementValues.read(position * elementSize, elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.read(position * USDS_ULONG_SIZE, USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.read(position * USDS_LONG_SIZE, USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << position << value;
	throw;
};

void UsdsArray::getValue(size_t position, int8_t* value) throw (...)
try
{
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	if (elementSize != 0)
		elementValues.read(position * elementSize, elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.read(position * USDS_ULONG_SIZE, USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.read(position * USDS_LONG_SIZE, USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << position << value;
	throw;
};

void UsdsArray::getValue(size_t position, uint8_t* value) throw (...)
try
{
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	if (elementSize != 0)
		elementValues.read(position * elementSize, elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.read(position * USDS_ULONG_SIZE, USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.read(position * USDS_LONG_SIZE, USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << position << value;
	throw;
};

void UsdsArray::getValue(size_t position, int16_t* value) throw (...)
try
{
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	if (elementSize != 0)
		elementValues.read(position * elementSize, elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.read(position * USDS_ULONG_SIZE, USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.read(position * USDS_LONG_SIZE, USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << position << value;
	throw;
};

void UsdsArray::getValue(size_t position, uint16_t* value) throw (...)
try
{
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	if (elementSize != 0)
		elementValues.read(position * elementSize, elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.read(position * USDS_ULONG_SIZE, USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.read(position * USDS_LONG_SIZE, USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << position << value;
	throw;
};

void UsdsArray::getValue(size_t position, int32_t* value) throw (...)
try
{
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	if (elementSize != 0)
		elementValues.read(position * elementSize, elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.read(position * USDS_ULONG_SIZE, USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.read(position * USDS_LONG_SIZE, USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << position << value;
	throw;
};

void UsdsArray::getValue(size_t position, uint32_t* value) throw (...)
try
{
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	if (elementSize != 0)
		elementValues.read(position * elementSize, elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.read(position * USDS_ULONG_SIZE, USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.read(position * USDS_LONG_SIZE, USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << position << value;
	throw;
};

void UsdsArray::getValue(size_t position, int64_t* value) throw (...)
try
{
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	if (elementSize != 0)
		elementValues.read(position * elementSize, elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.read(position * USDS_ULONG_SIZE, USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.read(position * USDS_LONG_SIZE, USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << position << value;
	throw;
};

void UsdsArray::getValue(size_t position, uint64_t* value) throw (...)
try
{
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	if (elementSize != 0)
		elementValues.read(position * elementSize, elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.read(position * USDS_ULONG_SIZE, USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.read(position * USDS_LONG_SIZE, USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << position << value;
	throw;
};

void UsdsArray::getValue(size_t position, float* value) throw (...)
try
{
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	if (elementSize != 0)
		elementValues.read(position * elementSize, elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.read(position * USDS_ULONG_SIZE, USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.read(position * USDS_LONG_SIZE, USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << position << value;
	throw;
};

void UsdsArray::getValue(size_t position, double* value) throw (...)
try
{
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	if (elementSize != 0)
		elementValues.read(position * elementSize, elementType, value);
	else if (elementType == USDS_UVARINT)
		elementValues.read(position * USDS_ULONG_SIZE, USDS_ULONG, value);
	else if (elementType == USDS_VARINT)
		elementValues.read(position * USDS_LONG_SIZE, USDS_LONG, value);
	else
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_SIMPLE) << "Array element must be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use method pushElementBack.";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << position << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << position << value;
	throw;
};

//====================================================================================================================

UsdsBaseType* UsdsArray::pushElementBack() throw(...)
try
{
	if (elementSize != 0 || elementType == USDS_UVARINT || elementType == USDS_VARINT)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_DIFFICULT) << "Array element must not be Simple or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use methods PushBack.";

	UsdsBaseType* element = parentBody->addField(arrayDictionaryElement, this);
	elementValues.writePointer(element);
	elementNumber++;

	return element;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushElementBack") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushElementBack");
	throw;
};

UsdsBaseType* UsdsArray::getElement(size_t position) throw(...)
try
{
	if (elementSize != 0 || elementType == USDS_UVARINT || elementType == USDS_VARINT)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_DIFFICULT) << "Array element must not be Simple type or UVARINT or VARINT, current value " << usdsTypeName(elementType) << ". Use methods getValue.";
	
	if (position >= elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << position << "], element number = " << elementNumber;

	UsdsBaseType* element;
	elementValues.readPointer(position * sizeof(UsdsBaseType*), (void**)(&element));
	return element;

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getElement") << position << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getElement") << position;
	throw;
};

//====================================================================================================================

void UsdsArray::additionalInitObject()
try
{
	elementType = ((DictionaryArray*)parentDictionaryObject)->getElementType();
	if (elementType == USDS_TAG)
	{
		arrayDictionaryElement = ((DictionaryTagLink*)(((DictionaryArray*)parentDictionaryObject)->getElement()))->getTag();
		elementType = arrayDictionaryElement->getType();
	}
	else
	{
		arrayDictionaryElement = ((DictionaryArray*)parentDictionaryObject)->getElement();
	}
	elementSize = usdsTypeSize(elementType);
	
	elementNumber = 0;
	elementValues.clear();

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::additionalInitType") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::additionalInitType");
	throw;
};


