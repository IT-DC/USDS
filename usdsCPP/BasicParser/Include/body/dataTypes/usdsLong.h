#ifndef USDS_LONG_H
#define USDS_LONG_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsLong : public UsdsBaseType
	{
	public:
		UsdsLong(BodyObjectPool* object_pool);
		~UsdsLong();

		virtual void setValue(long long value) throw (...);

	private:

		virtual void clear();

		long long objectValue;

	};

}

#endif