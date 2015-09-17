#include "base\usdsDictionary.h"

using namespace usds;

Dictionary::Dictionary(int id, unsigned char major, unsigned char minor) : dictionaryID(id), majorVersion(major), minorVersion(minor)
{
	dictionaryEncode = NO_ENCODE;

};

Dictionary::~Dictionary()
{


};

void Dictionary::clean()
{

};

//====================================================================================================================
// Dictionary constructors
//====================================================================================================================
// Create dictionary from classes
DicStructTag* Dictionary::addStructTag(const char* name, int id, bool root) throw (...)
{
	
	std::cout << "addStructTag(" << name << ", " << id << ', ' << root << std::endl;

	DicStructTag* tag = 0;
	return tag;
};

void Dictionary::finalizeDictionary() throw(...)
{

};
