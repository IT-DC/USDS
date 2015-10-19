#include "converters\usdsDictionaryTextCreator.h"

#include "dictionary\usdsDictionary.h"

#include "dictionary\dataTypes\dictionaryArray.h"
#include "dictionary\dataTypes\dictionaryBoolean.h"
#include "dictionary\dataTypes\dictionaryDouble.h"
#include "dictionary\dataTypes\dictionaryInt.h"
#include "dictionary\dataTypes\dictionaryLong.h"
#include "dictionary\dataTypes\dictionaryString.h"
#include "dictionary\dataTypes\dictionaryUVarint.h"
#include "dictionary\dataTypes\dictionaryStruct.h"

using namespace usds;

DictionaryTextCreator::DictionaryTextCreator()
{
	writeIndex[USDS_NO_TYPE] = 0;
	writeIndex[USDS_BOOLEAN] = &DictionaryTextCreator::writeBoolean;
	writeIndex[USDS_BYTE] = 0;
	writeIndex[USDS_UNSIGNED_BYTE] = 0;
	writeIndex[USDS_SHORT] = 0;
	writeIndex[USDS_UNSIGNED_SHORT] = 0;
	writeIndex[USDS_BIGENDIAN_SHORT] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	writeIndex[USDS_INT] = &DictionaryTextCreator::writeInt;
	writeIndex[USDS_UNSIGNED_INT] = 0;
	writeIndex[USDS_BIGENDIAN_INT] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	writeIndex[USDS_LONG] = &DictionaryTextCreator::writeLong;
	writeIndex[USDS_UNSIGNED_LONG] = 0;
	writeIndex[USDS_BIGENDIAN_LONG] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	writeIndex[USDS_INT128] = 0;
	writeIndex[USDS_UNSIGNED_INT128] = 0;
	writeIndex[USDS_BIGENDIAN_INT128] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	writeIndex[USDS_FLOAT] = 0;
	writeIndex[USDS_BIGENDIAN_FLOAT] = 0;
	writeIndex[USDS_DOUBLE] = &DictionaryTextCreator::writeDouble;
	writeIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	writeIndex[USDS_VARINT] = 0;
	writeIndex[USDS_UNSIGNED_VARINT] = &DictionaryTextCreator::writeUVarint;
	writeIndex[USDS_ARRAY] = &DictionaryTextCreator::writeArray;
	writeIndex[USDS_STRING] = &DictionaryTextCreator::writeString;
	writeIndex[USDS_LIST] = 0;
	writeIndex[USDS_MAP] = 0;
	writeIndex[USDS_POLYMORPH] = 0;
	writeIndex[USDS_STRUCT] = &DictionaryTextCreator::writeStruct;
	writeIndex[USDS_TAG] = 0;
};

void DictionaryTextCreator::generate(usdsEncodes encode, std::string* text, Dictionary* dict) throw (...)
try
{
	if (encode != USDS_UTF8)
	{
		std::wstringstream err;
		err << L"Unsupported encode, use USDS_UTF8. Your value: " << encode;
		throw ErrorMessage(TEXT_DICTIONARY_CREATOR_UNSUPPORTABLE_ENCODE, &err);
	};

	textBuff.clear();

	textBuff << "USDS DICTIONARY ID=" << dict->getDictionaryID() << " v." << int(dict->getMajorVersion()) << "." << int(dict->getMinorVersion()) << "\n";
	textBuff << "{\n";
	// get all tags
	for (int tag_id = 1; tag_id <= dict->getTagNumber(); tag_id++)
	{
		DictionaryBaseType* tag = dict->getTag(tag_id);
		textBuff << "\t" << tag->getID() << ": " << tag->getTypeName();
		// write specific Tag parameters
		(this->*(writeIndex[tag->getType()]))(tag);
	}
	textBuff << "}";

	*text = textBuff.str();
}
catch (ErrorMessage& err)
{
	err.addPath(L"DictionaryTextCreator::generate");
	throw err;
};

//========================================================================================


void DictionaryTextCreator::writeStruct(DictionaryBaseType* object)
{
	textBuff << " " << object->getName() << "\n\t{\n";
	int fieldNumber = ((DictionaryStruct*)object)->getFieldNumber();
	for (int i = 1; i <= fieldNumber; i++)
	{
		DictionaryBaseType* field = ((DictionaryStruct*)object)->getField(i);
		textBuff << "\t\t" << field->getID() << ": " << field->getTypeName();
		// write specific Field parameters
		(this->*(writeIndex[field->getType()]))(field);
	};
	textBuff << "\t}\n";
	if (!object->getRootStatus())
		textBuff << "\tRESTRICT {root=false;}\n";

};

void DictionaryTextCreator::writeBoolean(DictionaryBaseType* object) throw (...)
{

	textBuff << " " << object->getName() << ";\n";
};

void DictionaryTextCreator::writeInt(DictionaryBaseType* object) throw (...)
{

	textBuff << " " << object->getName() << ";\n";
};

void DictionaryTextCreator::writeLong(DictionaryBaseType* object) throw (...)
{

	textBuff << " " << object->getName() << ";\n";
};

void DictionaryTextCreator::writeDouble(DictionaryBaseType* object) throw (...)
{

	textBuff << " " << object->getName() << ";\n";
};

void DictionaryTextCreator::writeUVarint(DictionaryBaseType* object) throw (...)
{

	textBuff << " " << object->getName() << ";\n";
};


void DictionaryTextCreator::writeString(DictionaryBaseType* object)
try
{
	switch (((DictionaryString*)object)->getEncode())
	{
	case USDS_NO_ENCODE:
		break;
	default:
		textBuff << "<" << encodeName(((DictionaryString*)object)->getEncode()) << ">";
	};
	
	textBuff << " " << object->getName() << ";\n";
	
}
catch (ErrorMessage& err)
{
	err.addPath(L"DictionaryTextCreator::writeStringField");
	throw err;
};

void DictionaryTextCreator::writeArray(DictionaryBaseType* object)
try
{
	textBuff << "<";
	switch (((DictionaryArray*)object)->getElementType())
	{
	case USDS_TAG:
		textBuff << ((DictionaryArray*)object)->getElementTagName();
		break;
	default:
		textBuff << typeName(((DictionaryArray*)object)->getElementType());
	}
	textBuff << "> " << object->getName() << ";\n";
}
catch (ErrorMessage& err)
{
	err.addPath(L"DictionaryTextCreator::writeArrayField");
	throw err;
};
