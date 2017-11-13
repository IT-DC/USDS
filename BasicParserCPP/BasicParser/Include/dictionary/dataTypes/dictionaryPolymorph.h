#ifndef DICTIONARY_POLYMORPH_H
#define DICTIONARY_POLYMORPH_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"


namespace usds
{
	class DictionaryTagLink;
	class DictionaryStruct;

	class DictionaryPolymorph : public DictionaryBaseType
	{
	public:
		DictionaryPolymorph(Dictionary* dict);
		virtual ~DictionaryPolymorph();

		usdsType getType() { return USDS_POLYMORPH; };
		const char* getTypeName() { return "POLYMORPH"; };

		void addTag(const char* tag_name, size_t name_size) throw (...);
		void addTag(int32_t tag_id) throw (...);
		void setTags(DictionaryTagLink* tags_chain) throw (...);

		int32_t getSubtagId(const char* tag_name) throw (...);

		DictionaryStruct* getSubStruct(int32_t tag_id) throw (...);
		DictionaryStruct* getSubStruct(const char* tag_name) throw (...);

		void finalize() throw (...);
		void getSubStructs(DictionaryStruct** index) throw (...);
		DictionaryTagLink* getFirstTag() throw (...);

		bool hasDefaultValue() { return false; };

	private:
		void additionalInitType();

		DictionaryTagLink* firstSubTag;
		DictionaryTagLink* lastSubTag;
		bool tagsFinalized;
		bool checkRecursion;

		// field index
		int32_t subTagMaxID;
		DictionaryStruct** subTagIndex;
		int32_t buffIndexSize;
		bool indexed;


	};
}
#endif
