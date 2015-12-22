#ifndef DICTIONARY_STRUCT_H
#define DICTIONARY_STRUCT_H

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

#include <vector>

namespace usds
{
	class DictionaryStruct : public DictionaryBaseType
	{
	public:
		DictionaryStruct(DictionaryObjectPool* parent);
		virtual ~DictionaryStruct() { delete[] fieldIndex; };

		// add existing fields
		DictionaryBaseType* addField(usdsTypes field_type, int id, const char* name, size_t name_size) throw(...);

		DictionaryBaseType* getFirstField();
		DictionaryBaseType* getLastField();

		int getFieldNumber() throw (...);
		
		DictionaryBaseType* getField(int id) throw (...);
		DictionaryBaseType* getField(const char* name) throw (...);
		DictionaryBaseType* getField(const char* name, size_t name_size) throw (...);

		// Find field ID by Name
		// return 0 if field not found
		int findFieldID(const char* name) throw (...);
		int findFieldID(const char* name, size_t name_size) throw (...);

		// Dictionary finalization
		void finalize() throw(...);

	private:
		// it's executed in DicBaseTag.init()
		virtual void clear();

		void connectFieldToTag(DictionaryBaseType* field);
		DictionaryBaseType* firstField;
		DictionaryBaseType* lastField;

		// field index
		int fieldMaxID;
		int fieldNumber;
		DictionaryBaseType** fieldIndex;
		int buffIndexSize;

	};






};
#endif