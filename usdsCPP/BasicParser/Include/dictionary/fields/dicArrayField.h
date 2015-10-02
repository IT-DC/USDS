#ifndef DIC_ARRAY_FIELD
#define DIC_ARRAY_FIELD

#include <string>
#include <vector>

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

#include "dictionary\fields\dicBaseField.h"

namespace usds
{

	class DicArrayField : public DicBaseField
	{
	public:
		DicArrayField();
		~DicArrayField() {  };

		virtual usdsTypes getType() { return USDS_ARRAY; };
		virtual const char* getTypeName() { return typeName(USDS_ARRAY); };
		virtual void clear();

		void setElementAsTag(const char* tag_name, size_t name_size) throw (...);
		void setElementAsTag(int tag_id) throw (...);

		usdsTypes getElementType() throw (...);
		int getElementTagID() throw (...);
		const char* getElementTagName() throw (...);

		void finalizeField() throw (...);

	private:
		int arraySize;

		// simple type, USDS_STRING, USDS_TAG or USDS_POLYMORPH
		usdsTypes elementType;

		// if it's polymorph array (USDS_POLYMORPH)
		std::vector<int> elementTagIDs;
		std::vector<std::string> elementTagNames;

		// if elements is USDS_STRING
		usdsEncodes elementDefaultEncode;

		// if elements is USDS_TAG
		int elementTagID;
		std::string elementTagName;
		bool elementTagNeedID;
		bool elementTagNeedName;

	};


};
#endif