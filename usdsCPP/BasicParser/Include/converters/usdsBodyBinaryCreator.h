#ifndef USDS_BODY_BINARY_CREATOR_H
#define USDS_BODY_BINARY_CREATOR_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"



namespace usds
{
	class Body;
	class UsdsBaseType;
	class BinaryOutput;

	class BodyBinaryCreator
	{
	public:
		BodyBinaryCreator();
		~BodyBinaryCreator();

		void generate(BinaryOutput* buff, Body* body) throw (...);

	private:
		BinaryOutput* usdsBuff;

		void (BodyBinaryCreator::*writeIndex[USDS_LAST_TYPE])(UsdsBaseType*);

		void writeTag(UsdsBaseType* object) throw (...);
		void writeBoolean(UsdsBaseType* object) throw (...);
		void writeByte(UsdsBaseType* object) throw (...);
		void writeUByte(UsdsBaseType* object) throw (...);
		void writeShort(UsdsBaseType* object) throw (...);
		void writeUShort(UsdsBaseType* object) throw (...);
		void writeBEShort(UsdsBaseType* object) throw (...);
		void writeBEUShort(UsdsBaseType* object) throw (...);
		void writeInt(UsdsBaseType* object) throw (...);
		void writeUInt(UsdsBaseType* object) throw (...);
		void writeBEInt(UsdsBaseType* object) throw (...);
		void writeBEUInt(UsdsBaseType* object) throw (...);
		void writeLong(UsdsBaseType* object) throw (...);
		void writeULong(UsdsBaseType* object) throw (...);
		void writeBELong(UsdsBaseType* object) throw (...);
		void writeBEULong(UsdsBaseType* object) throw (...);
		void writeInt128(UsdsBaseType* object) throw (...);
		void writeUInt128(UsdsBaseType* object) throw (...);
		void writeBEInt128(UsdsBaseType* object) throw (...);
		void writeBEUInt128(UsdsBaseType* object) throw (...);
		void writeFloat(UsdsBaseType* object) throw (...);
		void writeBEFloat(UsdsBaseType* object) throw (...);
		void writeDouble(UsdsBaseType* object) throw (...);
		void writeBEDouble(UsdsBaseType* object) throw (...);
		void writeVarint(UsdsBaseType* object) throw (...);
		void writeUVarint(UsdsBaseType* object) throw (...);
		void writeString(UsdsBaseType* object) throw (...);
		void writeArray(UsdsBaseType* object) throw (...);
		void writeList(UsdsBaseType* object) throw (...);
		void writeMap(UsdsBaseType* object) throw (...);
		void writePolymorph(UsdsBaseType* object) throw (...);
		void writeStruct(UsdsBaseType* object) throw (...);
		void writeFunction(UsdsBaseType* object) throw (...);

	};

}

#endif
