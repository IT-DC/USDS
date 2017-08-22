#ifndef DICTIONARY_FLOAT_H
#define DICTIONARY_FLOAT_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryFloat : public DictionaryBaseType
	{
	public:
		DictionaryFloat(Dictionary* dict);
		virtual ~DictionaryFloat() {  };

		void finalize() throw (...) { };

		usdsType getType() { return USDS_FLOAT; };
		const char* getTypeName() { return "FLOAT"; };

		void setBigendian(bool is_bigendian) { isBigendian = is_bigendian; };
		bool getBigendian() { return isBigendian; };

		void setDefaultValue(float value);
		float getDefaultValue();
		bool hasDefaultValue();

	private:
		void additionalInitType();

		bool isBigendian;

		bool isDefault;
		float defaultValue;

	};

};
#endif
