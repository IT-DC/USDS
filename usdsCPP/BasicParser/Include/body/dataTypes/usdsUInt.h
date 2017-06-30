#ifndef USDS_UINT_H
#define USDS_UINT_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsUInt : public UsdsBaseType
	{
	public:
		UsdsUInt(Body* parent_body);
		virtual ~UsdsUInt();

		usdsTypes getType() { return USDS_UINT; };
		const char* getTypeName() { return "UINT"; };

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
		uint32_t get();
		void set(uint32_t value);

		bool isBigendian();

	private:

		void additionalInitObject();

		uint32_t objectValue;

	};


}

#endif
