#include "usdsBasicParser.h"

#include "dictionary\dataTypes\dictionaryStruct.h"

using namespace usds;

BasicParser::BasicParser() : usdsMajor(1), usdsMinor(0), dictionaryPool(this)
{
	currentDictionary = 0;
}

BasicParser::~BasicParser()
{
	

}

//====================================================================================================================
// Dictionary constructors
void BasicParser::addDictionaryFromText(const char* text_dictionary, size_t size, usdsEncode encode) throw(...)
try 
{
	Dictionary* dict = (Dictionary*)dictionaryPool.addObject();
	dict->clear();
	try
	{
		dictionaryTextParser.parse(text_dictionary, encode, dict);
	}
	catch(ErrorStack)
	{
		dict->remove();
		throw;
	}
	uint32_t id = dict->getDictionaryID();
	uint8_t major = dict->getMajorVersion();
	uint8_t minor = dict->getMinorVersion();

	if (findDictionary(id, major, minor) != 0)
		throw ErrorMessage(BASIC_PARSER__DICTIONARY_NOT_FOUND) << "Dictionary " << id << "." << uint32_t(major) << "." << uint32_t(minor) << " already exists";
	
	dictionaries.push_back(dict);
	currentDictionary = dict;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::addDictionaryFromText") << (void*)text_dictionary << size << encode << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::addDictionaryFromText") << (void*)text_dictionary << size << encode;
	throw;
};

void BasicParser::CurrentDictionaryToText(usdsEncode encode, std::string* text) throw(...)
try
{
	if (currentDictionary == 0)
		throw ErrorMessage(BASIC_PARSER__DICTIONARY_NOT_FOUND, "Current dictionary not set");
	dictionaryTextcreator.generate(encode, text, currentDictionary);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::CurrentDictionaryToText") << encode << text << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::CurrentDictionaryToText") << encode << text;
	throw;
}

//====================================================================================================================
// Working with several dictionaries

Dictionary* BasicParser::selectDictionary(int32_t id, uint8_t major, uint8_t minor) throw(...)
try
{
	Dictionary* object = findDictionary(id, major, minor);
	if (object == 0)
		throw ErrorMessage(BASIC_PARSER__DICTIONARY_NOT_FOUND) << "Dictionary ID=" << id << " v." << int(major) << "." << int(minor) << " not found";

	currentDictionary = object;

	return currentDictionary;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::selectDictionary") << id << major << minor << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::selectDictionary") << id << major << minor;
	throw;
}

Dictionary* BasicParser::selectFirstDictionary() throw(...)
try
{
	if (dictionaries.empty())
		throw ErrorMessage(BASIC_PARSER__NO_DICTIONARIES, "No dictionaries in the parser");

	currentDictionary = *(dictionaries.begin());
	return currentDictionary;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::selectFirstDictionary") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::selectFirstDictionary");
	throw;
};

Dictionary* BasicParser::selectNextDictionary() throw(...)
try
{
	if (dictionaries.empty())
		throw ErrorMessage(BASIC_PARSER__NO_DICTIONARIES, "No dictionaries in the parser");

	for (std::list<Dictionary*>::iterator it = dictionaries.begin(); it != dictionaries.end(); ++it)
	{
		if (currentDictionary == *it)
		{
			it++;
			if (it == dictionaries.end())
				return 0;
			currentDictionary = *it;
			return currentDictionary;
		}
	}
	return 0;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::selectNextDictionary") << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::selectNextDictionary");
	throw;
};
//====================================================================================================================
// Settings
int32_t BasicParser::getDictionaryID() throw(...)
try
{
	return currentDictionary->getDictionaryID();
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::getDictionaryID");
	throw;
}

uint8_t BasicParser::getDictionaryMajor() throw(...)
try
{
	return currentDictionary->getMajorVersion();
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::getDictionaryMajor");
	throw;
}

uint8_t BasicParser::getDictionaryMinor() throw(...)
try
{
	return currentDictionary->getMinorVersion();
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::getDictionaryMinor");
	throw;
}

const char* BasicParser::getDictionaryName() throw(...)
try
{
	return currentDictionary->getDictionaryName();
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::getDictionaryName");
	throw;
}

//====================================================================================================================
int32_t BasicParser::getTagID(const char* name) throw(...)
try
{

	return currentDictionary->findTagID(name);
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::getTagID") << name;
	throw;
}

int32_t BasicParser::getFieldID(int32_t tag_id, const char* name) throw(...)
try
{
	DictionaryBaseType* tag = currentDictionary->getTag(tag_id);
	return ((DictionaryStruct*)tag)->findFieldID(name);
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::getFieldID") << tag_id << name;
	throw;
};

UsdsBaseType* BasicParser::getFirstTag(const char* name) throw(...)
{

	return body.getFirstTag(currentDictionary->findTagID(name));
};

UsdsStruct* BasicParser::getFirstStructTag(const char* name) throw(...)
{
	UsdsBaseType* tag = body.getFirstTag(currentDictionary->findTagID(name));
	if (tag->getType() != USDS_STRUCT)
		throw ErrorMessage(BODY__ERROR_TAG_TYPE) << "Tag '" << name << "' has type " << tag->getTypeName();
	return (UsdsStruct*)tag;
};


//====================================================================================================================
// Body constructions
UsdsBaseType* BasicParser::addTag(int32_t id) throw(...)
try
{
	DictionaryBaseType* dict_tag = currentDictionary->getTag(id);
	return body.addTag(dict_tag);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::addTag") << id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::addTag") << id;
	throw;
};

UsdsStruct* BasicParser::addStructTag(const char* name) throw(...)
try
{
	DictionaryBaseType* dict_tag = currentDictionary->findTag(name);
	if (dict_tag == 0)
		throw ErrorMessage(BODY__TAG_NOT_FOUND) << "Tag name '" << name << "' is not found";
	if (dict_tag->getType() != USDS_STRUCT)
		throw ErrorMessage(BODY__ERROR_TAG_TYPE) << "Type of the tag '" << name << "' is not USDS_STRUCT (" << dict_tag->getTypeName() << ")";

	return (UsdsStruct*)body.addTag(dict_tag);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::addStructTag") << name << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::addStructTag") << name;
	throw;
};

UsdsStruct* BasicParser::addStructTag(int32_t id) throw(...)
try
{
	DictionaryBaseType* dict_tag = currentDictionary->getTag(id);
	if (dict_tag->getType() != USDS_STRUCT)
		throw ErrorMessage(BODY__ERROR_TAG_TYPE) << "Type of the tag with id=" << id << " is not USDS_STRUCT (" << dict_tag->getTypeName() << ")";

	return (UsdsStruct*)body.addTag(dict_tag);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::addStructTag") << id << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::addStructTag") << id;
	throw;
};

//====================================================================================================================
// Encode

void BasicParser::encode(BinaryOutput* buff, bool with_head, bool with_dictionary, bool with_body) throw(...)
try
{
	if (currentDictionary == 0)
		throw ErrorMessage(BASIC_PARSER__DICTIONARY_NOT_FOUND, "Dictionary is not selected");

	if (with_dictionary && with_body)
		binaryCreator.generate(buff, currentDictionary, (Body*)this);

}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::encode") << (void*)buff << with_head << with_dictionary << with_body << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::encode") << (void*)buff << with_head << with_dictionary << with_body;
	throw;
};

void BasicParser::getJSON(usdsEncode encode, std::string* text) throw(...)
try
{
	if (currentDictionary == 0)
		throw ErrorMessage(BASIC_PARSER__DICTIONARY_NOT_FOUND, "Dictionary is not selected");

	jsonCreator.generate(encode, text, &body);
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::getJSON") << encode << text << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::getJSON") << encode << text;
	throw;
};


//====================================================================================================================
// Decode

void BasicParser::decode(const uint8_t* data, size_t data_size) throw(...)
try
{
	binaryParser.setBinary(data, data_size);

	if (binaryParser.isHeadIncluded())
	{
		if (currentDictionary == 0)
		{
			Dictionary* dict = (Dictionary*)dictionaryPool.addObject();
			dict->clear();
			try
			{
				binaryParser.initDictionaryFromBinary(currentDictionary);
			}
			catch (ErrorStack)
			{
				dict->remove();
				throw;
			}
			dictionaries.push_back(dict);
			currentDictionary = dict;
		}
		else
		{
			int32_t dict_id = binaryParser.getDictionaryID();
			uint8_t dict_major = binaryParser.getDictionaryMajor();
			uint8_t dict_minor = binaryParser.getDictionaryMinor();
			if (currentDictionary->getDictionaryID() != dict_id || currentDictionary->getMajorVersion() != dict_major || currentDictionary->getMinorVersion() != dict_minor)
			{
				Dictionary* dict = findDictionary(dict_id, dict_major, dict_minor);
				if (dict == 0)
				{
					if (!binaryParser.isDictionaryIncluded())
						throw ErrorMessage(BASIC_PARSER__DICTIONARY_NOT_FOUND) << "Dictionary " << dict_id << "." << int(dict_major) << "." << int(dict_minor) << " not found";

					Dictionary* dict = (Dictionary*)dictionaryPool.addObject();
					dict->clear();
					try
					{
						binaryParser.initDictionaryFromBinary(currentDictionary);
					}
					catch (ErrorStack)
					{
						dict->remove();
						throw;
					}
					dictionaries.push_back(dict);
					currentDictionary = dict;
				}
				else
				{
					currentDictionary = dict;
				}
			}
		}
	}
	
	if (binaryParser.isBodyIncluded())
	{
		binaryParser.initBodyFromBinary(currentDictionary, (Body*)this);
	}
	
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::decode") << data << data_size << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::decode") << data << data_size;
	throw;
};



//====================================================================================================================
void BasicParser::clear()
{
	currentDictionary = 0;
	dictionaries.clear();
	dictionaryPool.clearPool();
	body.clear();

};

void BasicParser::clearBody()
{

	body.clear();
};

//====================================================================================================================
// private

Dictionary* BasicParser::findDictionary(int32_t id, uint8_t major, uint8_t minor) throw(...)
try
{
	for (std::list<Dictionary*>::iterator it = dictionaries.begin(); it != dictionaries.end(); it++)
	{
		if ((*it)->getDictionaryID() == id && (*it)->getMajorVersion() == major && (*it)->getMinorVersion() == minor)
			return *it;
	}

	// if not found
	return 0;

}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::findDictionary") << id << major << minor;
	throw;
};

