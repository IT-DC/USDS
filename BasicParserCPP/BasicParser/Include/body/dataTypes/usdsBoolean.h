#ifndef USDS_BOOLEAN_H
#define USDS_BOOLEAN_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsBoolean : public UsdsBaseType
	{
	public:
		UsdsBoolean(Body* parent_body);
		virtual ~UsdsBoolean();

		usdsType getType() { return USDS_BOOLEAN; };
		const char* getTypeName() { return "BOOLEAN"; };

		// Slow methods (virtual)
		void setValue(bool value) throw (...);

		using UsdsBaseType::setValue;

		void getValue(bool* value) throw (...);

		using UsdsBaseType::getValue;

		// Fast methods (not virtual)
		bool get();
		void set(bool value);

	private:

		void additionalInitObject();
		
		bool objectValue;

	};

}

#endif