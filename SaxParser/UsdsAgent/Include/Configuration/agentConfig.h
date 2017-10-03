#ifndef AGENT_CONFIG_H
#define AGENT_CONFIG_H

#include <string>
#include <vector>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

using namespace std;

namespace usdsAgent
{
	enum class command {help, clean, build, rebuild};
	enum class language { cpp };
	
	class AgentConfig
	{
	public:
		virtual void f() = 0;

		static void parse(int argc, char* argv[]);

		static boost::log::trivial::severity_level severityLevel;

		static command action;
		
		static string codePath;
		static string iniFile;

		static string dictFileExt;
		
		static string sourceCodeEncode;
		static language programLang;
		static vector<string> codeFileExt;
		static string cppAnnotation;

	};

}

#endif
