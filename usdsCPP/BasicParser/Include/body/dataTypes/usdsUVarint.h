#ifndef USDS_UVARINT_H
#define USDS_UVARINT_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsUVarint : public UsdsBaseType
	{
	public:
		UsdsUVarint(Body* parent_body);
		virtual ~UsdsUVarint();

		virtual void setValue(int32_t value) throw (...);
		virtual void setValue(int64_t value) throw (...);
		virtual void setValue(uint64_t value) throw (...);

		virtual int32_t getIntValue() throw (...);
		virtual int64_t getLongValue() throw (...);
		virtual uint64_t getULongValue() throw (...);

	private:

		virtual void initType();

		uint64_t objectValue;


	};

}

#endif