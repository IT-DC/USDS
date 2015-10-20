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

	private:

		virtual void clear();

		long long value;

	};

}

#endif