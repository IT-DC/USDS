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

		virtual void setValue(int32_t value) throw (...);

		virtual int32_t getIntValue() throw (...);

	private:

		virtual void initType();

		int32_t objectValue;

	};

}

#endif