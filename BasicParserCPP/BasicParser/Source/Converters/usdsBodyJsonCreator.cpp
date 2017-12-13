#include "converters\usdsBodyJsonCreator.h"

#include "body\usdsBody.h"

#include "body/dataTypes/usdsUInt.h"
#include "body/dataTypes/usdsUByte.h"
#include "body/dataTypes/usdsEnum.h"

using namespace usds;

BodyJsonCreator::BodyJsonCreator()
{
	writeIndex[USDS_BOOLEAN] = &BodyJsonCreator::writeBoolean;
	writeIndex[USDS_BYTE] = &BodyJsonCreator::writeByte;
	writeIndex[USDS_UBYTE] = &BodyJsonCreator::writeUByte;
	writeIndex[USDS_SHORT] = &BodyJsonCreator::writeShort;
	writeIndex[USDS_USHORT] = &BodyJsonCreator::writeUShort;
	writeIndex[USDS_INT] = &BodyJsonCreator::writeInt;
	writeIndex[USDS_UINT] = &BodyJsonCreator::writeUInt;
	writeIndex[USDS_LONG] = &BodyJsonCreator::writeLong;
	writeIndex[USDS_ULONG] = &BodyJsonCreator::writeULong;
	writeIndex[USDS_INT128] = &BodyJsonCreator::writeInt128;
	writeIndex[USDS_UINT128] = &BodyJsonCreator::writeUInt128;
	writeIndex[USDS_FLOAT] = &BodyJsonCreator::writeFloat;
	writeIndex[USDS_DOUBLE] = &BodyJsonCreator::writeDouble;
	writeIndex[USDS_VARINT] = &BodyJsonCreator::writeVarint;
	writeIndex[USDS_UVARINT] = &BodyJsonCreator::writeUVarint;
	writeIndex[USDS_STRING] = &BodyJsonCreator::writeString;
	writeIndex[USDS_ARRAY] = &BodyJsonCreator::writeArray;
	writeIndex[USDS_STRUCT] = &BodyJsonCreator::writeStruct;
	writeIndex[USDS_ENUM] = &BodyJsonCreator::writeEnum;
};

BodyJsonCreator::~BodyJsonCreator()
{


};

void BodyJsonCreator::generate(usdsEncode encode, std::string* text, Body* body) throw (...)
try
{
	if (encode != USDS_UTF8)
		throw ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTABLE_ENCODE) << "Unsupported encode, use USDS_UTF8. Your value: " << UsdsTypes::encodeName(encode);

	textBuff = text;

	*textBuff = "{\n";
	shiftLevel = 1;

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
catch (ErrorMessage& msg)
{
	throw ErrorStack("BodyJsonCreator::generate") << encode << text << (void*)body << msg;
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::generate") << encode << text << (void*)body;
	throw;
};

//=================================================================================================

void BodyJsonCreator::writeBoolean(UsdsBaseType* object) throw (...)
try
{
	if (((UsdsBoolean*)object)->get())
		*textBuff += "true";
	else
		*textBuff += "false";
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeBoolean") << (void*)object;
	throw;
};

void BodyJsonCreator::writeByte(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeByte") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BYTE for JSON Creator");
};

void BodyJsonCreator::writeUByte(UsdsBaseType* object) throw (...)
{
	uint8_t value = ((UsdsUByte*)object)->get();
	*textBuff += std::to_string(value);
};

void BodyJsonCreator::writeShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeShort") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type SHORT for JSON Creator");
};

void BodyJsonCreator::writeUShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeUShort") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED SHORT for JSON Creator");
};

void BodyJsonCreator::writeInt(UsdsBaseType* object) throw (...)
try
{
	int32_t value = ((UsdsInt*)object)->getValue<int32_t>();
	*textBuff += std::to_string(value);
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeBoolean") << (void*)object;
	throw;
};

void BodyJsonCreator::writeUInt(UsdsBaseType* object) throw (...)
{
	uint32_t value = ((UsdsUInt*)object)->get();
	*textBuff += std::to_string(value);
};

void BodyJsonCreator::writeLong(UsdsBaseType* object) throw (...)
try
{
	int64_t value = ((UsdsLong*)object)->get();
	*textBuff += std::to_string(value);
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeLong") << (void*)object;
	throw;
};

void BodyJsonCreator::writeULong(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeULong") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED LONG for JSON Creator");
};

void BodyJsonCreator::writeInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeInt128") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for JSON Creator");
};

void BodyJsonCreator::writeUInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeUInt128") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for JSON Creator");
};

void BodyJsonCreator::writeFloat(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeFloat") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type FLOAT for JSON Creator");
};

void BodyJsonCreator::writeDouble(UsdsBaseType* object) throw (...)
try
{
	double value = ((UsdsDouble*)object)->get();
	*textBuff += std::to_string(value);
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeDouble") << (void*)object;
	throw;
};

void BodyJsonCreator::writeVarint(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeVarint") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type VARINT for JSON Creator");
};

void BodyJsonCreator::writeUVarint(UsdsBaseType* object) throw (...)
try
{
	uint64_t value = ((UsdsUVarint*)object)->get();
	*textBuff += std::to_string(value);
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeUVarint") << (void*)object;
	throw;
};

void BodyJsonCreator::writeString(UsdsBaseType* object) throw (...)
try
{
	const char* value = (const char*)((UsdsString*)object)->getByteValue();
	*textBuff += "\"";
	*textBuff += value;
	*textBuff += "\"";
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeString") << (void*)object;
	throw;
};

void BodyJsonCreator::writeArray(UsdsBaseType* object) throw (...)
try
{
	int32_t element_number = ((UsdsArray*)object)->getSize();
	int32_t i = 0;
	*textBuff += '\n';
	textBuff->append(shiftLevel, '\t');

	// JSON does not support polymorph array
	if (((UsdsArray*)object)->getElementType() == USDS_POLYMORPH)
	{
		*textBuff += '{';
		shiftLevel++;
		while (true)
		{
			UsdsBaseType* tag = (((UsdsArray*)object)->getElement(i));
			*textBuff += '"';
			*textBuff += tag->getName();
			*textBuff += "\": ";
			// write specific Tag parameters
			(this->*(writeIndex[tag->getType()]))(tag);
			i++;
			if (i >= element_number)
				break;
			*textBuff += ", ";
		}
		shiftLevel--;
		*textBuff += '\n';
		textBuff->append(shiftLevel, '\t');
		*textBuff += '}';
	}
	else
	{
		*textBuff += '[';
		shiftLevel++;
		while (true)
		{
			UsdsBaseType* tag = (((UsdsArray*)object)->getElement(i));
			// write specific Tag parameters
			(this->*(writeIndex[tag->getType()]))(tag);
			i++;
			if (i >= element_number)
				break;
			*textBuff += ", ";
		}
		shiftLevel--;
		*textBuff += '\n';
		textBuff->append(shiftLevel, '\t');
		*textBuff += ']';
	};
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeArray") << (void*)object;
	throw;
};

void BodyJsonCreator::writeStruct(UsdsBaseType* object) throw (...)
try
{
	*textBuff += '\n';
	textBuff->append(shiftLevel, '\t');
	*textBuff += "{\n";
	shiftLevel++;
	int32_t fields_number = ((UsdsStruct*)object)->getFieldsNumber();
	int32_t id = 1;
	while (true)
	{
		if (((UsdsStruct*)object)->isNullable(id))
		{
			if (((UsdsStruct*)object)->isNull(id))
			{
				id++;
				if (id > fields_number)
					break;
				continue;
			}
		}
		UsdsBaseType* field = ((UsdsStruct*)object)->getField(id);
		textBuff->append(shiftLevel, '\t');
		*textBuff += '"';
		*textBuff += field->getName();
		*textBuff += "\": ";
		// write specific Field parameters
		(this->*(writeIndex[field->getType()]))(field);

		id++;
		if (id > fields_number)
			break;
		*textBuff += ",\n";
	}
	shiftLevel--;

	*textBuff += '\n';
	textBuff->append(shiftLevel, '\t');
	*textBuff += '}';
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeStruct") << (void*)object;
	throw;
};

void BodyJsonCreator::writeEnum(UsdsBaseType* object) throw (...)
try
{
	const char* value = ((UsdsEnum*)object)->getUTF8Value();
	*textBuff += "\"";
	*textBuff += value;
	*textBuff += "\"";
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeEnum") << (void*)object;
	throw;
};


