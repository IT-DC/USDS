#ifndef USDS_ARRAY_H
#define USDS_ARRAY_H

#include "body\usdsBaseType.h"
#include "binary\usdsBinaryOutput.h"

namespace usds
{
	class UsdsStruct;

	class UsdsArray : public UsdsBaseType
	{
	public:
		UsdsArray(Body* parent_body);
		virtual ~UsdsArray();

		usdsType getType() { return USDS_ARRAY; };
		const char* getTypeName() { return "ARRAY"; };

		size_t getSize();
		usdsType getElementType();
		const char* getElementName();
		size_t getElementNameSize();
		bool isBigendianElement();

		void setBufferSize(size_t buffer_size) throw(...);
		size_t getBufferSize();

		void pushBack(bool value) throw (...);
		void pushBack(int8_t value) throw (...);
		void pushBack(uint8_t value) throw (...);
		void pushBack(int16_t value) throw (...);
		void pushBack(uint16_t value) throw (...);
		void pushBack(int32_t value) throw (...);
		void pushBack(uint32_t value) throw (...);
		void pushBack(int64_t value) throw (...);
		void pushBack(uint64_t value) throw (...);
		void pushBack(float value) throw (...);
		void pushBack(double value) throw (...);
		void pushBack(const char* value) throw (...);
		void pushBack(const char* value, size_t size) throw (...);
		
		void pushBack(bool* value, size_t array_size) throw (...);
		void pushBack(int8_t* value, size_t array_size) throw (...);
		void pushBack(uint8_t* value, size_t array_size) throw (...);
		void pushBack(int16_t* value, size_t array_size) throw (...);
		void pushBack(uint16_t* value, size_t array_size) throw (...);
		void pushBack(int32_t* value, size_t array_size) throw (...);
		void pushBack(uint32_t* value, size_t array_size) throw (...);
		void pushBack(int64_t* value, size_t array_size) throw (...);
		void pushBack(uint64_t* value, size_t array_size) throw (...);
		void pushBack(float* value, size_t array_size) throw (...);
		void pushBack(double* value, size_t array_size) throw (...);
		void pushBack(const char** value, size_t array_size) throw (...);

		void setValue(size_t position, bool value) throw (...);
		void setValue(size_t position, int8_t value) throw (...);
		void setValue(size_t position, uint8_t value) throw (...);
		void setValue(size_t position, int16_t value) throw (...);
		void setValue(size_t position, uint16_t value) throw (...);
		void setValue(size_t position, int32_t value) throw (...);
		void setValue(size_t position, uint32_t value) throw (...);
		void setValue(size_t position, int64_t value) throw (...);
		void setValue(size_t position, uint64_t value) throw (...);
		void setValue(size_t position, float value) throw (...);
		void setValue(size_t position, double value) throw (...);
		void setValue(size_t position, const char* value) throw (...);
		void setValue(size_t position, const char* value, size_t size) throw (...);

		void getValue(size_t position, bool* value) throw (...);
		void getValue(size_t position, int8_t* value) throw (...);
		void getValue(size_t position, uint8_t* value) throw (...);
		void getValue(size_t position, int16_t* value) throw (...);
		void getValue(size_t position, uint16_t* value) throw (...);
		void getValue(size_t position, int32_t* value) throw (...);
		void getValue(size_t position, uint32_t* value) throw (...);
		void getValue(size_t position, int64_t* value) throw (...);
		void getValue(size_t position, uint64_t* value) throw (...);
		void getValue(size_t position, float* value) throw (...);
		void getValue(size_t position, double* value) throw (...);
		void getValue(size_t position, const char** value) throw (...);
		void getValue(size_t position, const char** value, size_t* size) throw (...);

		template <typename out_type> out_type getValue(size_t number) throw (...);

		UsdsBaseType* pushElementBack() throw(...);
		UsdsStruct* pushStructBack(int32_t tag_id);
		UsdsStruct* pushStructBack(const char* tag_name);

		UsdsBaseType* getElement(size_t position) throw(...);
		UsdsBaseType* getLastElement() throw(...);

		void erase(size_t number) throw (...);

	private:

		void additionalInitObject();

		DictionaryBaseType* arrayDictionaryElement;

		BinaryOutput elementValues;
		size_t elementNumber;
		usdsType elementInBinaryType;
		size_t elementInBinarySize;

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