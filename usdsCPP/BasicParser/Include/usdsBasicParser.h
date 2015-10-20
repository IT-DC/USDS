#ifndef USDS_BASIC_PARSER_H
#define USDS_BASIC_PARSER_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

#include "base\objectPool\usdsObjectPool.h"
#include "base\binary\usdsBinaryOutput.h"
#include "dictionary\usdsDictionary.h"

#include "body\usdsBody.h"

#include "converters\usdsBinaryCreator.h"
#include "converters\usdsBinaryParser.h"
#include "converters\usdsDictionaryTextCreator.h"
#include "converters\usdsDictionaryTextParser.h"

#include <list>

namespace usds
{
	class BasicParser : public Body
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
		void decode(const unsigned char* data, size_t data_size) throw(...);

		// clear
		void clear();		// it does not release memory in buffers
				
	private:

		Dictionary* findDictionary(int id, unsigned char major, unsigned char minor) throw(...);

		// Object pool of Dictionaries
		TemplateObjectPool<Dictionary, BasicParser> dictionaryPool;
		// All existing dictionary
		std::list<Dictionary*> dictionaries;

		BinaryCreator binaryCreator;
		BinaryParser binaryParser;
		DictionaryTextCreator dictionaryTextcreator;
		DictionaryTextParser dictionaryTextParser;

	};

};

#endif