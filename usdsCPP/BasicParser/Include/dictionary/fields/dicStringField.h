#ifndef DIC_STRING_FIELD
#define DIC_STRING_FIELD

#include <string>

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\fields\dicBaseField.h"

namespace usds
{
	class DicStringField : public DicBaseField
	{
	public:
		DicStringField();
		~DicStringField() {  };

		virtual usdsTypes getType() { return USDS_STRING; };
		virtual const char* getTypeName() { return typeName(USDS_STRING); };
		virtual void clear();

		void setDefault(const char* value);
		void setEncode(usdsEncodes encode) throw(...);

		usdsEncodes getEncode() throw(...);


	private:
		bool isDefault;
		std::string defaultValue;
		usdsEncodes defaultEncode;

	};


};
#endif
