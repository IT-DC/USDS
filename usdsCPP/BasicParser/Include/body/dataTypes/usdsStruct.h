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

		void setFieldValue(const char* name, int32_t value) throw (...);
		void setFieldValue(const char* name, int64_t value) throw (...);
		void setFieldValue(const char* name, double value) throw (...);
		void setFieldValue(const char* name, const char* value) throw (...);
		void setFieldValue(const char* name, bool value) throw (...);

		void setFieldValue(int32_t id, int32_t value) throw (...);
		void setFieldValue(int32_t id, int64_t value) throw (...);
		void setFieldValue(int32_t id, double value) throw (...);
		void setFieldValue(int32_t id, const char* value) throw (...);
		void setFieldValue(int32_t id, bool value) throw (...);

		void getFieldValue(const char* name, int32_t* value) throw (...);
		void getFieldValue(const char* name, int64_t* value) throw (...);
		void getFieldValue(const char* name, double* value) throw (...);
		void getFieldValue(const char* name, const char** value) throw (...);
		void getFieldValue(const char* name, bool* value) throw (...);

		void getFieldValue(int32_t id, int32_t* value) throw (...);
		void getFieldValue(int32_t id, int64_t* value) throw (...);
		void getFieldValue(int32_t id, double* value) throw (...);
		void getFieldValue(int32_t id, const char** value) throw (...);
		void getFieldValue(int32_t id, bool* value) throw (...);


		UsdsBaseType* getField(int32_t id) throw (...);

		UsdsArray* getArrayField(const char* name) throw (...);
		UsdsArray* getArrayField(int32_t id) throw (...);

		int32_t getFieldNumber() throw (...);

	private:
		// it's executed in initObject()
		void additionalInitObject();

		UsdsBaseType** fields;
		int32_t fieldsBuffSize; // in bytes

		int32_t fieldNumber;

	};
}

#endif