#ifndef CPP_CODE_READER_H
#define CPP_CODE_READER_H

#include "BasicParser/Include/usdsBasicParser.h"

namespace usdsAgent
{
	class CppCodeReader
	{
	public:
		virtual void f() = 0;

		static usds::BasicParser* parseSourceCode(usds::BasicParser* dicts, usds::BasicParser* code_mapping);

	private:
		
		static const char* cppAnnotation;
		static const char* codeDictionary;



	};
}
#endif
