#ifndef USDS_BASIC_PARSER
#define USDS_BASIC_PARSER

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

#include "base\object pool\usdsObjectPool.h"
#include "base\binary\usdsBinaryInput.h"
#include "base\binary\usdsBinaryOutput.h"
#include "dictionary\usdsDictionary.h"

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
		void encode(BinaryOutput* buff, bool with_head, bool with_dictionary, bool with_body) throw(...);

		// decode
		void decode(const unsigned char* data, int data_size) throw(...);

		// clear
		void clear();		// it does not release memory in buffers
		void clearBody();
		
	private:

		Dictionary* findDictionary(int id, unsigned char major, unsigned char minor) throw(...);

		// Object pool of Dictionaries
		TemplateObjectPool<Dictionary> dictionaryPool;
		// All existing dictionary
		std::list<Dictionary*> dictionaries;
		Dictionary* currentDictionary;
		
		BinaryInput usdsInput;

		// Deserialization
		void readHeadfromBinary() throw(...);
		void readDictionaryfromBinary(int id, unsigned char major, unsigned char minor) throw(...);
		void readBodyfromBinary() throw(...);
	};

};

#endif