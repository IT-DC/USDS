#ifndef DICTIONARY_BASE_TYPE_H
#define DICTIONARY_BASE_TYPE_H

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"
#include "base\objectPool\usdsObjectPool.h"

#include <string>

namespace usds
{
	class Dictionary;
	class DictionaryObjectPool;

	class DictionaryBaseType : public BasePoolObject
	{
	public:
		DictionaryBaseType(DictionaryObjectPool* parent) { objectPool = parent; };
		virtual ~DictionaryBaseType() { };

		void init(Dictionary* dict, DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);

		const char* getName() throw(...);
		size_t getNameSize() throw(...);
		int getID() throw(...);

		usdsTypes getType();
		const char* getTypeName();

		DictionaryBaseType* getNext() throw (...);
		DictionaryBaseType* getPrevious() throw (...);
		DictionaryBaseType* getParent() throw (...);

		void setNext(DictionaryBaseType* next);
		void setPrevious(DictionaryBaseType* previous);
		void setParent(DictionaryBaseType* parent);

		void setRoot(bool is_root) throw(...);
		bool getRootStatus() { return isRoot; };

	protected:
		std::string objectName;
		int objectID;

		// restrictions
		bool isRoot;

		// it's executed in init()
		virtual void clear() = 0;

		Dictionary* dictionary;
		DictionaryObjectPool* objectPool;

		usdsTypes objectType;

	private:
		DictionaryBaseType* parentObject;
		DictionaryBaseType* nextObject;
		DictionaryBaseType* previousObject;

	};



}

#endif