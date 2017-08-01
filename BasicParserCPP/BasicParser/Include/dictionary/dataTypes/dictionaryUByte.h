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

		void setDefaultValue(uint8_t value);
		uint8_t getDefaultValue();
		bool hasDefaultValue();

	private:
		void additionalInitType();

		bool isDefault;
		uint8_t defaultValue;


	};
};

#endif
