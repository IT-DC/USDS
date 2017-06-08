#ifndef USDS_DOUBLE_H
#define USDS_DOUBLE_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsDouble : public UsdsBaseType
	{
	public:
		UsdsDouble(Body* parent_body);
		virtual ~UsdsDouble();

		virtual void setValue(double value) throw (...);

		virtual double getDoubleValue() throw (...);

	private:

		virtual void initType();

		double objectValue;

	};

}

#endif