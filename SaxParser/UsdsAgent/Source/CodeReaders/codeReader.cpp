#include "CodeReaders/codeReader.h"

#include "Configuration/agentConfig.h"
#include "BasicParser/Include/common/errorMessage.h"

#include "CodeReaders/CPPCodeReader/cppCodeReader.h"

using namespace usds;
using namespace usdsAgent;

const char* CodeReader::codeDictionary =
"USDS ID:1 NAME:UsdsCodeDescription V:1.0\n"\
"{\n"\
"	1: "\
"	1: StructDescription\n"\
"	{\n"\
"		1: STRING<UTF-8> name;\n"\
"	};\n"\
"}";

BasicParser* CodeReader::findAllAnnotations(BasicParser* dicts)
try
{
	if (AgentConfig::action == command::help || AgentConfig::action == command::clean)
		return nullptr;

	BasicParser* codeDescripton = new BasicParser();
	codeDescripton->addDictionaryFromText(codeDictionary, 0, USDS_UTF8);

	switch (AgentConfig::programLang)
	{
		case language::cpp:
		{
			CppCodeReader::findAllAnnotations(dicts, codeDescripton);
			break;
		}
		default:
		{
			throw ErrorMessage(100, "Unsupported programming language.");
		}
	}
	return codeDescripton;
}
catch (ErrorMessage msg)
{
	throw ErrorStack("CodeReader::findAllAnnotations") << (void*)dicts << msg;
}
catch (ErrorStack err)
{
	throw err.addLevel("CodeReader::findAllAnnotations") << (void*)dicts;
}


