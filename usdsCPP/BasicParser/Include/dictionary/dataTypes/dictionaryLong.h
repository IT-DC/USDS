#ifndef DICTIONARY_LONG_H
#define DICTIONARY_LONG_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryLong : public DictionaryBaseType
	{
	public:
		DictionaryLong(Dictionary* dict);
		virtual ~DictionaryLong() {  };

		virtual void initType();
		virtual void finalize() throw (...) { };

		void setDefault(int64_t value);

	private:
		bool isDefault;
		int64_t defaultValue;

	};

};
#endif