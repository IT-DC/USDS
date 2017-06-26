#ifndef DICTIONARY_UBYTE_H
#define DICTIONARY_UBYTE_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryUByte : public DictionaryBaseType
	{
	public:
		DictionaryUByte(Dictionary* dict);
		virtual ~DictionaryUByte() {  };

		void finalize() throw (...) { };

		usdsTypes getType() { return USDS_UBYTE; };
		const char* getTypeName() { return "UBYTE"; };

	private:
		void additionalInitType();


	};
};

#endif
