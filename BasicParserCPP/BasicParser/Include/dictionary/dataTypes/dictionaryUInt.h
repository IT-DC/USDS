#ifndef DICTIONARY_UINT_H
#define DICTIONARY_UINT_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryUInt : public DictionaryBaseType
	{
	public:
		DictionaryUInt(Dictionary* dict);
		virtual ~DictionaryUInt() {  };

		void finalize() throw (...) { };

		usdsType getType() { return USDS_UINT; };
		const char* getTypeName() { return "UINT"; };

		void setBigendian(bool is_bigendian) { isBigendian = is_bigendian; };
		bool getBigendian() { return isBigendian; };

		void setDefaultValue(uint32_t value);
		uint32_t getDefaultValue();
		bool hasDefaultValue();

	private:
		void additionalInitType();

		bool isBigendian;

		bool isDefault;
		uint32_t defaultValue;
	};
};

#endif
