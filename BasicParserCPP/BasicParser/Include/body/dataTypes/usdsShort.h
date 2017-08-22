#ifndef USDS_SHORT_H
#define USDS_SHORT_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsShort : public UsdsBaseType
	{
	public:
		UsdsShort(Body* parent_body);
		virtual ~UsdsShort();

		usdsType getType() { return USDS_SHORT; };
		const char* getTypeName() { return "SHORT"; };

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
		int16_t get();
		void set(int16_t value);

		bool isBigendian();

	private:

		void additionalInitObject();

		int16_t objectValue;

	};


}

#endif
