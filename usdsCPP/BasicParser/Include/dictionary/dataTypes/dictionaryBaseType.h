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
		DictionaryBaseType(Dictionary* dict) { dictionary = dict; };
		virtual ~DictionaryBaseType() { };

		void init(DictionaryBaseType* parent, int id, const char* name, size_t name_size) throw(...);
		virtual void finalize() throw(...) = 0;

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

		// it's executed in init()
		virtual void initType() = 0;

	protected:
		std::string objectName;
		int objectID;

		// restrictions
		bool isRoot;

		Dictionary* dictionary;

		usdsTypes objectType;

	private:
		DictionaryBaseType* parentObject;
		DictionaryBaseType* nextObject;
		DictionaryBaseType* previousObject;

	};



}

#endif