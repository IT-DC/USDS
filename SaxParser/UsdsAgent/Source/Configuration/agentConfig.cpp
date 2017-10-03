#include "Configuration/agentConfig.h"

#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/ini_parser.hpp"
#include "boost/program_options.hpp"

#include "BasicParser/Include/common/errorMessage.h"

#include <iostream>

using namespace boost::property_tree;
using namespace boost::program_options;

using namespace std;

using namespace usdsAgent;

// initial values
#ifdef _DEBUG
	boost::log::trivial::severity_level AgentConfig::severityLevel = boost::log::trivial::debug;
#else
	boost::log::trivial::severity_level AgentConfig::severityLevel = boost::log::trivial::info;
#endif
command AgentConfig::action = command::build;
string AgentConfig::codePath = ".";
string AgentConfig::iniFile = "usdsAgent.ini";
string AgentConfig::dictFileExt = ".udic";
string AgentConfig::sourceCodeEncode = "UTF-8";
language AgentConfig::programLang = language::cpp;
vector<string> AgentConfig::codeFileExt = {".cpp", ".h"};
string AgentConfig::cppAnnotation = "//$S";

void AgentConfig::parse(int argc, char* argv[])
try
{
	// analize command line
	options_description command_line_options{ "Options" };
	command_line_options.add_options()
		("help,h", "Help screen")
		("build", "Build parser")
		("clean", "Clean")
		("rebuild", "Rebuild")
		("codePath,c", value<std::string>(), "Source code directory to analize")
		("iniFile,i", value<std::string>(), "Configuration file");
	variables_map command_line_parameters;
	store(parse_command_line(argc, argv, command_line_options), command_line_parameters);

	// Parameters from configuration file
	if (command_line_parameters.count("iniFile"))
	{
		iniFile = command_line_parameters["iniFile"].as<string>().c_str();
	}
	ptree agentConfig;
	ini_parser::read_ini(iniFile, agentConfig);

	// Parameters from command line
	if (command_line_parameters.count("help"))
	{
		BOOST_LOG_TRIVIAL(info) << command_line_options;
		action = command::help;
	}
	else
	{
		if (command_line_parameters.count("codePath"))
			codePath = command_line_parameters["codePath"].as<string>().c_str();
	}

	// Logger initialization
	boost::log::core::get()->set_filter
	(
		boost::log::trivial::severity >= severityLevel
	);

}
catch (boost::property_tree::ptree_error config_error)
{
	throw usds::ErrorStack("AgentConfig::AgentConfig") << argc << argv << usds::ErrorMessage(1, config_error.what());
}
catch (const error &parameter_error)
{
	throw usds::ErrorStack("AgentConfig::AgentConfig") << argc << argv << usds::ErrorMessage(2, parameter_error.what());
};



