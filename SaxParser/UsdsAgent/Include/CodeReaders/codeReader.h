#ifndef CODE_READER_H
#define CODE_READER_H

#include "BasicParser/Include/usdsBasicParser.h"

namespace usdsAgent
{
	class CodeReader
	{
	public:
		CodeReader();
		~CodeReader();
		virtual void f() = 0;

		static usds::BasicParser* findAllAnnotations(usds::BasicParser* dicts);

		static const char* codeDictionary;

	};

}

#endif
