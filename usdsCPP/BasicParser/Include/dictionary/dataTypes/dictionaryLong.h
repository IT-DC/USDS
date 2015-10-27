#ifndef DICTIONARY_LONG_H
#define DICTIONARY_LONG_H

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

namespace usds
{
	class DictionaryLong : public DictionaryBaseType
	{
	public:
		DictionaryLong(DictionaryObjectPool* parent);
		virtual ~DictionaryLong() {  };

		virtual void clear();

		void setDefault(long long value);

		DictionaryLong* NextInPool;

	private:
		bool isDefault;
		long long defaultValue;

	};

};
#endif