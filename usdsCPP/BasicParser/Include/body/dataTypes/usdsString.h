#ifndef USDS_STRING_H
#define USDS_STRING_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsString : public UsdsBaseType
	{
	public:
		UsdsString(BodyObjectPool* object_pool);
		~UsdsString();

		virtual void setValue(const char* value) throw (...);

		virtual const char* getStringValue() throw (...);

	private:

		virtual void clear();

		std::string objectValue;

	};

}

#endif