#ifndef USDS_ERRORS_H
#define USDS_ERRORS_H

#include <string>
#include <list>

namespace usds
{
	enum errorCodes
	{
		NO_ERROR_CODE = 0,
		// Binary Output: 001xxx
		BIN_OUT__BUFFER_OVERFLOW = 1001,
		BIN_OUT__ALLOCATE_ERROR = 1002,
		BIN_OUT__NEGATIVE_VALUE = 1003,
		// Binary Input: 002xxx
		BIN_IN__NULL_BUFF = 2001,
		BIN_IN__NULL_SIZE = 2002,
		BIN_IN__BUFF_OVERFLOW = 2003,
		BIN_IN__BEEG_UVARINT = 2004,
		// Dictionary Text Parser
		DICTIONARY_TEXT_PARSER__ERROR = 4001,
		DICTIONARY_TEXT_PARSER__UNSUPPORTABLE_ENCODE = 4002,
		// Dictionary
		DICTIONARY__ID_ERROR_VALUE = 5001,
		DICTIONARY__UNSUPPORTABLE_ENCODE = 5002,
		DICTIONARY__NOT_INITIALIZED = 5003,
		DICTIONARY__TAG_ALREADY_EXISTS = 5004,
		DICTIONARY__TAG_ID_ERROR_VALUE = 5005,
		DICTIONARY__NOT_FINALIZED = 5006,
		DICTIONARY__UNSUPPORTABLE_TYPE = 5007,
		DICTIONARY__UNKNOWN_FORMAT = 5008,
		DICTIONARY__FIELD_ALREADY_EXISTS = 5009,
		// StrucTag
		DIC_STRUCT_TAG__NOT_INITIALIZED_FIELD = 6001,
		DIC_STRUCT_TAG__FIELD_ID_ERROR_VALUE = 6002,
		DIC_STRUCT_TAG__FIELD_ALREADY_EXISTS = 6003,
		DIC_STRUCT_TAG__UNSUPPORTED_TYPE = 6004,
		// Text Dictionary Creator
		DICTIONARY_TEXT_CREATOR__UNSUPPORTABLE_ENCODE = 7001,
		// Struct Fields
		DIC_STRUCT_FIELD__ARRAY_NOT_INITIALIZED = 8001,
		DIC_STRUCT_FIELD__ARRAY_ELEMENT_NOT_TAG = 8002,
		DIC_STRUCT_FIELD__ARRAY_NOT_FINISHED = 8003,
		DIC_STRUCT_FIELD__TAG_NOT_FOUND = 8004,
		// Basic Parser
		BASIC_PARSER__DICTIONARY_NOT_FOUND = 9001,
		BASIC_PARSER__UNKNOWN_FORMAT = 9002,
		BASIC_PARSER__DICTIONARY_NULL_SIZE = 9003,
		BASIC_PARSER__BODY_IS_EMPTY = 9004,
		// Dictionary binary creator
		DIC_BINARY_CREATOR__UNSUPPORTED_TYPE = 10001,
		// Binary parser
		BINARY_PARSER__UNKNOWN_FORMAT = 11001,
		// Binary Dictionary Parser
		BINARY_DICTIONARY_PARSER__UNKNOWN_FORMAT = 12001,
		// Body
		BODY__ERROR_TAG_TYPE = 13001,
		BODY__ERROR_TAG_ROOT = 13002,
		BODY__TAG_NOT_FOUND = 13003,
		// Body Struct Tag
		BODY_STRUCT_TAG__FIELD_NOT_FOUND = 14001,
		BODY_STRUCT_TAG__ERROR_FIELD_TYPE = 14002,
		// Body Base Type
		USDS_BASE_TYPE__UNSUPPORTED_CONVERTION = 15001,
		// Body UVARINT type
		USDS_UVARINT__ERROR_VALUE = 16001,
		// Body Array Type
		USDS_ARRAY__ELEMENT_NOT_TAG = 17001,
		USDS_ARRAY__UNFIXED_ELEMENT_SIZE = 17002,
		// Body Json Creator
		BODY_JSON_CREATOR__UNSUPPORTABLE_ENCODE = 18001

	};

	class ErrorMessage
	{
	public:
		ErrorMessage(errorCodes code);
		ErrorMessage(errorCodes code, const char* utf8_message);
		~ErrorMessage();

		ErrorMessage& operator<<(const int value);
		ErrorMessage& operator<<(const size_t value);
		ErrorMessage& operator<<(const char* utf8_message);
		// addMessage(usdsEncodes code, void* message, size_t* size);

		errorCodes getCode();
		const char* getMessage();

	private:
		errorCodes errorCode;
		std::string message;
	};

	class ErrorStack
	{
	public:
		ErrorStack(const char* func_name);
		~ErrorStack();

		ErrorStack& addLevel(const char* func_name);

		ErrorStack& operator<<(ErrorMessage& message);

		ErrorStack& operator<<(const int value);
		ErrorStack& operator<<(const size_t value);
		ErrorStack& operator<<(const char* utf8_path);
		
		ErrorStack& operator<<(void* value);
		ErrorStack& operator<<(const unsigned char* value);
		ErrorStack& operator<<(unsigned long long* value);
		ErrorStack& operator<<(unsigned int* value);
		ErrorStack& operator<<(int* value);

		errorCodes getCode();
		const char* getMessage();
		const char* getFullMessage();

	private:
		errorCodes lastCode;
		std::string fullMessage;

		struct errorLevel
		{
			errorCodes code;
			std::string message;
			std::string path;
		};

		std::list<errorLevel> stack;

	};

};

#endif