#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryStruct.h"
#include "converters\usdsDictionaryBinaryCreator.h"

using namespace usds;

Dictionary::Dictionary(BasicParser* parent)
{
	
};

Dictionary::~Dictionary()
{

};

//====================================================================================================================
// Dictionary construction
//====================================================================================================================
void Dictionary::setID(int id, unsigned char major, unsigned char minor) throw (...)
try
{
	if (id < 0)
		throw ErrorMessage(DICTIONARY__ID_ERROR_VALUE) << "Dictionary ID must be >= 0. Your value: " << id;
	
	dictionaryID = id;
	majorVersion = major;
	minorVersion = minor;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("Dictionary::setID") << id << major << minor;

};

//====================================================================================================================
// Tags construction
DictionaryBaseType* Dictionary::addTag(usdsTypes tag_type, int id, const char* name, size_t name_size) throw (...)
try
{
	// check type
	if (tag_type <= USDS_TAG || tag_type >= USDS_LAST_TYPE)
		throw ErrorMessage(DICTIONARY__UNSUPPORTED_TYPE) << "Unsupported tag type '" << tag_type << "'";

	// check ID
	if (id <= 0)
		throw ErrorMessage(DICTIONARY__TAG_ID_ERROR_VALUE) << "Tag ID must be in range [1; 2,147,483,647]. Current value: " << id;

	// check name
	int tag_id;
	if (name_size == 0)
		tag_id = findTagID(name);
	else
		tag_id = findTagID(name, name_size);
	if (tag_id != 0)
		throw ErrorMessage(DICTIONARY__TAG_ALREADY_EXISTS) << "Tag with name '" << name << "' not unique in dictionary.";
	
	// Create object
	DictionaryBaseType* tag = objectPool.addObject(tag_type, this, 0, id, name, name_size);
	connectTagToDictionary(tag);
	
	// update data for index
	tagNumber++;
	if (tagMaxID < id)
		tagMaxID = id;

	return tag;
}
catch (ErrorMessage& err)
{
	throw ErrorStack("Dictionary::addTag") << tag_type << id << name << name_size << err;
}
catch (ErrorStack& err)
{
	err.addLevel("Dictionary::addTag") << tag_type << id << name << name_size;
	throw;
};


//====================================================================================================================
// Finalize
void Dictionary::finalizeDictionary() throw(...)
{
	// Tag numeration must be sequentially
	if (tagMaxID != tagNumber)
	{
		std::wstringstream err;
		err << L"Tag numeration must be sequentially. Tag number: " << tagNumber << ", wrong tag ID: " << tagMaxID;
		throw ErrorMessage(DICTIONARY_TAG_ID_ERROR_VALUE, &err, L"Dictionary::finalizeDictionary");
	}
	// Create Tag index
	tagIndex.reserve(tagNumber);
	tagIndex.assign(tagNumber, 0);
	DictionaryBaseType* tag = firstTag;
	while (tag != 0)
	{
		int id = tag->getID();
		if (tagIndex[id - 1] != 0)
		{
			std::wstringstream err;
			err << L"Not unique tag ID: " << id;
			throw ErrorMessage(DICTIONARY_TAG_ID_ERROR_VALUE, &err, L"Dictionary::finalizeDictionary");
		}
		tagIndex[id - 1] = tag;
		tag = tag->getNext();
	}
	// Finalize tags: replace TagName to TagID in Links, check errors
	firstTag = 0;
	lastTag = 0;
	for (int i = 0; i < tagNumber; i++)
	{
		tag = tagIndex[i];
		switch (tag->getType())
		{
		case USDS_STRUCT:
			((DictionaryStruct*)tag)->finalize();
			break;
		default:
			break;
		}
		connectTagToDictionary(tagIndex[i]);
	}
	
	finalized = true;

};

//====================================================================================================================
// Dictionary information
//====================================================================================================================
int Dictionary::getDictionaryID()  throw (...)
{
	if (dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getDictionaryID");
	return dictionaryID;
};
unsigned char Dictionary::getMajorVersion() throw (...)
{
	if (dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getMajorVersion");
	return majorVersion;
};
unsigned char Dictionary::getMinorVersion() throw (...)
{
	if (dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getMinorVersion");
	return minorVersion;
};

DictionaryBaseType* Dictionary::getFirstTag() throw (...)
{
	if (dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getFirstTag");

	return firstTag;
};

DictionaryBaseType* Dictionary::getLastTag() throw (...)
{
	if (dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getLastTag");

	return lastTag;
};

int Dictionary::findTagID(const char* name) throw (...)
{
	if (dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getTagID");
	
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

int Dictionary::findTagID(const char* name, size_t name_size) throw (...)
{
	if (dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getTagID");

	DictionaryBaseType* tag = firstTag;
	while (tag != 0)
	{
		if (strncmp(tag->getName(), name, name_size) == 0)
			return tag->getID();
		tag = tag->getNext();
	}

	// if not found
	return 0;
};

DictionaryBaseType* Dictionary::findTag(const char* name) throw (...)
{
	if (dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getTagID");

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
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getTagID");

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

DictionaryBaseType* Dictionary::getTag(int id) throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getTag");

	if (id > tagNumber)
		return 0;

	if (id < 0)
	{
		std::wstringstream err;
		err << L"Tag ID must be in range [1; 2,147,483,647]. Current value:" << id;
		throw ErrorMessage(DICTIONARY_TAG_ID_ERROR_VALUE, &err, L"Dictionary::getTag");
	}

	return tagIndex[id - 1];
};

int Dictionary::getTagNumber() throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getTagNumber");

	return tagNumber;
};

//====================================================================================================================
// encode

const unsigned char* Dictionary::getBinary(size_t* size) throw (...)
try
{
	if (!finalized)
		throw ErrorMessage(DICTIONARY_NOT_FINALIZED, L"Dictionary not finalized");


	if (binary.isEmpty())
	{
		DictionaryBinaryCreator creator;
		creator.generate(&binary, this);
	}

	return binary.getBinary(size);

}
catch (ErrorMessage& msg)
{
	msg.addPath(L"Dictionary::getBinary");
	throw msg;
};

void Dictionary::setBinary(const void* data, size_t size)
{
	binary.clear();
	binary.writeByteArray(data, size);

};

//====================================================================================================================
// Dictionary clearing and initialisation
//====================================================================================================================
void Dictionary::clear()
{
	dictionaryEncode = USDS_NO_ENCODE;
	dictionaryID = -1;
	
	firstTag = 0;
	lastTag = 0;

	tagMaxID = 0;
	tagNumber = 0;
	tagIndex.clear();
	finalized = false;

	binary.clear();
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
