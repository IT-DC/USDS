#ifndef USDS_LONG_H
#define USDS_LONG_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsLong : public UsdsBaseType
	{
	public:
		UsdsLong(Body* parent_body);
		virtual ~UsdsLong();

		virtual void setValue(int64_t value) throw (...);

		virtual int64_t getLongValue() throw (...);

	private:

		virtual void initType();

		int64_t objectValue;

	};

}

#endif