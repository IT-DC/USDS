#ifndef CODE_READER_H
#define CODE_READER_H

#include "BasicParser/Include/usdsBasicParser.h"

namespace usdsAgent
{
	class CodeReader
	{
	public:
		virtual void f() = 0;

		static usds::BasicParser* parseSourceCode(usds::BasicParser* dicts);

	private:

		static usds::BasicParser* initCodeMapping(usds::BasicParser* dicts);

		static const char* codeDictionary;

	};

}

#endif
