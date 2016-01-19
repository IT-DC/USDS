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
		virtual void finalize() throw (...);

		usdsTypes getElementType() throw (...);
		DictionaryBaseType* getElement() throw (...);

		DictionaryBaseType* setElementType(usdsTypes type_id) throw (...);
		void setElementAsTag(const char* tag_name, size_t name_size) throw (...);
		void setElementAsTag(int tag_id) throw (...);
		int getElementTagID() throw (...);
		const char* getElementTagName() throw (...);

	private:
		usdsTypes elementType;
		DictionaryBaseType* element;

		// if element is USDS_TAG 
		int elementTagID;
		std::string elementTagName;

	};


};
#endif