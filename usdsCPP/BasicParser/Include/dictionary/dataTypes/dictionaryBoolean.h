#ifndef DICTIONARY_BOOLEAN_H
#define DICTIONARY_BOOLEAN_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryBoolean : public DictionaryBaseType
	{
	public:
		DictionaryBoolean(Dictionary* dict);
		virtual ~DictionaryBoolean() {  };

		virtual void initType();
		virtual void finalize() throw (...) { };

		void setDefault(bool value);

	private:
		bool isDefault;
		bool defaultValue;

	};

};

#endif