#ifndef DICTIONARY_BOOLEAN_H
#define DICTIONARY_BOOLEAN_H

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

namespace usds
{
	class DictionaryBoolean : public DictionaryBaseType
	{
	public:
		DictionaryBoolean(DictionaryObjectPool* parent);
		virtual ~DictionaryBoolean() {  };

		virtual void clear();

		void setDefault(bool value);

		DictionaryBoolean* NextInPool;

	private:
		bool isDefault;
		bool defaultValue;

	};

};

#endif