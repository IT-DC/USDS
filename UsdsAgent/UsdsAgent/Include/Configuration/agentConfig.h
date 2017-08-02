#ifndef USDS_AGENT_CONFIG_H
#define USDS_AGENT_CONFIG_H

#include <string>

using namespace std;

namespace usdsAgent
{
	class AgentConfig
	{
	public:
		AgentConfig(int argc, char* argv[]);
		~AgentConfig();

		string solutionDirectory;
		string iniFile;

	};

}

#endif
