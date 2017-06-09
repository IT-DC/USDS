#ifndef USDS_INT_H
#define USDS_INT_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsInt : public UsdsBaseType
	{
	public:
		UsdsInt(Body* parent_body);
		virtual ~UsdsInt();

		usdsTypes getType() { return USDS_INT; };
		const char* getTypeName() { return "INT"; };

		void setValue(int8_t value) throw (...);
		void setValue(uint8_t value) throw (...);
		void setValue(int16_t value) throw (...);
		void setValue(uint16_t value) throw (...);
		void setValue(int32_t value) throw (...);
		void setValue(uint32_t value) throw (...);
		void setValue(int64_t value) throw (...);
		void setValue(uint64_t value) throw (...);

		using UsdsBaseType::setValue;

		void getValue(int8_t* value) throw (...);
		void getValue(uint8_t* value) throw (...);
		void getValue(int16_t* value) throw (...);
		void getValue(uint16_t* value) throw (...);
		void getValue(int32_t* value) throw (...);
		void getValue(uint32_t* value) throw (...);
		void getValue(int64_t* value) throw (...);
		void getValue(uint64_t* value) throw (...);

		using UsdsBaseType::getValue;

		int32_t getValue();

	private:

		void additionalInitObject();

		int32_t objectValue;

	};

	
}

#endif