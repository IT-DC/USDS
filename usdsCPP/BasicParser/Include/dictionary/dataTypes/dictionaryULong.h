#ifndef DICTIONARY_ULONG_H
#define DICTIONARY_ULONG_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryULong : public DictionaryBaseType
	{
	public:
		DictionaryULong(Dictionary* dict);
		virtual ~DictionaryULong() {  };

		void finalize() throw (...) { };

		usdsTypes getType() { return USDS_ULONG; };
		const char* getTypeName() { return "ULONG"; };

		void setBigendian(bool is_bigendian) { isBigendian = is_bigendian; };
		bool getBigendian() { return isBigendian; };

		void setDefaultValue(uint64_t value);
		uint64_t getDefaultValue();
		bool hasDefaultValue();

	private:
		void additionalInitType();

		bool isBigendian;

		bool isDefault;
		uint64_t defaultValue;
	};

};
#endif
