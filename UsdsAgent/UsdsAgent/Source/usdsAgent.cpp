#include "usdsAgent.h"

#include "BasicParser/Include/common/errorMessage.h"

#include "Configuration/agentConfig.h"
#include "DictionaryReader/dictionaryReader.h"
#include "CodeReaders/codeReader.h"

#include <iostream>

using namespace usdsAgent;
using namespace std;

int main(int argc, char* argv[])
try
{
	AgentConfig config(argc, argv);

	usds::BasicParser* usdsDictionaries = DictionatyReader::parse(&config);







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
}


