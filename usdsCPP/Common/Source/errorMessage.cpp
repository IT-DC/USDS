#include "errorMessage.h"

//#include <iconv.h>
#include <sstream>

using namespace usds;

ErrorMessage::ErrorMessage(int code)
{
	errorCode = code;
};

ErrorMessage::ErrorMessage(int code, const char* utf8_message)
{
	errorCode = code;
	message = utf8_message;
};

ErrorMessage::~ErrorMessage()
{

};

ErrorMessage& ErrorMessage::operator << (const bool value)
{
	std::stringstream buff;
	if (value)
		buff << "true";
	else
		buff << "false";
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const int8_t value)
{
	std::stringstream buff;
	buff << (int32_t)value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const uint8_t value)
{
	std::stringstream buff;
	buff << (uint32_t)value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const int16_t value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const uint16_t value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const int32_t value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const uint32_t value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const int64_t value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const uint64_t value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const float value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const double value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const char* utf8_value)
{
	if (utf8_value != 0)
		message += utf8_value;

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const std::string& utf8_value)
{
	message += utf8_value;

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const std::string* utf8_value)
{
	message += *utf8_value;

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const void* value)
{
	std::stringstream buff;
	buff << "0x" << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::addString(const char* utf8_value, size_t size)
{
	if (utf8_value != 0)
	{
		if (size != 0)
			message.append(utf8_value, size);
		else
			message += utf8_value;
	}
	return *this;
};

int ErrorMessage::getCode()
{
	return errorCode;
};

const char* ErrorMessage::getMessage()
{
	return message.c_str();
};

//=======================================================================================================

ErrorStack::ErrorStack(const char* func_name)
{
	lastCode = 0;

	errorLevel buff;
	buff.code = 0;
	buff.path = func_name;
	buff.path += '(';

	stack.push_front(buff);
};

ErrorStack::~ErrorStack()
{


};

ErrorStack& ErrorStack::addLevel(const char* func_name)
{
	errorLevel buff;
	buff.code = 0;
	buff.path = func_name;
	buff.path += '(';

	stack.push_front(buff);

	return *this;
};

ErrorStack& ErrorStack::operator << (ErrorMessage& message)
{
	lastCode = message.getCode();

	stack.front().code = lastCode;
	stack.front().message = message.getMessage();

	return *this;
};

ErrorStack& ErrorStack::operator << (const bool value)
{
	std::stringstream buff;
	if (value)
		buff << "true";
	else
		buff << "false";

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "bool ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const int8_t value)
{
	std::stringstream buff;
	buff << (int32_t)value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "int8_t ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const uint8_t value)
{
	std::stringstream buff;
	buff << (uint32_t)value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "uint8_t ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const int16_t value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "int16_t ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const uint16_t value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "uint16_t ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const int32_t value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "int32_t ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const uint32_t value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "uint32_t ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const int64_t value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "int64_t ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const uint64_t value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "uint64_t ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const float value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "float ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const double value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "double ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const char* utf8_value)
{
	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	if (utf8_value != 0)
	{
		*path += "const char* \"";
		*path += utf8_value;
		*path += '"';
	}
	else
	{
		*path += "const char* 0";
	}

	return *this;
};

ErrorStack& ErrorStack::operator<<(const std::string* utf8_value)
{
	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	if (utf8_value != 0)
	{
		*path += "string* \"";
		*path += *utf8_value;
		*path += '"';
	}
	else
		*path += "string* 0";

	return *this;
};

ErrorStack& ErrorStack::operator << (const std::string& utf8_value)
{
	std::stringstream buff;
	buff << utf8_value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "string \"";
	*path += buff.str();
	*path += "\"";

	return *this;
};

ErrorStack& ErrorStack::operator << (const void* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "void* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const bool* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "bool* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const int8_t* value)
{
	std::stringstream buff;
	buff << (void*)value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "int8_t* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const uint8_t* value)
{
	std::stringstream buff;
	buff << (void*)value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "uint8_t* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const int16_t* value)
{
	std::stringstream buff;
	buff << (void*)value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "int16_t* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const uint16_t* value)
{
	std::stringstream buff;
	buff << (void*)value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "uint16_t* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const int32_t* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "int32_t* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const uint32_t* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "uint32_t* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const int64_t* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "int64_t* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const uint64_t* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "uint64_t* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const float* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "float* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const double* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "double* 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const char** value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "char** 0x";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::addStringAndSize(const char* utf8_value, size_t size)
{
	std::stringstream buff;
	buff << size;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	if (utf8_value != 0)
	{
		*path += "const char* \"";
		if (size != 0)
			path->append(utf8_value, size);
		else
			*path += utf8_value;
		*path += "\", size_t ";
		*path += buff.str();
	}
	else
	{
		*path += "const char* 0, size_t ";
		*path += buff.str();
	}

	return *this;
};


int ErrorStack::getCode()
{
	return lastCode;
};


const char* ErrorStack::getMessage()
{
	std::list<errorLevel>::iterator it = stack.begin();
	while ((*it).code == 0)
	{
		it++;
		if (it == stack.end())
			return "no message";
	}

	return (*it).message.c_str();
};

const char* ErrorStack::getFullMessage()
{
	std::stringstream buff;
	int32_t level = 0;

	fullMessage = "Error code: ";
	buff << lastCode;
	fullMessage += buff.str();
	fullMessage += "\nError message: \"";
	fullMessage += getMessage();
	fullMessage += "\"\nStack:\n";

	for (std::list<errorLevel>::iterator it = stack.begin(); it != stack.end(); it++)
	{
		fullMessage.append(level, '\t');
		if (level != 0)
			fullMessage += "--> ";
		if ((*it).code != 0)
		{
			fullMessage += "code=";
			buff.str("");
			buff << (*it).code;
			fullMessage += buff.str();
			fullMessage += ' ';
			if ((*it).message.size() != 0)
			{
				fullMessage += "message=\"";
				fullMessage += (*it).message;
				fullMessage += "\" ";
			}
		}
		fullMessage += "path=";
		fullMessage += (*it).path;
		fullMessage += ")\n";
		level++;
	}

	return fullMessage.c_str();
};

