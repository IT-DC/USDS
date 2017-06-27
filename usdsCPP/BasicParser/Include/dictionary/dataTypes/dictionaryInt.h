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

		void finalize() throw (...) { };

		usdsTypes getType() { return USDS_INT; };
		const char* getTypeName() { return "INT"; };


	private:
		void additionalInitType();

	};
};

#endif