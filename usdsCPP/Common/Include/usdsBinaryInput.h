#ifndef USDS_BINARY_INPUT_H
#define USDS_BINARY_INPUT_H

#include "errorMessage.h"

namespace usds
{
	enum binaryInputErrorCodes
	{
		BIN_IN__NULL_BUFF = 21,
		BIN_IN__NULL_SIZE = 22,
		BIN_IN__BUFF_OVERFLOW = 23,
		BIN_IN__BEEG_UVARINT = 24,
		BIN_IN__UVARINT_ERROR_FORMAT = 25,
		BIN_IN__BOOLEAN_ERROR_FORMAT = 26,
		BIN_IN__VARINT_ERROR_FORMAT = 27
	};

	class BinaryInput
	{
	public:
		BinaryInput();
		~BinaryInput();

		void setBinary(const uint8_t* buff, size_t size) throw(...);

		void clear();		// it does not release memory in buffer

		// deserialization
		bool readBool() throw(...);
		int8_t readByte() throw(...);
		uint8_t readUByte() throw(...);
		int16_t readShort() throw(...);
		uint16_t readUShort() throw(...);
		int32_t readInt() throw(...);
		uint32_t readUInt() throw(...);
		int64_t readLong() throw(...);
		uint64_t readULong() throw(...);
		float readFloat() throw(...);
		double readDouble() throw(...);
		
		size_t readVarint(int64_t* value) throw(...);

		size_t readUVarint(uint64_t* value) throw(...);
		size_t readUVarint(uint32_t* value) throw(...);
		size_t readUVarint(int32_t* value) throw(...);

		void readByteArray(void* buff, size_t size) throw(...);
		const void* readByteArray(size_t size) throw(...);
		
		void stepBack(size_t size) throw(...);
		void stepForward(size_t size) throw(...);

		bool isEnd() throw(...);
		const uint8_t* getCurrentPosition() throw(...);
		const uint8_t* getFirstPosition() throw(...);
		size_t getSize() throw(...);

	private:
		// Buffer for USDS input document
		const uint8_t* usdsBuff;
		const uint8_t* buffLastPos;		// It is a position after last valid position in the Buffer. The Buffer size is buff_last_pos - usds_buff
		const uint8_t* buffCurrentPos;		// Last unread position in the Buffer. The document size is buff_current_pos - usds_buff

	};
};


#endif
