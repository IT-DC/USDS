#include "base\objectPool\usdsObjectPool.h"

using namespace usds;

BasePoolObject::BasePoolObject()
{
	
}

BasePoolObject::~BasePoolObject()
{

}

void BasePoolObject::remove()
{
	parentPool->removeObject(this);
};

//====================================================================

BasePoolClass::BasePoolClass()
{
	firstElement = 0;
	firstReservedElement = 0;
	lastElement = 0;
}

BasePoolClass::~BasePoolClass()
{
	BasePoolObject* object = firstElement;
	BasePoolObject* next;
	while (object != 0)
	{
		next = object->nextInPool;
		delete object;
		object = next;
	}
}

BasePoolObject* BasePoolClass::addObject() throw(...)
{
	BasePoolObject* object;
	// If pool is empty
	if (firstElement == 0)
	{
		object = createObject();
		firstElement = object;
		lastElement = object;
		object->nextInPool = 0;
		object->previousInPool = 0;
		object->parentPool = this;

		return object;
	}
	// If all Pool is already used
	if (firstReservedElement == 0)
	{
		object = createObject();
		lastElement->nextInPool = object;
		object->nextInPool = 0;
		object->previousInPool = lastElement;
		object->parentPool = this;
		lastElement = object;
		return object;
	}
	else
	{
		object = firstReservedElement;
		firstReservedElement = object->nextInPool;
		return object;
	}
};

BasePoolObject* BasePoolClass::getFirstElement()
{
	return firstElement;
}

BasePoolObject* BasePoolClass::getLastElement()
{
	return lastElement; 
}

BasePoolObject* BasePoolClass::getLastAllocatedElement()
{
	if (firstReservedElement == 0)
		return lastElement;
	else
		return firstReservedElement->previousInPool; 
}

BasePoolObject* BasePoolClass::getNextElement(BasePoolObject* object)
{
	return object->nextInPool;

};

BasePoolObject* BasePoolClass::getPreviousElement(BasePoolObject* object)
{

	return object->previousInPool;
};

void BasePoolClass::clearPool()
{
	firstReservedElement = firstElement;
};

size_t BasePoolClass::getFullSize()
{
	size_t size = 0;
	BasePoolObject* object = firstElement;
	while (object != 0)
	{
		size++;
		object = object->nextInPool;
	}
	return size;
}

size_t BasePoolClass::getAllocatedSize()
{
	size_t size = 0;
	BasePoolObject* object = firstElement;
	while (object != firstReservedElement)
	{
		size++;
		object = object->nextInPool;
	}
	return size;
}

void BasePoolClass::removeObject(BasePoolObject* object)
{
	// If error - do nothing
	if (firstReservedElement == object)
		return;
	// If it's last element in pool
	if (object->nextInPool == 0)
	{
		// If there is no reserved elements in pool
		if (firstReservedElement == 0)
			firstReservedElement = object;
		// Else - Error, but do nothing
		return;
	}
	// Else - move object to the back
	// Step 1: remove from Pool
	if (object->previousInPool != 0)
		object->previousInPool->nextInPool = object->nextInPool;
	else
		firstElement = object->nextInPool;
	object->nextInPool->previousInPool = object->previousInPool;
	// Step 2: Put to the back
	lastElement->nextInPool = object;
	object->previousInPool = lastElement;
	object->nextInPool = 0;
	lastElement = object;

}