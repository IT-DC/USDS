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

		usdsType getType() { return USDS_SHORT; };
		const char* getTypeName() { return "SHORT"; };

		void setBigendian(bool is_bigendian) { isBigendian = is_bigendian; };
		bool getBigendian() { return isBigendian; };

		void setDefaultValue(int16_t value);
		int16_t getDefaultValue();
		bool hasDefaultValue();

	private:
		void additionalInitType();

		bool isBigendian;

		bool isDefault;
		int16_t defaultValue;

	};
};

#endif


