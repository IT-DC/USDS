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

		// encode
		void encode(bool with_head, bool with_dictionary, bool with_body) throw(...);
		const unsigned char* getBinary(size_t* size) throw(...);

		// decode
		void decode(const unsigned char* data, int data_size) throw(...);

		// clear
		void clear();		// it does not release memory in buffers
		void clearBody();
		
	private:

		Dictionary* findDictionary(int id, unsigned char major, unsigned char minor) throw(...);

		DictionaryObjectPool dictionaryPool;
		std::list<Dictionary*> dictionaries;
		Dictionary* currentDictionary;
		
		BinaryInput usdsInput;
		BinaryOutput usdsOutput;

		// Serialization
		void addHeadToBinary() throw(...);
		void addDictionaryToBinary() throw(...);
		void addBodyToBinary() throw(...);

		// Deserialization
		void readHeadfromBinary() throw(...);
		void readDictionaryfromBinary() throw(...);
		void readBodyfromBinary() throw(...);
	};

};

#endif