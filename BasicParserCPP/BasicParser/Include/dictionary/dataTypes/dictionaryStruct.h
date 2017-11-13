#ifndef DICTIONARY_STRUCT_H
#define DICTIONARY_STRUCT_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

namespace usds
{
	class DictionaryStruct : public DictionaryBaseType
	{
	public:
		DictionaryStruct(Dictionary* dict);
		virtual ~DictionaryStruct();

		DictionaryBaseType* addField(usdsType field_type, int32_t id, const char* name, size_t name_size) throw(...);
		DictionaryBaseType* addField(usdsType field_type, const char* name, size_t name_size) throw(...);

		DictionaryBaseType* getFirstField();
		DictionaryBaseType* getLastField();

		int32_t getFieldNumbers() throw (...);
		
		DictionaryBaseType* getField(int32_t id) throw (...);
		DictionaryBaseType* getField(const char* name) throw (...);
		DictionaryBaseType* getField(const char* name, size_t name_size) throw (...);

		// Find field ID by Name
		// return 0 if field not found
		int32_t findFieldID(const char* name) throw (...);
		int32_t findFieldID(const char* name, size_t name_size) throw (...);

		// Dictionary finalization
		void finalize() throw (...);

		usdsType getType() { return USDS_STRUCT; };
		const char* getTypeName() { return "STRUCT"; };

		bool hasDefaultValue() { return false; };

	private:
		// it's executed in DicBaseTag.initType()
		void additionalInitType();


		void connectFieldToTag(DictionaryBaseType* field);
		DictionaryBaseType* firstField;
		DictionaryBaseType* lastField;

		// field index
		int32_t fieldMaxID;
		int32_t fieldNumber;
		DictionaryBaseType** fieldIndex;
		int32_t buffIndexSize;
		bool indexed;

	};






};
#endif