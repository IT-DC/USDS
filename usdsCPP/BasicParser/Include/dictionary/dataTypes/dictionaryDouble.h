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

		virtual void initType();
		virtual void finalize() throw (...) { };

		void setDefault(double value);

	private:
		bool isDefault;
		double defaultValue;

	};

};
#endif