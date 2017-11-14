#ifndef CPP_CODE_READER_H
#define CPP_CODE_READER_H

#include "BasicParser/Include/usdsBasicParser.h"

#include <memory>

namespace usdsAgent
{
	class CppCodeReader
	{
	public:
		virtual void f() = 0;

		static std::unique_ptr<usds::BasicParser> parseSourceCode(std::unique_ptr<usds::BasicParser>& dicts, std::unique_ptr<usds::BasicParser>& code_mapping);

	private:
		
		static const char* cppAnnotation;
		static const char* cppCodeDictionary;



	};
}
#endif
