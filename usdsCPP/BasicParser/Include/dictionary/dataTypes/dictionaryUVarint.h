#ifndef DICTIONARY_UVARINT_H
#define DICTIONARY_UVARINT_H

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

namespace usds
{
	class DictionaryUVarint : public DictionaryBaseType
	{
	public:
		DictionaryUVarint(DictionaryObjectPool* parent);
		virtual ~DictionaryUVarint() {  };

		virtual void clear();

		void setDefault(long long value);

		DictionaryUVarint* NextInPool;

	private:
		bool isDefault;
		unsigned long long defaultValue;

	};


};

#endif