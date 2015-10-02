#ifndef DIC_DOUBLE_FIELD
#define DIC_DOUBLE_FIELD

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\fields\dicBaseField.h"

namespace usds
{
	class DicDoubleField : public DicBaseField
	{
	public:
		DicDoubleField();
		~DicDoubleField() {  };

		virtual usdsTypes getType() { return USDS_DOUBLE; };
		virtual const char* getTypeName() { return typeName(USDS_DOUBLE); };
		virtual void clear();

		void setDefault(double value);

	private:
		bool isDefault;
		double defaultValue;

	};

};
#endif