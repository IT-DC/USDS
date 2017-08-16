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
command AgentConfig::action = command::build;
string AgentConfig::codePath = ".";
string AgentConfig::iniFile = "usdsAgent.ini";
string AgentConfig::dictFileExt = ".udic";
language AgentConfig::programLang = language::cpp;

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
		cout << command_line_options << '\n';
		action = command::help;
	}
	else
	{
		if (command_line_parameters.count("codePath"))
			codePath = command_line_parameters["codePath"].as<string>().c_str();



	}
}
catch (boost::property_tree::ptree_bad_path config_error)
{
	throw usds::ErrorStack("AgentConfig::AgentConfig") << argc << argv << usds::ErrorMessage(1, config_error.what());
}
catch (const error &parameter_error)
{
	throw usds::ErrorStack("AgentConfig::AgentConfig") << argc << argv << usds::ErrorMessage(2, parameter_error.what());
};

AgentConfig::~AgentConfig()
{
	

};


