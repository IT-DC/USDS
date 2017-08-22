#ifndef DICTIONARY_UVARINT_H
#define DICTIONARY_UVARINT_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryUVarint : public DictionaryBaseType
	{
	public:
		DictionaryUVarint(Dictionary* dict);
		virtual ~DictionaryUVarint() {  };

		virtual void finalize() throw (...) { };

		usdsType getType() { return USDS_UVARINT; };
		const char* getTypeName() { return "UVARINT"; };

		void setDefaultValue(uint64_t value);
		uint64_t getDefaultValue();
		bool hasDefaultValue();

	private:
		void additionalInitType();

		bool isDefault;
		uint64_t defaultValue;

	};


};

#endif