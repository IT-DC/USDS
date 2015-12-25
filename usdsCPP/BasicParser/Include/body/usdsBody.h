#ifndef USDS_BODY_H
#define USDS_BODY_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

#include "base\objectPool\bodyObjectPool.h"

#include "body\dataTypes\usdsArray.h"
#include "body\dataTypes\usdsBoolean.h"
#include "body\dataTypes\usdsDouble.h"
#include "body\dataTypes\usdsInt.h"
#include "body\dataTypes\usdsLong.h"
#include "body\dataTypes\usdsString.h"
#include "body\dataTypes\usdsStruct.h"
#include "body\dataTypes\usdsUVarint.h"

namespace usds
{
	class Dictionary;

	class Body
	{
	public:
		Body();
		virtual ~Body();

		// Body construction
		UsdsBaseType* addTag(int id) throw(...);
		UsdsBaseType* addTag(DictionaryBaseType* dict_tag) throw(...);
		UsdsBaseType* addField(DictionaryBaseType* dict_field, UsdsBaseType* parent_tag) throw(...);
		
		UsdsStruct* addStructTag(const char* name) throw(...);
		UsdsStruct* addStructTag(int id) throw(...);

		UsdsBaseType* getFirstTag() throw(...);
		UsdsBaseType* getFirstTag(const char* name) throw(...);
		UsdsStruct* getFirstStructTag(const char* name) throw(...);

		void clearBody();


	protected:
		Dictionary* currentDictionary;


	private:
		BodyObjectPool objectPool;

		UsdsBaseType* firstTag;
		UsdsBaseType* lastTag;
		void connectTagToBody(UsdsBaseType* tag);


	};
}
#endif