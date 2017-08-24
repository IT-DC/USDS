#ifndef DICTIONARY_ENUM_H
#define DICTIONARY_ENUM_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryEnum : public DictionaryBaseType
	{
	public:
		DictionaryEnum(Dictionary* dict);
		virtual ~DictionaryEnum();

		void setSubtype(usdsType subtype, bool is_bigendian);
		usdsType getSubtype();
		bool isSubtypeBigendian();

		void addEnumerator(int64_t value, const char* name, size_t name_size) throw(...);
		int64_t addEnumerator(const char* name, size_t name_size) throw(...);

		// return 0 if not found
		const char* getEnumerator(int64_t value);

		void setDefaultValue(int64_t value);
		int64_t getDefaultValue();
		bool hasDefaultValue();

		// Dictionary finalization
		void finalize() throw (...);

		// for autotests
		bool isIndexed();

		usdsType getType() { return USDS_ENUM; };
		const char* getTypeName() { return "ENUM"; };

	private:

		// it's executed in DicBaseTag.initType()
		void additionalInitType();

		usdsType subType;
		bool isBigendian;

		bool isDefault;
		int64_t defaultValue;

		struct Enumerator
		{
			int64_t value;
			char name[512-sizeof(int64_t)];
		};

		Enumerator* enumerators;
		size_t enumeratorNumbers;
		size_t enumeratorBufferSize;

		// sorted enumerators
		Enumerator** index;
		size_t indexBufferSize;
		bool isIndexUsed;	// index is not being used, if size is too big
		int64_t enumeratorMinValue;
		int64_t enumeratorMaxValue;
		int64_t lastAddedEnumerator;

		bool isFinalized;

	};
}

#endif

