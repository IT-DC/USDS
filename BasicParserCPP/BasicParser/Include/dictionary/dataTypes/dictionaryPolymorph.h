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

		DictionaryStruct* getTag(int32_t tag_id) throw (...);

		void finalize() throw (...);
		void getTags(DictionaryStruct** index) throw (...);

	private:
		void additionalInitType();

		DictionaryTagLink* firstSubTag;

		// field index
		int32_t subTagMaxID;
		DictionaryStruct** subTagIndex;
		int32_t buffIndexSize;
		bool indexed;


	};
}
#endif
