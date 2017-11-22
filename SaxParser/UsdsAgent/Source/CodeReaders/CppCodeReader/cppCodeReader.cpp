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
"\t\tDictionaryLinks []\n"
"\t\t{\n"
"\t\t\tSTRING dictionaryName;\n"
"\t\t\tUBYTE dictionaryMajorVersion = NULL;\n"
"\t\t\tUBYTE dictionaryMinorVersion = NULL;\n"
"\t\t};\n"
"\t\tENUM cppType { struct=1, class = 2 };\n"
"\t\tSTRING cppName;\n"
"\t\t<StructDescription||ClassDescription> typeDescription;\n"
"\t};\n"
"\n"
"\tStructDescription\n"
"\t{\n"
"\t\tStructFields []\n"
"\t\t{\n"
"\t\t\tSTRING fieldName;\n"
"\t\t\tSTRING typeName;\n"
"\t\t\tENUM fieldKind { simple = 1, link = 2, array_of_simple = 3 };\n"
"\t\t\tUVARINT array_size = NULL;\n"
"\t\t\tAnnotation[] additionalAnnotations = NULL;\n"
"\t\t};\n"
"\t};\n"
"\t\n"
"\tClassDescription\n"
"\t{\n"
"\t\tClassFields []\n"
"\t\t{\n"
"\t\t\tSTRING fieldName;\n"
"\t\t\tAnnotation[] additionalAnnotations = NULL;\n"
"\t\t};\n"
"\t};\n"
"\t\n"
"\t<StringEncode||NameMapping> Annotation;\n"
"\n"
"\tStringEncode\n"
"\t{\n"
"\t\tDictionaryLinks []\n"
"\t\t{\n"
"\t\t\tSTRING dictionaryName = NULL;\n"
"\t\t\tUBYTE dictionaryMajorVersion = NULL;\n"
"\t\t\tUBYTE dictionaryMinorVersion = NULL;\n"
"\t\t} = NULL;\n"
"\t\tUINT encodeId;\n"
"\t};\n"
"\t\n"
"\tNameMapping\n"
"\t{\n"
"\t\tDictionaryLinks []\n"
"\t\t{\n"
"\t\t\tSTRING dictionaryName = NULL;\n"
"\t\t\tUBYTE dictionaryMajorVersion = NULL;\n"
"\t\t\tUBYTE dictionaryMinorVersion = NULL;\n"
"\t\t} = NULL;\n"
"\t\tSTRING mappedName;\n"
"\t};\n"
"}"
;

std::unique_ptr<usds::BasicParser> CppCodeReader::parseSourceCode(std::unique_ptr<usds::BasicParser>& dicts, std::unique_ptr<usds::BasicParser>& code_mapping)
{
	BOOST_LOG_TRIVIAL(info) << "Read code files";
	auto dictFiles = FileSearcher::findCodeFiles(AgentConfig::codePath, AgentConfig::codeFileExt, AgentConfig::cppAnnotation);

	auto codeDescription = make_unique<usds::BasicParser>();;
	codeDescription->addDictionaryFromText(cppCodeDictionary, 0, usds::USDS_UTF8);

	// Parse code files
	for (auto it = dictFiles->begin(); it != dictFiles->end(); ++it)
	{
		// Creating scanner and parser
		std::stringstream input;
		std::stringstream output;
		input << (*it).second.c_str();
		cppTextReader::FlexCppTextReader scanner(&input, &output);
		cppTextReader::BisonCppTextReader textParser(&scanner, (*it).second.c_str(), codeDescription, 0);
		// Parse!
		textParser.parse();

	}

	return codeDescription;


	
}
