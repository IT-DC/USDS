#ifndef USDS_BODY_BINARY_PARSER_H
#define USDS_BODY_BINARY_PARSER_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

namespace usds
{
	class Body;
	class UsdsBaseType;
	class BinaryInput;

	class BodyBinaryParser
	{
	public:
		BodyBinaryParser();
		~BodyBinaryParser();

		void parse(BinaryInput* buff, Body* body_object) throw (...);

	private:
		BinaryInput* usdsBuff;
		Body* body;

		void (BodyBinaryParser::*readIndex[USDS_LAST_TYPE])(UsdsBaseType*);

		void readBoolean(UsdsBaseType* object) throw (...);
		void readInt(UsdsBaseType* object) throw (...);
		void readLong(UsdsBaseType* object) throw (...);
		void readDouble(UsdsBaseType* object) throw (...);
		void readUVarint(UsdsBaseType* object) throw (...);
		void readArray(UsdsBaseType* object) throw (...);
		void readString(UsdsBaseType* object) throw (...);
		void readStruct(UsdsBaseType* object) throw (...);

	};

}

#endif
