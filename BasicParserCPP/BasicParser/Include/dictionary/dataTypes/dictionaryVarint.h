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

		usdsType getType() { return USDS_VARINT; };
		const char* getTypeName() { return "VARINT"; };

		void setDefaultValue(int64_t value);
		int64_t getDefaultValue();
		bool hasDefaultValue();

	private:
		void additionalInitType();

		bool isDefault;
		int64_t defaultValue;

	};
};

#endif
