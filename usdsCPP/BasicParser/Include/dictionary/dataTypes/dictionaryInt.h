#ifndef DICTIONARY_INT_H
#define DICTIONARY_INT_H

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

namespace usds
{
	class DictionaryInt : public DictionaryBaseType
	{
	public:
		DictionaryInt(DictionaryObjectPool* parent);
		virtual ~DictionaryInt() {  };

		virtual void clear();

		void setDefault(int value);

	private:
		bool isDefault;
		int defaultValue;

	};
};

#endif