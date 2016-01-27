#ifndef USDS_OBJECT_POOL_H
#define USDS_OBJECT_POOL_H

#include "base\usdsErrors.h"

namespace usds
{
	class BasePoolClass;
	class BasePoolObject
	{
		friend class BasePoolClass;
	public:
		BasePoolObject();
		virtual ~BasePoolObject();
		// Hide object, not to delete
		void remove();

	private:
		BasePoolObject* nextInPool;
		BasePoolObject* previousInPool;
		BasePoolClass* parentPool;
	};

	class BasePoolClass
	{
	public:
		BasePoolClass();		
		virtual ~BasePoolClass();

		BasePoolObject* addObject();

		BasePoolObject* getFirstElement();
		BasePoolObject* getLastElement();
		BasePoolObject* getLastAllocatedElement();

		BasePoolObject* getNextElement(BasePoolObject* object);
		BasePoolObject* getPreviousElement(BasePoolObject* object);

		size_t getFullSize();
		size_t getAllocatedSize();

		void clearPool();
		
		// Hide object, not to delete
		void removeObject(BasePoolObject* object);

	protected:
		virtual BasePoolObject* createObject() = 0;

		BasePoolObject* firstElement;
		BasePoolObject* firstReservedElement;
		BasePoolObject* lastElement;

	};

	
	// template for pools
	template<class T_classPool, class parentPool_class>
	class TemplateObjectPool : public BasePoolClass
	{
	public:
		TemplateObjectPool(parentPool_class* parent)
		{
			parentClass = parent;
		};

		virtual ~TemplateObjectPool() { };

		virtual BasePoolObject* createObject() throw(...)
		try
		{
			BasePoolObject* object = new T_classPool(parentClass);
			return object;
		}
		catch (...)
		{
			throw ErrorStack("TemplateObjectPool::createObject") << ErrorMessage(USDS_OBJECT_POOL__ALLOCATE_ERROR, "Can't allocate memory for the object");
		};

	private:

		parentPool_class* parentClass;
	};

};

#endif