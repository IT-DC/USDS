#ifndef DIC_STRUCT_TAG
#define DIC_STRUCT_TAG

#include "tags\usdsTypes.h"
#include "base\usdsErrors.h"

#include "tags\dicBaseTag.h"

#include <vector>

namespace usds
{
	class DicBaseField;
	class DicIntField;
	class DicLongField;
	class DicDoubleField;
	class DicUVarintField;
	class DicStringField;
	class DicArrayField;

	class DicStructTag : public DicBaseTag
	{
	public:
		DicStructTag();
		~DicStructTag() { };

		virtual usdsTypes getType() { return USDS_STRUCT; };
		virtual const char* getTypeName() { return typeName(USDS_STRUCT); };
		virtual void writeToBinary(BinaryOutput* buff) throw(...);

		// add existing fields
		void setFields(DicBaseField* fields) throw(...);

		DicBaseField* getFirstField();
		DicBaseField* getLastField();

		DicIntField* addIntField(const char* name, int id, bool optional) throw(...);
		DicIntField* addIntField(const char* name, int id, int default_value) throw(...);

		DicLongField* addLongField(const char* name, int id, bool optional) throw(...);
		DicLongField* addLongField(const char* name, int id, long long default_value) throw(...);

		DicDoubleField* addDoubleField(const char* name, int id, bool optional) throw(...);
		DicDoubleField* addDoubleField(const char* name, int id, double default_value) throw(...);

		DicUVarintField* addUVarintField(const char* name, int id, bool optional) throw(...);
		DicUVarintField* addUVarintField(const char* name, int id, long long default_value) throw(...);

		DicStringField* addStringField(const char* name, int id, bool optional) throw(...);
		DicStringField* addStringField(const char* name, int id, const char* default_value) throw(...);

		DicArrayField* addArrayField(const char* name, int id, usdsTypes element_type, int size, bool optional) throw(...);

		// Find field ID by Name
		// return 0 if field not found
		int findFieldID(const char* name) throw (...);

		// Dictionary finalization
		void finalizeTag() throw(...);

	private:
		// it's executed in DicBaseTag.init()
		virtual void clear();

		DicBaseField* firstField;
		DicBaseField* lastField;

		void checkFieldAttribute(int id, const char* name) throw (...);

		// field index
		int fieldMaxID;
		int fieldNumber;
		std::vector<DicBaseField*> fieldIndex;

	};






};
#endif