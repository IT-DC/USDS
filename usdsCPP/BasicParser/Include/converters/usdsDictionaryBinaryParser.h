#ifndef USDS_DICTIONARY_BINARY_PARSER_H
#define USDS_DICTIONARY_BINARY_PARSER_H

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

namespace usds
{
	class BinaryInput;
	class Dictionary;
	class DictionaryBaseType;

	class DictionaryBinaryParser
	{
	public:
		DictionaryBinaryParser();
		~DictionaryBinaryParser();
		
		// read binary without size and signature
		void parse(BinaryInput* buff, Dictionary* dict) throw(...);

	private:
		
		void (DictionaryBinaryParser::*readIndex[USDS_LAST_TYPE])(DictionaryBaseType*);

		void readBoolean(DictionaryBaseType* object) throw (...);
		void readInt(DictionaryBaseType* object) throw (...);
		void readLong(DictionaryBaseType* object) throw (...);
		void readDouble(DictionaryBaseType* object) throw (...);
		void readUVarint(DictionaryBaseType* object) throw (...);
		void readArray(DictionaryBaseType* object) throw (...);
		void readString(DictionaryBaseType* object) throw (...);
		void readStruct(DictionaryBaseType* object) throw (...);

		BinaryInput* binary;
		Dictionary* dictionary;
	};

}

#endif