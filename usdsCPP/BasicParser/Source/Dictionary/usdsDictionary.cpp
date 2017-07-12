#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryStruct.h"
#include "converters\usdsDictionaryBinaryCreator.h"

using namespace usds;

Dictionary::Dictionary(BasicParser* parent) : objectPool(this), binary(64)
{
	dictionaryID = 0;
	majorVersion = 0;
	minorVersion = 0;
	nameBufferSize = 128;
	dictName = new char[nameBufferSize];
};

Dictionary::~Dictionary()
{
	delete[] dictName;
};

//====================================================================================================================
// Dictionary construction
//====================================================================================================================
void Dictionary::setID(const char* name, uint32_t id, uint8_t major, uint8_t minor) throw (...)
{
	size_t name_size = strlen(name) + 1;
	if (name_size > nameBufferSize)
	{
		delete[] dictName;
		nameBufferSize = name_size;
		dictName = new char[nameBufferSize];
	}
#pragma warning(disable:4996)
	strcpy(dictName, name);
	dictionaryID = id;
	majorVersion = major;
	minorVersion = minor;
};

void Dictionary::setID(const char* name, size_t name_size, uint32_t id, uint8_t major, uint8_t minor) throw (...)
{
	if (name[name_size - 1] != 0)
		name_size++;
	if (name_size > nameBufferSize)
	{
		delete[] dictName;
		nameBufferSize = name_size;
		dictName = new char[nameBufferSize];
	}
	memcpy(dictName, name, name_size-1);
	dictName[name_size - 1] = 0;
	dictionaryID = id;
	majorVersion = major;
	minorVersion = minor;
};


//====================================================================================================================
// Tags construction
DictionaryBaseType* Dictionary::addTag(usdsTypes tag_type, int32_t id, const char* name, size_t name_size) throw (...)
try
{
	if (finalized)
		throw ErrorMessage(DICTIONARY__FINALIZED_ALREADY, "The dictionary is filalized already");

	if (tag_type == USDS_TAG)
		throw ErrorMessage(DICTIONARY__UNSUPPORTED_TYPE, "Tag type can not be TAG");
	
	// check name
	int32_t tag_id;
	tag_id = findTagID(name, name_size);
	if (tag_id != 0)
		throw (ErrorMessage(DICTIONARY__TAG_ALREADY_EXISTS) << "Tag with name '").addString(name, name_size) << "' already exists in dictionary.";
	
	// Create object
	DictionaryBaseType* tag = objectPool.addObject(tag_type, 0, id, name, name_size);
	connectTagToDictionary(tag);
	
	// update data for index
	tagNumber++;
	if (tagMaxID < id)
		tagMaxID = id;

	return tag;
}
catch (ErrorMessage& err)
{
	throw (ErrorStack("Dictionary::addTag") << tag_type << id).addStringAndSize(name, name_size) << err;
}
catch (ErrorStack& err)
{
	(err.addLevel("Dictionary::addTag") << tag_type << id).addStringAndSize(name, name_size);
	throw;
};

DictionaryBaseType* Dictionary::addField(usdsTypes field_type, DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw (...)
try
{
	if (finalized)
		throw ErrorMessage(DICTIONARY__FINALIZED_ALREADY, "The dictionary is filalized already");

	return objectPool.addObject(field_type, parent, id, name, name_size);
}
catch (ErrorMessage& err)
{
	throw ErrorStack("Dictionary::addField") << field_type << (void*)parent << id << name << name_size << err;
}
catch (ErrorStack& err)
{
	err.addLevel("Dictionary::addField") << field_type << (void*)parent << id << name << name_size;
	throw;
};


//====================================================================================================================
// Finalize
void Dictionary::finalizeDictionary() throw(...)
try
{
	if (finalized)
		throw ErrorMessage(DICTIONARY__FINALIZED_ALREADY, "The dictionary is filalized already");

	if (tagNumber == 0)
		throw ErrorMessage(DICTIONARY__NO_TAGS, "Dictionary can't be empty.");

	// Tag numeration must be sequentially
	if (tagMaxID != tagNumber)
		throw ErrorMessage(DICTIONARY__TAG_ID_ERROR_VALUE) << "Tag numeration must be sequentially. Tag number: " << tagNumber << ", wrong tag ID: " << tagMaxID;

	// Create Tag index
	tagIndex.reserve(tagNumber+1);
	tagIndex.assign(tagNumber+1, 0);
	DictionaryBaseType* tag = firstTag;

	while (tag != 0)
	{
		int32_t id = tag->getID();
		if (tagIndex[id] != 0)
			throw ErrorMessage(DICTIONARY__TAG_ID_ERROR_VALUE) << "Not unique tag ID: " << id;

		tagIndex[id] = tag;
		tag = tag->getNext();
	}
	indexed = true;

	// Sort tags
	firstTag = 0;
	lastTag = 0;
	for (int32_t i = 1; i <= tagNumber; i++)
	{
		connectTagToDictionary(tagIndex[i]);
	}
	
	// Finalize tags: replace TagName to TagID in Links, check errors
	for (int32_t i = 1; i <= tagNumber; i++)
	{
		(tagIndex[i])->finalize();
	}
	
	finalized = true;

}
catch (ErrorMessage& err)
{
	indexed = false;
	throw ErrorStack("Dictionary::finalizeDictionary") << err;
}
catch (ErrorStack& err)
{
	indexed = false;
	err.addLevel("Dictionary::finalizeDictionary");
	throw;
};

//====================================================================================================================
// Dictionary information
//====================================================================================================================
const char* Dictionary::getDictionaryName()
{
	return dictName;
};

uint32_t Dictionary::getDictionaryID()
{
	return dictionaryID;
};
uint8_t Dictionary::getMajorVersion()
{
	return majorVersion;
};
uint8_t Dictionary::getMinorVersion()
{
	return minorVersion;
};


//====================================================================================================================
DictionaryBaseType* Dictionary::getFirstTag() throw (...)
{
	if (firstTag == 0)
		throw ErrorStack("Dictionary::getFirstTag") << ErrorMessage(DICTIONARY__NO_TAGS, "Dictionary is empty.");

	return firstTag;
};

DictionaryBaseType* Dictionary::getLastTag() throw (...)
{
	if (firstTag == 0)
		throw ErrorStack("Dictionary::getLastTag") << ErrorMessage(DICTIONARY__NO_TAGS, "Dictionary is empty.");

	return lastTag;
};

//====================================================================================================================
int32_t Dictionary::findTagID(const char* name) throw (...)
{
	if (name == 0)
		throw ErrorStack("Dictionary::findTagID") << name << ErrorMessage(DICTIONARY__NULL_NAME, "Name can not be NULL");

	DictionaryBaseType* tag = firstTag;
	while (tag != 0)
	{
		if (strcmp(tag->getName(), name) == 0)
			return tag->getID();
		tag = tag->getNext();
	}
	
	// if not found
	return 0;
};

int32_t Dictionary::findTagID(const char* name, size_t name_size) throw (...)
{
	if (name == 0)
		throw ErrorStack("Dictionary::findTagID") << name << name_size << ErrorMessage(DICTIONARY__NULL_NAME, "Name can not be NULL");

	DictionaryBaseType* tag = firstTag;
	while (tag != 0)
	{
		if (name_size == 0)
		{
			if (strcmp(tag->getName(), name) == 0)
				return tag->getID();
		}
		else
		{
			if (strncmp(tag->getName(), name, name_size) == 0)
				return tag->getID();
		}
		tag = tag->getNext();
	}

	// if not found
	return 0;
};

DictionaryBaseType* Dictionary::findTag(const char* name) throw (...)
{
	if (name == 0)
		throw ErrorStack("Dictionary::findTag") << name << ErrorMessage(DICTIONARY__NULL_NAME, "Name can not be NULL");

	DictionaryBaseType* tag = firstTag;
	while (tag != 0)
	{
		if (strcmp(tag->getName(), name) == 0)
			return tag;
		tag = tag->getNext();
	}

	// if not found
	return 0;

};

DictionaryBaseType* Dictionary::findTag(const char* name, size_t name_size) throw (...)
{
	if (name == 0)
		throw ErrorStack("Dictionary::findTag") << name << name_size << ErrorMessage(DICTIONARY__NULL_NAME, "Name can not be NULL");

	DictionaryBaseType* tag = firstTag;
	while (tag != 0)
	{
		if (strncmp(tag->getName(), name, name_size) == 0)
			return tag;
		tag = tag->getNext();
	}

	// if not found
	return 0;

};

//====================================================================================================================

DictionaryBaseType* Dictionary::getTag(int32_t tag_id) throw (...)
try
{
	if (!indexed)
		throw ErrorMessage(DICTIONARY__NOT_INITIALIZED, "Dictionary not initialized");

	if (tag_id < 1 || tag_id > tagNumber)
		throw ErrorMessage(DICTIONARY__TAG_ID_ERROR_VALUE) << "Tag ID must be in range [1; " << tagNumber << "]. Current value:" << tag_id;

	return tagIndex[tag_id];
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("Dictionary::getTag") << tag_id << msg;
};

int32_t Dictionary::getTagNumber() throw (...)
{
	return tagNumber;
};

//====================================================================================================================
// encode

const uint8_t* Dictionary::getBinary(size_t* size) throw (...)
try
{
	if (!finalized)
		throw ErrorMessage(DICTIONARY__NOT_FINALIZED, "Dictionary not finalized");
	
	if (binary.getSize() == 0)
	{
		DictionaryBinaryCreator creator;
		creator.generate(&binary, this);
	}

	return binary.getBinary(size);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("Dictionary::getBinary") << size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("Dictionary::getBinary") << size;
	throw;
};

void Dictionary::setBinary(const void* data, size_t size) throw(...)
try
{
	binary.clear();
	binary.writeByteArray(data, size);

}
catch (ErrorStack& err)
{
	err.addLevel("Dictionary::setBinary") << data << size;
	throw;
};

//====================================================================================================================
// Dictionary clearing and initialisation
//====================================================================================================================
void Dictionary::clear()
{
	dictionaryID = 0;
	
	firstTag = 0;
	lastTag = 0;

	tagMaxID = 0;
	tagNumber = 0;
	tagIndex.clear();
	finalized = false;
	indexed = false;

	binary.clear();
	objectPool.clear();
};

//====================================================================================================================
// private

void Dictionary::connectTagToDictionary(DictionaryBaseType* tag)
{
	if (firstTag == 0)
		firstTag = tag;
	tag->setPrevious(lastTag);
	tag->setNext(0);
	if (lastTag != 0)
		lastTag->setNext(tag);
	lastTag = tag;
};
