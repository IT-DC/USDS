#ifndef DIC_BASE_TAG
#define DIC_BASE_TAG

#include "tags\usdsTypes.h"

namespace usds
{
	class DicBaseTag
	{
	public:
		DicBaseTag();
		virtual ~DicBaseTag();

		DicBaseTag* getNextTag();

		void init(const char* name, int id, bool root) throw(...);

		virtual usdsTypes getType() = 0;
		std::string* getName();
		int getID();
		
		
		virtual void writeToBinary(BinaryOutput buff) throw(...) = 0;

	protected:
		std::string tagName;
		int tagID;
		bool isRoot;

	private:
		DicBaseTag* nextTag;
		DicBaseTag* previousTag;

	};

}
#endif