#ifndef USDS_BOOLEAN_H
#define USDS_BOOLEAN_H

#include "body\dataTypes\usdsBaseType.h"

namespace usds
{
	class UsdsBoolean : public UsdsBaseType
	{
	public:
		UsdsBoolean(BodyObjectPool* object_pool);
		~UsdsBoolean();

		void setValue(bool value);
		bool getValue();

	private:

		virtual void clear();
		
		bool objectValue;

	};

}

#endif