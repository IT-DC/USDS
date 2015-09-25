#ifndef USDS_BINARY_OUTPUT
#define USDS_BINARY_OUTPUT

#include <string>

#include "base\usdsErrors.h"

namespace usds
{
	class BinaryOutput
	{
	public:
		BinaryOutput() throw(...);
		~BinaryOutput();

		const unsigned char* getBinary(size_t* size) throw(...);

		void clear();		// it does not release memory in buffer

		// serialization
		void writeUVarint(unsigned long long value) throw(...);
		void writeUVarint(unsigned int value) throw(...);
		void writeUVarint(int value) throw(...);
		void writeInt(int value) throw(...);
		void writeLong(long long value) throw(...);
		void writeDouble(double value) throw(...);
		void writeUByte(unsigned char value) throw(...);
		void writeByteArray(void* value, size_t size) throw(...);
		void writeBool(bool value) throw(...);

	private:
		// Buffer for USDS output document
		size_t defaultDocSize;
		unsigned char* usdsBuff;
		unsigned char* buffLastPos;		// It is a position after last valid position in the Buffer. The Buffer size is buffLastPos - usdsBuff
		unsigned char* buffCurrentPos;	// Last claen position in the Buffer. The document size is buffCurrentPos - usdsBuff
		
		void checkSize(size_t min_increase) throw(...);


	};
};


#endif
