#ifndef DIC_STRUCT_TAG
#define DIC_STRUCT_TAG

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\tags\dicBaseTag.h"

#include <vector>

namespace usds
{
	class DicBaseField;

	class DicStructTag : public DicBaseTag
	{
	public:
		DicStructTag();
		~DicStructTag() { };

		virtual usdsTypes getType() { return USDS_STRUCT; };
		virtual const char* getTypeName() { return typeName(USDS_STRUCT); };

		// add existing fields
		DicBaseField* addField(usdsTypes field_type, int id, const char* name, size_t name_size) throw(...);

		DicBaseField* getFirstField();
		DicBaseField* getLastField();

		// Find field ID by Name
		// return 0 if field not found
		int findFieldID(const char* name) throw (...);
		int findFieldID(const char* name, size_t name_size) throw (...);

		// Dictionary finalization
		void finalizeTag() throw(...);

	private:
		// it's executed in DicBaseTag.init()
		virtual void clear();

		void connectFieldToTag(DicBaseField* field);
		DicBaseField* firstField;
		DicBaseField* lastField;

		// field index
		int fieldMaxID;
		int fieldNumber;
		std::vector<DicBaseField*> fieldIndex;

	};






};
#endif