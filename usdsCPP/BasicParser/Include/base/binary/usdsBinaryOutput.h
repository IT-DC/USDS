#ifndef USDS_BINARY_OUTPUT_H
#define USDS_BINARY_OUTPUT_H

#include "base\usdsErrors.h"
#include "base\usdsTypes.h"

namespace usds
{
	class BinaryOutput
	{
	public:
		BinaryOutput() throw(...);
		~BinaryOutput();

		const unsigned char* getBinary(size_t* size) throw(...);
		const unsigned char* getBinary() throw(...);
		size_t getSize();
		bool isEmpty();

		void clear();		// it does not release memory in the buffer

		// serialization
		int writeUVarint(unsigned long long value) throw(...);
		int writeUVarint(unsigned int value) throw(...);
		int writeUVarint(int value) throw(...);
		void writeInt(int value) throw(...);
		void writeLong(long long value) throw(...);
		void writeDouble(double value) throw(...);
		void writeUByte(unsigned char value) throw(...);
		void writeByte(char value) throw(...);
		void writeBool(bool value) throw(...);
		void writeType(usdsTypes value) throw(...);
		void writeSignature(usdsSignature value) throw(...);
		void writeByteArray(const void* value, size_t size) throw(...);

		void pushFrontSize() throw(...);
		void pushFrontUByte(unsigned char value) throw(...);
		void pushFrontInt(int value) throw(...);

		void readByteArray(size_t position, void* value, size_t size) throw(...);
		void readInt(size_t position, int* value) throw(...);

	private:
		// Buffer for USDS output document
		size_t defaultDocSize;
		size_t defaultFrontBuffSize;
		unsigned char* usdsBuff;
		unsigned char* buffFirstPos;
		unsigned char* buffLastPos;		// It is a position after last valid position in the Buffer. The Buffer size is buffLastPos - usdsBuff
		unsigned char* buffCurrentPos;	// Last claen position in the Buffer. The document size is buffCurrentPos - usdsBuff
				
		void checkSize(size_t min_increase) throw(...);


	};
};


#endif
