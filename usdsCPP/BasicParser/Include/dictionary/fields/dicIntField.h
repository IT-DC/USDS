#ifndef DIC_INT_FIELD
#define DIC_INT_FIELD

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\fields\dicBaseField.h"

namespace usds
{
	class DicIntField : public DicBaseField
	{
	public:
		DicIntField();
		~DicIntField() {  };

		virtual usdsTypes getType() { return USDS_INT; };
		virtual const char* getTypeName() { return typeName(USDS_INT); };
		virtual void clear();

		void setDefault(int value);

	private:
		bool isDefault;
		int defaultValue;

	};
};

#endif