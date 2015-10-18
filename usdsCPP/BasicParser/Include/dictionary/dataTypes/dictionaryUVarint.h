#ifndef DIC_UVARINT_FIELD
#define DIC_UVARINT_FIELD

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\fields\dicBaseField.h"

namespace usds
{
	class DicUVarintField : public DicBaseField
	{
	public:
		DicUVarintField();
		~DicUVarintField() {  };

		virtual usdsTypes getType() { return USDS_UNSIGNED_VARINT; };
		virtual const char* getTypeName() { return typeName(USDS_UNSIGNED_VARINT); };
		virtual void clear();

		void setDefault(long long value);

	private:
		bool isDefault;
		unsigned long long defaultValue;

	};


};

#endif