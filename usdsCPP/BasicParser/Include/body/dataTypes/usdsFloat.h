#ifndef USDS_FLOAT_H
#define USDS_FLOAT_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsFloat : public UsdsBaseType
	{
	public:
		UsdsFloat(Body* parent_body);
		virtual ~UsdsFloat();

		usdsTypes getType() { return USDS_FLOAT; };
		const char* getTypeName() { return "FLOAT"; };

		// Slow methods (virtual)
		void setValue(float value) throw (...);

		using UsdsBaseType::setValue;

		void getValue(float* value) throw (...);
		void getValue(double* value) throw (...);

		using UsdsBaseType::getValue;


		// Fast methods (not virtual)
		float get();
		void set(float value);


	private:

		void additionalInitObject();

		float objectValue;

	};

}

#endif
