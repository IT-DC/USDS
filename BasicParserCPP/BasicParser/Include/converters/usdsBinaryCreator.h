#ifndef USDS_BINARY_CREATOR_H
#define USDS_BINARY_CREATOR_H

#include "converters\usdsBodyBinaryCreator.h"

namespace usds
{
	class BinaryOutput;
	class Dictionary;
	class Body;

	class BinaryCreator
	{
	public:
		BinaryCreator();
		~BinaryCreator();

		void generate(BinaryOutput* buff, Dictionary* dict, Body* body) throw(...);

	private:
		BinaryOutput* binary;
		Dictionary* dictionary;

		// Serialization
		void addHeadToBinary() throw(...);

		BodyBinaryCreator bodyBinaryCreator;

	};






}

#endif
