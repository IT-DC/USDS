#ifndef DIC_BASE_TAG
#define DIC_BASE_TAG

#include "tags\usdsTypes.h"

namespace usds
{
	class DicBaseTag
	{
	public:
		DicBaseTag(DictionaryObjectPool* pull) { objectPull = pull; };
		virtual ~DicBaseTag();

		DicBaseTag* getNextTag();

		void init(const char* name, int id, bool root) throw(...);

		std::string* getName();
		int getID();
		
		virtual usdsTypes getType() = 0;
		virtual void writeToBinary(BinaryOutput buff) throw(...) = 0;

	protected:
		std::string tagName;
		int tagID;
		bool isRoot;

	private:
		DictionaryObjectPool* objectPull;
		
		DicBaseTag* nextTag;
		DicBaseTag* previousTag;

	};

};
#endif