#include "dictionary\dictionaryBaseType.h"

using namespace usds;

void DictionaryBaseType::initType(DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...)
try
{
	if (name == 0)
		throw ErrorMessage(DIC_BASE_TYPE__NULL_NAME, "Name can not be NULL");
	
	if (id <= 0)
		throw ErrorMessage(DIC_BASE_TYPE__TAG_ID_ERROR_VALUE) << "ID must be in range [1; 2,147,483,647]. Current value: " << id;

	// TODO check name by regular expression

	nextObject = 0;
	previousObject = 0;

	additionalInitType();

	parentObject = parent;

	if (name_size == 0)
		objectName = name;
	else
		objectName.assign(name, name_size);
	objectID = id;
	
	isRoot = (parent == 0);
	
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryBaseType::initType") << (void*)parent << id << name << name_size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryBaseType::initType") << (void*)parent << id << name << name_size;
	throw;
};

const char* DictionaryBaseType::getName() throw(...)
{

	return objectName.c_str();
};

size_t DictionaryBaseType::getNameSize() throw(...)
{

	return objectName.size();
};

int32_t DictionaryBaseType::getID() throw(...)
{

	return objectID;
};

DictionaryBaseType* DictionaryBaseType::getNext() throw (...)
{

	return nextObject;
};

DictionaryBaseType* DictionaryBaseType::getPrevious() throw (...)
{

	return previousObject;
};

DictionaryBaseType* DictionaryBaseType::getParent() throw (...)
{

	return parentObject;
};

void DictionaryBaseType::setNext(DictionaryBaseType* next)
{

	nextObject = next;
};

void DictionaryBaseType::setPrevious(DictionaryBaseType* previous)
{

	previousObject = previous;
};

void DictionaryBaseType::setParent(DictionaryBaseType* parent)
{

	parentObject = parent;
};

void DictionaryBaseType::setRoot(bool is_root) throw(...)
{

	isRoot = is_root;
};

