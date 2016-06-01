#ifndef USDS_BINARY_INPUT_H
#define USDS_BINARY_INPUT_H

#include "base\usdsErrors.h"

namespace usds
{
	class BinaryInput
	{
	public:
		BinaryInput();
		~BinaryInput();

		void setBinary(const uint8_t* buff, size_t size) throw(...);

		void clear();		// it does not release memory in buffer

		// deserialization
		int32_t readUVarint(uint64_t* value) throw(...);
		int32_t readUVarint(uint32_t* value) throw(...);
		int32_t readUVarint(int32_t* value) throw(...);
		int32_t readInt() throw(...);
		int64_t readLong() throw(...);
		double readDouble() throw(...);
		void readByteArray(void* buff, size_t size) throw(...);
		const void* readByteArray(size_t size) throw(...);
		bool readBool() throw(...);
		uint8_t readUByte() throw(...);
		int8_t readByte() throw(...);

		void stepBack(size_t size) throw(...);
		void stepForward(size_t size) throw(...);

		bool isEnd() throw(...);
		const uint8_t* getCurrentPosition() throw(...);
		const uint8_t* getFirstPosition() throw(...);
		size_t getDataSize() throw(...);

	private:
		// Buffer for USDS input document
		const uint8_t* usdsBuff;
		const uint8_t* buffLastPos;		// It is a position after last valid position in the Buffer. The Buffer size is buff_last_pos - usds_buff
		const uint8_t* buffCurrentPos;		// Last unread position in the Buffer. The document size is buff_current_pos - usds_buff

	};
};


#endif
