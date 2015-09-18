#ifndef DIC_STRUCT_TAG
#define DIC_STRUCT_TAG

#include <string>

#include "tags\usdsTypes.h"
#include "tags\dicBaseTag.h"
#include "tags\dicStructFields.h"

#include "base\usdsErrors.h"

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
		DicStructTag(DictionaryObjectPool* pull);
		~DicStructTag();

		usdsTypes getType() { return USDS_STRUCT; };
		void writeToBinary(BinaryOutput buff) throw(...);

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

	private:

		DicBaseField* firstField;
		DicBaseField* lastField;


	};






};
#endif