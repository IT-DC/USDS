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

		void finalize() throw (...) { };

		usdsTypes getType() { return USDS_LONG; };
		const char* getTypeName() { return "LONG"; };

	private:
		void additionalInitType();

	};

};
#endif