#ifndef USDS_BODY
#define USDS_BODY

namespace usds
{
	class Dictionary;

	class Body
	{
	public:
		Body();
		~Body();


		void clear();


	private:
		Dictionary* baseDictionary;

	};
}
#endif