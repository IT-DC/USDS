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
	writeIndex[USDS_TAG] = &DictionaryTextCreator::writeTag;
	writeIndex[USDS_BOOLEAN] = &DictionaryTextCreator::writeBoolean;
	writeIndex[USDS_BYTE] = &DictionaryTextCreator::writeByte;
	writeIndex[USDS_UNSIGNED_BYTE] = &DictionaryTextCreator::writeUByte;
	writeIndex[USDS_SHORT] = &DictionaryTextCreator::writeShort;
	writeIndex[USDS_UNSIGNED_SHORT] = &DictionaryTextCreator::writeUShort;
	writeIndex[USDS_BIGENDIAN_SHORT] = &DictionaryTextCreator::writeBEShort;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = &DictionaryTextCreator::writeBEUShort;
	writeIndex[USDS_INT] = &DictionaryTextCreator::writeInt;
	writeIndex[USDS_UNSIGNED_INT] = &DictionaryTextCreator::writeUInt;
	writeIndex[USDS_BIGENDIAN_INT] = &DictionaryTextCreator::writeBEInt;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT] = &DictionaryTextCreator::writeBEUInt;
	writeIndex[USDS_LONG] = &DictionaryTextCreator::writeLong;
	writeIndex[USDS_UNSIGNED_LONG] = &DictionaryTextCreator::writeULong;
	writeIndex[USDS_BIGENDIAN_LONG] = &DictionaryTextCreator::writeBELong;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = &DictionaryTextCreator::writeBEULong;
	writeIndex[USDS_INT128] = &DictionaryTextCreator::writeInt128;
	writeIndex[USDS_UNSIGNED_INT128] = &DictionaryTextCreator::writeUInt128;
	writeIndex[USDS_BIGENDIAN_INT128] = &DictionaryTextCreator::writeBEInt128;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = &DictionaryTextCreator::writeBEUInt128;
	writeIndex[USDS_FLOAT] = &DictionaryTextCreator::writeFloat;
	writeIndex[USDS_BIGENDIAN_FLOAT] = &DictionaryTextCreator::writeBEFloat;
	writeIndex[USDS_DOUBLE] = &DictionaryTextCreator::writeDouble;
	writeIndex[USDS_USDS_BIGENDIAN_DOUBLE] = &DictionaryTextCreator::writeBEDouble;
	writeIndex[USDS_VARINT] = &DictionaryTextCreator::writeVarint;
	writeIndex[USDS_UNSIGNED_VARINT] = &DictionaryTextCreator::writeUVarint;
	writeIndex[USDS_STRING] = &DictionaryTextCreator::writeString;
	writeIndex[USDS_ARRAY] = &DictionaryTextCreator::writeArray;
	writeIndex[USDS_LIST] = &DictionaryTextCreator::writeList;
	writeIndex[USDS_MAP] = &DictionaryTextCreator::writeMap;
	writeIndex[USDS_POLYMORPH] = &DictionaryTextCreator::writePolymorph;
	writeIndex[USDS_STRUCT] = &DictionaryTextCreator::writeStruct;
	writeIndex[USDS_FUNCTION] = &DictionaryTextCreator::writeFunction;
};

void DictionaryTextCreator::generate(usdsEncodes encode, std::string* text, Dictionary* dict) throw (...)
try
{
	if (encode != USDS_UTF8)
		throw ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_ENCODE) << "Unsupported encode, use USDS_UTF8. Your value: " << encode;

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
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryTextCreator::generate") << encode << text << (void*)dict << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryTextCreator::generate") << encode << text << (void*)dict;
	throw;
};


//========================================================================================

void DictionaryTextCreator::writeTag(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeTag") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type TAG for Dictionary Text Creator");
};

void DictionaryTextCreator::writeBoolean(DictionaryBaseType* object) throw (...)
{

	textBuff << " " << object->getName() << ";\n";
};

void DictionaryTextCreator::writeByte(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeByte") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BYTE for Dictionary Text Creator");
};

void DictionaryTextCreator::writeUByte(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeUByte") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED BYTE for Dictionary Text Creator");
};

void DictionaryTextCreator::writeShort(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeShort") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type SHORT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeUShort(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeUShort") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED SHORT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeBEShort(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeBEShort") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN SHORT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeBEUShort(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeBEUShort") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED SHORT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeInt(DictionaryBaseType* object) throw (...)
{

	textBuff << " " << object->getName() << ";\n";
};

void DictionaryTextCreator::writeUInt(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeUInt") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeBEInt(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeBEInt") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeBEUInt(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeBEUInt") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeLong(DictionaryBaseType* object) throw (...)
{

	textBuff << " " << object->getName() << ";\n";
};

void DictionaryTextCreator::writeULong(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeULong") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED LONG for Dictionary Text Creator");
};

void DictionaryTextCreator::writeBELong(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeBELong") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN LONG for Dictionary Text Creator");
};

void DictionaryTextCreator::writeBEULong(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeBEULong") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED LONG for Dictionary Text Creator");
};

void DictionaryTextCreator::writeInt128(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeInt128") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Dictionary Text Creator");
};

void DictionaryTextCreator::writeUInt128(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeUInt128") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Dictionary Text Creator");
};

void DictionaryTextCreator::writeBEInt128(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeBEInt128") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT128 for Dictionary Text Creator");
};

void DictionaryTextCreator::writeBEUInt128(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeBEUInt128") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT128 for Dictionary Text Creator");
};

void DictionaryTextCreator::writeFloat(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeFloat") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type FLOAT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeBEFloat(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeBEFloat") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN FLOAT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeDouble(DictionaryBaseType* object) throw (...)
{

	textBuff << " " << object->getName() << ";\n";
};

void DictionaryTextCreator::writeBEDouble(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeBEDouble") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN DOUBLE for Dictionary Text Creator");
};

void DictionaryTextCreator::writeVarint(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeVarint") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type VARINT for Dictionary Text Creator");
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
catch (ErrorStack& err)
{
	err.addLevel("DictionaryTextCreator::writeString") << (void*)object;
	throw;
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
catch (ErrorStack& err)
{
	err.addLevel("DictionaryTextCreator::writeArray") << (void*)object;
	throw;
};

void DictionaryTextCreator::writeList(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeList") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type LIST for Dictionary Text Creator");
};

void DictionaryTextCreator::writeMap(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeMap") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type MAP for Dictionary Text Creator");
};

void DictionaryTextCreator::writePolymorph(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writePolymorph") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type POLYMORPH for Dictionary Text Creator");
};

void DictionaryTextCreator::writeStruct(DictionaryBaseType* object)
try
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
		textBuff << "\tRESTRICT {notRoot;}\n";

}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryTextCreator::writeStruct") << (void*)object;
	throw;
};

void DictionaryTextCreator::writeFunction(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeFunction") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type FUNCTION for Dictionary Text Creator");
};