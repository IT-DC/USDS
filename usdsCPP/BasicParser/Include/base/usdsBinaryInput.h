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

		void setBinary(unsigned char* buff, size_t size) throw(...);

		void clear();		// it does not release memory in buffer

		// deserialization
		inline unsigned long long readUVarint() throw(...);
		inline int readInt() throw(...);
		inline long long readLong() throw(...);
		inline double readDouble() throw(...);
		inline void readString(unsigned char* buff, int size) throw(...);
		inline bool readBool() throw(...);

	private:
		// Buffer for USDS input document
		unsigned char* in_usds_buff;
		unsigned char* in_buff_last_pos;		// It is a position after last valid position in the Buffer. The Buffer size is buff_last_pos - usds_buff
		unsigned char* in_buff_current_pos;		// Last unread position in the Buffer. The document size is buff_current_pos - usds_buff
		unsigned char* in_buff_body_pos;		// The first byte of body, after tag 'B'
		unsigned char* in_buff_body_last_pos;	// The last body position - tag 0


	};
};


#endif
