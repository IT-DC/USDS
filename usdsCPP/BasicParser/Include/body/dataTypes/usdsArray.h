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

		size_t getElementNumber() throw(...);
		usdsTypes getElementType() throw(...);

		void addElement(int value) throw (...);
		void addElement(long long value) throw (...);
		void addElement(unsigned long long value) throw (...);
		void addElement(double value) throw (...);
		void addElement(const char* value) throw (...);
		void addElement(const char* value, size_t size) throw (...);
		void addElement(bool value) throw (...);
		UsdsBaseType* addTagElement() throw(...);

		int getElementIntValue(size_t number) throw (...);
		long long getElementLongValue(size_t number) throw (...);
		unsigned long long getElementULongValue(size_t number) throw (...);
		double getElementDoubleValue(size_t number) throw (...);
		const char* getElementStringValue(size_t number) throw (...);
		const char* getElementStringValue(size_t number, size_t* size) throw (...);
		bool getElementBooleanValue(size_t number) throw (...);
		UsdsBaseType* getTagElement(size_t number) throw(...);

		const void* getArrayBinary() throw(...);
		size_t getArrayBinarySize() throw(...);

		void setArrayBinary(const void* binary, size_t binary_size) throw(...);

	private:

		virtual void initType();

		usdsTypes elementType;
		DictionaryBaseType* arrayDictionaryElement;

		BinaryOutput elementValues;
		size_t elementNumber;

	};

}

#endif