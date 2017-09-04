#ifndef USDS_BASIC_PARSER_H
#define USDS_BASIC_PARSER_H

#include "usdsErrors.h"
#include "usdsTypes.h"

#include "dictionary\usdsDictionary.h"
#include "common\objectPool.h"
#include "binary\usdsBinaryOutput.h"
#include "body\usdsBody.h"

#include "converters\usdsBinaryCreator.h"
#include "converters\usdsBinaryParser.h"
#include "converters\usdsDictionaryTextCreator.h"
#include "converters\usdsDictionaryTextParser.h"
#include "converters\usdsBodyJsonCreator.h"

#include <list>

namespace usds
{
	class BasicParser
	{
	public:
		BasicParser();
		virtual ~BasicParser();

		// Settings
		const uint8_t usdsMajor;
		const uint8_t usdsMinor;

		// Dictionary constructors
		void addDictionaryFromText(const char* text_dictionary, size_t size, usdsEncode encode) throw(...);
		void CurrentDictionaryToText(usdsEncode encode, std::string* text) throw(...);

		// Working with several dictionaries
		Dictionary* selectDictionary(int32_t id, uint8_t major, uint8_t minor) throw(...);
		Dictionary* selectFirstDictionary() throw(...);
		Dictionary* selectNextDictionary() throw(...);

		// Return parameters for current dictionary
		int32_t getDictionaryID() throw(...);
		uint8_t getDictionaryMajor() throw(...);
		uint8_t getDictionaryMinor() throw(...);
		const char* getDictionaryName() throw(...);

		// Find id by names
		int32_t getTagID(const char* name) throw(...);
		int32_t getFieldID(int32_t tag_id, const char* name) throw(...);
		UsdsBaseType* getFirstTag(const char* name) throw(...);
		UsdsStruct* getFirstStructTag(const char* name) throw(...);

		// Body constructions
		UsdsBaseType* addTag(int32_t id) throw(...);
		UsdsStruct* addStructTag(const char* name) throw(...);
		UsdsStruct* addStructTag(int32_t id) throw(...);

		// encode
		void encode(BinaryOutput* buff, bool with_head, bool with_dictionary, bool with_body) throw(...);
		void getJSON(usdsEncode encode, std::string* text) throw(...);

		// decode
		void decode(const uint8_t* data, size_t data_size) throw(...);

		// clear
		void clear();		// it does not release memory in buffers
		void clearBody();

	private:

		Dictionary* findDictionary(int32_t id, uint8_t major, uint8_t minor) throw(...);

		// Object pool of Dictionaries
		TemplateObjectPool<Dictionary, BasicParser> dictionaryPool;
		// All existing dictionary
		std::list<Dictionary*> dictionaries;
		Dictionary* currentDictionary;

		Body body;

		BinaryCreator binaryCreator;
		BinaryParser binaryParser;
		DictionaryTextCreator dictionaryTextcreator;
		DictionaryTextParser dictionaryTextParser;
		BodyJsonCreator jsonCreator;

	};

};

#endif