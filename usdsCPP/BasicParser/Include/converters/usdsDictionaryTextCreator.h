#ifndef USDS_DICTIONARY_TEXT_CREATOR
#define USDS_DICTIONARY_TEXT_CREATOR

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
		
		void writeSimpleTag(DicBaseTag* tag);
		void writeStructTag(DicStructTag* tag);

		void writeSimpleField(DicBaseField* field);
		void writeStringField(DicStringField* field);
		void writeArrayField(DicArrayField* field);


	};

};

#endif