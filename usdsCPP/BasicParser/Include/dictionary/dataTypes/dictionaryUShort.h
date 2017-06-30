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

	private:
		void additionalInitType();

		bool isBigendian;
	};
};

#endif



