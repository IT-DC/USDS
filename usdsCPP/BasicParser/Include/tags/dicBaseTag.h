#ifndef DIC_BASE_TAG
#define DIC_BASE_TAG

#include "tags\usdsTypes.h"
#include "base\usdsObjectPool.h"
#include "base\usdsBinaryOutput.h"

namespace usds
{
	class DictionaryObjectPool;
	class BinaryOutput;

	class DicBaseTag
	{
	public:
		DicBaseTag(DictionaryObjectPool* pull);
		virtual ~DicBaseTag() { };

		virtual void init(const char* name, int id, bool root) throw(...);

		DicBaseTag* getNextTag() throw(...);
		DicBaseTag* getPreviousTag() throw(...);

		void setNextTag(DicBaseTag* next);
		void setPreviousTag(DicBaseTag* previous);

		const char* getName() throw(...);
		int getID() throw(...);
		
		virtual usdsTypes getType() = 0;
		virtual void writeToBinary(BinaryOutput buff) throw(...) = 0;
		virtual void clear() = 0;

	protected:
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