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
		
		// construction
		DicBaseTag* addTag(usdsTypes tag_type, bool root, int id, const char* name, size_t name_size) throw (...);
		DicBaseField* addField(usdsTypes field_type, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional) throw (...);
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

		// Get tag by ID
		// returns 0 if tag not found
		DicBaseTag* getTag(int id) throw (...);
		int getTagNumber() throw (...);

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

		DicBaseTag* firstTag;
		DicBaseTag* lastTag;
		void connectTagToDictionary(DicBaseTag* tag);

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