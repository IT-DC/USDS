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

		usdsType getType() { return USDS_DOUBLE; };
		const char* getTypeName() { return "DOUBLE"; };

		// Slow methods (virtual)
		void setValue(float value) throw (...);
		void setValue(double value) throw (...);

		using UsdsBaseType::setValue;
		
		void getValue(double* value) throw (...);

		using UsdsBaseType::getValue;

		// Fast methods (not virtual)
		double get();
		void set(double value);

		bool isBigendian();

	private:

		void additionalInitObject();

		double objectValue;

	};

}

#endif