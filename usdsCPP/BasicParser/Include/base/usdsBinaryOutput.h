#ifndef USDS_BINARY_OUTPUT
#define USDS_BINARY_OUTPUT

#include <string>

#include "base\usdsErrors.h"

namespace usds
{
	class BinaryOutput
	{
	public:
		BinaryOutput();
		~BinaryOutput();



		void clean();		// it does not release memory in buffer


		// serialization
		inline void writeUVarint(unsigned long long value) throw();
		inline void writeInt(int value) throw();
		inline void writeLong(long long value) throw();
		inline void writeDouble(double value) throw();
		inline void writeUTF8String(const char* value, int size) throw();
		inline void writeBool(bool value) throw();

	private:
		// Buffer for USDS output document
		size_t out_default_doc_size;
		unsigned char* out_usds_buff;
		unsigned char* out_buff_last_pos;		// It is a position after last valid position in the Buffer. The Buffer size is buff_last_pos - usds_buff
		unsigned char* out_buff_current_pos;	// Last claen position in the Buffer. The document size is buff_current_pos - usds_buff
		
		inline void resizeArray(size_t min_increase) throw();


	};
};


#endif
