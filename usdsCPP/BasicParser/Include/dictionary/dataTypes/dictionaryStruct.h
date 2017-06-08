#ifndef DICTIONARY_STRUCT_H
#define DICTIONARY_STRUCT_H

#include "usdsTypes.h"
#include "usdsErrors.h"

#include "dictionary\dictionaryBaseType.h"

#include <vector>

namespace usds
{
	class DictionaryStruct : public DictionaryBaseType
	{
	public:
		DictionaryStruct(Dictionary* dict);
		virtual ~DictionaryStruct();

		// add existing fields
		DictionaryBaseType* addField(usdsTypes field_type, int32_t id, const char* name, size_t name_size) throw(...);

		DictionaryBaseType* getFirstField();
		DictionaryBaseType* getLastField();

		int32_t getFieldNumber() throw (...);
		
		DictionaryBaseType* getField(int32_t id) throw (...);
		DictionaryBaseType* getField(const char* name) throw (...);
		DictionaryBaseType* getField(const char* name, size_t name_size) throw (...);

		// Find field ID by Name
		// return 0 if field not found
		int32_t findFieldID(const char* name) throw (...);
		int32_t findFieldID(const char* name, size_t name_size) throw (...);

		// Dictionary finalization
		virtual void finalize() throw (...);
		// it's executed in DicBaseTag.init()
		virtual void initType();

	private:


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