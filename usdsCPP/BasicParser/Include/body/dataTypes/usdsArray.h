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

		size_t size() throw(...);
		usdsTypes getElementType() throw(...);

		void pushBack(int value) throw (...);
		void pushBack(long long value) throw (...);
		void pushBack(unsigned long long value) throw (...);
		void pushBack(double value) throw (...);
		void pushBack(const char* value) throw (...);
		void pushBack(const char* value, size_t size) throw (...);
		void pushBack(bool value) throw (...);

		void pushBefore(size_t number, int value) throw (...);
		void pushBefore(size_t number, long long value) throw (...);
		void pushBefore(size_t number, unsigned long long value) throw (...);
		void pushBefore(size_t number, double value) throw (...);
		void pushBefore(size_t number, const char* value) throw (...);
		void pushBefore(size_t number, const char* value, size_t size) throw (...);
		void pushBefore(size_t number, bool value) throw (...);

		void setValue(size_t number, int value) throw (...);
		void setValue(size_t number, long long value) throw (...);
		void setValue(size_t number, unsigned long long value) throw (...);
		void setValue(size_t number, double value) throw (...);
		void setValue(size_t number, const char* value) throw (...);
		void setValue(size_t number, const char* value, size_t size) throw (...);
		void setValue(size_t number, bool value) throw (...);

		void getValue(size_t number, int* value) throw (...);
		void getValue(size_t number, long long* value) throw (...);
		void getValue(size_t number, unsigned long long* value) throw (...);
		void getValue(size_t number, double* value) throw (...);
		void getValue(size_t number, const char** value) throw (...);
		void getValue(size_t number, const char** value, size_t* size) throw (...);
		void getValue(size_t number, bool* value) throw (...);
		template <typename out_type> out_type getValue(size_t number) throw (...);

		UsdsBaseType* pushTagBack() throw(...);
		UsdsBaseType* pushTagBefore(size_t number) throw(...);
		UsdsBaseType* getTag(size_t number) throw(...);

		void erase(size_t number) throw (...);

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

	template <typename out_type> out_type UsdsArray::getValue(size_t number) throw (...)
	try
	{
		out_type value;
		getValue(number, &value);
		return value;
	}
	catch (ErrorStack& err)
	{
		err.addLevel("template <typename out_type> out_type UsdsArray::getValue") << number;
		throw;
	};

}

#endif