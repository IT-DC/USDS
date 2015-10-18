#ifndef USDS_BINARY_PARSER_H
#define USDS_BINARY_PARSER_H

#include "base\binary\usdsBinaryInput.h"
#include "converters\usdsDictionaryBinaryParser.h"

namespace usds
{
	class Dictionary;

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

		BinaryDictionaryParser dictionaryParser;

	};
}

#endif