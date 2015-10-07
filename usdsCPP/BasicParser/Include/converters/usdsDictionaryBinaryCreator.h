#ifndef USDS_DICTIONARY_BINARY_CREATOR
#define USDS_DICTIONARY_BINARY_CREATOR

namespace usds
{
	class BinaryOutput;
	class Dictionary;
	class DicBaseTag;
	class DicBaseField;

	class DictionaryBinaryCreator
	{
	public:

		DictionaryBinaryCreator();
		~DictionaryBinaryCreator();
		
		void generate(BinaryOutput* buff, Dictionary* dict) throw (...);

	private:
		
		void (DictionaryBinaryCreator::*writeTagIndex[33])(DicBaseTag*);

		void writeStructTag(DicBaseTag* tag) throw (...);

		void (DictionaryBinaryCreator::*writeFieldIndex[33])(DicBaseField*);

		void writeBooleanField(DicBaseField* field) throw (...);
		void writeIntField(DicBaseField* field) throw (...);
		void writeLongField(DicBaseField* field) throw (...);
		void writeDoubleField(DicBaseField* field) throw (...);
		void writeUVarintField(DicBaseField* field) throw (...);
		void writeArrayField(DicBaseField* field) throw (...);
		void writeStringField(DicBaseField* field) throw (...);
		
		BinaryOutput* outBuffer;

	};
}

#endif

