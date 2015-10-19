#ifndef USDS_DICTIONARY_BINARY_CREATOR_H
#define USDS_DICTIONARY_BINARY_CREATOR_H

namespace usds
{
	class BinaryOutput;
	class Dictionary;
	class DictionaryBaseType;

	class DictionaryBinaryCreator
	{
	public:

		DictionaryBinaryCreator();
		~DictionaryBinaryCreator();
		
		// Generate Binary Dictionary without size and signature
		void generate(BinaryOutput* buff, Dictionary* dict) throw (...);

	private:
		
		void (DictionaryBinaryCreator::*writeIndex[33])(DictionaryBaseType*);

		void writeBoolean(DictionaryBaseType* object) throw (...);
		void writeInt(DictionaryBaseType* object) throw (...);
		void writeLong(DictionaryBaseType* object) throw (...);
		void writeDouble(DictionaryBaseType* object) throw (...);
		void writeUVarint(DictionaryBaseType* object) throw (...);
		void writeArray(DictionaryBaseType* object) throw (...);
		void writeString(DictionaryBaseType* object) throw (...);
		void writeStruct(DictionaryBaseType* object) throw (...);

		BinaryOutput* outBuffer;

	};
}

#endif

