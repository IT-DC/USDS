#include "CodeReaders/CPPCodeReader/cppCodeReader.h"

#include "Configuration/agentConfig.h"
#include "Common/fileSearcher.h"

#include <iostream>

#include "CppTextReader/flexCppTextReader.h"
#include "CppTextReader/bisonCppTextReader.hh"

using namespace std;
using namespace usdsAgent;

const char* CppCodeReader::cppAnnotation = "//$S";

// take this string from usdsCppCodeReader.udic in repository
const char* CppCodeReader::cppCodeDictionary =
"USDS UsdsCppCodeReader\n"
"ENCODE:UTF-8\n"
"{\n"
"\tCodeDescription\n"
"\t{\n"
"\t\tAnnotation[] mainAnnotations;\n"
"\t\t<StructDescription||ClassDescription> typeDescription;\n"
"\t};\n"
"\n"
"\tAnnotation\n"
"\t{\n"
"\t\tSTRING dictionaryName = NULL;\n"
"\t\tUBYTE dictionaryMajorVersion = NULL;\n"
"\t\tUBYTE dictionaryMinorVersion = NULL;\n"
"\t\t<StringEncode||NameMapping> attribute = NULL;\n"
"\t};\n"
"\t\n"
"\tStringEncode\n"
"\t{\n"
"\t\tUINT encodeId;\n"
"\t};\n"
"\t\n"
"\tNameMapping\n"
"\t{\n"
"\t\tSTRING mappedName;\n"
"\t};\n"
"\t\n"
"\tStructDescription\n"
"\t{\n"
"\t\tSTRING cppName;\n"
"\t\tElements []\n"
"\t\t{\n"
"\t\t\tAnnotation[] additionalAnnotations = NULL;\n"
"\t\t\t<FieldDescription||MethodDescription> ElementDescription;\n"
"\t\t};\n"
"\t};\n"
"\t\n"
"\tClassDescription\n"
"\t{\n"
"\t\tSTRING cppName;\n"
"\t\tElements []\n"
"\t\t{\n"
"\t\t\tAnnotation[] additionalAnnotations = NULL;\n"
"\t\t\t<FieldDescription||MethodDescription> ElementDescription;\n"
"\t\t};\n"
"\t};\n"
"\t\n"
"\tFieldDescription\n"
"\t{\n"
"\t\tSTRING fieldName;\n"
"\t\tSTRING typeName;\n"
"\t\tENUM fieldKind { simple = 1, link = 2, reference = 3 };\n"
"\t\tUBYTE linksNumber = NULL;\n"
"\t\tUVARINT[] arraySizes = NULL;\n"
"\t};\n"
"\t\n"
"\tMethodDescription\n"
"\t{\n"
"\t\tSTRING methodName;\n"
"\t\n"
"\t};\n"
"\n"
"}"
;

std::unique_ptr<usds::BasicParser> CppCodeReader::parseSourceCode(std::unique_ptr<usds::BasicParser>& dicts, std::unique_ptr<usds::BasicParser>& code_mapping)
{
	
	auto dictFiles = FileSearcher::findCodeFiles(AgentConfig::codePath, AgentConfig::codeFileExt, AgentConfig::cppAnnotation);

	BOOST_LOG_TRIVIAL(debug) << "Read dictionary 'cppCodeDictionary'";
	auto codeDescription = make_unique<usds::BasicParser>();;
	codeDescription->addDictionaryFromText(cppCodeDictionary, 0, usds::USDS_UTF8);

	BOOST_LOG_TRIVIAL(info) << "Read code files:";
	// Parse code files
	for (auto it = dictFiles->begin(); it != dictFiles->end(); ++it)
	{
		BOOST_LOG_TRIVIAL(info) << (*it).first;
		// Creating scanner and parser
		std::stringstream input;
		std::stringstream output;
		input << (*it).second.c_str();
		cppTextReader::FlexCppTextReader scanner(&input, &output);
		cppTextReader::BisonCppTextReader textParser(&scanner, (*it).second.c_str(), codeDescription, 0);
		// Parse!
		textParser.parse();
	}
	
	std::string json = "";
	codeDescription->getJSON(usds::USDS_UTF8, &json);
	BOOST_LOG_TRIVIAL(debug) << "Result:\n" << json;

	return codeDescription;


	
}
