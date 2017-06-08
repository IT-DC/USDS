#ifndef USDS_DICTIONARY_BINARY_PARSER_H
#define USDS_DICTIONARY_BINARY_PARSER_H

#include "usdsTypes.h"
#include "usdsErrors.h"

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

		void readTag(DictionaryBaseType* object) throw (...);
		void readBoolean(DictionaryBaseType* object) throw (...);
		void readByte(DictionaryBaseType* object) throw (...);
		void readUByte(DictionaryBaseType* object) throw (...);
		void readShort(DictionaryBaseType* object) throw (...);
		void readUShort(DictionaryBaseType* object) throw (...);
		void readBEShort(DictionaryBaseType* object) throw (...);
		void readBEUShort(DictionaryBaseType* object) throw (...);
		void readInt(DictionaryBaseType* object) throw (...);
		void readUInt(DictionaryBaseType* object) throw (...);
		void readBEInt(DictionaryBaseType* object) throw (...);
		void readBEUInt(DictionaryBaseType* object) throw (...);
		void readLong(DictionaryBaseType* object) throw (...);
		void readULong(DictionaryBaseType* object) throw (...);
		void readBELong(DictionaryBaseType* object) throw (...);
		void readBEULong(DictionaryBaseType* object) throw (...);
		void readInt128(DictionaryBaseType* object) throw (...);
		void readUInt128(DictionaryBaseType* object) throw (...);
		void readBEInt128(DictionaryBaseType* object) throw (...);
		void readBEUInt128(DictionaryBaseType* object) throw (...);
		void readFloat(DictionaryBaseType* object) throw (...);
		void readBEFloat(DictionaryBaseType* object) throw (...);
		void readDouble(DictionaryBaseType* object) throw (...);
		void readBEDouble(DictionaryBaseType* object) throw (...);
		void readVarint(DictionaryBaseType* object) throw (...);
		void readUVarint(DictionaryBaseType* object) throw (...);
		void readString(DictionaryBaseType* object) throw (...);
		void readArray(DictionaryBaseType* object) throw (...);
		void readList(DictionaryBaseType* object) throw (...);
		void readMap(DictionaryBaseType* object) throw (...);
		void readPolymorph(DictionaryBaseType* object) throw (...);
		void readStruct(DictionaryBaseType* object) throw (...);
		void readFunction(DictionaryBaseType* object) throw (...);

		BinaryInput* binary;
		Dictionary* dictionary;
	};

}

#endif