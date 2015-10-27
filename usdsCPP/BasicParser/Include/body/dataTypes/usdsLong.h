#ifndef USDS_LONG_H
#define USDS_LONG_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsLong : public UsdsBaseType
	{
	public:
		UsdsLong(BodyObjectPool* object_pool);
		virtual ~UsdsLong();

		virtual void setValue(long long value) throw (...);

		virtual long long getLongValue() throw (...);

		UsdsLong* NextInPool;

	private:

		virtual void clear();

		long long objectValue;

	};

}

#endif