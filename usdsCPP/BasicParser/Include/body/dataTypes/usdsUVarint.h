#ifndef USDS_UVARINT_H
#define USDS_UVARINT_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsUVarint : public UsdsBaseType
	{
	public:
		UsdsUVarint(BodyObjectPool* object_pool);
		~UsdsUVarint();

		virtual void setValue(int value) throw (...);
		virtual void setValue(long long value) throw (...);


	private:

		virtual void clear();

		unsigned long long objectValue;


	};

}

#endif