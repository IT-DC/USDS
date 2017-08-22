#ifndef USDS_UVARINT_H
#define USDS_UVARINT_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsUVarint : public UsdsBaseType
	{
	public:
		UsdsUVarint(Body* parent_body);
		virtual ~UsdsUVarint();

		usdsType getType() { return USDS_UVARINT; };
		const char* getTypeName() { return "UVARINT"; };

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


	private:

		void additionalInitObject();

		uint64_t objectValue;


	};

}

#endif