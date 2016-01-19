#ifndef USDS_DICTIONARY_H
#define USDS_DICTIONARY_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"
#include "base\objectPool\dicObjectPool.h"
#include "base\binary\usdsBinaryOutput.h"

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
		void setID(int id, unsigned char major, unsigned char minor) throw (...);
		
		// construction
		DictionaryBaseType* addTag(usdsTypes tag_type, int id, const char* name, size_t name_size) throw (...);
		DictionaryBaseType* addField(usdsTypes field_type, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw (...);

		// Replace Tag names to tag ID, check errors
		void finalizeDictionary() throw(...);

		// Dictionary information
		int getDictionaryID()  throw (...);
		unsigned char getMajorVersion() throw (...);
		unsigned char getMinorVersion() throw (...);
		
		DictionaryBaseType* getFirstTag() throw (...);
		DictionaryBaseType* getLastTag() throw (...);

		// Find Tag ID by Name
		// returns 0 if tag not found
		int findTagID(const char* name) throw (...);
		int findTagID(const char* name, size_t name_size) throw (...);
		
		// Find Tag by Name
		// returns 0 if tag not found
		DictionaryBaseType* findTag(const char* name) throw (...);
		DictionaryBaseType* findTag(const char* name, size_t name_size) throw (...);

		// Get tag by ID
		DictionaryBaseType* getTag(int tag_id) throw (...);
		int getTagNumber() throw (...);

		// Encode dictionary
		const unsigned char* getBinary(size_t* size) throw(...);
		// add existing binary
		void setBinary(const void* data, size_t size) throw(...);

		// Clear dictionary, it does not release memory in DictionaryObjectPool
		void clear();

	private:
		unsigned char majorVersion;
		unsigned char minorVersion;
		int dictionaryID;

		DictionaryBaseType* firstTag;
		DictionaryBaseType* lastTag;
		void connectTagToDictionary(DictionaryBaseType* tag);

		// tag index
		int tagMaxID;
		int tagNumber;
		std::vector<DictionaryBaseType*> tagIndex;
		bool finalized;
		bool indexed;

		DictionaryObjectPool objectPool;

		BinaryOutput binary;

	};
};
#endif