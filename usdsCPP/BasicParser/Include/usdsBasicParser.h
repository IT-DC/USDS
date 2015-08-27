#ifndef USDS_BASIC_PARSER
#define USDS_BASIC_PARSER

#include "base\usdsErrors.h"
#include "base\usdsObjectPool.h"
#include "base\usdsDictionary.h"
#include "base\usdsBinaryInput.h"
#include "base\usdsBinaryOutput.h"

namespace usds
{
	class BasicParser
	{
	public:
		BasicParser();
		~BasicParser();

		// Settings
		void setDictionaryVersion(unsigned char major, unsigned char minor);
		void getUsdsVersion(int* major, int* minor);
		void getDictionaryVersion(int* major, int* minor);

		// Dictionary constructor
		void initDictionaryFromText(const char* text_dictionary, int size) throw(...);

		// Serialization
		void addHead();
		void addDictionary();
		void addBody();
		void getUSDS(unsigned char** data, int* size);

		// Deserialization
		void parse(unsigned char* data, int data_size);

		// clean
		void clean();		// it does not release memory in buffer
		void release();		// release all memory
		
	private:
		// settings
		unsigned char usds_major;
		unsigned char usds_minor;
		unsigned char dictionary_major;
		unsigned char dictionary_minor;
		int full_dictionary_version;

		// Current output status
		bool out_head_added;
		bool out_dictionary_added;
		bool out_body_added;

		// Current input status
		bool in_head_included;
		bool in_dictionary_included;

		Dictionary dict;
		BinaryInput usds_input;
		BinaryOutput usds_output;
		


	};

};

#endif