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

		usdsTypes getType() { return USDS_UVARINT; };
		const char* getTypeName() { return "UVARINT"; };

		void setValue(int32_t value) throw (...);
		void setValue(int64_t value) throw (...);
		void setValue(uint64_t value) throw (...);

		int32_t getIntValue() throw (...);
		int64_t getLongValue() throw (...);
		uint64_t getULongValue() throw (...);

	private:

		void additionalInitObject();

		uint64_t objectValue;


	};

}

#endif