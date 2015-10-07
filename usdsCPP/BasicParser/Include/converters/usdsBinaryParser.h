#ifndef USDS_BINARY_PARSER
#define USDS_BINARY_PARSER

namespace usds
{
	class Dictionary;
	class BinaryInput;

	class BinaryParser
	{
	public:
		BinaryParser(const unsigned char* data, int data_size);
		~BinaryParser();

		bool isHeadIncluded();
		bool isDictionaryIncluded();
		int getDictionaryID();
		unsigned char getDictionaryMajor();
		unsigned char getDictionaryMinor();
		bool isBodyIncluded();

		void initDictionaryFromBinary(Dictionary* dict) throw(...);
		void initBodyFromBinary(Dictionary* dict) throw(...);

	private:
		
		void readHead(BinaryInput* binary) throw(...);
		
		int dictionaryID;
		unsigned char dictionaryMajor;
		unsigned char dictionaryMinor;
		size_t documentSize;
		bool headExists;
		bool dictionaryExists;
		const unsigned char* dictionaryPosition;
		size_t dictionarySize;
		bool bodyExists;
		const unsigned char* bodyPosition;
		size_t bodySize;
	};
}

#endif