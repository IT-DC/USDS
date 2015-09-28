#ifndef USDS_DICTIONARY
#define USDS_DICTIONARY

#include "base\usdsErrors.h"
#include "tags\usdsTypes.h"
#include "base\usdsBinaryOutput.h"
#include "base\usdsObjectPool.h"

#include <string>
#include <vector>

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
	class DictionaryObjectPool;
	
	class Dictionary
	{
	public:
		Dictionary();
		~Dictionary();

		// Dictionary construction
		void setID(int id, unsigned char major, unsigned char minor) throw (...);
		void setEncode(usdsEncodes encode) throw (...);
		
		// tag construction
		DicBaseTag* addTag(bool root, int id, const char* name, size_t name_size, usdsTypes tag_type) throw (...);
		DicStructTag* addStructTag(bool root, int id, const char* name, size_t name_size) throw (...);
		
		// field construction
		DicBooleanField* addBooleanField(int id, const char* name, size_t name_size, bool is_optional) throw (...);
		DicIntField* addIntField(int id, const char* name, size_t name_size, bool is_optional) throw (...);
		DicLongField* addLongField(int id, const char* name, size_t name_size, bool is_optional) throw (...);
		DicDoubleField* addDoubleField(int id, const char* name, size_t name_size, bool is_optional) throw (...);
		DicUVarintField* addUVarintField(int id, const char* name, size_t name_size, bool is_optional) throw (...);
		DicArrayField* addArrayField(int id, const char* name, size_t name_size, bool is_optional) throw (...);
		DicStringField* addStringField(int id, const char* name, size_t name_size, bool is_optional) throw (...);

		// Replace Tag names to tag ID, check errors
		void finalizeDictionary() throw(...);

		// Dictionary information
		int getDictionaryID()  throw (...);
		unsigned char getMajorVersion() throw (...);
		unsigned char getMinorVersion() throw (...);
		usdsEncodes getEncode() throw (...);
		
		DicBaseTag* getFirstTag() throw (...);
		DicBaseTag* getLastTag() throw (...);

		// Find Tag ID by Name
		// returns 0 if tag not found
		int findTagID(const char* name) throw (...);
		int findTagID(const char* name, size_t name_size) throw (...);

		// encode
		const unsigned char* getBinary(size_t* size) throw (...);
		// decode
		void initFromBinary(const void* buff, size_t size);

		// Clear dictionary, it does not release memory in DictionaryObjectPool
		void clear();

	private:
		unsigned char majorVersion;
		unsigned char minorVersion;
		int dictionaryID;
		usdsEncodes dictionaryEncode;

		void connectTagToDictionary(DicBaseTag* tag);
		void checkTagAttribute(int id, const char* name) throw (...);
		void checkTagAttribute(int id, const char* name, size_t name_size) throw (...);

		DicBaseTag* firstTag;
		DicBaseTag* lastTag;

		// tag index
		int tagMaxID;
		int tagNumber;
		std::vector<DicBaseTag*> tagIndex;
		bool finalized;

		// for serialization
		DictionaryObjectPool objectPool;
		BinaryOutput binaryDictionary;
		bool binaryExists;

	};
};
#endif