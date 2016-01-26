#include "body\dataTypes\usdsBaseType.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

using namespace usds;

UsdsBaseType::UsdsBaseType(Body* parent_body)
{
	parentBody = parent_body;
}

UsdsBaseType::~UsdsBaseType()
{
}

void UsdsBaseType::init(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...)
try
{
	if (dict_parent == 0)
		throw ErrorMessage(BODY_BASE_TYPE__NULL_DICTIONARY_TAG, "Dictionary tag can not be NULL");
	
	nextObject = 0;
	previousObject = 0;

	parentDictionaryObject = dict_parent;
	parentObject = body_parent;

	initType();

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("UsdsBaseType::init") << (void*)dict_parent << (void*)body_parent << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("UsdsBaseType::init") << (void*)dict_parent << (void*)body_parent;
	throw;
};;

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

