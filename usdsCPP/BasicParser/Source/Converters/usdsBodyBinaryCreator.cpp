#include "converters\usdsBodyBinaryCreator.h"

#include "body\usdsBody.h"

using namespace usds;

BodyBinaryCreator::BodyBinaryCreator()
{
	writeIndex[USDS_NO_TYPE] = 0;
	writeIndex[USDS_BOOLEAN] = &BodyBinaryCreator::writeBoolean;
	writeIndex[USDS_BYTE] = 0;
	writeIndex[USDS_UNSIGNED_BYTE] = 0;
	writeIndex[USDS_SHORT] = 0;
	writeIndex[USDS_UNSIGNED_SHORT] = 0;
	writeIndex[USDS_BIGENDIAN_SHORT] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	writeIndex[USDS_INT] = &BodyBinaryCreator::writeInt;
	writeIndex[USDS_UNSIGNED_INT] = 0;
	writeIndex[USDS_BIGENDIAN_INT] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	writeIndex[USDS_LONG] = &BodyBinaryCreator::writeLong;
	writeIndex[USDS_UNSIGNED_LONG] = 0;
	writeIndex[USDS_BIGENDIAN_LONG] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	writeIndex[USDS_INT128] = 0;
	writeIndex[USDS_UNSIGNED_INT128] = 0;
	writeIndex[USDS_BIGENDIAN_INT128] = 0;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	writeIndex[USDS_FLOAT] = 0;
	writeIndex[USDS_BIGENDIAN_FLOAT] = 0;
	writeIndex[USDS_DOUBLE] = &BodyBinaryCreator::writeDouble;
	writeIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	writeIndex[USDS_VARINT] = 0;
	writeIndex[USDS_UNSIGNED_VARINT] = &BodyBinaryCreator::writeUVarint;
	writeIndex[USDS_ARRAY] = &BodyBinaryCreator::writeArray;
	writeIndex[USDS_STRING] = &BodyBinaryCreator::writeString;
	writeIndex[USDS_LIST] = 0;
	writeIndex[USDS_MAP] = 0;
	writeIndex[USDS_POLYMORPH] = 0;
	writeIndex[USDS_STRUCT] = &BodyBinaryCreator::writeStruct;
	writeIndex[USDS_TAG] = 0;

};

BodyBinaryCreator::~BodyBinaryCreator()
{


};

void BodyBinaryCreator::generate(BinaryOutput* buff, Body* body) throw (...)
try
{

	usdsBuff = buff;

	UsdsBaseType* tag = body->getFirstTag();
	while (true)
	{
		*textBuff += "\t\"";
		*textBuff += tag->getName();
		*textBuff += "\": ";
		// write specific Tag parameters
		(this->*(writeIndex[tag->getType()]))(tag);
		tag = tag->getNext();
		if (tag == 0)
			break;
		*textBuff += ",\n";
	}
	*textBuff += "\n}";

}
catch (ErrorMessage& err)
{
	err.addPath(L"DictionaryTextCreator::generate");
	throw err;
};

//=================================================================================================

void BodyBinaryCreator::writeBoolean(UsdsBaseType* object) throw (...)
try
{
	if (((UsdsBoolean*)object)->getBooleanValue())
		*textBuff += "true";
	else
		*textBuff += "false";
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeBoolean");
	throw err;
};

void BodyBinaryCreator::writeInt(UsdsBaseType* object) throw (...)
try
{
	int value = ((UsdsInt*)object)->getIntValue();
	*textBuff += std::to_string(value);
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeInt");
	throw err;
};

void BodyBinaryCreator::writeLong(UsdsBaseType* object) throw (...)
try
{
	long long value = ((UsdsLong*)object)->getLongValue();
	*textBuff += std::to_string(value);
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeLong");
	throw err;
};

void BodyBinaryCreator::writeDouble(UsdsBaseType* object) throw (...)

try
{
	double value = ((UsdsDouble*)object)->getDoubleValue();
	*textBuff += std::to_string(value);
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeDouble");
	throw err;
};

void BodyBinaryCreator::writeUVarint(UsdsBaseType* object) throw (...)

try
{
	unsigned long long value = ((UsdsUVarint*)object)->getULongValue();
	*textBuff += std::to_string(value);
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeUVarint");
	throw err;
};

void BodyBinaryCreator::writeArray(UsdsBaseType* object) throw (...)

try
{
	int element_number = ((UsdsArray*)object)->getElementNumber();
	int i = 0;
	*textBuff += '\n';
	textBuff->append(shiftLevel, '\t');
	*textBuff += '[';
	shiftLevel++;

	switch (((UsdsArray*)object)->getElementType())
	{
	case USDS_TAG:

		while (true)
		{
			UsdsBaseType* tag = (((UsdsArray*)object)->getTagElement(i));
			// write specific Tag parameters
			(this->*(writeIndex[tag->getType()]))(tag);
			i++;
			if (i >= element_number)
				break;
			*textBuff += ", ";
		}
		break;
	}

	shiftLevel--;
	*textBuff += '\n';
	textBuff->append(shiftLevel, '\t');
	*textBuff += ']';
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeArray");
	throw err;
};

void BodyBinaryCreator::writeString(UsdsBaseType* object) throw (...)
try
{
	const char* value = ((UsdsUVarint*)object)->getStringValue();
	*textBuff += "\"";
	*textBuff += value;
	*textBuff += "\"";
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeString");
	throw err;
};

void BodyBinaryCreator::writeStruct(UsdsBaseType* object) throw (...)
try
{
	*textBuff += '\n';
	textBuff->append(shiftLevel, '\t');
	*textBuff += "{\n";
	shiftLevel++;
	int field_number = ((UsdsStruct*)object)->getFieldNumber();
	int id = 1;
	while (true)
	{
		UsdsBaseType* field = ((UsdsStruct*)object)->getField(id);
		textBuff->append(shiftLevel, '\t');
		*textBuff += '"';
		*textBuff += field->getName();
		*textBuff += "\": ";
		// write specific Field parameters
		(this->*(writeIndex[field->getType()]))(field);

		id++;
		if (id > field_number)
			break;
		*textBuff += ",\n";
	}
	shiftLevel--;

	*textBuff += '\n';
	textBuff->append(shiftLevel, '\t');
	*textBuff += '}';
}
catch (ErrorMessage& err)
{
	err.addPath(L"BodyJsonCreator::writeStruct");
	throw err;
};