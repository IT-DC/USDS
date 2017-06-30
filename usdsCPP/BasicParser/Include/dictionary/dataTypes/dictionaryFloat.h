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

		usdsTypes getType() { return USDS_FLOAT; };
		const char* getTypeName() { return "FLOAT"; };

		void setBigendian(bool is_bigendian) { isBigendian = is_bigendian; };
		bool getBigendian() { return isBigendian; };

	private:
		void additionalInitType();

		bool isBigendian;

	};

};
#endif
