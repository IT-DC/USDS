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

		virtual void initType();
		virtual void finalize() throw (...);

		usdsTypes getElementType() throw (...);
		DictionaryBaseType* getElement() throw (...);

		DictionaryBaseType* setElementType(usdsTypes type_id) throw (...);

	private:
		DictionaryBaseType* element;

	};


};
#endif