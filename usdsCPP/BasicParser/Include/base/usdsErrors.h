#ifndef USDS_ERRORS
#define USDS_ERRORS

#include <string>

namespace usds
{
	enum errorCode
	{
		// Binary Output: 001xxx
		BIN_OUT_BUFFER_OVERFLOW = 1001,
		BIN_OUT_ALLOCATE_ERROR = 1002,
		// Binary Input: 002xxx
		BIN_IN_NULL_BUFF = 2001,
		BIN_IN_NULL_SIZE = 2002,
		BIN_IN_BUFF_OVERFLOW = 2003,
		BIN_IN_BEEG_UVARINT = 2004,
		// Dictionary Text Parser: 003xxx
		DIC_TEXT_PARSER_UNKNOWN_TOKEN = 3001



	};

	// For exceptions
	class ErrorMessage
	{
	public:
		ErrorMessage(errorCode err_code, std::string* err_message, const char* err_path);
		~ErrorMessage() {};

		void addMessage(std::string* err_message, const char* err_path);
		void addMessage(const char* err_path);
		int getCode() { return code; };

	private:
		errorCode code;
		std::string message;
		std::string full_message;
		rsize_t level;
		
	};
		
};


#endif