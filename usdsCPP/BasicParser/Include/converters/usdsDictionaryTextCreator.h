#ifndef USDS_DICTIONARY_TEXT_CREATOR_H
#define USDS_DICTIONARY_TEXT_CREATOR_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

#include <string>

namespace usds
{
	class Dictionary;
	class DictionaryBaseType;

	class DictionaryTextCreator
	{
	public:
		DictionaryTextCreator();
		~DictionaryTextCreator() { };

		void generate(usdsEncodes encode, std::string* text, Dictionary* dict) throw (...);

	private:
		std::stringstream textBuff;
		
		void (DictionaryTextCreator::*writeIndex[33])(DictionaryBaseType*);

		void writeBoolean(DictionaryBaseType* object) throw (...);
		void writeInt(DictionaryBaseType* object) throw (...);
		void writeLong(DictionaryBaseType* object) throw (...);
		void writeDouble(DictionaryBaseType* object) throw (...);
		void writeUVarint(DictionaryBaseType* object) throw (...);
		void writeArray(DictionaryBaseType* object) throw (...);
		void writeString(DictionaryBaseType* object) throw (...);
		void writeStruct(DictionaryBaseType* object) throw (...);

	};

};

#endif