#ifndef DIC_BASE_FIELD
#define DIC_BASE_FIELD

#include "tags\usdsTypes.h"
#include "base\usdsErrors.h"

#include <string>

namespace usds
{
	class DicStructTag;
	class Dictionary;
	class BinaryOutput;

	class DicBaseField
	{
	public:
		DicBaseField() { };
		virtual ~DicBaseField() { };

		void init(Dictionary* dict, int id, const char* name, size_t name_size, bool optional) throw(...);

		const char* getName() throw(...);
		size_t getNameSize() throw(...);
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

		Dictionary* dictionary;

	private:
		DicStructTag* parentTag;
		DicBaseField* nextField;
		DicBaseField* previousField;

	};



}

#endif