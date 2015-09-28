#ifndef DIC_BASE_TAG
#define DIC_BASE_TAG

#include "tags\usdsTypes.h"
#include <string>

namespace usds
{
	class Dictionary;
	class BinaryOutput;
	class BinaryInput;

	class DicBaseTag
	{
	public:
		DicBaseTag();
		virtual ~DicBaseTag() { };

		void init(Dictionary* dict, bool root, int id, const char* name, size_t name_size) throw(...);

		DicBaseTag* getNextTag() throw(...);
		DicBaseTag* getPreviousTag() throw(...);

		void setNextTag(DicBaseTag* next);
		void setPreviousTag(DicBaseTag* previous);

		const char* getName() throw(...);
		size_t getNameSize() throw(...);
		int getID() throw(...);
		bool getRootStatus() { return isRoot; };

		virtual usdsTypes getType() = 0;
		virtual const char* getTypeName() = 0;
		
		// encode
		virtual void writeToBinary(BinaryOutput* buff) throw(...) = 0;
		// decode
		virtual void initFromBinary(BinaryInput* buff) throw(...) = 0;

	protected:
		// it's executed in init()
		virtual void clear() = 0;

		std::string tagName;
		int tagID;
		bool isRoot;
		
		Dictionary* dictionary;

	private:
		DicBaseTag* nextTag;
		DicBaseTag* previousTag;

	};

};
#endif