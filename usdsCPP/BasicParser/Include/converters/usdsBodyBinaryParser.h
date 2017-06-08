#ifndef USDS_BODY_BINARY_PARSER_H
#define USDS_BODY_BINARY_PARSER_H

#include "usdsErrors.h"
#include "usdsTypes.h"

namespace usds
{
	class Body;
	class Dictionary;
	class UsdsBaseType;
	class BinaryInput;

	class BodyBinaryParser
	{
	public:
		BodyBinaryParser();
		~BodyBinaryParser();

		void parse(BinaryInput* buff, Dictionary* dict_object, Body* body_object) throw (...);

	private:
		BinaryInput* usdsBuff;
		Body* body;
		Dictionary* dict;

		void (BodyBinaryParser::*readIndex[USDS_LAST_TYPE])(UsdsBaseType*);

		void readTag(UsdsBaseType* object) throw (...);
		void readBoolean(UsdsBaseType* object) throw (...);
		void readByte(UsdsBaseType* object) throw (...);
		void readUByte(UsdsBaseType* object) throw (...);
		void readShort(UsdsBaseType* object) throw (...);
		void readUShort(UsdsBaseType* object) throw (...);
		void readBEShort(UsdsBaseType* object) throw (...);
		void readBEUShort(UsdsBaseType* object) throw (...);
		void readInt(UsdsBaseType* object) throw (...);
		void readUInt(UsdsBaseType* object) throw (...);
		void readBEInt(UsdsBaseType* object) throw (...);
		void readBEUInt(UsdsBaseType* object) throw (...);
		void readLong(UsdsBaseType* object) throw (...);
		void readULong(UsdsBaseType* object) throw (...);
		void readBELong(UsdsBaseType* object) throw (...);
		void readBEULong(UsdsBaseType* object) throw (...);
		void readInt128(UsdsBaseType* object) throw (...);
		void readUInt128(UsdsBaseType* object) throw (...);
		void readBEInt128(UsdsBaseType* object) throw (...);
		void readBEUInt128(UsdsBaseType* object) throw (...);
		void readFloat(UsdsBaseType* object) throw (...);
		void readBEFloat(UsdsBaseType* object) throw (...);
		void readDouble(UsdsBaseType* object) throw (...);
		void readBEDouble(UsdsBaseType* object) throw (...);
		void readVarint(UsdsBaseType* object) throw (...);
		void readUVarint(UsdsBaseType* object) throw (...);
		void readString(UsdsBaseType* object) throw (...);
		void readArray(UsdsBaseType* object) throw (...);
		void readList(UsdsBaseType* object) throw (...);
		void readMap(UsdsBaseType* object) throw (...);
		void readPolymorph(UsdsBaseType* object) throw (...);
		void readStruct(UsdsBaseType* object) throw (...);
		void readFunction(UsdsBaseType* object) throw (...);

	};

}

#endif
