#ifndef USDS_INT_H
#define USDS_INT_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsInt : public UsdsBaseType
	{
	public:
		UsdsInt(BodyObjectPool* object_pool);
		~UsdsInt();

		virtual void setValue(int value) throw (...);

		virtual int getIntValue() throw (...);

	private:

		virtual void clear();

		int objectValue;

	};

}

#endif