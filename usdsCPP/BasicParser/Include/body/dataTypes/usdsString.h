#ifndef USDS_STRING_H
#define USDS_STRING_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsString : public UsdsBaseType
	{
	public:
		UsdsString(Body* parent_body);
		virtual ~UsdsString();

		usdsTypes getType() { return USDS_STRING; };
		const char* getTypeName() { return "STRING"; };

		void setValue(const char* value) throw (...);
		void setValue(const char* value, size_t size) throw (...);

		const char* getValue() throw (...);
		size_t getSize() throw (...);

	private:

		void additionalInitObject();

		char* objectValue;
		size_t valueSize;
		size_t buffSize;

	};

}

#endif