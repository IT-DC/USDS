#include "base\usdsDictionary.h"

using namespace usds;

Dictionary::Dictionary()
{
	dictionaryEncode = USDS_NO_ENCODE;
	dictionaryID = -1;
};

Dictionary::~Dictionary()
{


};

//====================================================================================================================
// Dictionary construction
//====================================================================================================================
void Dictionary::setID(int id, unsigned char major, unsigned char minor) throw (...)
{
	clear();

	if (id < 0)
	{
		std::wstringstream err;
		err << L"Dictionary ID must be > 0. Your value: " << id;
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
{
	std::cout << "addStructTag(" << name << ", " << id << ", " << (root ? "true" : "false") << ")\n";

	DicStructTag* tag = 0;
	return tag;
};

DicBooleanField* Dictionary::addBooleanField(const char* name, int id, bool is_optional) throw (...)
{
	std::cout << "addBooleanField(" << name << ", " << id << ", " << (is_optional ? "true" : "false") << ")\n";


	DicBooleanField* field = 0;
	return field;
};

DicIntField* Dictionary::addIntField(const char* name, int id, bool is_optional) throw (...)
{
	std::cout << "addIntField(" << name << ", " << id << ", " << (is_optional ? "true" : "false") << ")\n";


	DicIntField* field = 0;
	return field;
};

DicLongField* Dictionary::addLongField(const char* name, int id, bool is_optional) throw (...)
{
	std::cout << "addLongField(" << name << ", " << id << ", " << (is_optional ? "true" : "false") << ")\n";


	DicLongField* field = 0;
	return field;
};

DicDoubleField* Dictionary::addDoubleField(const char* name, int id, bool is_optional) throw (...)
{
	std::cout << "addDoubleField(" << name << ", " << id << ", " << (is_optional ? "true" : "false") << ")\n";


	DicDoubleField* field = 0;
	return field;
};

DicUVarintField* Dictionary::addUVarintField(const char* name, int id, bool is_optional) throw (...)
{
	std::cout << "addUVarintField(" << name << ", " << id << ", " << (is_optional ? "true" : "false") << ")\n";


	DicUVarintField* field = 0;
	return field;
};

DicArrayField* Dictionary::addArrayField(const char* name, int id, bool is_optional, const char* tag_name) throw (...)
{
	std::cout << "addArrayField(" << name << ", " << id << ", " << (is_optional ? "true" : "false") << ", " << tag_name << ")\n";


	DicArrayField* field = 0;
	return field;
};

DicStringField* Dictionary::addStringField(const char* name, int id, bool is_optional) throw (...)
{
	std::cout << "addStringField(" << name << ", " << id << ", " << (is_optional ? "true" : "false") << ")\n";


	DicStringField* field = 0;
	return field;
};

void Dictionary::finalizeDictionary() throw(...)
{

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

//====================================================================================================================
// Dictionary clearing
//====================================================================================================================
void Dictionary::clear()
{
	dictionaryEncode = USDS_NO_ENCODE;
	dictionaryID = -1;
};