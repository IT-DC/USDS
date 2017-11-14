#include "Communication/packer.h"

using namespace usdsAgent;

std::unique_ptr<Package> Packer::packToUsdsBinary(std::unique_ptr<usds::BasicParser>& dictdionaries, std::unique_ptr<usds::BasicParser>& code_descriptions)
{
	auto output = std::make_unique<Package>();

	output->binary = 0;
	output->size = 0;


	return output;
}