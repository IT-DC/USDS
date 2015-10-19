#ifndef USDS_STRING_H
#define USDS_STRING_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsString : public UsdsBaseType
	{
	public:
		UsdsString();
		~UsdsString();

	private:

		virtual void clear();

		std::string objectValue;

	};

}

#endif