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

int32_t UsdsBaseType::getID() throw(...)
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

void UsdsBaseType::setValue(int32_t value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from int32_t to " << getTypeName());
};

void UsdsBaseType::setValue(int64_t value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from int64_t to " << getTypeName());
};

void UsdsBaseType::setValue(uint64_t value) throw (...)
{
	throw ErrorStack("UsdsBaseType::setValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from uint64_t to " << getTypeName());
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

void UsdsBaseType::getValue(int32_t* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to int32_t*");
};

void UsdsBaseType::getValue(int64_t* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to int64_t*");
};

void UsdsBaseType::getValue(uint64_t* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to uint64_t*");
};

void UsdsBaseType::getValue(double* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to double*");
};

void UsdsBaseType::getValue(const char** value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to const char**");
};

void UsdsBaseType::getValue(const char** value, size_t* size) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << size << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to const char**");
};

void UsdsBaseType::getValue(bool* value) throw (...)
{
	throw ErrorStack("UsdsBaseType::getValue") << value << (ErrorMessage(BODY_BASE_TYPE__UNSUPPORTED_CONVERTION) << "Unsupported conversion from " << getTypeName() << " to bool*");
};

