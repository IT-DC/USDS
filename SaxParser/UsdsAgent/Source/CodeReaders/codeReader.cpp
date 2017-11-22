#include "CodeReaders/codeReader.h"

#include "Configuration/agentConfig.h"
#include "BasicParser/Include/common/errorMessage.h"

#include "CodeReaders/CPPCodeReader/cppCodeReader.h"

using namespace usds;
using namespace usdsAgent;

// take this string from usdsSaxParser.udic in repository
const char* CodeReader::codeDictionary =
"USDS 100001:UsdsCodeDescription 0.1\n"
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

std::unique_ptr<usds::BasicParser> CodeReader::parseSourceCode(std::unique_ptr<usds::BasicParser>& dicts)
try
{
	if (AgentConfig::action == command::help || AgentConfig::action == command::clean)
		return nullptr;

	auto codeMapping = initCodeMapping(dicts);

	switch (AgentConfig::programLang)
	{
		case language::cpp:
		{
			CppCodeReader::parseSourceCode(dicts, codeMapping);
			break;
		}
		default:
		{
			throw ErrorMessage(100, "Unsupported programming language.");
		}
	}
	return codeMapping;
}
catch (ErrorMessage msg)
{
	throw ErrorStack("CodeReader::findAllAnnotations") << (void*)&dicts << msg;
}
catch (ErrorStack err)
{
	throw err.addLevel("CodeReader::findAllAnnotations") << (void*)&dicts;
}


std::unique_ptr<usds::BasicParser> CodeReader::initCodeMapping(std::unique_ptr<usds::BasicParser>& dicts)
try
{
	auto codeMapping = make_unique<usds::BasicParser>();
	codeMapping->addDictionaryFromText(codeDictionary, 0, USDS_UTF8);

	usds::Dictionary* dict = dicts->selectFirstDictionary();
	while (dict != 0 )
	{
		


		dict = dicts->selectNextDictionary();
	}


	return codeMapping;
}
catch (ErrorMessage msg)
{
	throw ErrorStack("CodeReader::initCodeDescriptor") << (void*)&dicts << msg;
}
catch (ErrorStack err)
{
	throw err.addLevel("CodeReader::initCodeDescriptor") << (void*)&dicts;
}


