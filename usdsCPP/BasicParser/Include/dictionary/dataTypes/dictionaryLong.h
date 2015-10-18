#ifndef DIC_LONG_FIELD
#define DIC_LONG_FIELD

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

namespace usds
{
	class DicLongField : public DicBaseField
	{
	public:
		DicLongField();
		~DicLongField() {  };

		virtual usdsTypes getType() { return USDS_LONG; };
		virtual const char* getTypeName() { return typeName(USDS_LONG); };
		virtual void clear();

		void setDefault(long long value);

	private:
		bool isDefault;
		long long defaultValue;

	};

};
#endif