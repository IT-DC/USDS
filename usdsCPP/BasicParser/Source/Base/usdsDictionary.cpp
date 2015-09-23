#include "base\usdsDictionary.h"

#include "base\usdsBinaryInput.h"
#include "base\usdsBinaryOutput.h"
#include "tags\dicStructTag.h"
#include "tags\dicStructFields.h"

using namespace usds;

Dictionary::Dictionary()
{
	dictionaryEncode = USDS_NO_ENCODE;
	dictionaryID = -1;

	firstTag = 0;
	lastTag = 0;
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
DicStructTag* Dictionary::addStructTag(const char* name, int id, bool root) throw (...)
try
{
	checkTagAttribute(id, name);
	DicStructTag* tag = objectPool.addStructTag(name, id, root);
	connectTagToDictionary(tag);

	// update data for index
	tagNumber++;
	if (tagMaxID < id)
		tagMaxID = id;

	return tag;
}
catch (ErrorMessage& err)
{
	err.addPath(L"Dictionary::addStructTag");
	throw err;
};


//====================================================================================================================
// Fields construction

DicBooleanField* Dictionary::addBooleanField(const char* name, int id, bool is_optional) throw (...)
{
	DicBooleanField* field = objectPool.addBooleanField(name, id, is_optional);
	return field;
};

DicIntField* Dictionary::addIntField(const char* name, int id, bool is_optional) throw (...)
{
	DicIntField* field = objectPool.addIntField(name, id, is_optional);
	return field;
};

DicLongField* Dictionary::addLongField(const char* name, int id, bool is_optional) throw (...)
{
	DicLongField* field = objectPool.addLongField(name, id, is_optional);
	return field;
};

DicDoubleField* Dictionary::addDoubleField(const char* name, int id, bool is_optional) throw (...)
{
	DicDoubleField* field = objectPool.addDoubleField(name, id, is_optional);
	return field;
};

DicUVarintField* Dictionary::addUVarintField(const char* name, int id, bool is_optional) throw (...)
{
	DicUVarintField* field = objectPool.addUVarintField(name, id, is_optional);
	return field;
};

DicArrayField* Dictionary::addArrayField(const char* name, int id, bool is_optional, const char* tag_name) throw (...)
{
	DicArrayField* field = objectPool.addArrayField(name, id, is_optional, tag_name);
	return field;
};

DicStringField* Dictionary::addStringField(const char* name, int id, bool is_optional, usdsEncodes encode) throw (...)
{
	DicStringField* field = objectPool.addStringField(name, id, is_optional, encode);
	return field;
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
	DicBaseTag* tag = firstTag;
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
		tag = tag->getNextTag();
	}
	// Finalize tags: replace TagName to TagID in Links, check errors
	tag = firstTag;
	while (tag != 0)
	{
		switch (tag->getType())
		{
		case USDS_STRUCT:
			((DicStructTag*)tag)->finalizeTag(firstTag);
			break;
		default:
			break;
		}

		tag = tag->getNextTag();
	}

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

DicBaseTag* Dictionary::getFirstTag() throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getFirstTag");

	return firstTag;
};

DicBaseTag* Dictionary::getLastTag() throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getLastTag");

	return lastTag;
};

int Dictionary::findTagID(const char* name) throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getTagID");
	
	DicBaseTag* tag = firstTag;
	while (tag != 0)
	{
		if (strcmp(tag->getName(), name) == 0)
			return tag->getID();
		tag = tag->getNextTag();
	}
	
	// if not found
	return 0;
};

//====================================================================================================================
// Dictionary clearing
//====================================================================================================================
void Dictionary::clear()
{
	dictionaryEncode = USDS_NO_ENCODE;
	dictionaryID = -1;
	
	objectPool.clear();

	firstTag = 0;
	lastTag = 0;

	tagMaxID = 0;
	tagNumber = 0;
	tagIndex.clear();
};

//====================================================================================================================
// private

void Dictionary::connectTagToDictionary(DicBaseTag* tag)
{
	if (firstTag == 0)
	{
		firstTag = tag;
		lastTag = tag;
	}
	else
	{
		tag->setPreviousTag(lastTag);
		lastTag->setNextTag(tag);
		lastTag = tag;
	}
};

void Dictionary::checkTagAttribute(int id, const char* name) throw (...)
{
	if (findTagID(name) != 0)
	{
		std::stringstream err;
		err << "Tag with name '" << name << "' not unique in dictionary.";
		throw ErrorMessage(DICTIONARY_TAG_ALREADY_EXISTS, &err, L"Dictionary::checkTagAttribute");
	}

	if (id <= 0 )
	{
		std::wstringstream err;
		err << L"Tag ID must be in range [1; 2,147,483,647]. Current value:" << id;
		throw ErrorMessage(DICTIONARY_TAG_ID_ERROR_VALUE, &err, L"Dictionary::checkTagAttribute");
	}

};