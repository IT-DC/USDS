#ifndef DICTIONARY_STRING_H
#define DICTIONARY_STRING_H

#include <string>

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

namespace usds
{
	class DictionaryString : public DictionaryBaseType
	{
	public:
		DictionaryString(DictionaryObjectPool* parent);
		~DictionaryString() {  };

		virtual usdsTypes getType() { return USDS_STRING; };
		virtual const char* getTypeName() { return typeName(USDS_STRING); };
		virtual void clear();

		void setDefault(const char* value);
		void setEncode(usdsEncodes encode) throw(...);

		usdsEncodes getEncode() throw(...);


	private:
		bool isDefault;
		std::string defaultValue;
		usdsEncodes defaultEncode;

	};


};
#endif
