#ifndef DICTIONARY_DOUBLE_H
#define DICTIONARY_DOUBLE_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryDouble : public DictionaryBaseType
	{
	public:
		DictionaryDouble(Dictionary* dict);
		virtual ~DictionaryDouble() {  };

		void finalize() throw (...) { };

		usdsTypes getType() { return USDS_DOUBLE; };
		const char* getTypeName() { return "DOUBLE"; };

		void setBigendian(bool is_bigendian) { isBigendian = is_bigendian; };
		bool getBigendian() { return isBigendian; };

	private:
		void additionalInitType();

		bool isBigendian;

	};

};
#endif