#ifndef USDS_BYTE_H
#define USDS_BYTE_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsByte : public UsdsBaseType
	{
	public:
		UsdsByte(Body* parent_body);
		virtual ~UsdsByte();

		usdsType getType() { return USDS_BYTE; };
		const char* getTypeName() { return "BYTE"; };

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
		int8_t get();
		void set(int8_t value);

	private:

		void additionalInitObject();

		int8_t objectValue;

	};


}

#endif