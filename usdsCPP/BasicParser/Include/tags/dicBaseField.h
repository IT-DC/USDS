#ifndef DIC_BASE_FIELD
#define DIC_BASE_FIELD

#include "tags\usdsTypes.h"
#include "base\usdsErrors.h"

#include <string>

namespace usds
{
	class DicStructTag;
	class DictionaryObjectPool;
	class BinaryOutput;

	class DicBaseField
	{
	public:
		DicBaseField(DictionaryObjectPool* pool) { objectPull = pool; };
		virtual ~DicBaseField() { };

		void init(const char* name, int id, bool optional) throw(...);

		const char* getName() throw(...);
		int getID() throw(...);

		virtual usdsTypes getType() = 0;
		virtual const char* getTypeName() = 0;
		virtual void writeToBinary(BinaryOutput* buff) throw (...) = 0;
		virtual void clear() = 0;

		DicBaseField* getNextField() throw (...);
		DicBaseField* getPreviousField() throw (...);
		DicStructTag* getParentTag() throw (...);

		void setNextField(DicBaseField* next);
		void setPreviousField(DicBaseField* previous);
		void setParentTag(DicStructTag* parent);

	protected:
		std::string fieldName;
		int fieldID;
		bool isOptional;

		DictionaryObjectPool* objectPull;

	private:
		DicStructTag* parentTag;
		DicBaseField* nextField;
		DicBaseField* previousField;

	};



}

#endif