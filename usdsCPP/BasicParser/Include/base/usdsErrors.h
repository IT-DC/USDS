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
		BIN_OUT__BEEG_VALUE = 1004,
		BIN_OUT__NULL_POINTER = 1005,
		// Binary Input: 002xxx
		BIN_IN__NULL_BUFF = 2001,
		BIN_IN__NULL_SIZE = 2002,
		BIN_IN__BUFF_OVERFLOW = 2003,
		BIN_IN__BEEG_UVARINT = 2004,
		BIN_IN__UVARINT_ERROR_FORMAT = 2005,
		BIN_IN__BOOLEAN_ERROR_FORMAT = 2006,
		// Dictionary Text Parser
		DICTIONARY_TEXT_PARSER__ERROR = 4001,
		DICTIONARY_TEXT_PARSER__UNSUPPORTABLE_ENCODE = 4002,
		// Dictionary
		DICTIONARY__ID_ERROR_VALUE = 5001,
		DICTIONARY__NO_TAGS = 5002,
		DICTIONARY__NOT_INITIALIZED = 5003,
		DICTIONARY__TAG_ALREADY_EXISTS = 5004,
		DICTIONARY__TAG_ID_ERROR_VALUE = 5005,
		DICTIONARY__NOT_FINALIZED = 5006,
		DICTIONARY__UNSUPPORTED_TYPE = 5007,
		DICTIONARY__NULL_NAME = 5008,
		// Dictionary Struct
		DIC_STRUCT__NOT_INITIALIZED_FIELD = 6001,
		DIC_STRUCT__FIELD_ID_ERROR_VALUE = 6002,
		DIC_STRUCT__FIELD_ALREADY_EXISTS = 6003,
		DIC_STRUCT__UNSUPPORTED_TYPE = 6004,
		DIC_STRUCT__FIELD_NOT_FOUND = 6005,
		DIC_STRUCT__NULL_NAME = 6006,
		DIC_STRUCT__STRUCT_IS_FINALIZED = 6007,
		DIC_STRUCT__STRUCT_IS_NOT_FINALIZED = 6008,
		DIC_STRUCT__NO_FIELD = 6009,
		DIC_STRUCT__ALLOCATE_ERROR = 6010,
		DIC_STRUCT__RECURSION_ERROR = 6011,
		// Text Dictionary Creator
		DIC_TEXT_CREATOR__UNSUPPORTED_ENCODE = 7001,
		DIC_TEXT_CREATOR__UNSUPPORTED_TYPE = 7001,
		// Dictionary array
		DIC_ARRAY__NOT_INITIALIZED = 8001,
		DIC_ARRAY__ELEMENT_NOT_TAG = 8002,
		DIC_ARRAY__NOT_FINISHED = 8003,
		DIC_ARRAY__TAG_NOT_FOUND = 8004,
		DIC_ARRAY__ERROR_ELEMENT_TYPE = 8005,
		DIC_ARRAY__ERROR_ELEMENT_NAME = 8006,
		DIC_ARRAY__ERROR_ELEMENT_ID = 8007,
		DIC_ARRAY__RECURSION_ERROR = 8008,
		DIC_ARRAY__ALREADY_INITIALIZED = 8009,
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
		DICTIONARY_BINARY_PARSER__UNKNOWN_FORMAT = 12001,
		// Body
		BODY__ERROR_TAG_TYPE = 13001,
		BODY__ERROR_TAG_ROOT = 13002,
		BODY__TAG_NOT_FOUND = 13003,
		BODY__NULL_PARENT_TAG = 13004,
		// Body Struct Tag
		BODY_STRUCT__FIELD_NOT_FOUND = 14001,
		BODY_STRUCT__ERROR_FIELD_TYPE = 14002,
		// Body Base Type
		BODY_BASE_TYPE__UNSUPPORTED_CONVERTION = 15001,
		// Body UVARINT type
		BODY_UVARINT__ERROR_VALUE = 16001,
		// Body Array Type
		BODY_ARRAY__ELEMENT_NOT_TAG = 17001,
		BODY_ARRAY__UNFIXED_ELEMENT_SIZE = 17002,
		BODY_ARRAY__ELEMENT_NOT_FOUND = 17003,
		// Body Json Creator
		BODY_JSON_CREATOR__UNSUPPORTABLE_ENCODE = 18001,
		BODY_JSON_CREATOR__UNSUPPORTED_TYPE = 18002,
		// USDS Types
		USDS_TYPES__ERROR_TYPE_CODE = 19001,
		USDS_TYPES__ERROR_ENCODE = 19002,
		// UsdsObjectPool
		USDS_OBJECT_POOL__ALLOCATE_ERROR = 20001,
		// BodyObjectPool
		BODY_OBJECT_POOL__UNSUPPORTED_TYPE = 21001,
		BODY_OBJECT_POOL__NULL_DICTIONARY_TAG = 21002,
		// DicObjectPool
		DIC_OBJECT_POOL__UNSUPPORTED_TYPE = 22001,
		// BodyBinaryCreator
		BODY_BINARY_CREATOR__UNSUPPORTED_TYPE = 23001,
		// Body Binary Parser
		BODY_BINARY_PARSER__UNSUPPORTED_TYPE = 24001,
		// DictionaryBaseType
		DIC_BASE_TYPE__NULL_DICTIONARY = 25001,
		DIC_BASE_TYPE__NULL_NAME = 25002,
		DIC_BASE_TYPE__TAG_ID_ERROR_VALUE = 25003,
		// Dictionary Tag Link
		DIC_TAG_LINK__TAG_NOT_FOUND = 26001,
		DIC_TAG_LINK__ERROR_ELEMENT_NAME = 26002,
		DIC_TAG_LINK__ERROR_ELEMENT_ID = 26003,
		DIC_TAG_LINK__NOT_INITIALIZED = 26004,
		// Dictionary String
		DIC_STRING__ERROR_ENCODE = 27001

	};

	class ErrorMessage
	{
	public:
		ErrorMessage(errorCodes code);
		ErrorMessage(errorCodes code, const char* utf8_message);
		~ErrorMessage();

		ErrorMessage& operator<<(const int value);
		ErrorMessage& operator<<(const unsigned int value);
		ErrorMessage& operator<<(const long long value);
		ErrorMessage& operator<<(const unsigned long long value);
		ErrorMessage& operator<<(const char* utf8_message);
		ErrorMessage& operator<<(const std::string& utf8_message);
		
		ErrorMessage& addString(const char* name, size_t size);

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

		ErrorStack& operator<<(const bool value);
		ErrorStack& operator<<(const unsigned char value);
		ErrorStack& operator<<(const int value);
		ErrorStack& operator<<(const unsigned int value);
		ErrorStack& operator<<(const long long value);
		ErrorStack& operator<<(const unsigned long long value);
		ErrorStack& operator<<(const double value);
		ErrorStack& operator<<(const char* utf8_path);
		
		ErrorStack& operator<<(const void* value);
		ErrorStack& operator<<(const unsigned char* value);
		ErrorStack& operator<<(const unsigned long long* value);
		ErrorStack& operator<<(const unsigned int* value);
		ErrorStack& operator<<(const int* value);
		ErrorStack& operator<<(const char** value);
		ErrorStack& operator<<(const std::string* value);

		ErrorStack& addStringAttribute(const char* name, size_t size);

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