#ifndef USDS_BASIC_PARSER
#define USDS_BASIC_PARSER

#include "base\usdsErrors.h"
#include "tags\usdsTypes.h"

#include "base\usdsObjectPool.h"
#include "base\usdsBinaryInput.h"
#include "base\usdsBinaryOutput.h"
#include "base\usdsDictionary.h"

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

		// Dictionary constructors
		void addDictionaryFromText(const char* text_dictionary, int size, usdsEncodes encode) throw(...);
		void CurrentDictionaryToText(usdsEncodes encode, std::string* text) throw(...);
		// add clean dictionary
		Dictionary* addNewDictionary(int id, unsigned char major, unsigned char minor) throw(...);

		// Working with several dictionaries
		void selectDictionary(int id, unsigned char major, unsigned char minor) throw(...);

		// Return parameters for current dictionary
		int getDictionaryID() throw(...);
		unsigned char getDictionaryMajor() throw(...);
		unsigned char getDictionaryMinor() throw(...);

		// Serialization
		void addHeadToBinary();
		void addDictionaryToBinary();
		void addBodyToBinary();
		void getBinary(unsigned char** data, int* size);

		// Deserialization
		void parseBinary(unsigned char* data, int data_size);

		// clear
		void clear();		// it does not release memory in buffer
		void release();		// release all memory
		
	private:

		Dictionary* findDictionary(int id, unsigned char major, unsigned char minor) throw(...);

		DictionaryObjectPool dictionaryPool;
		std::list<Dictionary*> dictionaries;
		Dictionary* currentDictionary;
		
		BinaryInput usdsInput;
		BinaryOutput usdsOutput;

	};

};

#endif