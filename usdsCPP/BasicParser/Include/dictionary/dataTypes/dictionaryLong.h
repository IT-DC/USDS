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
		DictionaryLong();
		~DictionaryLong() {  };

		virtual usdsTypes getType() { return USDS_LONG; };
		virtual const char* getTypeName() { return typeName(USDS_LONG); };
		virtual void clear();

		void setDefault(long long value);

	private:
		bool isDefault;
		long long defaultValue;

	};

};
#endif