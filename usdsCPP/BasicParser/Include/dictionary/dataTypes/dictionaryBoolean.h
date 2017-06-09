#ifndef DICTIONARY_BOOLEAN_H
#define DICTIONARY_BOOLEAN_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryBoolean : public DictionaryBaseType
	{
	public:
		DictionaryBoolean(Dictionary* dict);
		virtual ~DictionaryBoolean() {  };

		void finalize() throw (...) { };
		
		usdsTypes getType() { return USDS_BOOLEAN; };
		const char* getTypeName() { return "BOOLEAN"; };

		void setDefault(bool value);

	private:
		void additionalInitType();

		bool isDefault;
		bool defaultValue;

	};

};

#endif