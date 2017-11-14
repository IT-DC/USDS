#ifndef DICTIONARY_READER_H
#define DICTIONARY_READER_H

#include "BasicParser/Include/usdsBasicParser.h"
#include <memory>

namespace usdsAgent
{

	class AgentConfig;

	class DictionaryReader
	{
	public:
		virtual void f() = 0;

		static std::unique_ptr<usds::BasicParser> findAllDictionaries();


	};

}

#endif
