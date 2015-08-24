#ifndef USDS_ERRORS
#define USDS_ERRORS

#include <string>

namespace usds
{
	enum errorCode
	{
		// Binary Output: 001xxx
		BIN_OUT_BUFFER_OVERFLOW = 1001,
		BIN_OUT_ALLOCATE_ERROR = 1002


	};

	// For exceptions
	class errorMessage
	{
	public:
		errorMessage(errorCode err_code, std::string* err_message, const char* err_path);
		~errorMessage() {};

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