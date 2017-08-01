#include "body\usdsBaseType.h"

#include "dictionary\dictionaryBaseType.h"

using namespace usds;

UsdsBaseType::UsdsBaseType(Body* parent_body)
{
	parentBody = parent_body;
}

UsdsBaseType::~UsdsBaseType()
{
}

void UsdsBaseType::initObject(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	if (dict_parent == 0)
		throw ErrorMessage(BODY_BASE_TYPE__NULL_DICTIONARY_TAG, "Dictionary tag can not be NULL");
	
	nextObject = 0;
	previousObject = 0;

	parentDictionaryObject = dict_parent;
	parentObject = body_parent;

	additionalInitObject();

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsBaseType::additionalInitObject") << (void*)dict_parent << (void*)body_parent << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsBaseType::additionalInitObject") << (void*)dict_parent << (void*)body_parent;
	throw;
};

const char* UsdsBaseType::getName() throw(...)
{
	return parentDictionaryObject->getName();
};

size_t UsdsBaseType::getNameSize() throw(...)
{
	return parentDictionaryObject->getNameSize();
};

int32_t UsdsBaseType::getID() throw(...)
{
	return parentDictionaryObject->getID();
};

//=============================================================================================

UsdsBaseType* UsdsBaseType::getNext() throw (...)
{
	return nextObject;
};

UsdsBaseType* UsdsBaseType::getPrevious() throw (...)
{
	return previousObject;
};

UsdsBaseType* UsdsBaseType::getParent() throw (...)
{
	return parentObject;
};


void UsdsBaseType::setNext(UsdsBaseType* next)
{
	nextObject = next;
};

void UsdsBaseType::setPrevious(UsdsBaseType* previous)
{
	previousObject = previous;

};

void UsdsBaseType::setParent(UsdsBaseType* parent)
{
	parentObject = parent;
};

//=============================================================================================

void UsdsBaseType::setValue(bool value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from bool to " << getTypeName());
};

void UsdsBaseType::setValue(int8_t value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from int8_t to " << getTypeName());
};

void UsdsBaseType::setValue(uint8_t value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from uint8_t to " << getTypeName());
};

void UsdsBaseType::setValue(int16_t value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from int16_t to " << getTypeName());
};

void UsdsBaseType::setValue(uint16_t value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from uint16_t to " << getTypeName());
};

void UsdsBaseType::setValue(int32_t value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from int32_t to " << getTypeName());
};

void UsdsBaseType::setValue(uint32_t value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from uint32_t to " << getTypeName());
};

void UsdsBaseType::setValue(int64_t value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from int64_t to " << getTypeName());
};

void UsdsBaseType::setValue(uint64_t value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from uint64_t to " << getTypeName());
};

void UsdsBaseType::setValue(float value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from float to " << getTypeName());
};

void UsdsBaseType::setValue(double value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from double to " << getTypeName());
};

//=============================================================================================

void UsdsBaseType::getValue(bool* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from " << getTypeName() << " to bool*");
};

void UsdsBaseType::getValue(int8_t* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from " << getTypeName() << " to int8_t*");
};

void UsdsBaseType::getValue(uint8_t* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from " << getTypeName() << " to uint8_t*");
};

void UsdsBaseType::getValue(int16_t* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from " << getTypeName() << " to int16_t*");
};

void UsdsBaseType::getValue(uint16_t* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from " << getTypeName() << " to uint16_t*");
};

void UsdsBaseType::getValue(int32_t* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from " << getTypeName() << " to int32_t*");
};

void UsdsBaseType::getValue(uint32_t* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from " << getTypeName() << " to uint32_t*");
};

void UsdsBaseType::getValue(int64_t* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from " << getTypeName() << " to int64_t*");
};

void UsdsBaseType::getValue(uint64_t* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from " << getTypeName() << " to uint64_t*");
};

void UsdsBaseType::getValue(float* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from " << getTypeName() << " to float*");
};

void UsdsBaseType::getValue(double* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion from " << getTypeName() << " to double*");
};


