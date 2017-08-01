#ifndef DICTIONARY_USHORT_H
#define DICTIONARY_USHORT_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryUShort : public DictionaryBaseType
	{
	public:
		DictionaryUShort(Dictionary* dict);
		virtual ~DictionaryUShort() {  };

		void finalize() throw (...) { };

		usdsTypes getType() { return USDS_USHORT; };
		const char* getTypeName() { return "USHORT"; };

		void setBigendian(bool is_bigendian) { isBigendian = is_bigendian; };
		bool getBigendian() { return isBigendian; };

		void setDefaultValue(uint16_t value);
		uint16_t getDefaultValue();
		bool hasDefaultValue();

	private:
		void additionalInitType();

		bool isBigendian;

		bool isDefault;
		uint16_t defaultValue;

	};
};

#endif



