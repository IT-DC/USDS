#ifndef USDS_ERRORS
#define USDS_ERRORS

#include <string>
#include <sstream>

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
		// Text Dictionary Parser
		TEXT_DICTIONARY_PARSER_ERROR = 4001,
		TEXT_DICTIONARY_PARSER_UNSUPPORTABLE_ENCODE = 4002,
		// Dictionary
		DICTIONARY_ID_ERROR_VALUE = 5001,
		DICTIONARY_UNSUPPORTABLE_ENCODE = 5002,
		DICTIONARY_NOT_INITIALIZED = 5003



	};

	// For exceptions
	class ErrorMessage
	{
	public:
		ErrorMessage(errorCode err_code, wchar_t* err_message);
		ErrorMessage(errorCode err_code, std::wstringstream* err_message);
		ErrorMessage(errorCode err_code, wchar_t* err_message, wchar_t* err_path);
		ErrorMessage(errorCode err_code, std::stringstream* err_message_utf8, wchar_t* err_path);
		ErrorMessage(errorCode err_code, std::wstringstream* err_message, wchar_t* err_path);
		~ErrorMessage();

		void addMessage(wchar_t* err_message);
		void addMessage(std::wstringstream* err_message);
		void addMessage(wchar_t* err_message, wchar_t* err_path);
		void addMessage(std::wstringstream* err_message, wchar_t* err_path);

		void setMessage(wchar_t* err_message);
		void setMessage(std::wstringstream* err_message);

		void setPath(wchar_t* err_path);
		void addPath(wchar_t* err_path);

		errorCode getCode() { return code; };
		const wchar_t* getMessage() { return message.c_str(); };
		const char* getMessageUTF8();
		const wchar_t* getFullMessage() { return fullMessage.c_str(); };
		const char* getFullMessageUTF8();

	private:
		errorCode code;
		std::wstring message;
		std::wstring fullMessage;
		int level;
		
		char* utf8Message;
		char* utf8FullMessage;
		

	};
		
};


#endif