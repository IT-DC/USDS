#ifndef USDS_OBJECT_POOL_H
#define USDS_OBJECT_POOL_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

#include <list>

namespace usds
{
	// template for pools
	template<class T_classPool, class parentPool_class>
	class TemplateObjectPool
	{
	public:
		TemplateObjectPool(parentPool_class* parent)
		{
			parentClass = parent;
			lastElement = new T_classPool(parentClass);
			firstElement = lastElement;
		};
		~TemplateObjectPool()
		{
			T_classPool* object = firstElement;
			T_classPool* next;
			while (object != 0)
			{
				next = object->NextInPool;
				delete object;
				object = next;
			}
		};

		T_classPool* addObject() throw(...)
		{
			if (lastElement->NextInPool == 0)
				lastElement->NextInPool = new T_classPool(parentClass);
			T_classPool* object = lastElement;
			lastElement = lastElement->NextInPool;

			return object;
		};

		void clearPool() throw(...){ lastElement = firstElement; };

	private:
		T_classPool* lastElement;
		T_classPool* firstElement;
		parentPool_class* parentClass;
	};
};
#endif