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
"USDS 2:UsdsCppCodeReader 0.1\n"
"ENCODE:UTF-8\n"
"{\n"
"\tCodeDescription\n"
"\t{\n"
"\t\tSTRING dictionaryName;\n"
"\t\tUBYTE dictionaryMajorVersion = NULL;\n"
"\t\tUBYTE dictionaryMinorVersion = NULL;\n"
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
"\t\t\tAnnotation[] additionalAnnotations;\n"
"\t\t};\n"
"\t};\n"
"\t\n"
"\tClassDescription\n"
"\t{\n"
"\t\tStructFields []\n"
"\t\t{\n"
"\t\t\tSTRING fieldName;\n"
"\t\t\tAnnotation[] additionalAnnotations;\n"
"\t\t};\n"
"\t};\n"
"\t\n"
"\t<StringEncode||NameMapping> Annotation;\n"
"\n"
"\tStringEncode\n"
"\t{\n"
"\t\tSTRING dictionaryName = NULL;\n"
"\t\tUBYTE dictionaryMajorVersion = NULL;\n"
"\t\tUBYTE dictionaryMinorVersion = NULL;\n"
"\t\tENUM encode { noencode = 0, utf8 = 1 };\n"
"\t};\n"
"\t\n"
"\tNameMapping\n"
"\t{\n"
"\t\tSTRING dictionaryName = NULL;\n"
"\t\tUBYTE dictionaryMajorVersion = NULL;\n"
"\t\tUBYTE dictionaryMinorVersion = NULL;\t\n"
"\t\tSTRING mappedName;\n"
"\t};\n"
"}"
;

usds::BasicParser* CppCodeReader::parseSourceCode(usds::BasicParser* dicts, usds::BasicParser* code_mapping)
{
	BOOST_LOG_TRIVIAL(info) << "Read code files";
	list<pair<string, string>>* dictFiles = FileSearcher::findCodeFiles(AgentConfig::codePath, AgentConfig::codeFileExt, AgentConfig::cppAnnotation);

	usds::BasicParser* codeDescription = new usds::BasicParser();
	codeDescription->addDictionaryFromText(cppCodeDictionary, 0, usds::USDS_UTF8);

	// Parse code files
	for (auto it = dictFiles->begin(); it != dictFiles->end(); ++it)
	{
		// Creating scanner and parser
		std::stringstream input;
		std::stringstream output;
		input << (*it).second.c_str();
		cppTextReader::FlexCppTextReader scanner(&input, &output);
		cppTextReader::BisonCppTextReader textParser(&scanner, (*it).second.c_str(), codeDescription);
		// Parse!
		textParser.parse();

	}




	return 0;
}
