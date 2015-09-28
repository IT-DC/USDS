#ifndef USDS_BINARY_INPUT
#define USDS_BINARY_INPUT

#include <string>

#include "base\usdsErrors.h"

namespace usds
{
	class BinaryInput
	{
	public:
		BinaryInput();
		~BinaryInput();

		void setBinary(const unsigned char* buff, size_t size) throw(...);

		void clear();		// it does not release memory in buffer

		// deserialization
		int readUVarint(unsigned long long* value) throw(...);
		int readUVarint(unsigned int* value) throw(...);
		int readUVarint(int* value) throw(...);
		int readInt() throw(...);
		long long readLong() throw(...);
		double readDouble() throw(...);
		void readByteArray(void* buff, size_t size) throw(...);
		const void* readByteArray(size_t size) throw(...);
		bool readBool() throw(...);
		unsigned char readByte() throw(...);

		void stepBack(size_t size) throw(...);
		void stepForward(size_t size) throw(...);

		bool isEnd() throw(...);

	private:
		// Buffer for USDS input document
		const unsigned char* usdsBuff;
		const unsigned char* buffLastPos;		// It is a position after last valid position in the Buffer. The Buffer size is buff_last_pos - usds_buff
		const unsigned char* buffCurrentPos;		// Last unread position in the Buffer. The document size is buff_current_pos - usds_buff



	};
};


#endif
