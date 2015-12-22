#ifndef USDS_BASE_TYPE_H
#define USDS_BASE_TYPE_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"
#include "base\objectPool\usdsObjectPool.h"

namespace usds
{
	class DictionaryBaseType;
	class UsdsBaseType;
	class BodyObjectPool;

	class UsdsBaseType : public BasePoolObject
	{
	public:
		UsdsBaseType(BodyObjectPool* object_pool);
		virtual ~UsdsBaseType();

		void init(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);

		const char* getName() throw(...);
		size_t getNameSize() throw(...);
		int getID() throw(...);
		usdsTypes getType();
		const char* getTypeName();

		UsdsBaseType* getNext() throw (...);
		UsdsBaseType* getPrevious() throw (...);
		UsdsBaseType* getParent() throw (...);

		void setNext(UsdsBaseType* next);
		void setPrevious(UsdsBaseType* previous);
		void setParent(UsdsBaseType* parent);

		virtual void setValue(int value) throw (...);
		virtual void setValue(long long value) throw (...);
		virtual void setValue(unsigned long long value) throw (...);
		virtual void setValue(double value) throw (...);
		virtual void setValue(const char* value) throw (...);
		virtual void setValue(const char* value, size_t size) throw (...);
		virtual void setValue(bool value) throw (...);

		virtual int getIntValue() throw (...);
		virtual long long getLongValue() throw (...);
		virtual unsigned long long getULongValue() throw (...);
		virtual double getDoubleValue() throw (...);
		virtual const char* getStringValue() throw (...);
		virtual const char* getStringValue(size_t* size) throw (...);
		virtual bool getBooleanValue() throw (...);

	protected:

		// it's executed in init()
		virtual void clear() = 0;

		DictionaryBaseType* parentDictionaryObject;
		BodyObjectPool* objectPool;

		usdsTypes objectType;

	private:
		UsdsBaseType* parentObject;
		UsdsBaseType* nextObject;
		UsdsBaseType* previousObject;


	};
}

#endif