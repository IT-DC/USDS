#include "converters\usdsDictionaryTextCreator.h"

#include "dictionary\usdsDictionary.h"

#include "dictionary\tags\dicStructTag.h"

#include "dictionary\fields\dicArrayField.h"
#include "dictionary\fields\dicBaseField.h"
#include "dictionary\fields\dicBooleanField.h"
#include "dictionary\fields\dicDoubleField.h"
#include "dictionary\fields\dicIntField.h"
#include "dictionary\fields\dicLongField.h"
#include "dictionary\fields\dicStringField.h"
#include "dictionary\fields\dicUVarintField.h"

using namespace usds;


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
		DicBaseTag* tag = dict->getTag(tag_id);
		textBuff << "\t" << tag->getID() << ": " << tag->getTypeName() << " " << tag->getName();
		
		switch (tag->getType())
		{
		case USDS_STRUCT:
			writeStructTag((DicStructTag*)tag);
			break;
		default:
			textBuff << ";\n";
		}
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
// Tags

void DictionaryTextCreator::writeStructTag(DicStructTag* tag)
{
	textBuff << "\n\t{\n";
	for (int i = 1; i <= tag->getFieldNumber(); i++)
	{
		DicBaseField* field = tag->getField(i);
		switch (field->getType())
		{
		case USDS_STRING:
			writeStringField((DicStringField*)field);
			break;
		case USDS_ARRAY:
			writeArrayField((DicArrayField*)field);
			break;		
		default:
			textBuff << "\t\t" << field->getID() << ": " << field->getTypeName() << " " << field->getName() << ";\n";
		}
	};
	textBuff << "\t}\n";
	if (!tag->getRootStatus())
	{
		textBuff << "\tRESTRICT {root=false;}\n";


	}

};

//========================================================================================
// Fields

void DictionaryTextCreator::writeStringField(DicStringField* field)
try
{
	textBuff << "\t\t" << field->getID() << ": " << field->getTypeName();
	switch (field->getEncode())
	{
	case USDS_NO_ENCODE:
		break;
	default:
		textBuff << "<" << encodeName(field->getEncode()) << ">";
	};
	
	textBuff << " " << field->getName() << ";" << std::endl;
	
}
catch (ErrorMessage& err)
{
	err.addPath(L"DictionaryTextCreator::writeStringField");
	throw err;
};

void DictionaryTextCreator::writeArrayField(DicArrayField* field)
try
{
	textBuff << "\t\t" << field->getID() << ": " << field->getTypeName() << "<";
	switch (field->getElementType())
	{
	case USDS_TAG:
		textBuff << field->getElementTagName();
		break;
	default:
		textBuff << typeName(field->getElementType());
	}
	textBuff << "> " << field->getName() << ";" << std::endl;
}
catch (ErrorMessage& err)
{
	err.addPath(L"DictionaryTextCreator::writeArrayField");
	throw err;
};
