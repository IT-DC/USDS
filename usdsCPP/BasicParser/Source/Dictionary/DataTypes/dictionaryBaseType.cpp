#include "dictionary\dataTypes\dictionaryBaseType.h"

using namespace usds;

void DictionaryBaseType::init(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...)
{
	nextObject = 0;
	previousObject = 0;

	clear();

	dictionary = dict;
	parentObject = parent;

	if (name_size == 0)
		objectName = name;
	else
		objectName.assign(name, name_size);
	objectID = id;
	
	isRoot = (parent == 0);
	
};

const char* DictionaryBaseType::getName() throw(...)
{

	return objectName.c_str();
};

size_t DictionaryBaseType::getNameSize() throw(...)
{

	return objectName.size();
};

int DictionaryBaseType::getID() throw(...)
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

