#ifndef USDS_BINARY_OUTPUT_H
#define USDS_BINARY_OUTPUT_H

#include "errorMessage.h"
#include "usdsTypes.h"
#include "usdsTypeConverter.h"

namespace usds
{
	enum binaryOutputErrorCodes
	{
		BIN_OUT__BUFFER_OVERFLOW = 11,
		BIN_OUT__ALLOCATE_ERROR = 12,
		BIN_OUT__NEGATIVE_VALUE = 13,
		BIN_OUT__BEEG_VALUE = 14,
		BIN_OUT__NULL_POINTER = 15,
		BIN_OUT__ALREADY_INITIALIZED = 16
	};

	class BinaryOutput
	{
	public:
		BinaryOutput(size_t front_buffer_size) throw(...);
		~BinaryOutput();

		const uint8_t* getBinary(size_t* size) throw(...);
		const uint8_t* getBinary() throw(...);
		size_t getSize();
		
		// Working only with a data buffer, without front buffer
		size_t getBufferSize();
		void setBufferSize(size_t new_size) throw(...);

		void clear();		// it does not release memory in the buffer

		// serialization
		void writeBoolean(bool value) throw(...);
		void writeByte(int8_t value) throw(...);
		void writeUByte(uint8_t value) throw(...);
		void writeShort(int16_t value) throw(...);
		void writeUShort(uint16_t value) throw(...);
		void writeInt(int32_t value) throw(...);
		void writeUInt(uint32_t value) throw(...);
		void writeLong(int64_t value) throw(...);
		void writeULong(uint64_t value) throw(...);
		void writeFloat(float value) throw(...);
		void writeDouble(double value) throw(...);
		
		size_t writeVarint(int64_t value) throw(...);
		size_t writeUVarint(uint64_t value) throw(...);
		size_t writeUVarint(uint32_t value) throw(...);
		size_t writeUVarint(int32_t value) throw(...);

		void writeType(usdsTypes value) throw(...);
		void writeEncode(usdsEncodes value) throw(...);
		void writeSignature(usdsSignature value) throw(...);

		void writeByteArray(const void* value, size_t size) throw(...);
		void readByteArray(size_t position, void* value, size_t size) throw(...);

		// For usds headers
		// Working only with the front buffer
		void pushFrontSize() throw(...);
		void pushFrontUByte(uint8_t value) throw(...);
		void pushFrontUInt(uint32_t value) throw(...);
		void pushFrontSignature(usdsSignature value) throw(...);

		// For USDS arrays
		void write(usdsTypes usds_type, bool value) throw(...);
		void write(usdsTypes usds_type, int8_t value) throw(...);
		void write(usdsTypes usds_type, int16_t value) throw(...);
		void write(usdsTypes usds_type, int32_t value) throw(...);
		void write(usdsTypes usds_type, int64_t value) throw(...);
		void write(usdsTypes usds_type, uint8_t value) throw(...);
		void write(usdsTypes usds_type, uint16_t value) throw(...);
		void write(usdsTypes usds_type, uint32_t value) throw(...);
		void write(usdsTypes usds_type, uint64_t value) throw(...);
		void write(usdsTypes usds_type, float value) throw(...);
		void write(usdsTypes usds_type, double value) throw(...);

		void read(size_t position, usdsTypes usds_type, bool* value) throw(...);
		void read(size_t position, usdsTypes usds_type, int8_t* value) throw(...);
		void read(size_t position, usdsTypes usds_type, int16_t* value) throw(...);
		void read(size_t position, usdsTypes usds_type, int32_t* value) throw(...);
		void read(size_t position, usdsTypes usds_type, int64_t* value) throw(...);
		void read(size_t position, usdsTypes usds_type, uint8_t* value) throw(...);
		void read(size_t position, usdsTypes usds_type, uint16_t* value) throw(...);
		void read(size_t position, usdsTypes usds_type, uint32_t* value) throw(...);
		void read(size_t position, usdsTypes usds_type, uint64_t* value) throw(...);
		void read(size_t position, usdsTypes usds_type, float* value) throw(...);
		void read(size_t position, usdsTypes usds_type, double* value) throw(...);

		void writePointer(void* value) throw(...);
		void readPointer(size_t position, void** value) throw(...);

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
