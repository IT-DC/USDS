#ifndef USDS_DICTIONARY_TEXT_CREATOR_H
#define USDS_DICTIONARY_TEXT_CREATOR_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

#include <string>

namespace usds
{
	class Dictionary;
	class DicStructTag;
	class DicBaseTag;
	class DicBaseField;
	class DicStringField;
	class DicArrayField;

	class DictionaryTextCreator
	{
	public:
		DictionaryTextCreator() { };
		~DictionaryTextCreator() { };

		void generate(usdsEncodes encode, std::string* text, Dictionary* dict) throw (...);

	private:
		std::stringstream textBuff;
		
		void writeStructTag(DicStructTag* tag);

		void writeStringField(DicStringField* field);
		void writeArrayField(DicArrayField* field);


	};

};

#endif