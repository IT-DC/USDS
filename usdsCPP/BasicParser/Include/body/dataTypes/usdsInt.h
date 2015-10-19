#ifndef USDS_INT_H
#define USDS_INT_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsInt : public UsdsBaseType
	{
	public:
		UsdsInt();
		~UsdsInt();

	private:

		virtual void clear();

		int value;

	};

}

#endif