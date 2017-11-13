#ifndef DICTIONARY_ARRAY_H
#define DICTIONARY_ARRAY_H

#include <string>
#include <vector>

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{

	class DictionaryArray : public DictionaryBaseType
	{
	public:
		DictionaryArray(Dictionary* dict);
		virtual ~DictionaryArray() {  };

		void finalize() throw (...);

		usdsType getType() {return USDS_ARRAY;};
		const char* getTypeName() {return "ARRAY";};

		usdsType getElementType() throw (...);
		DictionaryBaseType* getElement() throw (...);

		DictionaryBaseType* setElementType(usdsType type_id) throw (...);

		bool hasDefaultValue() { return false; };

	private:
		virtual void additionalInitType();

		DictionaryBaseType* element;

	};


};
#endif