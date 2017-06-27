#ifndef DICTIONARY_UINT_H
#define DICTIONARY_UINT_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryUInt : public DictionaryBaseType
	{
	public:
		DictionaryUInt(Dictionary* dict);
		virtual ~DictionaryUInt() {  };

		void finalize() throw (...) { };

		usdsTypes getType() { return USDS_UINT; };
		const char* getTypeName() { return "UINT"; };


	private:
		void additionalInitType();

	};
};

#endif
