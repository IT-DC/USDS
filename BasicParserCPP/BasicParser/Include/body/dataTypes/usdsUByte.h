#ifndef USDS_UBYTE_H
#define USDS_UBYTE_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsUByte : public UsdsBaseType
	{
	public:
		UsdsUByte(Body* parent_body);
		virtual ~UsdsUByte();

		usdsType getType() { return USDS_UBYTE; };
		const char* getTypeName() { return "UBYTE"; };

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
		uint8_t get() throw (...);
		void set(uint8_t value) throw (...);

	private:

		void additionalInitObject();

		uint8_t objectValue;

	};


}

#endif
