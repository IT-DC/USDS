#ifndef AGENT_CONFIG_H
#define AGENT_CONFIG_H

#include <string>

using namespace std;

namespace usdsAgent
{
	enum class command {help, clean, build, rebuild};
	enum class language { cpp };
	
	class AgentConfig
	{
	public:
		AgentConfig(int argc, char* argv[]);
		~AgentConfig();

		command action;
		
		string codePath;
		string iniFile;

		string dictFileExt;

		language programLang;



	};

}

#endif
