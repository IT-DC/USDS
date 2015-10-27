#ifndef DICTIONARY_DOUBLE_H
#define DICTIONARY_DOUBLE_H

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\dataTypes\dictionaryBaseType.h"

namespace usds
{
	class DictionaryDouble : public DictionaryBaseType
	{
	public:
		DictionaryDouble(DictionaryObjectPool* parent);
		virtual ~DictionaryDouble() {  };

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