#ifndef USDS_DICTIONARY_H
#define USDS_DICTIONARY_H

#include "usdsErrors.h"
#include "usdsTypes.h"
#include "dictionary\dicObjectPool.h"
#include "usdsBinaryOutput.h"

#include <string>
#include <vector>

namespace usds
{
	class DictionaryStruct;
	class DictionaryBaseType;
	class BasicParser;

	class Dictionary : public BasePoolObject
	{
	public:
		Dictionary(BasicParser* parent);
		~Dictionary();

		// Dictionary construction
		void setID(int32_t id, uint8_t major, uint8_t minor) throw (...);
		
		// construction
		DictionaryBaseType* addTag(usdsTypes tag_type, int32_t id, const char* name, size_t name_size) throw (...);
		DictionaryBaseType* addField(usdsTypes field_type, DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw (...);

		// Replace Tag names to tag ID, check errors
		void finalizeDictionary() throw(...);

		// Dictionary information
		int32_t getDictionaryID()  throw (...);
		uint8_t getMajorVersion() throw (...);
		uint8_t getMinorVersion() throw (...);
		
		DictionaryBaseType* getFirstTag() throw (...);
		DictionaryBaseType* getLastTag() throw (...);

		// Find Tag ID by Name
		// returns 0 if tag not found
		int32_t findTagID(const char* name) throw (...);
		int32_t findTagID(const char* name, size_t name_size) throw (...);
		
		// Find Tag by Name
		// returns 0 if tag not found
		DictionaryBaseType* findTag(const char* name) throw (...);
		DictionaryBaseType* findTag(const char* name, size_t name_size) throw (...);

		// Get tag by ID
		DictionaryBaseType* getTag(int32_t tag_id) throw (...);
		int32_t getTagNumber() throw (...);

		// Encode dictionary
		const uint8_t* getBinary(size_t* size) throw(...);
		// add existing binary
		void setBinary(const void* data, size_t size) throw(...);

		// Clear dictionary, it does not release memory in DictionaryObjectPool
		void clear();

	private:
		uint8_t majorVersion;
		uint8_t minorVersion;
		int32_t dictionaryID;

		DictionaryBaseType* firstTag;
		DictionaryBaseType* lastTag;
		void connectTagToDictionary(DictionaryBaseType* tag);

		// tag index
		int32_t tagMaxID;
		int32_t tagNumber;
		std::vector<DictionaryBaseType*> tagIndex;
		bool finalized;
		bool indexed;

		DictionaryObjectPool objectPool;

		BinaryOutput binary;

	};
};
#endif