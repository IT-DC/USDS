#ifndef USDS_POLYMORPH_H
#define USDS_POLYMORPH_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsStruct;

	class UsdsPolymorph : public UsdsBaseType
	{
	public:
		UsdsPolymorph(Body* parent_body);
		virtual ~UsdsPolymorph();

		usdsType getType() { return USDS_POLYMORPH; };
		const char* getTypeName() { return "POLYMORPH"; };

		UsdsStruct* setSubtagId(int32_t tag_id) throw(...);
		
		UsdsStruct* getSubtag() throw(...);
		int32_t getSubtagId() throw(...);

	private:
		// it's executed in initObject()
		void additionalInitObject();

		UsdsStruct* subObject;

	};
}

#endif
