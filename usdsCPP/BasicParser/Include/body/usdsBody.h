#ifndef USDS_BODY
#define USDS_BODY

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