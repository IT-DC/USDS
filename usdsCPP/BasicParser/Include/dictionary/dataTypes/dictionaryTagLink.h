#ifndef DICTIONARY_TAG_H
#define DICTIONARY_TAG_H

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

namespace usds
{
	class DictionaryTagLink : public DictionaryBaseType
	{
	public:
		DictionaryTagLink(Dictionary* dict);
		virtual ~DictionaryTagLink() {  };

		virtual void initType();
		virtual void finalize() throw (...);

		void setTag(const char* tag_name, size_t name_size) throw (...);
		void setTag(int32_t tag_id) throw (...);

		DictionaryBaseType* getTag() throw (...);

	private:
		DictionaryBaseType* tag;
		int32_t tagID;
		std::string tagName;

	};

};

#endif