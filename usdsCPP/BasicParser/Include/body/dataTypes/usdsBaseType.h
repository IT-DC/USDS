#ifndef USDS_BASE_TYPE_H
#define USDS_BASE_TYPE_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"
#include "base\objectPool\usdsObjectPool.h"

namespace usds
{
	class DictionaryBaseType;
	class UsdsBaseType;
	class Body;

	class UsdsBaseType : public BasePoolObject
	{
	public:
		UsdsBaseType(Body* parent_body);
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

		virtual void getValue(int* value) throw (...);
		virtual void getValue(long long* value) throw (...);
		virtual void getValue(unsigned long long* value) throw (...);
		virtual void getValue(double* value) throw (...);
		virtual void getValue(const char** value) throw (...);
		virtual void getValue(const char** value, size_t* size) throw (...);
		virtual void getValue(bool* value) throw (...);

	protected:

		// it's executed in init()
		virtual void initType() = 0;

		DictionaryBaseType* parentDictionaryObject;
		Body* parentBody;

		usdsTypes objectType;

	private:
		UsdsBaseType* parentObject;
		UsdsBaseType* nextObject;
		UsdsBaseType* previousObject;


	};
}

#endif