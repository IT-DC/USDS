#ifndef DIC_INT_FIELD
#define DIC_INT_FIELD

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

namespace usds
{
	class DictionaryInt : public DictionaryBaseType
	{
	public:
		DictionaryInt();
		~DictionaryInt() {  };

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