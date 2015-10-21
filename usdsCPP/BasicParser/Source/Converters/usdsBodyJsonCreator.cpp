#include "converters\usdsBodyJsonCreator.h"

#include "body\usdsBody.h"

using namespace usds;

BodyJsonCreator::BodyJsonCreator()
{
	writeIndex[USDS_NO_TYPE] = 0;
	writeIndex[USDS_BOOLEAN] = &BodyJsonCreator::writeBoolean;
	writeIndex[USDS_BYTE] = 0;
	writeIndex[USDS_UNSIGNED_BYTE] = 0;
	writeIndex[USDS_SHORT] = 0;
	writeIndex[USDS_UNSIGNED_SHORT] = 0;
	writeIndex[USDS_BIGENDIAN_SHORT] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	writeIndex[USDS_INT] = &BodyJsonCreator::writeInt;
	writeIndex[USDS_UNSIGNED_INT] = 0;
	writeIndex[USDS_BIGENDIAN_INT] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	writeIndex[USDS_LONG] = &BodyJsonCreator::writeLong;
	writeIndex[USDS_UNSIGNED_LONG] = 0;
	writeIndex[USDS_BIGENDIAN_LONG] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	writeIndex[USDS_INT128] = 0;
	writeIndex[USDS_UNSIGNED_INT128] = 0;
	writeIndex[USDS_BIGENDIAN_INT128] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	writeIndex[USDS_FLOAT] = 0;
	writeIndex[USDS_BIGENDIAN_FLOAT] = 0;
	writeIndex[USDS_DOUBLE] = &BodyJsonCreator::writeDouble;
	writeIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	writeIndex[USDS_VARINT] = 0;
	writeIndex[USDS_UNSIGNED_VARINT] = &BodyJsonCreator::writeUVarint;
	writeIndex[USDS_ARRAY] = &BodyJsonCreator::writeArray;
	writeIndex[USDS_STRING] = &BodyJsonCreator::writeString;
	writeIndex[USDS_LIST] = 0;
	writeIndex[USDS_MAP] = 0;
	writeIndex[USDS_POLYMORPH] = 0;
	writeIndex[USDS_STRUCT] = &BodyJsonCreator::writeStruct;
	writeIndex[USDS_TAG] = 0;

};

BodyJsonCreator::~BodyJsonCreator()
{


};

void BodyJsonCreator::generate(usdsEncodes encode, std::string* text, Body* body) throw (...)
try
{
	if (encode != USDS_UTF8)
	{
		std::wstringstream err;
		err << L"Unsupported encode, use USDS_UTF8. Your value: " << encode;
		throw ErrorMessage(BODY_JSON_CREATOR_UNSUPPORTABLE_ENCODE, &err);
	};

	textBuff.clear();

	textBuff << "{\n";
	shiftLevel = 1;

	UsdsBaseType* tag = body->getFirstTag();
	while (tag != 0)
	{
		textBuff << "\t\"" << tag->getName() << "\":";
		// write specific Tag parameters
		(this->*(writeIndex[tag->getType()]))(tag);
		textBuff << '\n';
		tag = tag->getNext();
	}
	textBuff << '}';

	*text = textBuff.str();
}
catch (ErrorMessage& err)
{
	err.addPath(L"DictionaryTextCreator::generate");
	throw err;
};

//=================================================================================================

void BodyJsonCreator::writeBoolean(UsdsBaseType* object) throw (...)
try
{


}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeBoolean");
	throw err;
};

void BodyJsonCreator::writeInt(UsdsBaseType* object) throw (...)
try
{


}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeInt");
	throw err;
};

void BodyJsonCreator::writeLong(UsdsBaseType* object) throw (...)
try
{


}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeLong");
	throw err;
};

void BodyJsonCreator::writeDouble(UsdsBaseType* object) throw (...)

try
{


}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeDouble");
	throw err;
};

void BodyJsonCreator::writeUVarint(UsdsBaseType* object) throw (...)

try
{


}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeUVarint");
	throw err;
};

void BodyJsonCreator::writeArray(UsdsBaseType* object) throw (...)

try
{


}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeArray");
	throw err;
};

void BodyJsonCreator::writeString(UsdsBaseType* object) throw (...)
try
{


}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeString");
	throw err;
};

void BodyJsonCreator::writeStruct(UsdsBaseType* object) throw (...)
try
{
	//((UsdsStruct*)object)->getFieldsNumber();




}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeStruct");
	throw err;
};