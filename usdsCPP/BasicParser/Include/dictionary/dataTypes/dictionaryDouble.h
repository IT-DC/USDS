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

		void setDefault(double value);

	private:
		void additionalInitType();

		bool isDefault;
		double defaultValue;

	};

};
#endif