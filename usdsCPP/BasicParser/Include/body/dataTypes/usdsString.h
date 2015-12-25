#ifndef USDS_STRING_H
#define USDS_STRING_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsString : public UsdsBaseType
	{
	public:
		UsdsString(Body* parent_body);
		virtual ~UsdsString();

		virtual void setValue(const char* value) throw (...);
		virtual void setValue(const char* value, size_t size) throw (...);

		virtual const char* getStringValue() throw (...);
		virtual const char* getStringValue(size_t* size) throw (...);

	private:

		virtual void initType();

		char* objectValue;
		size_t valueSize;
		size_t buffSize;

	};

}

#endif