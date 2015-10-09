#ifndef USDS_BINARY_PARSER
#define USDS_BINARY_PARSER

#include "base\binary\usdsBinaryInput.h"

namespace usds
{
	class Dictionary;
	class BinaryInput;

	class BinaryParser
	{
	public:
		BinaryParser();
		~BinaryParser();

		void setBinary(const unsigned char* data, int data_size) throw(...);
		bool isHeadIncluded();
		bool isDictionaryIncluded();
		int getDictionaryID();
		unsigned char getDictionaryMajor();
		unsigned char getDictionaryMinor();
		bool isBodyIncluded();

		void initDictionaryFromBinary(Dictionary* dict) throw(...);
		void initBodyFromBinary(Dictionary* dict) throw(...);

	private:
	
		bool headExists;
		int dictionaryID;
		unsigned char dictionaryMajor;
		unsigned char dictionaryMinor;
		size_t documentSize;
		
		bool dictionaryExists;
		bool bodyExists;

		BinaryInput binary;
		BinaryInput dictionaryBinary;
		BinaryInput bodyBinary;


	};
}

#endif