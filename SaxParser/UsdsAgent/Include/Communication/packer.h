#ifndef PACKER_H
#define PACKER_H

#include "BasicParser/Include/usdsBasicParser.h"

namespace usdsAgent
{
	struct Package
	{
		uint8_t* binary;
		size_t size;
	};


	class Packer
	{
	public:
		Packer();
		~Packer();
		virtual void f() = 0;

		static Package packToUsdsBinary(usds::BasicParser* dictdionaries, usds::BasicParser* code_descriptions);

	};
}

#endif
