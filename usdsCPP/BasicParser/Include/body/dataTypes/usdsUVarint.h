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

	private:

		virtual void clear();

		unsigned long long objectValue;


	};

}

#endif