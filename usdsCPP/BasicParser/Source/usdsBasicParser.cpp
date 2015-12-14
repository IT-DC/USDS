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
void BasicParser::addDictionaryFromText(const char* text_dictionary, int size, usdsEncodes encode) throw(...)
try 
{
	dictionaryTextParser.parse(text_dictionary, encode, this);
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::initDictionaryFromText") << (void*)text_dictionary << size << encode;
	throw;
};

void BasicParser::CurrentDictionaryToText(usdsEncodes encode, std::string* text) throw(...)
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

Dictionary* BasicParser::addNewDictionary(int id, unsigned char major, unsigned char minor) throw(...)
try
{
	Dictionary* object = findDictionary(id, major, minor);
	if (object != 0)
		throw ErrorMessage(BASIC_PARSER__DICTIONARY_NOT_FOUND) << "Dictionary ID=" << id << " v." << int(major) << "." << int(minor) << " already exists";
	
	object = dictionaryPool.addObject();
	dictionaries.push_back(object);
	object->clear();
	object->setID(id, major, minor);
	currentDictionary = object;

	return object;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("BasicParser::addNewDictionary") << id << major << minor << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::addNewDictionary") << id << major << minor;
	throw;
}

//====================================================================================================================
// Working with several dictionaries

void BasicParser::selectDictionary(int id, unsigned char major, unsigned char minor) throw(...)
try
{
	Dictionary* object = findDictionary(id, major, minor);
	if (object == 0)
		throw ErrorMessage(BASIC_PARSER__DICTIONARY_NOT_FOUND) << "Dictionary ID=" << id << " v." << int(major) << "." << int(minor) << " not found";

	currentDictionary = object;
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


//====================================================================================================================
// Settings
int BasicParser::getDictionaryID() throw(...)
try
{
	return currentDictionary->getDictionaryID();
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::getDictionaryID");
	throw;
}

unsigned char BasicParser::getDictionaryMajor() throw(...)
try
{
	return currentDictionary->getMajorVersion();
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::getDictionaryMajor");
	throw;
}

unsigned char BasicParser::getDictionaryMinor() throw(...)
try
{
	return currentDictionary->getMinorVersion();
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::getDictionaryMinor");
	throw;
}

//====================================================================================================================
int BasicParser::getTagID(const char* name) throw(...)
try
{

	return currentDictionary->findTagID(name);
}
catch (ErrorStack& err)
{
	err.addLevel("BasicParser::getTagID") << name;
	throw;
}

int BasicParser::getFieldID(int tag_id, const char* name) throw(...)
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

void BasicParser::getJSON(usdsEncodes encode, std::string* text) throw(...)
try
{
	if (currentDictionary == 0)
		throw ErrorMessage(BASIC_PARSER__DICTIONARY_NOT_FOUND, "Dictionary is not selected");
	if (getFirstTag() == 0)
		throw ErrorMessage(BASIC_PARSER__BODY_IS_EMPTY, "Body is empty");

	jsonCreator.generate(encode, text, (Body*)this);
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

void BasicParser::decode(const unsigned char* data, size_t data_size) throw(...)
try
{
	binaryParser.setBinary(data, data_size);

	if (binaryParser.isHeadIncluded())
	{
		int dict_id = binaryParser.getDictionaryID();
		unsigned char dict_major = binaryParser.getDictionaryMajor();
		unsigned char dict_minor = binaryParser.getDictionaryMinor();
		if (currentDictionary == 0)
		{
			addNewDictionary(dict_id, dict_major, dict_minor);
			binaryParser.initDictionaryFromBinary(currentDictionary);
		}
		else
		{
			if (currentDictionary->getDictionaryID() != dict_id || currentDictionary->getMajorVersion() != dict_major || currentDictionary->getMinorVersion() != dict_minor)
			{
				Dictionary* dict = findDictionary(dict_id, dict_major, dict_minor);
				if (dict == 0)
				{
					if (!binaryParser.isDictionaryIncluded())
						throw ErrorMessage(BASIC_PARSER__DICTIONARY_NOT_FOUND) << "Dictionary ID=" << dict_id << " v." << int(dict_major) << "." << int(dict_minor) << " not found";

					addNewDictionary(dict_id, dict_major, dict_minor);
					binaryParser.initDictionaryFromBinary(currentDictionary);
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
		binaryParser.initBodyFromBinary((Body*)this);
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
	clearBody();

};

//====================================================================================================================
// private

Dictionary* BasicParser::findDictionary(int id, unsigned char major, unsigned char minor) throw(...)
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

