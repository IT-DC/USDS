#ifndef DICTIONARY_INT_H
#define DICTIONARY_INT_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryInt : public DictionaryBaseType
	{
	public:
		DictionaryInt(Dictionary* dict);
		virtual ~DictionaryInt() {  };

		virtual void initType();
		virtual void finalize() throw (...) { };

		void setDefault(int32_t value);

	private:
		bool isDefault;
		int32_t defaultValue;

	};
};

#endif