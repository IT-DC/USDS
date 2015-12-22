#ifndef USDS_BOOLEAN_H
#define USDS_BOOLEAN_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsBoolean : public UsdsBaseType
	{
	public:
		UsdsBoolean(BodyObjectPool* object_pool);
		virtual ~UsdsBoolean();

		virtual void setValue(bool value) throw (...);

		virtual bool getBooleanValue() throw (...);

	private:

		virtual void clear();
		
		bool objectValue;

	};

}

#endif