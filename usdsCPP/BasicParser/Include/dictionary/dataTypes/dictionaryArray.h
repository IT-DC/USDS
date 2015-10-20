#ifndef DICTIONARY_ARRAY_H
#define DICTIONARY_ARRAY_H

#include <string>
#include <vector>

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

namespace usds
{

	class DictionaryArray : public DictionaryBaseType
	{
	public:
		DictionaryArray(DictionaryObjectPool* parent);
		~DictionaryArray() {  };

		virtual usdsTypes getType() { return USDS_ARRAY; };
		virtual const char* getTypeName() { return typeName(USDS_ARRAY); };
		virtual void clear();

		usdsTypes getElementType() throw (...);

		void setElementAsTag(const char* tag_name, size_t name_size) throw (...);
		void setElementAsTag(int tag_id) throw (...);
		int getElementTagID() throw (...);
		const char* getElementTagName() throw (...);

		void finalize() throw (...);

	private:
		int arraySize;

		// simple type, USDS_STRING, USDS_TAG or USDS_POLYMORPH
		usdsTypes elementType;

		// if it's polymorph array (USDS_POLYMORPH)
		std::vector<int> elementTagIDs;
		std::vector<std::string> elementTagNames;

		// if elements is USDS_STRING
		usdsEncodes elementEncode;

		// if elements is USDS_TAG
		int elementTagID;
		std::string elementTagName;
		bool elementTagNeedID;
		bool elementTagNeedName;

	};


};
#endif