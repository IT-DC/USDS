#include "CodeReaders/codeReader.h"

#include "Configuration/agentConfig.h"
#include "BasicParser/Include/common/errorMessage.h"

#include "CodeReaders/CPPCodeReader/cppCodeReader.h"

using namespace usds;
using namespace usdsAgent;

// take this string from usdsSaxParser.udic in repository
const char* CodeReader::codeDictionary =
"USDS 1:UsdsCodeDescription 0.1\n"
"ENCODE:UTF-8\n"
"{\n"
"\tParserDescription\n"
"\t{\n"
"\t\tENUM language { Cpp=1, C=2, CS=3, Java=4 };\n"
"\t\t<CppParameters||CParameters||CsParameters> languageParameters;\n"
"\t\tCodeDescription []\n"
"\t\t{\n"
"\t\t\tSTRING dictionaryName;\n"
"\t\t\tUINT dictionaryID;\n"
"\t\t\tVersions []\n"
"\t\t\t{\n"
"\t\t\t\tUBYTE majorVersion;\n"
"\t\t\t\tUBYTE minorVersion;\n"
"\t\t\t\tTagDescriptions []\n"
"\t\t\t\t{\n"
"\t\t\t\t\tSTRING tagName;\n"
"\t\t\t\t\tINT tagID;\n"
"\t\t\t\t\tSTRING codeName;\n"
"\t\t\t\t\tENUM codeType { struct=1, class=2 };\n"
"\t\t\t\t\tSTRING codeCreateMethod = NULL;\n"
"\t\t\t\t\tSTRING codeBeforeMethod = NULL;\n"
"\t\t\t\t\tSTRING codeAfterMethod = NULL;\n"
"\t\t\t\t\t<StructDescription||ClassDescription> codeTypeDescription = NULL;\n"
"\t\t\t\t};\n"
"\t\t\t};\n"
"\t\t};\n"
"\t};\n"
"\n"
"\tStructDescription\n"
"\t{\n"
"\t\tfieldsDescription []\n"
"\t\t{\n"
"\t\t\tSTRING fieldName;\n"
"\t\t\tINT fieldID;\n"
"\t\t\tSTRING codeName = NULL;\n"
"\t\t\tENUM codeType { bool, int8, int32, float, double };\n"
"\t\t\tSTRING codeSetMethod = NULL;\n"
"\t\t\tSTRING codeGetMethod = NULL;\n"
"\t\t\tSTRING codeCreateMethod = NULL;\n"
"\t\t\tSTRING codeBeforeMethod = NULL;\n"
"\t\t\tSTRING codeAfterMethod = NULL;\n"
"\t\t};\n"
"\t\tStructDescription[] inheritors = NULL;\n"
"\t\tStructDescription[] subStructs = NULL;\n"
"\t};\n"
"\n"
"\tClassDescription\n"
"\t{\n"
"\t\tfieldsDescription []\n"
"\t\t{\n"
"\t\t\tSTRING fieldName;\n"
"\t\t\tINT fieldID;\n"
"\t\t\tSTRING codeName = NULL;\n"
"\t\t\tENUM codeType { bool, int8, int32, float, double };\n"
"\t\t\tSTRING codeSetMethod = NULL;\n"
"\t\t\tSTRING codeGetMethod = NULL;\n"
"\t\t\tSTRING codeCreateMethod = NULL;\n"
"\t\t\tSTRING codeBeforeMethod = NULL;\n"
"\t\t\tSTRING codeAfterMethod = NULL;\n"
"\t\t};\n"
"\t\tClassDescription[] inheritors = NULL;\n"
"\t\tClassDescription[] subClass = NULL;\n"
"\t};\n"
"\t\n"
"\tCppParameters\n"
"\t{\n"
"\t\tENUM platform { x86, ARM };\n"
"\t\tENUM mode { debug, release, both };\n"
"\t\tENUM linkMode { static, dynamic };\n"
"\t\tENUM operationSystem { windows, linux };\t\n"
"\t};\n"
"\t\n"
"\tCParameters\n"
"\t{\n"
"\t\tENUM platform { x86, ARM };\n"
"\t\tENUM mode { debug, release, both };\n"
"\t\tENUM linkMode { static, dynamic };\n"
"\t\tENUM operationSystem { windows, linux };\t\n"
"\t};\n"
"\t\n"
"\tCsParameters\n"
"\t{\n"
"\t\tENUM mode {debug, release, both };\n"
"\t};\n"
"\t\n"
"}";

BasicParser* CodeReader::findAllAnnotations(BasicParser* dicts)
try
{
	if (AgentConfig::action == command::help || AgentConfig::action == command::clean)
		return nullptr;

	BasicParser* codeDescripton = initCodeDescriptor(dicts);

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


usds::BasicParser* CodeReader::initCodeDescriptor(usds::BasicParser* dicts)
try
{
	BasicParser* codeDescripton = new BasicParser();
	codeDescripton->addDictionaryFromText(codeDictionary, 0, USDS_UTF8);

	usds::Dictionary* dict = dicts->selectFirstDictionary();
	while (dict != 0 )
	{
		


		dict = dicts->selectNextDictionary();
	}


	return codeDescripton;
}
catch (ErrorMessage msg)
{
	throw ErrorStack("CodeReader::initCodeDescriptor") << (void*)dicts << msg;
}
catch (ErrorStack err)
{
	throw err.addLevel("CodeReader::initCodeDescriptor") << (void*)dicts;
}


