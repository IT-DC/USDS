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

		void writeBoolean(UsdsBaseType* object) throw (...);
		void writeInt(UsdsBaseType* object) throw (...);
		void writeLong(UsdsBaseType* object) throw (...);
		void writeDouble(UsdsBaseType* object) throw (...);
		void writeUVarint(UsdsBaseType* object) throw (...);
		void writeArray(UsdsBaseType* object) throw (...);
		void writeString(UsdsBaseType* object) throw (...);
		void writeStruct(UsdsBaseType* object) throw (...);

	};

}

#endif
