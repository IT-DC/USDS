#ifndef USDS_DOUBLE_H
#define USDS_DOUBLE_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsDouble : public UsdsBaseType
	{
	public:
		UsdsDouble(BodyObjectPool* object_pool);
		~UsdsDouble();

		virtual void setValue(double value) throw (...);

	private:

		virtual void clear();

		double objectValue;

	};

}

#endif