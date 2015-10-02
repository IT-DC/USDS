#ifndef DIC_BASE_TAG
#define DIC_BASE_TAG

#include "base\usdsTypes.h"
#include <string>

namespace usds
{
	class Dictionary;

	class DicBaseTag
	{
	public:
		DicBaseTag();
		virtual ~DicBaseTag() { };

		void init(Dictionary* dict, int id, const char* name, size_t name_size) throw(...);
		void setRoot(bool is_root) throw(...);

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
		
	protected:
		// it's executed in init()
		virtual void clear() = 0;

		std::string tagName;
		int tagID;

		// restrictions
		bool isRoot;

		Dictionary* dictionary;

	private:
		DicBaseTag* nextTag;
		DicBaseTag* previousTag;

	};

};
#endif