#include "usdsAgent.h"

#include "BasicParser/Include/common/errorMessage.h"
#include "BasicParser/Include/usdsBasicParser.h"

#include "Configuration/agentConfig.h"
#include "DictionaryReader/dictionaryReader.h"
#include "CodeReaders/codeReader.h"
#include "Communication/packer.h"
#include "Communication/sender.h"

#include <iostream>

using namespace usdsAgent;
using namespace std;

int main(int argc, char* argv[])
try
{
	AgentConfig::parse(argc, argv);
	auto usdsDictionaries = DictionaryReader::findAllDictionaries();
	auto codeMapping = CodeReader::parseSourceCode(usdsDictionaries);
	auto package = Packer::packToUsdsBinary(usdsDictionaries, codeMapping);
	auto session_id = Sender::sent(package->binary, package->size);
	Sender::wait(session_id);

#ifdef _DEBUG
	cout << "Press enter";
	cin.get();
#endif

	return 0;
}
catch (usds::ErrorStack msg)
{
	BOOST_LOG_TRIVIAL(fatal) << msg.getMessage();
#ifdef _DEBUG
	cout << "Press enter";
	cin.get();
#endif
	return -1;
}


