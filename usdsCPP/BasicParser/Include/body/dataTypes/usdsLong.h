#ifndef USDS_LONG_H
#define USDS_LONG_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsLong : public UsdsBaseType
	{
	public:
		UsdsLong(Body* parent_body);
		virtual ~UsdsLong();

		usdsTypes getType() { return USDS_LONG; };
		const char* getTypeName() { return "LONG"; };

		void setValue(int64_t value) throw (...);

		int64_t getValue() throw (...);

	private:

		void additionalInitObject();

		int64_t objectValue;

	};

}

#endif