#ifndef USDS_BOOLEAN_H
#define USDS_BOOLEAN_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsBoolean : public UsdsBaseType
	{
	public:
		UsdsBoolean(Body* parent_body);
		virtual ~UsdsBoolean();

		virtual void setValue(bool value) throw (...);

		virtual bool getBooleanValue() throw (...);

	private:

		virtual void initType();
		
		bool objectValue;

	};

}

#endif