#ifndef USDS_UVARINT_H
#define USDS_UVARINT_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsUVarint : public UsdsBaseType
	{
	public:
		UsdsUVarint(Body* parent_body);
		virtual ~UsdsUVarint();

		virtual void setValue(int value) throw (...);
		virtual void setValue(long long value) throw (...);
		virtual void setValue(unsigned long long value) throw (...);

		virtual int getIntValue() throw (...);
		virtual long long getLongValue() throw (...);
		virtual unsigned long long getULongValue() throw (...);

	private:

		virtual void initType();

		unsigned long long objectValue;


	};

}

#endif