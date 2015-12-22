#ifndef USDS_STRING_H
#define USDS_STRING_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsString : public UsdsBaseType
	{
	public:
		UsdsString(BodyObjectPool* object_pool);
		virtual ~UsdsString();

		virtual void setValue(const char* value) throw (...);
		virtual void setValue(const char* value, size_t size) throw (...);

		virtual const char* getStringValue() throw (...);
		virtual const char* getStringValue(size_t* size) throw (...);

	private:

		virtual void clear();

		char* objectValue;
		size_t valueSize;
		size_t buffSize;

	};

}

#endif