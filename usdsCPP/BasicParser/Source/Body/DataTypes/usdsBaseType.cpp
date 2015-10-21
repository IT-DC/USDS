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
	return parentDictionaryObject->getType();
};

const char* UsdsBaseType::getTypeName()
{
	return parentDictionaryObject->getTypeName();
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
	std::stringstream msg;
	msg << "Unsupported conversion from int to " << getTypeName();
	throw ErrorMessage(USDS_BASE_TYPE_UNSUPPORTED_CONVERTION, &msg, L"UsdsBaseType::setValue(int)");
};

void UsdsBaseType::setValue(long long value) throw (...)
{
	std::stringstream msg;
	msg << "Unsupported conversion from long long to " << getTypeName();
	throw ErrorMessage(USDS_BASE_TYPE_UNSUPPORTED_CONVERTION, &msg, L"UsdsBaseType::setValue(long long)");
};

void UsdsBaseType::setValue(double value) throw (...)
{
	std::stringstream msg;
	msg << "Unsupported conversion from double to " << getTypeName();
	throw ErrorMessage(USDS_BASE_TYPE_UNSUPPORTED_CONVERTION, &msg, L"UsdsBaseType::setValue(double)");
};

void UsdsBaseType::setValue(const char* value) throw (...)
{
	std::stringstream msg;
	msg << "Unsupported conversion from const char* to " << getTypeName();
	throw ErrorMessage(USDS_BASE_TYPE_UNSUPPORTED_CONVERTION, &msg, L"UsdsBaseType::setValue(const char*)");
};

void UsdsBaseType::setValue(bool value) throw (...)
{
	std::stringstream msg;
	msg << "Unsupported conversion from bool to " << getTypeName();
	throw ErrorMessage(USDS_BASE_TYPE_UNSUPPORTED_CONVERTION, &msg, L"UsdsBaseType::setValue(bool)");
};



