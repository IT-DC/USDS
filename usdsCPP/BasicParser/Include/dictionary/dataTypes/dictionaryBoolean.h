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
		DictionaryBoolean(Dictionary* dict);
		virtual ~DictionaryBoolean() {  };

		virtual void initType();

		void setDefault(bool value);

	private:
		bool isDefault;
		bool defaultValue;

	};

};

#endif