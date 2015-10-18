#ifndef USDS_BINARY_CREATOR_H
#define USDS_BINARY_CREATOR_H

namespace usds
{
	class BinaryOutput;
	class Dictionary;

	class BinaryCreator
	{
	public:
		BinaryCreator();
		~BinaryCreator();

		void generate(BinaryOutput* buff, Dictionary* dict) throw(...);

	private:
		BinaryOutput* binary;
		Dictionary* dictionary;

		// Serialization
		void addHeadToBinary() throw(...);



	};






}

#endif
