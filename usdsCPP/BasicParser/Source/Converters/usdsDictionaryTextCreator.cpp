#include "converters\usdsDictionaryTextCreator.h"

#include "base\usdsDictionary.h"
#include "tags\dicBaseTag.h"
#include "tags\dicBaseField.h"
#include "tags\dicStructTag.h"
#include "tags\dicStructFields.h"

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

	textBuff << "USDS Dictionary ID=" << dict->getDictionaryID() << " v." << int(dict->getMajorVersion()) << "." << int(dict->getMinorVersion()) << std::endl;
	textBuff << "{" << std::endl;
	// get all tags
	for (int tag_id = 1; tag_id <= dict->getTagNumber(); tag_id++)
	{
		DicBaseTag* tag = dict->getTag(tag_id);
		switch (tag->getType())
		{
		case USDS_STRUCT:
			writeStructTag((DicStructTag*)tag);
			break;
		default:
			writeSimpleTag(tag);
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

void DictionaryTextCreator::writeSimpleTag(DicBaseTag* tag)
{
	textBuff << "\t" << tag->getID() << (tag->getRootStatus() ? ": root " : ": ") << tag->getTypeName() << " " << tag->getName() << ";" << std::endl;
};

void DictionaryTextCreator::writeStructTag(DicStructTag* tag)
{
	textBuff << "\t" << tag->getID() << (tag->getRootStatus() ? ": root " : ": ") << tag->getTypeName() << " " << tag->getName() << std::endl;
	textBuff << "\t{" << std::endl;
	DicBaseField* field = tag->getFirstField();
	while (field != 0)
	{
		switch (field->getType())
		{
		case USDS_STRING:
			writeStringField((DicStringField*)field);
			break;
		case USDS_ARRAY:
			writeArrayField((DicArrayField*)field);
			break;		
		default:
			writeSimpleField(field);
		}
			field = field->getNextField();
	};
	textBuff << "\t}" << std::endl;

};

//========================================================================================
// Fields

void DictionaryTextCreator::writeSimpleField(DicBaseField* field)
{
	textBuff << "\t\t" << field->getID() << ": " << field->getTypeName() << " " << field->getName() << ";" << std::endl;

};

void DictionaryTextCreator::writeStringField(DicStringField* field)
try
{
	textBuff << "\t\t" << field->getID() << ": " << field->getTypeName();
	switch (field->getEncode())
	{
	case USDS_NO_ENCODE:
		break;
	case USDS_UTF8:
		textBuff << " (utf-8)";
		break;
	default:
		std::wstringstream err;
		err << L"Unsupported encode, use USDS_UTF8. Your value: " << field->getEncode();
		throw ErrorMessage(TEXT_DICTIONARY_CREATOR_UNSUPPORTABLE_ENCODE, &err);
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
