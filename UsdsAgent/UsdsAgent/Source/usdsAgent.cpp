#include "usdsAgent.h"

#include "BasicParser/Include/common/errorMessage.h"

#include "Configuration/agentConfig.h"
#include "DictionaryReader/dictionaryReader.h"

#include <iostream>

using namespace usdsAgent;
using namespace std;

int main(int argc, char* argv[])
try
{
	AgentConfig config(argc, argv);
	
	cout << "Read usds-dictionary files:\n";
	
	DictionatyReader dictionaries(&config);





	cout << "Press any key\n";
	cin.get();

}
catch (usds::ErrorStack msg)
{
	if (msg.getCode() != 0)
		cerr << msg.getMessage();
	cout << "Press any key\n";
	cin.get();
}


