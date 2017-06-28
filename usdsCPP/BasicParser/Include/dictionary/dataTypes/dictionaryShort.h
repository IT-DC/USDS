#ifndef DICTIONARY_SHORT_H
#define DICTIONARY_SHORT_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryShort : public DictionaryBaseType
	{
	public:
		DictionaryShort(Dictionary* dict);
		virtual ~DictionaryShort() {  };

		void finalize() throw (...) { };

		usdsTypes getType() { return USDS_SHORT; };
		const char* getTypeName() { return "SHORT"; };


	private:
		void additionalInitType();

	};
};

#endif


