#ifndef USDS_DICTIONARY
#define USDS_DICTIONARY

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"
#include "base\object pool\dicObjectPool.h"
#include "base\binary\usdsBinaryOutput.h"

#include <string>
#include <vector>

namespace usds
{
	class DicStructTag;
	class DicBaseTag;
	class DicBaseField;

	class Dictionary
	{
	public:
		Dictionary();
		~Dictionary();

		// Dictionary construction
		void setID(int id, unsigned char major, unsigned char minor) throw (...);
		void setEncode(usdsEncodes encode) throw (...);
		
		// construction
		DicBaseTag* addTag(usdsTypes tag_type, int id, const char* name, size_t name_size) throw (...);
		DicBaseField* addField(usdsTypes field_type, DicStructTag* tag, int id, const char* name, size_t name_size) throw (...);
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

		// Encode dictionary
		const unsigned char* getBinary(size_t* size) throw(...);
		// add existing binary
		void setBinary(const void* data, size_t size, bool addHead, bool addSize);

		// Clear dictionary, it does not release memory in DictionaryObjectPool
		void clear();

		// For Struct tag
		DictionaryObjectPool* getObjectPool() { return &objectPool; };

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

		DictionaryObjectPool objectPool;

		BinaryOutput binary;

	};
};
#endif