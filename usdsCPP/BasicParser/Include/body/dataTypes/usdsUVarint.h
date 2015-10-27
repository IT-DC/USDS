#ifndef USDS_UVARINT_H
#define USDS_UVARINT_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsUVarint : public UsdsBaseType
	{
	public:
		UsdsUVarint(BodyObjectPool* object_pool);
		virtual ~UsdsUVarint();

		virtual void setValue(int value) throw (...);
		virtual void setValue(long long value) throw (...);
		virtual void setValue(unsigned long long value) throw (...);

		virtual int getIntValue() throw (...);
		virtual long long getLongValue() throw (...);
		virtual unsigned long long getULongValue() throw (...);

		UsdsUVarint* NextInPool;

	private:

		virtual void clear();

		unsigned long long objectValue;


	};

}

#endif