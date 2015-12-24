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
		DictionaryUVarint(Dictionary* dict);
		virtual ~DictionaryUVarint() {  };

		virtual void clear();

		void setDefault(long long value);

	private:
		bool isDefault;
		unsigned long long defaultValue;

	};


};

#endif