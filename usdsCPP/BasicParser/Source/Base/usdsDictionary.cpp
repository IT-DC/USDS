#include "base\usdsDictionary.h"

#include "base\usdsBinaryInput.h"
#include "base\usdsBinaryOutput.h"
#include "tags\dicStructTag.h"
#include "tags\dicStructFields.h"

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
DicBaseTag* Dictionary::addTag(usdsTypes tag_type, bool root, int id, const char* name, size_t name_size) throw (...)
try
{
	// check ID
	if (tag_type < 1 || tag_type > 32)
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
		throw ErrorMessage(DICTIONARY_TAG_ALREADY_EXISTS, &err, L"Dictionary::checkTagAttribute");
	}
	
	// check ID
	if (id <= 0)
	{
		std::wstringstream err;
		err << L"Tag ID must be in range [1; 2,147,483,647]. Current value:" << id;
		throw ErrorMessage(DICTIONARY_TAG_ID_ERROR_VALUE, &err, L"Dictionary::checkTagAttribute");
	}

	// Create object
	DicBaseTag* tag = objectPool.addTag(tag_type, this, root, id, name, name_size);
	connectTagToDictionary(tag);
	
	// update data for index
	tagNumber++;
	if (tagMaxID < id)
		tagMaxID = id;

	return 0;
}
catch (ErrorMessage& err)
{
	err.addPath(L"Dictionary::addTag");
	throw err;
};

//====================================================================================================================
// Fields construction

DicBaseField* Dictionary::addField(usdsTypes field_type, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional) throw (...)
try
{
	if (field_type < 1 || field_type > 32 || field_type == USDS_STRUCT)
	{
		std::wstringstream msg;
		msg << L"Unsupported field type '" << field_type << "'";
		throw ErrorMessage(DICTIONARY_UNSUPPORTABLE_TYPE, &msg);
	}
	
	// check ID
	if (id <= 0)
	{
		std::wstringstream err;
		err << L"Tag ID must be in range [1; 2,147,483,647]. Current value:" << id;
		throw ErrorMessage(DICTIONARY_TAG_ID_ERROR_VALUE, &err, L"Dictionary::checkTagAttribute");
	}

	// Create object
	DicBaseField* field = objectPool.addField(field_type, this, tag, id, name, name_size, is_optional);
	
	return field;
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
	firstTag = 0;
	lastTag = 0;
	for (int i = 0; i < tagNumber; i++)
	{
		tag = tagIndex[i];
		switch (tag->getType())
		{
		case USDS_STRUCT:
			((DicStructTag*)tag)->finalizeTag();
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

int Dictionary::findTagID(const char* name, size_t name_size) throw (...)
{
	if (dictionaryEncode == USDS_NO_ENCODE || dictionaryID < 0)
		throw ErrorMessage(DICTIONARY_NOT_INITIALIZED, L"Dictionary not initialized", L"Dictionary::getTagID");

	DicBaseTag* tag = firstTag;
	while (tag != 0)
	{
		if (strncmp(tag->getName(), name, name_size) == 0)
			return tag->getID();
		tag = tag->getNextTag();
	}

	// if not found
	return 0;
};

DicBaseTag* Dictionary::getTag(int id) throw (...)
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
	if (!binaryExists)
	{
		if (!finalized)
		{
			throw ErrorMessage(DICTIONARY_NOT_FINALIZED, L"Dictionary not finalized");
		}

		// Write text encode
		binaryDictionary.writeUVarint(unsigned int(dictionaryEncode));

		// Write tags
		for (int i = 0; i < tagNumber; i++)
		{
			DicBaseTag* tag = tagIndex[i];
			if (tag->getRootStatus())
				binaryDictionary.writeUByte('r');
			else
				binaryDictionary.writeUByte('t');
			binaryDictionary.writeUVarint(tag->getID());
			size_t size = tag->getNameSize();
			binaryDictionary.writeUVarint(size);
			binaryDictionary.writeByteArray((void*)tag->getName(), size);
			binaryDictionary.writeUVarint(USDS_STRUCT);
			// write specific Tag parameters
			tag->writeToBinary(&binaryDictionary);
		}

		binaryExists = true;
	}

	const unsigned char* buff = binaryDictionary.getBinary(size);
	return buff;
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"Dictionary::getBinary");
	throw msg;
};

//====================================================================================================================
// decode
void Dictionary::initFromBinary(const void* buff, size_t size)
try
{
	BinaryInput input_buff;
	input_buff.setBinary((const unsigned char*)buff, size);

	// read text encode
	int encode;
	input_buff.readUVarint(&encode);
	setEncode((usdsEncodes)encode);

	// read tags
	while (!input_buff.isEnd())
	{
		// read signature
		unsigned char signature = input_buff.readByte();
		switch (signature)
		{
		case 't':
		case 'r':
			{
				// read main attributes
				int tag_id;
				input_buff.readUVarint(&tag_id);
				size_t name_size;
				input_buff.readUVarint(&name_size);
				const void* name = input_buff.readByteArray(name_size);
				int tag_type;
				input_buff.readUVarint(&tag_type);
				DicBaseTag* tag = addTag((usdsTypes)tag_type, ((signature == 'r') ? true : false), tag_id, (const char*)name, name_size);
				// read specific attributes
				tag->initFromBinary(&input_buff);
				// update data for indexes
				tagNumber++;
				if (tagMaxID < tag_id)
					tagMaxID = tag_id;
				break;
			}
		default:
			std::wstringstream msg;
			msg << L"Unexpected signature '" << signature << L"'";
			throw ErrorMessage(DICTIONARY_UNKNOWN_FORMAT, &msg);
		};
	};

	// check errors, create indexes
	finalizeDictionary();

	// binary input == binary output
	binaryDictionary.writeByteArray(buff, size);
	binaryExists = true;

}
catch (ErrorMessage& msg)
{
	msg.addPath(L"Dictionary::initFromBinary");
	throw msg;
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

	binaryDictionary.clear();
	binaryExists = false;
};

//====================================================================================================================
// private

void Dictionary::connectTagToDictionary(DicBaseTag* tag)
{
	if (firstTag == 0)
		firstTag = tag;
	tag->setPreviousTag(lastTag);
	tag->setNextTag(0);
	if (lastTag != 0)
		lastTag->setNextTag(tag);
	lastTag = tag;
};
