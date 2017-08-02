#include "DictionaryReader/dictionaryReader.h"

#include "Configuration/agentConfig.h"

#include "boost/filesystem.hpp"

#include "BasicParser/Include/common/errorMessage.h"

#include <iostream>

using namespace usdsAgent;
using namespace boost::filesystem;


DictionatyReader::DictionatyReader(AgentConfig* config)
try
{
	path p(config->solutionDirectory);
	directory_iterator end_itr;

	for (directory_iterator itr(p); itr != end_itr; ++itr)
	{
		std::string current_file = itr->path().string();
		std::cout << current_file << std::endl;


	}



}
catch(filesystem_error err)
{
	
	throw usds::ErrorStack("AgentConfig::AgentConfig") << (void*)config << usds::ErrorMessage(3, err.what());
}

DictionatyReader::~DictionatyReader()
{
	
}

