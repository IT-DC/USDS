#ifndef DICTIONARY_BASE_TYPE_H
#define DICTIONARY_BASE_TYPE_H

#include "usdsTypes.h"
#include "usdsErrors.h"
#include "common\objectPool.h"

#include <string>

namespace usds
{
	class Dictionary;
	class DictionaryObjectPool;

	class DictionaryBaseType : public BasePoolObject
	{
	public:
		DictionaryBaseType(Dictionary* dict) { dictionary = dict; };
		virtual ~DictionaryBaseType() { };

		// For initialization in ObjectPool
		void initType(DictionaryBaseType* parent, int32_t id, const char* name, size_t name_size) throw(...);
	protected:
		virtual void additionalInitType() = 0;	// it's executing in initType()
	
	public:
		virtual void finalize() throw(...) = 0;

		const char* getName() throw(...);
		size_t getNameSize() throw(...);
		int32_t getID() throw(...);

		virtual usdsType getType() = 0;
		virtual const char* getTypeName() = 0;

		DictionaryBaseType* getNext() throw (...);
		DictionaryBaseType* getPrevious() throw (...);
		DictionaryBaseType* getParent() throw (...);

		void setNext(DictionaryBaseType* next);
		void setPrevious(DictionaryBaseType* previous);
		void setParent(DictionaryBaseType* parent);

		void setRoot(bool is_root) throw(...);
		bool getRootStatus() { return isRoot; };

		// for fields
		DictionaryBaseType* setNullable(bool is_nullable);
		bool isNullable();
		virtual bool hasDefaultValue() = 0;

	protected:
		std::string objectName;
		int32_t objectID;

		// restrictions
		bool isRoot;

		Dictionary* dictionary;

	private:
		DictionaryBaseType* parentObject;
		DictionaryBaseType* nextObject;
		DictionaryBaseType* previousObject;

		// for fields
		bool nullableValue;
	};



}

#endif