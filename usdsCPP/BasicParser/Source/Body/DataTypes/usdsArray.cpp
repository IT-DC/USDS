#include "body\dataTypes\usdsArray.h"

#include "body\usdsBody.h"
#include "dictionary\dataTypes\dictionaryArray.h"

using namespace usds;

UsdsArray::UsdsArray(Body* parent_body) : UsdsBaseType(parent_body)
{

}

UsdsArray::~UsdsArray()
{
}

//====================================================================================================================

size_t UsdsArray::getSize() throw(...)
{

	return elementNumber;
};

usdsTypes UsdsArray::getElementType() throw(...)
{

	return elementType;
};


//====================================================================================================================
// pushBack

void UsdsArray::pushBack(bool value) throw (...)
try
{
	switch (elementType)
	{

	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from bool to " << usdsTypeName(elementType);
	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(int8_t value) throw (...)
try
{
	switch (elementType)
	{
	case USDS_INT:
		elementValues.writeInt(value);
		elementNumber++;
		break;


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from int8_t to " << usdsTypeName(elementType);

	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(uint8_t value) throw (...)
try
{
	switch (elementType)
	{
	case USDS_INT:
		elementValues.writeInt(value);
		elementNumber++;
		break;


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from uint8_t to " << usdsTypeName(elementType);

	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(int16_t value) throw (...)
try
{
	switch (elementType)
	{
	case USDS_INT:
		elementValues.writeInt(value);
		elementNumber++;
		break;


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from int16_t to " << usdsTypeName(elementType);

	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(uint16_t value) throw (...)
try
{
	switch (elementType)
	{
	case USDS_INT:
		elementValues.writeInt(value);
		elementNumber++;
		break;


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from int16_t to " << usdsTypeName(elementType);

	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(int32_t value) throw (...)
try
{
	switch (elementType)
	{
	case USDS_INT:
		elementValues.writeInt(value);
		elementNumber++;
		break;


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from int32_t to " << usdsTypeName(elementType);

	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(uint32_t value) throw (...)
try
{
	switch (elementType)
	{
	case USDS_INT:
		if (value > 2147483647)
			throw ErrorStack("UsdsArray::setValue") << value << (ErrorMessage(BODY_ARRAY__TOO_BIG_VALUE) << "Value must be in range[-2147483648, 2147483647], current value : " << value);
		elementValues.writeInt(value);
		elementNumber++;
		break;


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from uint32_t to " << usdsTypeName(elementType);

	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(int64_t value) throw (...)
try
{
	switch (elementType)
	{
	case USDS_INT:
		if (value > 2147483647 || value < -2147483648ll)
			throw ErrorStack("UsdsArray::setValue") << value << (ErrorMessage(BODY_ARRAY__TOO_BIG_VALUE) << "Value must be in range[-2147483648, 2147483647], current value : " << value);
		elementValues.writeInt((int32_t)value);
		elementNumber++;
		break;


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from int64_t to " << usdsTypeName(elementType);

	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(uint64_t value) throw (...)
try
{
	switch (elementType)
	{
	case USDS_INT:
		if (value > 2147483647)
			throw ErrorStack("UsdsArray::setValue") << value << (ErrorMessage(BODY_ARRAY__TOO_BIG_VALUE) << "Value must be in range[-2147483648, 2147483647], current value : " << value);
		elementValues.writeInt((int32_t)value);
		elementNumber++;
		break;


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from uint64_t to " << usdsTypeName(elementType);

	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(float value) throw (...)
try
{
	switch (elementType)
	{


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from float to " << usdsTypeName(elementType);

	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(double value) throw (...)
try
{
	switch (elementType)
	{


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from double to " << usdsTypeName(elementType);

	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(const char* value) throw (...)
try
{
	switch (elementType)
	{


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from const char* to " << usdsTypeName(elementType);

	}

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

//------------------------------------------------------------------------------------------------------------

void UsdsArray::pushBack(const char* value, size_t size) throw (...)
try
{
	switch (elementType)
	{


	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from const char* to " << usdsTypeName(elementType);

	}

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushBack") << value << size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushBack") << value << size;
	throw;
};

//------------------------------------------------------------------------------------------------------------

UsdsBaseType* UsdsArray::pushTagBack() throw(...)
try
{
	if (elementType != USDS_TAG)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_TAG) << "Array element must be TAG, current value " << usdsTypeName(elementType);
	
	UsdsBaseType* element = parentBody->addField(arrayDictionaryElement, this);
	elementValues.writeByteArray(&element, sizeof(size_t));
	elementNumber++;

	return element;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::pushTagBack") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::pushTagBack");
	throw;
};



//====================================================================================================================
// getValue

void UsdsArray::getValue(size_t number, int32_t* value) throw (...)
try
{
	if (number > elementNumber)
		throw ErrorMessage(BODY_ARRAY__ELEMENT_NOT_FOUND) << "Can not find element [" << number << "], element number = " << elementNumber;

	switch (elementType)
	{
	case USDS_INT:
		elementValues.readInt(number * USDS_INT_SIZE, value);
		break;

	default:
		throw ErrorMessage(BODY_ARRAY__UNSUPPORTED_CONVERSION) << "Unsupported conversion for Element's type: from Int to " << usdsTypeName(elementType);

	}

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsArray::getValue") << number << value << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getValue") << number << value;
	throw;
};

void UsdsArray::getValue(size_t number, int64_t* value) throw (...)
{


};

void UsdsArray::getValue(size_t number, uint64_t* value) throw (...)
{


};

void UsdsArray::getValue(size_t number, double* value) throw (...)
{


};

void UsdsArray::getValue(size_t number, const char** value) throw (...)
{


};

void UsdsArray::getValue(size_t number, const char** value, size_t* size) throw (...)
{


};

void UsdsArray::getValue(size_t number, bool* value) throw (...)
{


};

UsdsBaseType* UsdsArray::getTag(size_t number) throw(...)
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
	throw ErrorStack("UsdsArray::getTag") << number << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsArray::getTag") << number;
	throw;
};

//====================================================================================================================

void UsdsArray::additionalInitObject()
try
{
	elementType = ((DictionaryArray*)parentDictionaryObject)->getElementType();
	arrayDictionaryElement = ((DictionaryArray*)parentDictionaryObject)->getElement();

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


