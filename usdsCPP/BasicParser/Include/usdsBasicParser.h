#ifndef USDS_BASIC_PARSER
#define USDS_BASIC_PARSER

#include "base\usdsErrors.h"
#include "base\usdsObjectPool.h"
#include "base\usdsDictionary.h"
#include "base\usdsBinaryInput.h"
#include "base\usdsBinaryOutput.h"
#include "internalParsers\usdsDictionaryTextParser.h"

#include <list>

namespace usds
{
	class BasicParser
	{
	public:
		BasicParser();
		~BasicParser();

		// Settings
		const unsigned char usdsMajor;
		const unsigned char usdsMinor;
		void getDictionaryVersion(unsigned char* major, unsigned char* minor) throw(...);
		int getDictionaryID() throw(...);

		// Dictionary constructors
		void initDictionaryFromText(const char* text_dictionary, int size, usdsEncodes encode) throw(...);

		void initDictionary(int id, unsigned char major, unsigned char minor, usdsEncodes encode) throw(...);

		// Serialization
		void addHeadToBinary();
		void addDictionaryToBinary();
		void addBodyToBinary();
		void getBinary(unsigned char** data, int* size);

		// Deserialization
		void parseBinary(unsigned char* data, int data_size);

		// clean
		void clean();		// it does not release memory in buffer
		void release();		// release all memory
		
	private:
		Dictionary dictionariy;
		
		BinaryInput usdsInput;
		BinaryOutput usdsOutput;

	};

};

#endif