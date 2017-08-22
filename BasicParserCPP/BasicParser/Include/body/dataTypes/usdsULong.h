#ifndef USDS_ULONG_H
#define USDS_ULONG_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsULong : public UsdsBaseType
	{
	public:
		UsdsULong(Body* parent_body);
		virtual ~UsdsULong();

		usdsType getType() { return USDS_ULONG; };
		const char* getTypeName() { return "ULONG"; };

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
		uint64_t get();
		void set(uint64_t value);

		bool isBigendian();

	private:

		void additionalInitObject();

		uint64_t objectValue;

	};

}

#endif
