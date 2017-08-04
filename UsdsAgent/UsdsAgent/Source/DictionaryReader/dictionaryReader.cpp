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
	list<pair<string, string>>* dictFiles = FileSearcher::findDictFiles(config->codePath, config->dictFileExt);

	usds::BasicParser* dicts = new usds::BasicParser();
	for(auto it = dictFiles->begin(); it != dictFiles->end(); ++it)
	{
		cout << (*it).first << "\n";
		dicts->addDictionaryFromText((*it).second.c_str(), 0, usds::USDS_UTF8);
		cout << dicts->getDictionaryName() << " " << dicts->getDictionaryID() << "." << (uint32_t)dicts->getDictionaryMajor() << "." << (uint32_t)dicts->getDictionaryMinor() << " success\n";
	}

	return dicts;

}
catch (usds::ErrorStack err)
{
	throw err.addLevel("DictionatyReader::parse");

}

