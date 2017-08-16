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
	usds::BasicParser* usdsDictionaries = DictionaryReader::findAllDictionaries();
	usds::BasicParser* codeDescription = CodeReader::findAllAnnotations(usdsDictionaries);
	Package package = Packer::packToUsdsBinary(usdsDictionaries, codeDescription);
	string* session_id = Sender::sent(package.binary, package.size);
	Sender::wait(session_id);

#ifdef _DEBUG
	cout << "Press any key\n";
	cin.get();
#endif

	return 0;
}
catch (usds::ErrorStack msg)
{
	cerr << "Error: " << msg.getMessage() << "\n";
#ifdef _DEBUG
	cout << "Press any key\n";
	cin.get();
#endif
	return -1;
}


