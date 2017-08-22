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
#include "dictionary\dataTypes\dictionaryTagLink.h"

using namespace usds;

DictionaryTextCreator::DictionaryTextCreator()
{
	writeIndex[USDS_TAG] = &DictionaryTextCreator::writeTag;
	writeIndex[USDS_BOOLEAN] = &DictionaryTextCreator::writeBoolean;
	writeIndex[USDS_BYTE] = &DictionaryTextCreator::writeByte;
	writeIndex[USDS_UBYTE] = &DictionaryTextCreator::writeUByte;
	writeIndex[USDS_SHORT] = &DictionaryTextCreator::writeShort;
	writeIndex[USDS_USHORT] = &DictionaryTextCreator::writeUShort;
	writeIndex[USDS_INT] = &DictionaryTextCreator::writeInt;
	writeIndex[USDS_UINT] = &DictionaryTextCreator::writeUInt;
	writeIndex[USDS_LONG] = &DictionaryTextCreator::writeLong;
	writeIndex[USDS_ULONG] = &DictionaryTextCreator::writeULong;
	writeIndex[USDS_INT128] = &DictionaryTextCreator::writeInt128;
	writeIndex[USDS_UINT128] = &DictionaryTextCreator::writeUInt128;
	writeIndex[USDS_FLOAT] = &DictionaryTextCreator::writeFloat;
	writeIndex[USDS_DOUBLE] = &DictionaryTextCreator::writeDouble;
	writeIndex[USDS_VARINT] = &DictionaryTextCreator::writeVarint;
	writeIndex[USDS_UVARINT] = &DictionaryTextCreator::writeUVarint;
	writeIndex[USDS_STRING] = &DictionaryTextCreator::writeString;
	writeIndex[USDS_ARRAY] = &DictionaryTextCreator::writeArray;
	writeIndex[USDS_STRUCT] = &DictionaryTextCreator::writeStruct;
};

void DictionaryTextCreator::generate(usdsEncode encode, std::string* text, Dictionary* dict) throw (...)
try
{
	if (encode != USDS_UTF8)
		throw ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_ENCODE) << "Unsupported encode, use USDS_UTF8. Your value: " << encode;

	textBuff.str("");

	textBuff << "USDS DICTIONARY ID=" << dict->getDictionaryID() << " v." << int(dict->getMajorVersion()) << "." << int(dict->getMinorVersion()) << "\n";
	textBuff << "{\n";
	// get all tags
	for (int32_t tag_id = 1; tag_id <= dict->getTagNumber(); tag_id++)
	{
		DictionaryBaseType* tag = dict->getTag(tag_id);
		textBuff << "\t" << tag->getID() << ": ";
		// write Tag
		(this->*(writeIndex[tag->getType()]))(tag);
		textBuff << ";\n";
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
	textBuff << ((DictionaryTagLink*)object)->getTag()->getName() << " " << object->getName();
};

void DictionaryTextCreator::writeBoolean(DictionaryBaseType* object) throw (...)
{

	textBuff << "BOOLEAN " << object->getName();
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

void DictionaryTextCreator::writeInt(DictionaryBaseType* object) throw (...)
{

	textBuff << "INT " << object->getName();
};

void DictionaryTextCreator::writeUInt(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeUInt") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeLong(DictionaryBaseType* object) throw (...)
{

	textBuff << "LONG " << object->getName();
};

void DictionaryTextCreator::writeULong(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeULong") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED LONG for Dictionary Text Creator");
};

void DictionaryTextCreator::writeInt128(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeInt128") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Dictionary Text Creator");
};

void DictionaryTextCreator::writeUInt128(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeUInt128") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for Dictionary Text Creator");
};

void DictionaryTextCreator::writeFloat(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeFloat") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type FLOAT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeDouble(DictionaryBaseType* object) throw (...)
{

	textBuff << "DOUBLE " << object->getName();
};

void DictionaryTextCreator::writeVarint(DictionaryBaseType* object) throw (...)
{
	throw ErrorStack("DictionaryTextCreator::writeVarint") << (void*)object << ErrorMessage(DIC_TEXT_CREATOR__UNSUPPORTED_TYPE, "Unsupported type VARINT for Dictionary Text Creator");
};

void DictionaryTextCreator::writeUVarint(DictionaryBaseType* object) throw (...)
{

	textBuff << "UNSIGNED VARINT " << object->getName();
};

void DictionaryTextCreator::writeString(DictionaryBaseType* object)
try
{
		textBuff << "STRING<" << UsdsTypes::encodeName(((DictionaryString*)object)->getDefaultEncode()) << "> " << object->getName();
	
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryTextCreator::writeString") << (void*)object;
	throw;
};

void DictionaryTextCreator::writeArray(DictionaryBaseType* object)
try
{
	textBuff << "ARRAY<";
	usdsType element_type = ((DictionaryArray*)object)->getElementType();
	if (element_type == USDS_TAG)
	{
		textBuff << ((DictionaryTagLink*)object)->getTag()->getName();
	}
	else
	{
		textBuff << UsdsTypes::typeName(element_type);
	}
	textBuff << "> " << object->getName();
}
catch (ErrorStack& err)
{
	err.addLevel("DictionaryTextCreator::writeArray") << (void*)object;
	throw;
};

void DictionaryTextCreator::writeStruct(DictionaryBaseType* object)
try
{
	textBuff << " " << object->getName() << "\n\t{\n";
	int32_t fieldNumber = ((DictionaryStruct*)object)->getFieldNumbers();
	for (int32_t i = 1; i <= fieldNumber; i++)
	{
		DictionaryBaseType* field = ((DictionaryStruct*)object)->getField(i);
		textBuff << "\t\t" << field->getID() << ": ";
		// write Field
		(this->*(writeIndex[field->getType()]))(field);
		textBuff << ";\n";
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



