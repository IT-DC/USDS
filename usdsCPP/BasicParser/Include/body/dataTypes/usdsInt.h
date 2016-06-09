#ifndef USDS_INT_H
#define USDS_INT_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsInt : public UsdsBaseType
	{
	public:
		UsdsInt(Body* parent_body);
		virtual ~UsdsInt();

		virtual void setValue(int8_t value) throw (...);
		virtual void setValue(uint8_t value) throw (...);
		virtual void setValue(int16_t value) throw (...);
		virtual void setValue(uint16_t value) throw (...);
		virtual void setValue(int32_t value) throw (...);
		virtual void setValue(uint32_t value) throw (...);
		virtual void setValue(int64_t value) throw (...);
		virtual void setValue(uint64_t value) throw (...);

		using UsdsBaseType::setValue;

		virtual void getValue(int8_t* value) throw (...);
		virtual void getValue(uint8_t* value) throw (...);
		virtual void getValue(int16_t* value) throw (...);
		virtual void getValue(uint16_t* value) throw (...);
		virtual void getValue(int32_t* value) throw (...);
		virtual void getValue(uint32_t* value) throw (...);
		virtual void getValue(int64_t* value) throw (...);
		virtual void getValue(uint64_t* value) throw (...);

		using UsdsBaseType::getValue;

		int32_t getValue();

	private:

		virtual void initType();

		int32_t objectValue;

	};

	
}

#endif