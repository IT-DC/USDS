#include "tags\dicBaseTag.h"

#include "base\usdsDictionary.h"
#include "base\usdsBinaryOutput.h"

using namespace usds;

DicBaseTag::DicBaseTag()
{
	
};

void DicBaseTag::init(Dictionary* dict, const char* name, int id, bool root) throw(...)
{
	nextTag = 0;
	previousTag = 0;
	clear();

	dictionary = dict;

	tagName = name;
	tagID = id;
	isRoot = root;
};

DicBaseTag* DicBaseTag::getNextTag() throw(...)
{
	return nextTag;
};

DicBaseTag* DicBaseTag::getPreviousTag() throw(...)
{
	return previousTag;

};

void DicBaseTag::setNextTag(DicBaseTag* next)
{
	nextTag = next;

};
void DicBaseTag::setPreviousTag(DicBaseTag* previous)
{
	previousTag = previous;
};

const char* DicBaseTag::getName() throw(...)
{
	return tagName.c_str();
};

size_t DicBaseTag::getNameSize() throw(...)
{

	return tagName.size();
};

int DicBaseTag::getID() throw(...)
{
	return tagID;

};
