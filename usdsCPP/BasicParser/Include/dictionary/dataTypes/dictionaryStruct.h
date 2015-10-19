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
		DictionaryStruct();
		~DictionaryStruct() { };

		virtual usdsTypes getType() { return USDS_STRUCT; };
		virtual const char* getTypeName() { return typeName(USDS_STRUCT); };

		// add existing fields
		DictionaryBaseType* addField(usdsTypes field_type, int id, const char* name, size_t name_size) throw(...);

		DictionaryBaseType* getFirstField();
		DictionaryBaseType* getLastField();

		DictionaryBaseType* getField(int id) throw (...);
		int getFieldNumber() throw (...);

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
		std::vector<DictionaryBaseType*> fieldIndex;

	};






};
#endif