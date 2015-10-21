#ifndef USDS_STRUCT_H
#define USDS_STRUCT_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsArray;

	class UsdsStruct : public UsdsBaseType
	{
	public:
		UsdsStruct(BodyObjectPool* object_pool);
		~UsdsStruct();

		void setFieldValue(const char* name, int value) throw (...);
		void setFieldValue(const char* name, long long value) throw (...);
		void setFieldValue(const char* name, double value) throw (...);
		void setFieldValue(const char* name, const char* value) throw (...);
		void setFieldValue(const char* name, bool value) throw (...);

		void setFieldValue(int id, int value) throw (...);
		void setFieldValue(int id, long long value) throw (...);
		void setFieldValue(int id, double value) throw (...);
		void setFieldValue(int id, const char* value) throw (...);
		void setFieldValue(int id, bool value) throw (...);

		UsdsArray* getArrayField(const char* name) throw (...);
		UsdsArray* getArrayField(int id) throw (...);

	private:
		// it's executed in init()
		virtual void clear();

		UsdsBaseType** fields; // 16 bytes per field
		int fieldsBuffSize; // in bytes

		int fieldNumber;

	};
}

#endif