#ifndef DICTIONARY_DOUBLE_H
#define DICTIONARY_DOUBLE_H

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

namespace usds
{
	class DictionaryDouble : public DictionaryBaseType
	{
	public:
		DictionaryDouble(Dictionary* dict);
		virtual ~DictionaryDouble() {  };

		virtual void initType();
		virtual void finalize() throw (...) { };

		void setDefault(double value);

	private:
		bool isDefault;
		double defaultValue;

	};

};
#endif