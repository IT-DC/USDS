#ifndef USDS_ARRAY_H
#define USDS_ARRAY_H

#include "body\dataTypes\usdsBaseType.h"
#include "base\binary\usdsBinaryOutput.h"

namespace usds
{
	class UsdsArray : public UsdsBaseType
	{
	public:
		UsdsArray(Body* parent_body);
		virtual ~UsdsArray();

		UsdsBaseType* addTagElement() throw(...);

		size_t getElementNumber() throw(...);
		
		usdsTypes getElementType() throw(...);
		UsdsBaseType* getTagElement(size_t number) throw(...);

		const void* getArrayBinary() throw(...);
		size_t getArrayBinarySize() throw(...);

		void setArrayBinary(const void* binary, size_t binary_size) throw(...);

	private:

		virtual void initType();

		usdsTypes elementType;
		
		// if Element is other tag
		DictionaryBaseType* tagElement;

		BinaryOutput elementValues;
		size_t elementNumber;

	};

}

#endif