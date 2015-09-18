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

		// Dictionary construction
		void setID(int id, unsigned char major, unsigned char minor) throw (...);
		void setEncode(usdsEncodes encode) throw (...);
		// tag construction
		DicStructTag* addStructTag(const char* name, int id, bool root) throw (...);
		DicBooleanField* addBooleanField(const char* name, int id, bool is_optional) throw (...);
		DicIntField* addIntField(const char* name, int id, bool is_optional) throw (...);
		DicLongField* addLongField(const char* name, int id, bool is_optional) throw (...);
		DicDoubleField* addDoubleField(const char* name, int id, bool is_optional) throw (...);
		DicUVarintField* addUVarintField(const char* name, int id, bool is_optional) throw (...);
		DicArrayField* addArrayField(const char* name, int id, bool is_optional, const char* tag_name) throw (...);
		DicStringField* addStringField(const char* name, int id, bool is_optional) throw (...);

		void finalizeDictionary() throw(...);

		// Dictionary information
		int getDictionaryID()  throw (...);
		unsigned char getMajorVersion() throw (...);
		unsigned char getMinorVersion() throw (...);
		usdsEncodes getEncode() throw (...);
		
		// Clear dictionary, it does not release memory in DictionaryObjectPool
		void clear();

	private:

		unsigned char majorVersion;
		unsigned char minorVersion;
		int dictionaryID;
		usdsEncodes dictionaryEncode;

		DictionaryObjectPool objects;

	};
};
#endif