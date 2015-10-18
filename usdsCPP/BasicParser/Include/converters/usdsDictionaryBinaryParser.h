#ifndef USDS_BINARY_DICTIONARY_PARSER_H
#define USDS_BINARY_DICTIONARY_PARSER_H

namespace usds
{
	class BinaryInput;
	class Dictionary;
	class DicBaseTag;
	class DicBaseField;

	class BinaryDictionaryParser
	{
	public:
		BinaryDictionaryParser();
		~BinaryDictionaryParser();
		
		void parse(BinaryInput* buff, Dictionary* dict) throw(...);

	private:
		
		void (BinaryDictionaryParser::*readTagIndex[33])(DicBaseTag*);

		void readStructTag(DicBaseTag* tag) throw (...);

		void (BinaryDictionaryParser::*readFieldIndex[33])(DicBaseField*);

		void readBooleanField(DicBaseField* field) throw (...);
		void readIntField(DicBaseField* field) throw (...);
		void readLongField(DicBaseField* field) throw (...);
		void readDoubleField(DicBaseField* field) throw (...);
		void readUVarintField(DicBaseField* field) throw (...);
		void readArrayField(DicBaseField* field) throw (...);
		void readStringField(DicBaseField* field) throw (...);
	
		BinaryInput* binary;
		Dictionary* dictionary;
	};

}

#endif