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
	DicBaseTag* tag = dict->getFirstTag();
	// get all tags
	while (tag != 0)
	{
		switch (tag->getType())
		{
		case USDS_STRUCT:
			writeStructTag((DicStructTag*)tag);
			break;
		default:
			writeSimpleTag(tag);
		}
		tag = tag->getNextTag();
	}
	textBuff << "}";

	*text = textBuff.str();
}
catch (ErrorMessage& err)
{
	err.addPath(L"DictionaryTextCreator::generate");
	throw err;
};

void DictionaryTextCreator::writeSimpleTag(DicBaseTag* tag)
{
	textBuff << "\t" << tag->getID() << (tag->getRootStatus() ? ": root " : ": ") << tag->getTypeName() << " " << tag->getName() << ";" << std::endl;
};

void DictionaryTextCreator::writeStructTag(DicStructTag* tag)
{
	DicBaseField* field = tag->getFirstField();
	textBuff << std::endl << "\t{" << std::endl;
	while (field != 0)
	{
		switch (field->getType())
		{
		case USDS_STRING:
			writeStringField((DicStringField*)field);
			break;
		default:
			writeSimpleField(field);
		}
			field = field->getNextField();
	};
	textBuff << "\t};" << std::endl;

};

//========================================================================================
// Fields

void DictionaryTextCreator::writeSimpleField(DicBaseField* field)
{
	textBuff << "\t\t" << field->getID() << ": " << field->getTypeName() << " " << field->getName() << ";" << std::endl;

};

void DictionaryTextCreator::writeStringField(DicStringField* field)
{
	textBuff << "\t\t" << field->getID() << ": " << field->getTypeName() << "(" << field->getEncode() << ")" << " " << field->getName() << ";" << std::endl;


};