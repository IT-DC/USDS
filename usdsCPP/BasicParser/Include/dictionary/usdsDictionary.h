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

	class Dictionary
	{
	public:
		Dictionary(BasicParser* parent);
		~Dictionary();

		// Dictionary construction
		void setID(int id, unsigned char major, unsigned char minor) throw (...);
		void setEncode(usdsEncodes encode) throw (...);
		
		// construction
		DictionaryBaseType* addTag(usdsTypes tag_type, int id, const char* name, size_t name_size) throw (...);

		// Replace Tag names to tag ID, check errors
		void finalizeDictionary() throw(...);

		// Dictionary information
		int getDictionaryID()  throw (...);
		unsigned char getMajorVersion() throw (...);
		unsigned char getMinorVersion() throw (...);
		usdsEncodes getEncode() throw (...);
		
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
		// returns 0 if tag not found
		DictionaryBaseType* getTag(int id) throw (...);
		int getTagNumber() throw (...);

		// Encode dictionary
		const unsigned char* getBinary(size_t* size) throw(...);
		// add existing binary
		void setBinary(const void* data, size_t size);

		// Clear dictionary, it does not release memory in DictionaryObjectPool
		void clear();

		Dictionary* NextInPool;

	private:
		unsigned char majorVersion;
		unsigned char minorVersion;
		int dictionaryID;
		usdsEncodes dictionaryEncode;

		DictionaryBaseType* firstTag;
		DictionaryBaseType* lastTag;
		void connectTagToDictionary(DictionaryBaseType* tag);

		// tag index
		int tagMaxID;
		int tagNumber;
		std::vector<DictionaryBaseType*> tagIndex;
		bool finalized;

		DictionaryObjectPool objectPool;

		BinaryOutput binary;

	};
};
#endif