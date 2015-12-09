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
			firstElement = 0;
			lastElement = 0;
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
			if (firstElement == 0)
			{
				try
				{
					firstElement = new T_classPool(parentClass);
				}
				catch (...)
				{
					throw ErrorStack("addObject") << ErrorMessage(USDS_OBJECT_POOL__ALLOCATE_ERROR, "Can't allocate memory for the object");
				}
				lastElement = firstElement;
				return lastElement;
			}
			
			if (lastElement->NextInPool == 0)
			{
				try
				{
					lastElement->NextInPool = new T_classPool(parentClass);
				}
				catch (...)
				{
					throw ErrorStack("addObject") << ErrorMessage(USDS_OBJECT_POOL__ALLOCATE_ERROR, "Can't allocate memory for the object");
				}
			}
			T_classPool* object = lastElement;
			lastElement = lastElement->NextInPool;

			return object;
		};

		void clearPool() { lastElement = firstElement; };

	private:
		T_classPool* lastElement;
		T_classPool* firstElement;
		parentPool_class* parentClass;
	};
};
#endif