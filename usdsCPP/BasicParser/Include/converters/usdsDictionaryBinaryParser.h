#ifndef USDS_BINARY_DICTIONARY_PARSER_H
#define USDS_BINARY_DICTIONARY_PARSER_H

namespace usds
{
	class BinaryInput;
	class Dictionary;
	class DictionaryBaseType;

	class BinaryDictionaryParser
	{
	public:
		BinaryDictionaryParser();
		~BinaryDictionaryParser();
		
		// read binary without size and signature
		void parse(BinaryInput* buff, Dictionary* dict) throw(...);

	private:
		
		void (BinaryDictionaryParser::*readIndex[33])(DictionaryBaseType*);

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