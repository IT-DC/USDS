#include "converters\usdsBodyJsonCreator.h"

#include "body\usdsBody.h"

using namespace usds;

BodyJsonCreator::BodyJsonCreator()
{
	writeIndex[USDS_NO_TYPE] = 0;
	writeIndex[USDS_TAG] = &BodyJsonCreator::writeTag;
	writeIndex[USDS_BOOLEAN] = &BodyJsonCreator::writeBoolean;
	writeIndex[USDS_BYTE] = &BodyJsonCreator::writeByte;
	writeIndex[USDS_UNSIGNED_BYTE] = &BodyJsonCreator::writeUByte;
	writeIndex[USDS_SHORT] = &BodyJsonCreator::writeShort;
	writeIndex[USDS_UNSIGNED_SHORT] = &BodyJsonCreator::writeUShort;
	writeIndex[USDS_BIGENDIAN_SHORT] = &BodyJsonCreator::writeBEShort;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = &BodyJsonCreator::writeBEUShort;
	writeIndex[USDS_INT] = &BodyJsonCreator::writeInt;
	writeIndex[USDS_UNSIGNED_INT] = &BodyJsonCreator::writeUInt;
	writeIndex[USDS_BIGENDIAN_INT] = &BodyJsonCreator::writeBEInt;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT] = &BodyJsonCreator::writeBEUInt;
	writeIndex[USDS_LONG] = &BodyJsonCreator::writeLong;
	writeIndex[USDS_UNSIGNED_LONG] = &BodyJsonCreator::writeULong;
	writeIndex[USDS_BIGENDIAN_LONG] = &BodyJsonCreator::writeBELong;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = &BodyJsonCreator::writeBEULong;
	writeIndex[USDS_INT128] = &BodyJsonCreator::writeInt128;
	writeIndex[USDS_UNSIGNED_INT128] = &BodyJsonCreator::writeUInt128;
	writeIndex[USDS_BIGENDIAN_INT128] = &BodyJsonCreator::writeBEInt128;
	writeIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = &BodyJsonCreator::writeBEUInt128;
	writeIndex[USDS_FLOAT] = &BodyJsonCreator::writeFloat;
	writeIndex[USDS_BIGENDIAN_FLOAT] = &BodyJsonCreator::writeBEFloat;
	writeIndex[USDS_DOUBLE] = &BodyJsonCreator::writeDouble;
	writeIndex[USDS_USDS_BIGENDIAN_DOUBLE] = &BodyJsonCreator::writeBEDouble;
	writeIndex[USDS_VARINT] = &BodyJsonCreator::writeVarint;
	writeIndex[USDS_UNSIGNED_VARINT] = &BodyJsonCreator::writeUVarint;
	writeIndex[USDS_STRING] = &BodyJsonCreator::writeString;
	writeIndex[USDS_ARRAY] = &BodyJsonCreator::writeArray;
	writeIndex[USDS_LIST] = &BodyJsonCreator::writeList;
	writeIndex[USDS_MAP] = &BodyJsonCreator::writeMap;
	writeIndex[USDS_POLYMORPH] = &BodyJsonCreator::writePolymorph;
	writeIndex[USDS_STRUCT] = &BodyJsonCreator::writeStruct;
	writeIndex[USDS_FUNCTION] = &BodyJsonCreator::writeFunction;

};

BodyJsonCreator::~BodyJsonCreator()
{


};

void BodyJsonCreator::generate(usdsEncodes encode, std::string* text, Body* body) throw (...)
try
{
	if (encode != USDS_UTF8)
		throw ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTABLE_ENCODE) << "Unsupported encode, use USDS_UTF8. Your value: " << encode;

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
	if (((UsdsBoolean*)object)->getBooleanValue())
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
	throw ErrorStack("BodyJsonCreator::writeUByte") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED BYTE for JSON Creator");
};

void BodyJsonCreator::writeShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeShort") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type SHORT for JSON Creator");
};

void BodyJsonCreator::writeUShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeUShort") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED SHORT for JSON Creator");
};

void BodyJsonCreator::writeBEShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeBEShort") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN SHORT for JSON Creator");
};

void BodyJsonCreator::writeBEUShort(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeBEUShort") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED SHORT for JSON Creator");
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
	throw ErrorStack("BodyJsonCreator::writeUInt") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT for JSON Creator");
};

void BodyJsonCreator::writeBEInt(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeBEInt") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT for JSON Creator");
};

void BodyJsonCreator::writeBEUInt(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeBEUInt") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT for JSON Creator");
};

void BodyJsonCreator::writeLong(UsdsBaseType* object) throw (...)
try
{
	int64_t value = ((UsdsLong*)object)->getLongValue();
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

void BodyJsonCreator::writeBELong(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeBELong") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN LONG for JSON Creator");
};

void BodyJsonCreator::writeBEULong(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeBEULong") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED LONG for JSON Creator");
};

void BodyJsonCreator::writeInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeInt128") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for JSON Creator");
};

void BodyJsonCreator::writeUInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeUInt128") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type UNSIGNED INT128 for JSON Creator");
};

void BodyJsonCreator::writeBEInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeBEInt128") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN INT128 for JSON Creator");
};

void BodyJsonCreator::writeBEUInt128(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeBEUInt128") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN UNSIGNED INT128 for JSON Creator");
};

void BodyJsonCreator::writeFloat(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeFloat") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type FLOAT for JSON Creator");
};

void BodyJsonCreator::writeBEFloat(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeBEFloat") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN FLOAT for JSON Creator");
};

void BodyJsonCreator::writeDouble(UsdsBaseType* object) throw (...)

try
{
	double value = ((UsdsDouble*)object)->getDoubleValue();
	*textBuff += std::to_string(value);
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeDouble") << (void*)object;
	throw;
};

void BodyJsonCreator::writeBEDouble(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeBEDouble") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type BIGENDIAN DOUBLE for JSON Creator");
};

void BodyJsonCreator::writeVarint(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeVarint") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type VARINT for JSON Creator");
};

void BodyJsonCreator::writeUVarint(UsdsBaseType* object) throw (...)
try
{
	uint64_t value = ((UsdsUVarint*)object)->getULongValue();
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
	const char* value = ((UsdsString*)object)->getStringValue();
	*textBuff += "\"";
	*textBuff += value;
	*textBuff += "\"";
}
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeString") << (void*)object;
	throw;
};

void BodyJsonCreator::writeList(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeList") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type LIST for JSON Creator");
};

void BodyJsonCreator::writeMap(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeMap") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type MAP for JSON Creator");
};

void BodyJsonCreator::writePolymorph(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writePolymorph") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type POLYMORPH for JSON Creator");
};

void BodyJsonCreator::writeArray(UsdsBaseType* object) throw (...)

try
{
	int32_t element_number = ((UsdsArray*)object)->size();
	int32_t i = 0;
	*textBuff += '\n';
	textBuff->append(shiftLevel, '\t');
	*textBuff += '[';
	shiftLevel++;

	switch (((UsdsArray*)object)->getElementType())
	{
	case USDS_TAG:

		while (true)
		{
			UsdsBaseType* tag = (((UsdsArray*)object)->getTag(i));
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
	int32_t field_number = ((UsdsStruct*)object)->getFieldNumber();
	int32_t id = 1;
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
catch (ErrorStack& err)
{
	err.addLevel("BodyJsonCreator::writeStruct") << (void*)object;
	throw;
};

void BodyJsonCreator::writeFunction(UsdsBaseType* object) throw (...)
{
	throw ErrorStack("BodyJsonCreator::writeFunction") << (void*)object << ErrorMessage(BODY_JSON_CREATOR__UNSUPPORTED_TYPE, "Unsupported type FUNCTION for JSON Creator");
};
