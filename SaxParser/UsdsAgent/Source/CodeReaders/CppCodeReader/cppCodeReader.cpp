#include "CodeReaders/CPPCodeReader/cppCodeReader.h"

#include "Configuration/agentConfig.h"
#include "Common/fileSearcher.h"

#include <iostream>

#include "CppTextReader/flexCppTextReader.h"
#include "CppTextReader/bisonCppTextReader.hh"

using namespace std;
using namespace usdsAgent;

const char* CppCodeReader::cppAnnotation = "//$S";

usds::BasicParser* CppCodeReader::parseSourceCode(usds::BasicParser* dicts, usds::BasicParser* code_mapping)
{
	BOOST_LOG_TRIVIAL(info) << "Read code files";
	list<pair<string, string>>* dictFiles = FileSearcher::findCodeFiles(AgentConfig::codePath, AgentConfig::codeFileExt, AgentConfig::cppAnnotation);


	// Parse code files
	for (auto it = dictFiles->begin(); it != dictFiles->end(); ++it)
	{
		// Creating scanner and parser
		std::stringstream input;
		std::stringstream output;
		input << (*it).second.c_str();
		cppTextReader::FlexCppTextReader scanner(&input, &output);
		cppTextReader::BisonCppTextReader textParser(&scanner);
		// Parse!
		textParser.parse();

	}




	return 0;
}
