#ifndef USDS_DICTIONARY
#define USDS_DICTIONARY

#include "base\usdsBinaryInput.h"
#include "base\usdsBinaryOutput.h"
#include "base\usdsObjectPool.h"
#include "base\usdsErrors.h"

#include "tags\dicBaseTag.h"
#include "tags\dicStructTag.h"

#include <iostream>

namespace usds
{
	class Dictionary
	{
	public:
		Dictionary(int id, unsigned char major, unsigned char minor);
		~Dictionary();

		const unsigned char majorVersion;
		const unsigned char minorVersion;
		const int dictionaryID;

		void clean();

		DicStructTag* addStructTag(const char* name, int id, bool root) throw (...);
		void finalizeDictionary() throw(...);

	private:

		usdsEncodes dictionaryEncode;
		DictionaryObjectPool objects;

	};
};
#endif