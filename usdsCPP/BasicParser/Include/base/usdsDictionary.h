#ifndef USDS_DICTIONARY
#define USDS_DICTIONARY

#include "base\usdsBinaryInput.h"
#include "base\usdsBinaryOutput.h"
#include "base\usdsObjectPool.h"
#include "base\usdsErrors.h"
#include "base\usdsDictionaryBaseParser.h"
#include "base\usdsDictionaryTextParser.h"

#include "tags\dicBaseTag.h"
#include "tags\dicStructTag.h"

namespace usds
{
	class Dictionary
	{
	public:
		Dictionary();
		~Dictionary();

		void clean();

		DicStructTag* addStructTag(const char* name, int id, bool root) throw (...);
		void finalizeDictionary() throw(...);

		void initFromText(const char * text_dictionary, int size, usdsEncodes encode) throw(...);


	private:

		void initDictionary(DictionaryBaseParser* parser) throw(...);

		int dictionaryID;
		unsigned char majorVersion;
		unsigned char minorVersion;
		usdsEncodes dictionaryEncode;

		DictionaryObjectPool objects;

	};
};
#endif