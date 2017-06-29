#ifndef DICTIONARY_VARINT_H
#define DICTIONARY_VARINT_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryVarint : public DictionaryBaseType
	{
	public:
		DictionaryVarint(Dictionary* dict);
		virtual ~DictionaryVarint() {  };

		virtual void finalize() throw (...) { };

		usdsTypes getType() { return USDS_VARINT; };
		const char* getTypeName() { return "VARINT"; };

	private:
		void additionalInitType();

	};
};

#endif
