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

		void setValue(const char* field_name, bool value) throw (...);
		void setValue(const char* field_name, int8_t value) throw (...);
		void setValue(const char* field_name, uint8_t value) throw (...);
		void setValue(const char* field_name, int16_t value) throw (...);
		void setValue(const char* field_name, uint16_t value) throw (...);
		void setValue(const char* field_name, int32_t value) throw (...);
		void setValue(const char* field_name, uint32_t value) throw (...);
		void setValue(const char* field_name, int64_t value) throw (...);
		void setValue(const char* field_name, uint64_t value) throw (...);
		void setValue(const char* field_name, float value) throw (...);
		void setValue(const char* field_name, double value) throw (...);
		void setValue(const char* field_name, usdsEncode encode, const char* value) throw (...);
		void setFromUTF8(const char* field_name, const char* value) throw (...);
		void setFromUTF8(const char* field_name, const char* value, size_t byte_size) throw (...);

		void setValue(int32_t field_id, bool value) throw (...);
		void setValue(int32_t field_id, int8_t value) throw (...);
		void setValue(int32_t field_id, uint8_t value) throw (...);
		void setValue(int32_t field_id, int16_t value) throw (...);
		void setValue(int32_t field_id, uint16_t value) throw (...);
		void setValue(int32_t field_id, int32_t value) throw (...);
		void setValue(int32_t field_id, uint32_t value) throw (...);
		void setValue(int32_t field_id, int64_t value) throw (...);
		void setValue(int32_t field_id, uint64_t value) throw (...);
		void setValue(int32_t field_id, float value) throw (...);
		void setValue(int32_t field_id, double value) throw (...);
		void setValue(int32_t field_id, usdsEncode encode, const char* value) throw (...);
		
		void getValue(const char* field_name, bool* value) throw (...);
		void getValue(const char* field_name, int8_t* value) throw (...);
		void getValue(const char* field_name, uint8_t* value) throw (...);
		void getValue(const char* field_name, int16_t* value) throw (...);
		void getValue(const char* field_name, uint16_t* value) throw (...);
		void getValue(const char* field_name, int32_t* value) throw (...);
		void getValue(const char* field_name, uint32_t* value) throw (...);
		void getValue(const char* field_name, int64_t* value) throw (...);
		void getValue(const char* field_name, uint64_t* value) throw (...);
		void getValue(const char* field_name, float* value) throw (...);
		void getValue(const char* field_name, double* value) throw (...);
		void getValue(const char* field_name, usdsEncode encode, const char** value) throw (...);

		template <typename out_type> out_type getValue(const char* field_name) throw (...);

		void getValue(int32_t field_id, bool* value) throw (...);
		void getValue(int32_t field_id, int8_t* value) throw (...);
		void getValue(int32_t field_id, uint8_t* value) throw (...);
		void getValue(int32_t field_id, int16_t* value) throw (...);
		void getValue(int32_t field_id, uint16_t* value) throw (...);
		void getValue(int32_t field_id, int32_t* value) throw (...);
		void getValue(int32_t field_id, uint32_t* value) throw (...);
		void getValue(int32_t field_id, int64_t* value) throw (...);
		void getValue(int32_t field_id, uint64_t* value) throw (...);
		void getValue(int32_t field_id, float* value) throw (...);
		void getValue(int32_t field_id, double* value) throw (...);
		void getValue(int32_t field_id, usdsEncode encode, const char** value) throw (...);

		template <typename out_type> out_type getValue(int32_t field_id) throw (...);

		UsdsArray* addArray(int32_t field_id) throw (...);
		UsdsArray* addArray(const char* field_name) throw (...);

		UsdsStruct* addStruct(int32_t field_id) throw (...);
		UsdsStruct* addStruct(const char* field_name) throw (...);
		
		// for Polumorph fields only
		UsdsStruct* addStruct(int32_t polyfield_id, int32_t tag_id) throw (...);
		UsdsStruct* addStruct(const char* polyfield_name, const char* tag_name) throw (...);

		void setNull(const char* field_name) throw (...);
		void setNull(int32_t field_id) throw (...);
		bool isNull(const char* field_name) throw (...);
		bool isNull(int32_t field_id) throw (...);

		UsdsBaseType* getField(int32_t field_id) throw (...);
		UsdsBaseType* getField(const char* field_name) throw (...);

		int32_t getFieldsNumber() throw (...);

	private:
		// it's executed in initObject()
		void additionalInitObject();

		UsdsBaseType** fields;
		int32_t fieldsBuffSize; // in bytes

		int32_t fieldNumber;

	};

	template <typename out_type> out_type UsdsStruct::getValue(const char* field_name) throw (...)
	try
	{
		out_type value;
		getValue(field_name, &value);
		return value;
	}
	catch (ErrorStack& err)
	{
		err.addLevel("template <typename out_type> out_type UsdsStruct::getValue") << field_name;
		throw;
	};


	template <typename out_type> out_type UsdsStruct::getValue(int32_t field_id) throw (...)
	try
	{
		out_type value;
		getValue(field_id, &value);
		return value;
	}
	catch (ErrorStack& err)
	{
		err.addLevel("template <typename out_type> out_type UsdsStruct::getValue") << field_id;
		throw;
	};
}

#endif