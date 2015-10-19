#ifndef USDS_ARRAY_H
#define USDS_ARRAY_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsArray : public UsdsBaseType
	{
	public:
		UsdsArray();
		~UsdsArray();

		UsdsBaseType* addTagElement() throw(...);


	private:

		virtual void clear();


	};

}

#endif