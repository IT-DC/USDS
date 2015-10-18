#ifndef USDS_BODY_H
#define USDS_BODY_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

#include "base\objectPool\bodyObjectPool.h"

namespace usds
{
	class Dictionary;

	class Body
	{
	public:
		Body();
		~Body();


		void clearBody();


	protected:
		Dictionary* currentDictionary;

		BodyObjectPool bodyObjectPool;

	};
}
#endif