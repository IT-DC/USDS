#ifndef USDS_ERRORS_H
#define USDS_ERRORS_H

#include <string>
#include <sstream>

namespace usds
{
	enum errorCode
	{
		// Binary Output: 001xxx
		BIN_OUT_BUFFER_OVERFLOW = 1001,
		BIN_OUT_ALLOCATE_ERROR = 1002,
		BIN_OUT_NEGATIVE_VALUE = 1003,
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
		DICTIONARY_NOT_INITIALIZED = 5003,
		DICTIONARY_TAG_ALREADY_EXISTS = 5004,
		DICTIONARY_TAG_ID_ERROR_VALUE = 5005,
		DICTIONARY_NOT_FINALIZED = 5006,
		DICTIONARY_UNSUPPORTABLE_TYPE = 5007,
		DICTIONARY_UNKNOWN_FORMAT = 5008,
		DICTIONARY_FIELD_ALREADY_EXISTS = 5009,
		// StrucTag
		DIC_STRUCT_TAG_NOT_INITIALIZED_FIELD = 6001,
		DIC_STRUCT_TAG_FIELD_ID_ERROR_VALUE = 6002,
		DIC_STRUCT_TAG_FIELD_ALREADY_EXISTS = 6003,
		DIC_STRUCT_TAG_UNSUPPORTED_TYPE = 6004,
		// Text Dictionary Creator
		TEXT_DICTIONARY_CREATOR_UNSUPPORTABLE_ENCODE = 7001,
		// Struct Fields
		DIC_STRUCT_FIELD_ARRAY_NOT_INITIALIZED = 8001,
		DIC_STRUCT_FIELD_ARRAY_ELEMENT_NOT_TAG = 8002,
		DIC_STRUCT_FIELD_ARRAY_NOT_FINISHED = 8003,
		DIC_STRUCT_FIELD_TAG_NOT_FOUND = 8004,
		// Basic Parser
		BASIC_PARSER_DICTIONARY_NOT_FOUND = 9001,
		BASIC_PARSER_UNKNOWN_FORMAT = 9002,
		BASIC_PARSER_DICTIONARY_NULL_SIZE = 9003,
		// Dictionary binary creator
		DIC_BINARY_CREATOR_UNSUPPORTED_TYPE = 10001,
		// Binary parser
		BINARY_PARSER_UNKNOWN_FORMAT = 11001,
		// Binary Dictionary Parser
		BINARY_DICTIONARY_PARSER_UNKNOWN_FORMAT = 12001

	};

	// For exceptions
	class ErrorMessage
	{
	public:
		ErrorMessage(errorCode err_code, wchar_t* err_message);
		ErrorMessage(errorCode err_code, std::stringstream* err_message_utf8);
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