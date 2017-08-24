#ifndef USDS_ENUM_H
#define USDS_ENUM_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsEnum : public UsdsBaseType
	{
	public:
		UsdsEnum(Body* parent_body);
		virtual ~UsdsEnum();

		usdsType getType() { return USDS_ENUM; };
		const char* getTypeName() { return "ENUM"; };

		usdsType getSubtype();
		bool isSubtypeBigendian();

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
		int64_t get();
		void set(int64_t value);

	private:

		void additionalInitObject();

		int64_t objectValue;

		usdsType subType;

	};
	
}

#endif
