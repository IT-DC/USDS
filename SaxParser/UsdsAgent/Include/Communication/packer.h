#ifndef PACKER_H
#define PACKER_H

#include "BasicParser/Include/usdsBasicParser.h"

#include <memory>

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
		virtual void f() = 0;

		static std::unique_ptr<Package> packToUsdsBinary(std::unique_ptr<usds::BasicParser>& dictdionaries, std::unique_ptr<usds::BasicParser>& code_descriptions);

	};
}

#endif
