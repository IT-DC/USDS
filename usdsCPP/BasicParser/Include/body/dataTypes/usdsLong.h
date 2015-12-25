#ifndef USDS_LONG_H
#define USDS_LONG_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsLong : public UsdsBaseType
	{
	public:
		UsdsLong(Body* parent_body);
		virtual ~UsdsLong();

		virtual void setValue(long long value) throw (...);

		virtual long long getLongValue() throw (...);

	private:

		virtual void initType();

		long long objectValue;

	};

}

#endif