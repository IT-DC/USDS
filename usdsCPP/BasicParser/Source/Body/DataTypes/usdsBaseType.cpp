#include "body\dataTypes\usdsBaseType.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

using namespace usds;

UsdsBaseType::UsdsBaseType(BodyObjectPool* object_pool)
{
	objectPool = object_pool;
}

UsdsBaseType::~UsdsBaseType()
{
}

void UsdsBaseType::init(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
{
	nextObject = 0;
	previousObject = 0;

	parentDictionaryObject = dict_parent;
	parentObject = body_parent;

	clear();

};

const char* UsdsBaseType::getName() throw(...)
{
	return parentDictionaryObject->getName();
};

size_t UsdsBaseType::getNameSize() throw(...)
{
	return parentDictionaryObject->getNameSize();
};

int UsdsBaseType::getID() throw(...)
{
	return parentDictionaryObject->getID();
};

usdsTypes UsdsBaseType::getType()
{
	return objectType;
};

const char* UsdsBaseType::getTypeName()
{
	return typeName(objectType);
};


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

void UsdsBaseType::setValue(int value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from int to " << getTypeName());
};

void UsdsBaseType::setValue(long long value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from long long to " << getTypeName());
};

void UsdsBaseType::setValue(unsigned long long value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from unsigned long long to " << getTypeName());
};

void UsdsBaseType::setValue(double value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from double to " << getTypeName());
};

void UsdsBaseType::setValue(const char* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from const char* to " << getTypeName());
};

void UsdsBaseType::setValue(const char* value, size_t size) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue").addStringAttribute(value, size) << size << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from const char* to " << getTypeName());
};

void UsdsBaseType::setValue(bool value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from bool to " << getTypeName());
};

//=============================================================================================

int UsdsBaseType::getIntValue() throw (...)
{
	throw ErrorStack("UsdsBaseType::getIntValue") << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to int");
};

long long UsdsBaseType::getLongValue() throw (...)
{
	throw ErrorStack("UsdsBaseType::getLongValue") << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to long long");
};

unsigned long long UsdsBaseType::getULongValue() throw (...)
{
	throw ErrorStack("UsdsBaseType::getULongValue") << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to unsigned long long");
};

double UsdsBaseType::getDoubleValue() throw (...)
{
	throw ErrorStack("UsdsBaseType::getDoubleValue") << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to double");
};

const char* UsdsBaseType::getStringValue() throw (...)
{
	throw ErrorStack("UsdsBaseType::getStringValue") << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to const char*");
};

const char* UsdsBaseType::getStringValue(size_t* size) throw (...)
{
	throw ErrorStack("UsdsBaseType::getStringValue") << size << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to const char*");
};

bool UsdsBaseType::getBooleanValue() throw (...)
{
	throw ErrorStack("UsdsBaseType::getBooleanValue") << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to bool");
};

