#ifndef DICTIONARY_TAG_H
#define DICTIONARY_TAG_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryTagLink : public DictionaryBaseType
	{
	public:
		DictionaryTagLink(Dictionary* dict);
		virtual ~DictionaryTagLink() {  };

		void finalize() throw (...);

		usdsType getType() { return USDS_TAG; };
		const char* getTypeName() { return "TAG"; };

		void setTag(const char* tag_name, size_t name_size) throw (...);
		void setTag(int32_t tag_id) throw (...);

		DictionaryBaseType* getTag() throw (...);

	private:
		void additionalInitType();

		DictionaryBaseType* tag;
		int32_t tagID;
		std::string tagName;

	};

};

#endif