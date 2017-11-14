#ifndef CODE_READER_H
#define CODE_READER_H

#include "BasicParser/Include/usdsBasicParser.h"

#include <memory>

namespace usdsAgent
{
	class CodeReader
	{
	public:
		virtual void f() = 0;

		static std::unique_ptr<usds::BasicParser> parseSourceCode(std::unique_ptr<usds::BasicParser>& dicts);

	private:

		static std::unique_ptr<usds::BasicParser> initCodeMapping(std::unique_ptr<usds::BasicParser>& dicts);

		static const char* codeDictionary;

	};

}

#endif
