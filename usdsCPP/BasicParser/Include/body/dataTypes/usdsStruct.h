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

		usdsTypes getType() { return USDS_STRUCT; };
		const char* getTypeName() { return "STRUCT"; };

		void setFieldValue(const char* name, bool value) throw (...);
		void setFieldValue(const char* name, int8_t value) throw (...);
		void setFieldValue(const char* name, uint8_t value) throw (...);
		void setFieldValue(const char* name, int16_t value) throw (...);
		void setFieldValue(const char* name, uint16_t value) throw (...);
		void setFieldValue(const char* name, int32_t value) throw (...);
		void setFieldValue(const char* name, uint32_t value) throw (...);
		void setFieldValue(const char* name, int64_t value) throw (...);
		void setFieldValue(const char* name, uint64_t value) throw (...);
		void setFieldValue(const char* name, float value) throw (...);
		void setFieldValue(const char* name, double value) throw (...);
		void setFieldValue(const char* name, usdsEncodes encode, const char* value) throw (...);

		void setFieldValue(int32_t id, bool value) throw (...);
		void setFieldValue(int32_t id, int8_t value) throw (...);
		void setFieldValue(int32_t id, uint8_t value) throw (...);
		void setFieldValue(int32_t id, int16_t value) throw (...);
		void setFieldValue(int32_t id, uint16_t value) throw (...);
		void setFieldValue(int32_t id, int32_t value) throw (...);
		void setFieldValue(int32_t id, uint32_t value) throw (...);
		void setFieldValue(int32_t id, int64_t value) throw (...);
		void setFieldValue(int32_t id, uint64_t value) throw (...);
		void setFieldValue(int32_t id, float value) throw (...);
		void setFieldValue(int32_t id, double value) throw (...);
		void setFieldValue(int32_t id, usdsEncodes encode, const char* value) throw (...);
		
		void getFieldValue(const char* name, bool* value) throw (...);
		void getFieldValue(const char* name, int8_t* value) throw (...);
		void getFieldValue(const char* name, uint8_t* value) throw (...);
		void getFieldValue(const char* name, int16_t* value) throw (...);
		void getFieldValue(const char* name, uint16_t* value) throw (...);
		void getFieldValue(const char* name, int32_t* value) throw (...);
		void getFieldValue(const char* name, uint32_t* value) throw (...);
		void getFieldValue(const char* name, int64_t* value) throw (...);
		void getFieldValue(const char* name, uint64_t* value) throw (...);
		void getFieldValue(const char* name, float* value) throw (...);
		void getFieldValue(const char* name, double* value) throw (...);
		void getFieldValue(const char* name, usdsEncodes encode, const char** value) throw (...);

		template <typename out_type> out_type getFieldValue(const char* name) throw (...);

		void getFieldValue(int32_t id, bool* value) throw (...);
		void getFieldValue(int32_t id, int8_t* value) throw (...);
		void getFieldValue(int32_t id, uint8_t* value) throw (...);
		void getFieldValue(int32_t id, int16_t* value) throw (...);
		void getFieldValue(int32_t id, uint16_t* value) throw (...);
		void getFieldValue(int32_t id, int32_t* value) throw (...);
		void getFieldValue(int32_t id, uint32_t* value) throw (...);
		void getFieldValue(int32_t id, int64_t* value) throw (...);
		void getFieldValue(int32_t id, uint64_t* value) throw (...);
		void getFieldValue(int32_t id, float* value) throw (...);
		void getFieldValue(int32_t id, double* value) throw (...);
		void getFieldValue(int32_t id, usdsEncodes encode, const char** value) throw (...);

		template <typename out_type> out_type getFieldValue(int32_t id) throw (...);

		UsdsBaseType* getField(int32_t id) throw (...);
		UsdsBaseType* getField(const char* name) throw (...);

		int32_t getFieldsNumber() throw (...);

	private:
		// it's executed in initObject()
		void additionalInitObject();

		UsdsBaseType** fields;
		int32_t fieldsBuffSize; // in bytes

		int32_t fieldNumber;

	};

	template <typename out_type> out_type UsdsStruct::getFieldValue(const char* name) throw (...)
	try
	{
		out_type value;
		getFieldValue(name, &value);
		return value;
	}
	catch (ErrorStack& err)
	{
		err.addLevel("template <typename out_type> out_type UsdsStruct::getFieldValue") << name;
		throw;
	};


	template <typename out_type> out_type UsdsStruct::getFieldValue(int32_t id) throw (...)
	try
	{
		out_type value;
		getFieldValue(id, &value);
		return value;
	}
	catch (ErrorStack& err)
	{
		err.addLevel("template <typename out_type> out_type UsdsStruct::getFieldValue") << id;
		throw;
	};
}

#endif