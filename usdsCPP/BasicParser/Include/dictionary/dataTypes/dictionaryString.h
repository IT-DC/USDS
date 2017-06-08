#ifndef DICTIONARY_STRING_H
#define DICTIONARY_STRING_H

#include <string>

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryString : public DictionaryBaseType
	{
	public:
		DictionaryString(Dictionary* dict);
		virtual ~DictionaryString() {  };

		virtual void initType();
		virtual void finalize() throw (...);

		void setDefault(const char* value);
		void setEncode(usdsEncodes value) throw(...);

		usdsEncodes getEncode() throw(...);

	private:
		bool isDefault;
		std::string defaultValue;
		usdsEncodes encode;

	};


};
#endif
