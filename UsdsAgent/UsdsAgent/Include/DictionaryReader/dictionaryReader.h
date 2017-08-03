#ifndef DICTIONARY_READER_H
#define DICTIONARY_READER_H

#include "BasicParser/Include/usdsBasicParser.h"

namespace usdsAgent
{

	class AgentConfig;

	class DictionatyReader
	{
	public:
		DictionatyReader(AgentConfig* config);
		~DictionatyReader();
		virtual void f() = 0;

		static usds::BasicParser* parse(AgentConfig* config);


	};

}

#endif
