#ifndef USDS_BASE_TYPE_H
#define USDS_BASE_TYPE_H

#include "usdsErrors.h"
#include "usdsTypes.h"
#include "objectPool.h"

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

		const char* getName() throw(...);
		size_t getNameSize() throw(...);
		int32_t getID() throw(...);
		
		virtual usdsTypes getType() = 0;
		virtual const char* getTypeName() = 0;

		virtual void setValue(bool value) throw (...);
		virtual void setValue(int8_t value) throw (...);
		virtual void setValue(uint8_t value) throw (...);
		virtual void setValue(int16_t value) throw (...);
		virtual void setValue(uint16_t value) throw (...);
		virtual void setValue(int32_t value) throw (...);
		virtual void setValue(uint32_t value) throw (...);
		virtual void setValue(int64_t value) throw (...);
		virtual void setValue(uint64_t value) throw (...);
		virtual void setValue(float value) throw (...);
		virtual void setValue(double value) throw (...);
		virtual void setValue(const char* value) throw (...);
		virtual void setValue(const char* value, size_t size) throw (...);

		virtual void getValue(bool* value) throw (...);
		virtual void getValue(int8_t* value) throw (...);
		virtual void getValue(uint8_t* value) throw (...);
		virtual void getValue(int16_t* value) throw (...);
		virtual void getValue(uint16_t* value) throw (...);
		virtual void getValue(int32_t* value) throw (...);
		virtual void getValue(uint32_t* value) throw (...);
		virtual void getValue(int64_t* value) throw (...);
		virtual void getValue(uint64_t* value) throw (...);
		virtual void getValue(float* value) throw (...);
		virtual void getValue(double* value) throw (...);
		virtual void getValue(const char** value) throw (...);
		virtual void getValue(const char** value, size_t* size) throw (...);

		template <typename out_type> out_type getValue() throw (...);


		// Internal methods
		// For initialization in ObjectPool
		void initObject(DictionaryBaseType* dict_parent, UsdsBaseType* body_parent) throw(...);

		UsdsBaseType* getNext() throw (...);
		UsdsBaseType* getPrevious() throw (...);
		UsdsBaseType* getParent() throw (...);

		void setNext(UsdsBaseType* next);
		void setPrevious(UsdsBaseType* previous);
		void setParent(UsdsBaseType* parent);

	protected:

		// it's executed in initObject()
		virtual void additionalInitObject() = 0;

		DictionaryBaseType* parentDictionaryObject;
		Body* parentBody;

	private:
		UsdsBaseType* parentObject;
		UsdsBaseType* nextObject;
		UsdsBaseType* previousObject;


	};

	template <typename out_type> out_type UsdsBaseType::getValue() throw (...)
	try
	{
		out_type value;
		getValue(&value);
		return value;
	}
	catch (ErrorStack& err)
	{
		err.addLevel("template <typename out_type> out_type UsdsInt::getValue");
		throw;
	};
}

#endif