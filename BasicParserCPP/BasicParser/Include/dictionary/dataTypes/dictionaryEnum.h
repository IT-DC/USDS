#ifndef DICTIONARY_STRUCT_H
#define DICTIONARY_STRUCT_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryEnum : public DictionaryBaseType
	{
	public:
		DictionaryEnum(Dictionary* dict);
		virtual ~DictionaryEnum();

		DictionaryBaseType* addEnumerator(int64_t value, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addEnumerator(uint64_t value, const char* name, size_t name_size) throw(...);


	private:





	};
}

#endif

