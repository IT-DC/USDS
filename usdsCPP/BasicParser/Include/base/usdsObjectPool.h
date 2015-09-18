#ifndef USDS_OBJECT_PULL
#define USDS_OBJECT_PULL

#include <list>

#include "tags\dicStructTag.h"
#include "tags\dicStructFields.h"

namespace usds
{
	// Memory allocator, pattern "Object Pull"
	class DictionaryObjectPool
	{
	public:
		DictionaryObjectPool();
		~DictionaryObjectPool();

		// add objects from pull
		DicStructTag* addStructTag() throw(...);
		DicBooleanField* addBooleanField() throw(...);
		DicIntField* addIntField() throw(...);
		DicLongField* addLongField() throw(...);
		DicDoubleField* addDoubleField() throw(...);
		DicArrayField* addArrayField() throw(...);
		DicStringField* addStringField() throw(...);

		// Clear pull, it does not release memory
		void clear();

	private:
		// Pull of the objects
		std::list<DicStructTag> structTags;
		std::list<DicBooleanField> booleanFields;
		std::list<DicIntField> intFields;
		std::list<DicLongField> longFields;
		std::list<DicDoubleField> doubleFields;
		std::list<DicArrayField> arrayFields;
		std::list<DicStringField> stringFields;

		// last elements
		std::list<DicStructTag>::iterator lastStructTag;
		std::list<DicBooleanField>::iterator lastBooleanField;
		std::list<DicIntField>::iterator lastIntField;
		std::list<DicLongField>::iterator lastLongField;
		std::list<DicDoubleField>::iterator lastDoubleField;
		std::list<DicArrayField>::iterator lastArrayField;
		std::list<DicStringField>::iterator lastStringField;



	};

};
#endif