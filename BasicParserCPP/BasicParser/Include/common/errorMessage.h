#ifndef ERROR_MESSAGE_H
#define ERROR_MESSAGE_H

#include <string>
#include <list>

#ifdef _MSC_VER
#if _MSC_VER >= 1600
#include <cstdint>
#else
typedef __int8              int8_t;
typedef __int16             int16_t;
typedef __int32             int32_t;
typedef __int64             int64_t;
typedef unsigned __int8     uint8_t;
typedef unsigned __int16    uint16_t;
typedef unsigned __int32    uint32_t;
typedef unsigned __int64    uint64_t;
#endif
#elif __GNUC__ >= 3
#include <cstdint>
#endif


namespace usds
{
	class ErrorMessage
	{
	public:
		ErrorMessage(int code);
		ErrorMessage(int code, const char* utf8_message);
		~ErrorMessage();

		ErrorMessage& operator<<(const bool value);
		ErrorMessage& operator<<(const int8_t value);
		ErrorMessage& operator<<(const uint8_t value);
		ErrorMessage& operator<<(const int16_t value);
		ErrorMessage& operator<<(const uint16_t value);
		ErrorMessage& operator<<(const int32_t value);
		ErrorMessage& operator<<(const uint32_t value);
		ErrorMessage& operator<<(const int64_t value);
		ErrorMessage& operator<<(const uint64_t value);
		ErrorMessage& operator<<(const float value);
		ErrorMessage& operator<<(const double value);
		ErrorMessage& operator<<(const char* utf8_value);
		ErrorMessage& operator<<(const std::string& utf8_value);
		ErrorMessage& operator<<(const std::string* utf8_value);
		ErrorMessage& operator<<(const void* value);

		ErrorMessage& addString(const char* utf8_value, size_t size);

		int getCode();
		const char* getMessage();

	private:
		int errorCode;
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
		ErrorStack& operator<<(const int8_t value);
		ErrorStack& operator<<(const uint8_t value);
		ErrorStack& operator<<(const int16_t value);
		ErrorStack& operator<<(const uint16_t value);
		ErrorStack& operator<<(const int32_t value);
		ErrorStack& operator<<(const uint32_t value);
		ErrorStack& operator<<(const int64_t value);
		ErrorStack& operator<<(const uint64_t value);
		ErrorStack& operator<<(const float value);
		ErrorStack& operator<<(const double value);
		ErrorStack& operator<<(const char* utf8_value);
		ErrorStack& operator<<(const std::string* utf8_value);
		ErrorStack& operator<<(const std::string& utf8_value);

		ErrorStack& operator<<(const void* value);
		ErrorStack& operator<<(const bool* value);
		ErrorStack& operator<<(const int8_t* value);
		ErrorStack& operator<<(const uint8_t* value);
		ErrorStack& operator<<(const int16_t* value);
		ErrorStack& operator<<(const uint16_t* value);
		ErrorStack& operator<<(const int32_t* value);
		ErrorStack& operator<<(const uint32_t* value);
		ErrorStack& operator<<(const int64_t* value);
		ErrorStack& operator<<(const uint64_t* value);
		ErrorStack& operator<<(const float* value);
		ErrorStack& operator<<(const double* value);
		ErrorStack& operator<<(const char** value);

		ErrorStack& addStringAndSize(const char* utf8_value, size_t size);

		int getCode();
		const char* getMessage();
		const char* getFullMessage();

	private:
		int lastCode;
		std::string fullMessage;

		struct errorLevel
		{
			int code;
			std::string message;
			std::string path;
		};

		std::list<errorLevel> stack;

	};



}

#endif
