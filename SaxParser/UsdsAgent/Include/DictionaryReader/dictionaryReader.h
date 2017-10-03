#ifndef DICTIONARY_READER_H
#define DICTIONARY_READER_H

#include "BasicParser/Include/usdsBasicParser.h"

namespace usdsAgent
{

	class AgentConfig;

	class DictionaryReader
	{
	public:
		virtual void f() = 0;

		static usds::BasicParser* findAllDictionaries();


	};

}

#endif
