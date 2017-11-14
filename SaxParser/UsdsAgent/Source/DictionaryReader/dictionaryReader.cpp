#include "DictionaryReader/dictionaryReader.h"

#include "Configuration/agentConfig.h"
#include "Common/fileSearcher.h"

#include "BasicParser/Include/common/errorMessage.h"

#include <iostream>
#include <list>
#include <string>

using namespace usdsAgent;

std::unique_ptr<usds::BasicParser> DictionaryReader::findAllDictionaries()
try
{
	if (AgentConfig::action == command::help || AgentConfig::action == command::clean)
		return nullptr;

	BOOST_LOG_TRIVIAL(info) << "Read usds-dictionary files";
	auto dictFiles = FileSearcher::findDictFiles(AgentConfig::codePath, AgentConfig::dictFileExt);

	auto dicts = make_unique<usds::BasicParser>();
	for(auto it = dictFiles->begin(); it != dictFiles->end(); ++it)
	{
		BOOST_LOG_TRIVIAL(debug) << (*it).first;
		dicts->addDictionaryFromText((*it).second.c_str(), 0, usds::USDS_UTF8);
		BOOST_LOG_TRIVIAL(debug) << dicts->getDictionaryName() << " " << dicts->getDictionaryID() << "." << (uint32_t)dicts->getDictionaryMajor() << "." << (uint32_t)dicts->getDictionaryMinor() << " success";
	}

	return dicts;

}
catch (usds::ErrorStack err)
{
	throw err.addLevel("DictionaryReader::findAllDictionaries");

}

