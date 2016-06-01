#ifndef USDS_BINARY_PARSER_H
#define USDS_BINARY_PARSER_H

#include "base\binary\usdsBinaryInput.h"
#include "converters\usdsDictionaryBinaryParser.h"
#include "converters\usdsBodyBinaryParser.h"

namespace usds
{
	class Dictionary;
	class Body;

	class BinaryParser
	{
	public:
		BinaryParser();
		~BinaryParser();

		void setBinary(const uint8_t* data, size_t data_size) throw(...);
		bool isHeadIncluded();
		bool isDictionaryIncluded();
		int32_t getDictionaryID();
		uint8_t getDictionaryMajor();
		uint8_t getDictionaryMinor();
		bool isBodyIncluded();

		void initDictionaryFromBinary(Dictionary* dict) throw(...);
		void initBodyFromBinary(Dictionary* dict, Body* body) throw(...);

	private:
	
		bool headExists;
		int32_t dictionaryID;
		uint8_t dictionaryMajor;
		uint8_t dictionaryMinor;
		size_t documentSize;
		
		bool dictionaryExists;
		bool bodyExists;

		BinaryInput binary;
		BinaryInput dictionaryBinary;
		BinaryInput bodyBinary;

		DictionaryBinaryParser dictionaryParser;
		BodyBinaryParser bodyParser;

	};
}

#endif