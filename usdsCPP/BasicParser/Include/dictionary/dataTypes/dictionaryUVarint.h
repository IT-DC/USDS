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

		virtual void initType();
		virtual void finalize() throw (...) { };

		void setDefault(int64_t value);

	private:
		bool isDefault;
		uint64_t defaultValue;

	};


};

#endif