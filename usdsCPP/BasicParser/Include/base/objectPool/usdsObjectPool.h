#ifndef USDS_OBJECT_POOL_H
#define USDS_OBJECT_POOL_H

#include "base\usdsErrors.h"

namespace usds
{
	
	class BasePoolObject
	{
	public:
		BasePoolObject() { _nextInPool = 0; _previousInPool = 0; };
		~BasePoolObject() {};

		BasePoolObject* _nextInPool;
		BasePoolObject* _previousInPool;
		
		BasePoolObject** _firstInPool;
		BasePoolObject** _firstReservedInPool;
		BasePoolObject** _lastInPool;

		// Hide object, not to delete
		void remove()
		{
			// If error - do nothing
			if (*_firstReservedInPool == this)
				return;
			// If it's last element in pool
			if (_nextInPool == 0)
			{
				// If there is no reserved elements in pool
				if (*_firstReservedInPool == 0)
					*_firstReservedInPool = this;
				// Else - Error, but do nothing
				return;
			}
			// Else - move object to the back
			// Step 1: remove from Pool
			if (_previousInPool != 0)
				_previousInPool->_nextInPool = _nextInPool;
			else
				*_firstInPool = _nextInPool;
			_nextInPool->_previousInPool = _previousInPool;
			// Step 2: Put to the back
			(*_lastInPool)->_nextInPool = this;
			_previousInPool = (*_lastInPool);
			_nextInPool = 0;
			(*_lastInPool) = this;
		}

	};

	
	// template for pools
	template<class T_classPool, class parentPool_class>
	class TemplateObjectPool
	{
	public:
		TemplateObjectPool(parentPool_class* parent)
		{
			firstElement = 0;
			firstReservedElement = 0;
			lastElement = 0;
			parentClass = parent;
		};
		~TemplateObjectPool()
		{
			T_classPool* object = firstElement;
			T_classPool* next;
			while (object != 0)
			{
				next = (T_classPool*)(object->_nextInPool);
				delete object;
				object = next;
			}
		};

		T_classPool* addObject() throw(...)
		{
			T_classPool* object;
			// If pool is empty
			if (firstElement == 0)
			{
				try
				{
					object = new T_classPool(parentClass);
				}
				catch (...)
				{
					throw ErrorStack("addObject") << ErrorMessage(USDS_OBJECT_POOL__ALLOCATE_ERROR, "Can't allocate memory for the object");
				}
				firstElement = object;
				lastElement = object;
				
				object->_firstInPool = (BasePoolObject**)&firstElement;
				object->_firstReservedInPool = (BasePoolObject**)&firstReservedElement;
				object->_lastInPool = (BasePoolObject**)&lastElement;
				return object;
			}
			// If all Pool is already used
			if (firstReservedElement == 0)
			{
				try
				{
					object = new T_classPool(parentClass);
				}
				catch (...)
				{
					throw ErrorStack("addObject") << ErrorMessage(USDS_OBJECT_POOL__ALLOCATE_ERROR, "Can't allocate memory for the object");
				}
				object->_firstInPool = (BasePoolObject**)&firstElement;
				object->_firstReservedInPool = (BasePoolObject**)&firstReservedElement;
				object->_lastInPool = (BasePoolObject**)&lastElement;
				lastElement->_nextInPool = object;
				object->_previousInPool = lastElement;
				lastElement = object;

				return object;
			}
			else
			{
				object = firstReservedElement;
				firstReservedElement = (T_classPool*)(object->_nextInPool);
				return object;
			}
			
		};

		void clearPool() { firstReservedElement = firstElement; };

		T_classPool* getFirstElement() { return firstElement; }
		T_classPool* getLastElement() { return lastElement; }
		T_classPool* getLastAllocatedElement() { return (T_classPool*)(firstReservedElement->_previousInPool); }

		size_t getFullSize()
		{
			size_t size = 0;
			T_classPool* object = firstElement;
			while (object != 0)
			{
				size++;
				object = (T_classPool*)(object->_nextInPool);
			}
			return size;
		}

		size_t getAllocatedSize()
		{
			size_t size = 0;
			T_classPool* object = firstElement;
			while (object != firstReservedElement)
			{
				size++;
				object = (T_classPool*)(object->_nextInPool);
			}
			return size;
		}

	private:
		T_classPool* firstElement;
		T_classPool* firstReservedElement;
		T_classPool* lastElement;
		parentPool_class* parentClass;
	};
};
#endif