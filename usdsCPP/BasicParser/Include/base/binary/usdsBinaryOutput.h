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

		const uint8_t* getBinary(size_t* size) throw(...);
		const uint8_t* getBinary() throw(...);
		size_t getSize();
		bool isEmpty();

		void clear();		// it does not release memory in the buffer

		// serialization
		int32_t writeUVarint(uint64_t value) throw(...);
		int32_t writeUVarint(uint32_t value) throw(...);
		int32_t writeUVarint(int32_t value) throw(...);
		void writeInt(int32_t value) throw(...);
		void writeLong(int64_t value) throw(...);
		void writeDouble(double value) throw(...);
		void writeUByte(uint8_t value) throw(...);
		void writeByte(int8_t value) throw(...);
		void writeBool(bool value) throw(...);
		void writeType(usdsTypes value) throw(...);
		void writeSignature(usdsSignature value) throw(...);
		void writeByteArray(const void* value, size_t size) throw(...);

		void pushFrontSize() throw(...);
		void pushFrontUByte(uint8_t value) throw(...);
		void pushFrontInt(int32_t value) throw(...);

		void readByteArray(size_t position, void* value, size_t size) throw(...);
		void readInt(size_t position, int32_t* value) throw(...);

	private:
		// Buffer for USDS output document
		size_t defaultDocSize;
		size_t defaultFrontBuffSize;
		uint8_t* usdsBuff;
		uint8_t* buffFirstPos;
		uint8_t* buffLastPos;		// It is a position after last valid position in the Buffer. The Buffer size is buffLastPos - usdsBuff
		uint8_t* buffCurrentPos;	// Last claen position in the Buffer. The document size is buffCurrentPos - usdsBuff
				
		void checkSize(size_t min_increase) throw(...);


	};
};


#endif
