#ifndef USDS_BOOLEAN_H
#define USDS_BOOLEAN_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsBoolean : public UsdsBaseType
	{
	public:
		UsdsBoolean(Body* parent_body);
		virtual ~UsdsBoolean();

		usdsTypes getType() { return USDS_BOOLEAN; };
		const char* getTypeName() { return "BOOLEAN"; };

		void setValue(bool value) throw (...);

		bool getValue() throw (...);

	private:

		void additionalInitObject();
		
		bool objectValue;

	};

}

#endif