#ifndef USDS_OBJECT_POOL_H
#define USDS_OBJECT_POOL_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

#include <list>

namespace usds
{
	// template for pools
	template<class T_classPool, class parentPool_class>
	class TemplateObjectPool : public std::list<T_classPool*>
	{
	public:
		TemplateObjectPool(parentPool_class* parent) : std::list<T_classPool*>() { lastElement = begin(); parentClass = parent; };
		~TemplateObjectPool()
		{
			for (typename std::list<T_classPool*>::iterator it = begin(); it != end(); it++)
			{
				T_classPool* object = *it;
				if (object != 0)
					delete object;
			}
		};

		T_classPool* addObject() throw(...)
		{
			T_classPool* object;

			if (lastElement == end())
			{
				object = new T_classPool(parentClass);
				push_back(object);
				lastElement = end();
			}
			else
			{
				object = *lastElement;
				lastElement++;
			}

			return object;
		};

		void clearPool() throw(...){ lastElement = begin();	};

	private:
		typename std::list<T_classPool*>::iterator lastElement;
		parentPool_class* parentClass;
	};
};
#endif