#ifndef USDS_USHORT_H
#define USDS_USHORT_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsUShort : public UsdsBaseType
	{
	public:
		UsdsUShort(Body* parent_body);
		virtual ~UsdsUShort();

		usdsTypes getType() { return USDS_USHORT; };
		const char* getTypeName() { return "USHORT"; };

		// Slow methods (virtual)
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


		// Fast methods (not virtual)
		uint16_t get();
		void set(uint16_t value);

	private:

		void additionalInitObject();

		uint16_t objectValue;

	};


}

#endif
