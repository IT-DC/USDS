#include "base\usdsErrors.h"

//#include <iconv.h>
#include <sstream>

using namespace usds;

ErrorMessage::ErrorMessage(errorCodes code)
{
	errorCode = code;
};

ErrorMessage::ErrorMessage(errorCodes code, const char* utf8_message)
{
	errorCode = code;
	message = utf8_message;
};

ErrorMessage::~ErrorMessage()
{

};

ErrorMessage& ErrorMessage::operator << (const int value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const long long value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const unsigned long long value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const size_t value)
{
	std::stringstream buff;
	buff << value;
	message += buff.str();

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const char* utf8_message)
{
	message += utf8_message;

	return *this;
};

ErrorMessage& ErrorMessage::operator << (const std::string& utf8_message)
{
	message += utf8_message;

	return *this;
};

ErrorMessage& ErrorMessage::addString(const char* name, size_t size)
{
	message.append(name, size);

	return *this;
};

errorCodes ErrorMessage::getCode()
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
	lastCode = NO_ERROR_CODE;

	errorLevel buff;
	buff.code = NO_ERROR_CODE;
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
	buff.code = NO_ERROR_CODE;
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
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "bool ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const unsigned char value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "unsigned char ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const int value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "int ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const unsigned int value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "unsigned int ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const long long value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "long long ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator << (const unsigned long long value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";
	*path += "unsigned long long ";
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

ErrorStack& ErrorStack::operator << (const char* utf8_path)
{
	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "const char* \"";
	*path += utf8_path;
	*path += '"';

	return *this;
};

ErrorStack& ErrorStack::operator << (const void* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "void* ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const unsigned char* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "const unsigned char* ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const unsigned long long* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "unsigned long long* ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const unsigned int* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "unsigned int* ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const int* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "int* ";
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

	*path += "const char** ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::operator<<(const std::string* value)
{
	std::stringstream buff;
	buff << value;

	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "const string* ";
	*path += buff.str();

	return *this;
};

ErrorStack& ErrorStack::addStringAttribute(const char* name, size_t size)
{
	std::string* path = &(stack.front().path);

	if (path->back() != '(')
		*path += ", ";

	*path += "const char* \"";
	path->append(name, size);
	*path += '"';
	
	return *this;
};


errorCodes ErrorStack::getCode()
{
	return lastCode;
};


const char* ErrorStack::getMessage()
{
	std::list<errorLevel>::iterator it = stack.begin();
	while ((*it).code == NO_ERROR_CODE)
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
	int level = 0;

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
		if ((*it).code != NO_ERROR_CODE)
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

