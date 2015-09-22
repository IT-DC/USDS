#ifndef DIC_BASE_TAG
#define DIC_BASE_TAG

#include "tags\usdsTypes.h"
#include <string>

namespace usds
{
	class DictionaryObjectPool;
	class BinaryOutput;

	class DicBaseTag
	{
	public:
		DicBaseTag(DictionaryObjectPool* pull);
		virtual ~DicBaseTag() { };

		void init(const char* name, int id, bool root) throw(...);

		DicBaseTag* getNextTag() throw(...);
		DicBaseTag* getPreviousTag() throw(...);

		void setNextTag(DicBaseTag* next);
		void setPreviousTag(DicBaseTag* previous);

		const char* getName() throw(...);
		int getID() throw(...);
		bool getRootStatus() { return isRoot; };

		virtual usdsTypes getType() = 0;
		virtual const char* getTypeName() = 0;
		virtual void writeToBinary(BinaryOutput* buff) throw(...) = 0;

	protected:
		// it's executed in init()
		virtual void clear() = 0;

		std::string tagName;
		int tagID;
		bool isRoot;
		
		DictionaryObjectPool* objectPull;

	private:
		DicBaseTag* nextTag;
		DicBaseTag* previousTag;

	};

};
#endif