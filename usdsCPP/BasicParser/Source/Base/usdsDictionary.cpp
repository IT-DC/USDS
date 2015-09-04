#include "base\usdsDictionary.h"

using namespace usds;

Dictionary::Dictionary()
{
	dictionaryID = 0;
	majorVersion = 0;
	minorVersion = 0;
	dictionaryEncode = NO_ENCODE;

};
Dictionary::~Dictionary()
{


};

void Dictionary::clean()
{
	dictionaryID = 0;
	majorVersion = 0;
	minorVersion = 0;

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
