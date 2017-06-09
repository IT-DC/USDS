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

		usdsTypes getType() { return USDS_DOUBLE; };
		const char* getTypeName() { return "DOUBLE"; };

		void setValue(double value) throw (...);

		double getValue() throw (...);

	private:

		void additionalInitObject();

		double objectValue;

	};

}

#endif