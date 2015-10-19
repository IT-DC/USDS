#include "dictionary\usdsDictionary.h"
#include "dictionary\dataTypes\dictionaryStruct.h"
#include "converters\usdsDictionaryBinaryCreator.h"

using namespace usds;

Dictionary::Dictionary()
{
	
};

Dictionary::~Dictionary()
{

};

//====================================================================================================================
// Dictionary construction
//====================================================================================================================
void Dictionary::setID(int id, unsigned char major, unsigned char minor) throw (...)
{
	if (id < 0)
	{
		std::wstringstream err;
		err << L"Dictionary ID must be >= 0. Your value: " << id;
		throw ErrorMessage(DICTIONARY_ID_ERROR_VALUE, &err, L"Dictionary::setID");
	}
	
	dictionaryID = id;
	majorVersion = major;
	minorVersion = minor;
};

void Dictionary::setEncode(usdsEncodes encode) throw (...)
{
	if (encode != USDS_UTF8)
	{
		std::wstringstream err;
		err << L"Unsupported encode, use USDS_UTF8. Your value: " << encode;
		throw ErrorMessage(DICTIONARY_UNSUPPORTABLE_ENCODE, &err, L"Dictionary::setID");
	};

	dictionaryEncode = encode;
};


//====================================================================================================================
// Tags construction
DictionaryBaseType* Dictionary::addTag(usdsTypes tag_type, int id, const char* name, size_t name_size) throw (...)
try
{
	// check type
	if (tag_type < 1 || tag_type > 31)
	{
		std::wstringstream msg;
		msg << L"Unsupported tag type '" << tag_type << "'";
		throw ErrorMessage(DICTIONARY_UNSUPPORTABLE_TYPE, &msg);
	}
	
	// check name
	int tag_id;
	if (name_size == 0)
		tag_id = findTagID(name);
	else
		tag_id = findTagID(name, name_size);
	if (tag_id != 0)
	{
		std::stringstream err;
		err << "Tag with name '" << name << "' not unique in dictionary.";
		throw ErrorMessage(DICTIONARY_TAG_ALREADY_EXISTS, &err);
	}
	
	// check ID
	if (id <= 0)
	{
		std::wstringstream err;
		err << L"Tag ID must be in range [1; 2,147,483,647]. Current value:" << id;
		throw ErrorMessage(DICTIONARY_TAG_ID_ERROR_VALUE, &err);
	}

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
	err.addPath(L"Dictionary::addTag");
	throw err;
};

//====================================================================================================================
// Fields construction

DictionaryBaseType* Dictionary::addField(usdsTypes field_type, DictionaryStruct* tag, int id, const char* name, size_t name_size) throw (...)
try
{
	return tag->addField(field_type, id, name, name_size);
}
catch (ErrorMessage& err)
{
	err.addPath(L"Dictionary::addField");
	throw err;
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
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getDictionaryID");
	return dictionaryID;
};
unsigned char Dictionary::getMajorVersion() throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getMajorVersion");
	return majorVersion;
};
unsigned char Dictionary::getMinorVersion() throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getMinorVersion");
	return minorVersion;
};
usdsEncodes Dictionary::getEncode() throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getEncode");
	return dictionaryEncode;
};

DictionaryBaseType* Dictionary::getFirstTag() throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getFirstTag");

	return firstTag;
};

DictionaryBaseType* Dictionary::getLastTag() throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getLastTag");

	return lastTag;
};

int Dictionary::findTagID(const char* name) throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
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
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
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
