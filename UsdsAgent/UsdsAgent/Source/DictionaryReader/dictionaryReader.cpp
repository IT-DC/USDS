#include "DictionaryReader/dictionaryReader.h"

#include "Configuration/agentConfig.h"
#include "Common/fileSearcher.h"

#include "BasicParser/Include/common/errorMessage.h"

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace usdsAgent;

usds::BasicParser* DictionatyReader::parse(AgentConfig* config)
try
{
	if (config->action == command::help || config->action == command::clean)
		return nullptr;

	cout << "Read usds-dictionary files:\n";
	list<string>* dictFiles = FileSearcher::findDictFiles(config->codePath, config->dictFileExt);

	usds::BasicParser* dicts = new usds::BasicParser();
	for(auto it = dictFiles->begin(); it != dictFiles->end(); ++it)
	{
		dicts->addDictionaryFromText((*it).c_str(), 0, usds::USDS_UTF8);
	}

}
catch (usds::ErrorStack err)
{
	throw err.addLevel("DictionatyReader::parse");

}

