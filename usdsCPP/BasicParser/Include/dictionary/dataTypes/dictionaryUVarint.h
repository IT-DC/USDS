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
		DictionaryUVarint();
		~DictionaryUVarint() {  };

		virtual usdsTypes getType() { return USDS_UNSIGNED_VARINT; };
		virtual const char* getTypeName() { return typeName(USDS_UNSIGNED_VARINT); };
		virtual void clear();

		void setDefault(long long value);

	private:
		bool isDefault;
		unsigned long long defaultValue;

	};


};

#endif