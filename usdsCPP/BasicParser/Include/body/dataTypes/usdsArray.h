#ifndef USDS_ARRAY_H
#define USDS_ARRAY_H

#include "body\dataTypes\usdsBaseType.h"
#include "base\binary\usdsBinaryOutput.h"

namespace usds
{
	class UsdsArray : public UsdsBaseType
	{
	public:
		UsdsArray(BodyObjectPool* object_pool);
		~UsdsArray();

		UsdsBaseType* addTagElement() throw(...);


	private:

		virtual void clear();

		usdsTypes elementType;
		
		// if Element is other tag
		DictionaryBaseType* tagElement;

		BinaryOutput elementValues;
		size_t elementNumber;

	};

}

#endif