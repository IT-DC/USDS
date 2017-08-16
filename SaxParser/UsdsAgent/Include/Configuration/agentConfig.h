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
		AgentConfig();
		~AgentConfig();
		virtual void f() = 0;

		static void parse(int argc, char* argv[]);


		static command action;
		
		static string codePath;
		static string iniFile;

		static string dictFileExt;

		static language programLang;



	};

}

#endif
