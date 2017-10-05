#ifndef USDS_STRUCT_H
#define USDS_STRUCT_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsArray;

	class UsdsStruct : public UsdsBaseType
	{
	public:
		UsdsStruct(Body* parent_body);
		virtual ~UsdsStruct();

		usdsType getType() { return USDS_STRUCT; };
		const char* getTypeName() { return "STRUCT"; };

		void setFieldValue(const char* field_name, bool value) throw (...);
		void setFieldValue(const char* field_name, int8_t value) throw (...);
		void setFieldValue(const char* field_name, uint8_t value) throw (...);
		void setFieldValue(const char* field_name, int16_t value) throw (...);
		void setFieldValue(const char* field_name, uint16_t value) throw (...);
		void setFieldValue(const char* field_name, int32_t value) throw (...);
		void setFieldValue(const char* field_name, uint32_t value) throw (...);
		void setFieldValue(const char* field_name, int64_t value) throw (...);
		void setFieldValue(const char* field_name, uint64_t value) throw (...);
		void setFieldValue(const char* field_name, float value) throw (...);
		void setFieldValue(const char* field_name, double value) throw (...);
		void setFieldValue(const char* field_name, usdsEncode encode, const char* value) throw (...);
		void setFieldFromUTF8(const char* field_name, const char* value) throw (...);
		void setFieldFromUTF8(const char* field_name, const char* value, size_t byte_size) throw (...);

		void setFieldValue(int32_t field_id, bool value) throw (...);
		void setFieldValue(int32_t field_id, int8_t value) throw (...);
		void setFieldValue(int32_t field_id, uint8_t value) throw (...);
		void setFieldValue(int32_t field_id, int16_t value) throw (...);
		void setFieldValue(int32_t field_id, uint16_t value) throw (...);
		void setFieldValue(int32_t field_id, int32_t value) throw (...);
		void setFieldValue(int32_t field_id, uint32_t value) throw (...);
		void setFieldValue(int32_t field_id, int64_t value) throw (...);
		void setFieldValue(int32_t field_id, uint64_t value) throw (...);
		void setFieldValue(int32_t field_id, float value) throw (...);
		void setFieldValue(int32_t field_id, double value) throw (...);
		void setFieldValue(int32_t field_id, usdsEncode encode, const char* value) throw (...);
		
		void getFieldValue(const char* field_name, bool* value) throw (...);
		void getFieldValue(const char* field_name, int8_t* value) throw (...);
		void getFieldValue(const char* field_name, uint8_t* value) throw (...);
		void getFieldValue(const char* field_name, int16_t* value) throw (...);
		void getFieldValue(const char* field_name, uint16_t* value) throw (...);
		void getFieldValue(const char* field_name, int32_t* value) throw (...);
		void getFieldValue(const char* field_name, uint32_t* value) throw (...);
		void getFieldValue(const char* field_name, int64_t* value) throw (...);
		void getFieldValue(const char* field_name, uint64_t* value) throw (...);
		void getFieldValue(const char* field_name, float* value) throw (...);
		void getFieldValue(const char* field_name, double* value) throw (...);
		void getFieldValue(const char* field_name, usdsEncode encode, const char** value) throw (...);

		template <typename out_type> out_type getFieldValue(const char* field_name) throw (...);

		void getFieldValue(int32_t field_id, bool* value) throw (...);
		void getFieldValue(int32_t field_id, int8_t* value) throw (...);
		void getFieldValue(int32_t field_id, uint8_t* value) throw (...);
		void getFieldValue(int32_t field_id, int16_t* value) throw (...);
		void getFieldValue(int32_t field_id, uint16_t* value) throw (...);
		void getFieldValue(int32_t field_id, int32_t* value) throw (...);
		void getFieldValue(int32_t field_id, uint32_t* value) throw (...);
		void getFieldValue(int32_t field_id, int64_t* value) throw (...);
		void getFieldValue(int32_t field_id, uint64_t* value) throw (...);
		void getFieldValue(int32_t field_id, float* value) throw (...);
		void getFieldValue(int32_t field_id, double* value) throw (...);
		void getFieldValue(int32_t field_id, usdsEncode encode, const char** value) throw (...);

		template <typename out_type> out_type getFieldValue(int32_t field_id) throw (...);

		UsdsStruct* setFieldSubtype(const char* field_name, const char* tag_name) throw (...);

		UsdsBaseType* getField(int32_t field_id) throw (...);
		UsdsBaseType* getField(const char* field_name) throw (...);

		void setFieldAsNull(const char* field_name) throw (...);
		void setFieldAsNull(int32_t field_id) throw (...);
		bool isNullValue(const char* field_name) throw (...);
		bool isNullValue(int32_t field_id) throw (...);



		int32_t getFieldsNumber() throw (...);

	private:
		// it's executed in initObject()
		void additionalInitObject();

		UsdsBaseType** fields;
		int32_t fieldsBuffSize; // in bytes

		int32_t fieldNumber;

	};

	template <typename out_type> out_type UsdsStruct::getFieldValue(const char* field_name) throw (...)
	try
	{
		out_type value;
		getFieldValue(field_name, &value);
		return value;
	}
	catch (ErrorStack& err)
	{
		err.addLevel("template <typename out_type> out_type UsdsStruct::getFieldValue") << field_name;
		throw;
	};


	template <typename out_type> out_type UsdsStruct::getFieldValue(int32_t field_id) throw (...)
	try
	{
		out_type value;
		getFieldValue(field_id, &value);
		return value;
	}
	catch (ErrorStack& err)
	{
		err.addLevel("template <typename out_type> out_type UsdsStruct::getFieldValue") << field_id;
		throw;
	};
}

#endif