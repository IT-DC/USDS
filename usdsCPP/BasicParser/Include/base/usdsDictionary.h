#ifndef USDS_DICTIONARY
#define USDS_DICTIONARY

#include "base\usdsBinaryInput.h"
#include "base\usdsBinaryOutput.h"
#include "base\usdsObjectPool.h"
#include "base\usdsErrors.h"

#include "tags\dicBaseTag.h"

namespace usds
{
	class Dictionary
	{
	public:
		Dictionary();
		~Dictionary();



	private:

		int dictionaryID;
		unsigned char majorVersion;
		unsigned char minorVersion;


		DictionaryObjectPool objects;




	};
}
#endif