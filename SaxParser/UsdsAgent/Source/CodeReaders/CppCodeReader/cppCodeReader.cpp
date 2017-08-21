#include "CodeReaders/CPPCodeReader/cppCodeReader.h"

#include "Configuration/agentConfig.h"
#include "Common/fileSearcher.h"

#include <iostream>

using namespace std;
using namespace usdsAgent;

usds::BasicParser* CppCodeReader::findAllAnnotations(usds::BasicParser* dicts, usds::BasicParser* code_description)
{
	BOOST_LOG_TRIVIAL(info) << "Read code files";
	list<pair<string, string>>* dictFiles = FileSearcher::findDictFiles(AgentConfig::codePath, AgentConfig::codeFileExt);

	// Parse code files
	for (auto it = dictFiles->begin(); it != dictFiles->end(); ++it)
	{
		BOOST_LOG_TRIVIAL(debug) << (*it).first << " success";
	}




	return 0;
}
