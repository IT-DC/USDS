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
		virtual ~DictionaryString();

		void finalize() throw (...);

		usdsTypes getType() { return USDS_STRING; };
		const char* getTypeName() { return "STRING"; };

		void setDefaultEncode(usdsEncodes value) throw(...);
		usdsEncodes getDefaultEncode() throw(...);

		void setDefaultValueFromUTF8(const char* value);
		void setDefaultValueFromUTF8(const char* value, size_t byte_size);
		const char* getUTF8DefaultValue();
		bool hasDefaultValue();

	private:
		void additionalInitType();

		usdsEncodes defaultEncode;

		bool isDefault;
		char* defaultValue;
		size_t defaultValueBufferSize;
	};


};
#endif
