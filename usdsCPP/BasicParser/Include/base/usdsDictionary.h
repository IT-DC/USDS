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
		Dictionary();
		~Dictionary();

		void clean();

		DicStructTag* addStructTag(const char* name, int id, bool root) throw (...);
		void finalizeDictionary() throw(...);

	private:

		int dictionaryID;
		unsigned char majorVersion;
		unsigned char minorVersion;
		usdsEncodes dictionaryEncode;

		DictionaryObjectPool objects;

	};
};
#endif