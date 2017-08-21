#ifndef CPP_CODE_READER_H
#define CPP_CODE_READER_H

#include "BasicParser/Include/usdsBasicParser.h"

namespace usdsAgent
{
	class CppCodeReader
	{
	public:
		CppCodeReader();
		~CppCodeReader();
		virtual void f() = 0;

		static usds::BasicParser* findAllAnnotations(usds::BasicParser* dicts, usds::BasicParser* code_description);

	};
}
#endif
