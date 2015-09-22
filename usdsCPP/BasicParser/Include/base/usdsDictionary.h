#ifndef USDS_DICTIONARY
#define USDS_DICTIONARY

#include "base\usdsErrors.h"
#include "tags\usdsTypes.h"

#include "base\usdsObjectPool.h"

#include <string>

namespace usds
{
	class DicStructTag;
	class DicBooleanField;
	class DicIntField;
	class DicLongField;
	class DicDoubleField;
	class DicUVarintField;
	class DicArrayField;
	class DicStringField;
	class DicBaseTag;
	
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
		// field construction
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
		
		DicBaseTag* getFirstTag() throw (...);
		DicBaseTag* getLastTag() throw (...);

		// Clear dictionary, it does not release memory in DictionaryObjectPool
		void clear();

	private:
		unsigned char majorVersion;
		unsigned char minorVersion;
		int dictionaryID;
		usdsEncodes dictionaryEncode;

		DictionaryObjectPool objectPool;

		DicBaseTag* firstTag;
		DicBaseTag* lastTag;

	};
};
#endif