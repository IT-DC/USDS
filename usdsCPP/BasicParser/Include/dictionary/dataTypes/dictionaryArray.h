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
		DictionaryArray(Dictionary* dict);
		virtual ~DictionaryArray() {  };

		virtual void initType();

		usdsTypes getElementType() throw (...);
		DictionaryBaseType* getElement() throw (...);

		void setElementType(usdsTypes type_id) throw (...);
		void setElementAsTag(const char* tag_name, size_t name_size) throw (...);
		void setElementAsTag(int tag_id) throw (...);
		int getElementTagID() throw (...);
		DictionaryBaseType* getElementTag() throw (...);
		const char* getElementTagName() throw (...);

		void finalize() throw (...);

	private:
		int arraySize;

		usdsTypes elementType;
		DictionaryBaseType* element;

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