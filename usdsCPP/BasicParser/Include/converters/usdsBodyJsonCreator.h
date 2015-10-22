#ifndef USDS_BODY_JSON_CREATOR_H
#define USDS_BODY_JSON_CREATOR_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

#include <string>

namespace usds
{
	class Body;
	class UsdsBaseType;

	class BodyJsonCreator
	{
	public:
		BodyJsonCreator();
		~BodyJsonCreator();

		void generate(usdsEncodes encode, std::string* text, Body* body) throw (...);

	private:
		std::string* textBuff;

		void (BodyJsonCreator::*writeIndex[USDS_LAST_TYPE])(UsdsBaseType*);

		void writeBoolean(UsdsBaseType* object) throw (...);
		void writeInt(UsdsBaseType* object) throw (...);
		void writeLong(UsdsBaseType* object) throw (...);
		void writeDouble(UsdsBaseType* object) throw (...);
		void writeUVarint(UsdsBaseType* object) throw (...);
		void writeArray(UsdsBaseType* object) throw (...);
		void writeString(UsdsBaseType* object) throw (...);
		void writeStruct(UsdsBaseType* object) throw (...);

		int shiftLevel;

	};

}

#endif
