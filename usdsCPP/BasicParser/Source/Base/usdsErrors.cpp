#include "base\usdsErrors.h"

#include <iconv.h>
#include <sstream>

using namespace usds;

void ErrorMessage::operator << (const int value)
{
	std::stringstream buff;
	buff << value;
	*message += buff.str();
};

void ErrorMessage::operator << (const char* utf8_message)
{
	*message += utf8_message;
};

//=======================================================================================================

void ErrorPath::operator << (const int value)
{
	std::stringstream buff;
	buff << value;
	
	*pathString += "int ";
	*pathString += buff.str();
	*pathString += ", ";
};

void ErrorPath::operator << (const char* utf8_path)
{
	if (pathString->size() == 0)
	{
		*pathString += utf8_path;
		*pathString += '(';
	}
	else
	{
		*pathString += "const char* '";
		*pathString += utf8_path;
		*pathString += "', ";
	}
};

//=======================================================================================================
Error::Error(errorCodes code)
{
	lastCode = code;
	
	ErrorLevel* level = new ErrorLevel;
	errorStack.push_front(level);
	level->errorCode = code;
	
	message._setSource(&(level->errorMessage));
	path._setSource(&(level->functionName));
};

Error::Error(errorCodes code, const char* utf8_message)
{
	lastCode = code;
	
	ErrorLevel* level = new ErrorLevel;
	errorStack.push_front(level);
	level->errorCode = code;
	level->errorMessage = utf8_message;

	message._setSource(&(level->errorMessage));
	path._setSource(&(level->functionName));
};

Error::~Error()
{
	while (!errorStack.empty())
	{
		ErrorLevel* level = errorStack.back();
		delete level;
		errorStack.pop_back();
	}
};

void Error::addLevel()
{
	ErrorLevel* level = new ErrorLevel;
	errorStack.push_front(level);
	level->errorCode = NO_ERROR_CODE;

	message._setSource(&(level->errorMessage));
	path._setSource(&(level->functionName));
};

void Error::addLevel(errorCodes code)
{
	lastCode = code;

	ErrorLevel* level = new ErrorLevel;
	errorStack.push_front(level);
	level->errorCode = code;

	message._setSource(&(level->errorMessage));
	path._setSource(&(level->functionName));
};

void Error::addLevel(errorCodes code, const char* utf8_message)
{
	lastCode = code;

	ErrorLevel* level = new ErrorLevel;
	errorStack.push_front(level);
	level->errorCode = code;
	level->errorMessage = utf8_message;

	message._setSource(&(level->errorMessage));
	path._setSource(&(level->functionName));
};


errorCodes Error::getCode()
{
	return lastCode;
};

const char* Error::getMessage()
{
	std::list<ErrorLevel*>::iterator it = errorStack.begin();
	while ((*it)->errorCode == NO_ERROR_CODE)
	{
		it++;
		if (it == errorStack.end())
			return "no message";
	}

	return (*it)->errorMessage.c_str();
};

const char* Error::getFullMessage()
{
	std::stringstream buff;
	int level = 0;
	
	fullMessage = "Error code: ";
	buff << lastCode;
	fullMessage += buff.str();
	fullMessage += "\nError message: ";
	fullMessage += getMessage();
	fullMessage += "\nStack:\n";

	for (std::list<ErrorLevel*>::iterator it = errorStack.begin(); it != errorStack.end(); it++)
	{
		fullMessage.append("-", level);
		if ((*it)->errorCode != NO_ERROR_CODE)
		{
			fullMessage += "code=";
			buff.clear();
			buff << (*it)->errorCode;
			fullMessage += buff.str();
			if ((*it)->errorMessage.size() != 0)
			{
				fullMessage += ", message='";
				fullMessage += (*it)->errorMessage;
				fullMessage += "', ";
			}
		}
		fullMessage += "path='";
		size_t size = (*it)->functionName.size();
		if (size > 0)
		{
			if ((*it)->functionName[size - 2] == ',')
				(*it)->functionName[size - 2] = ')';
			else
				(*it)->functionName += ')';
			fullMessage += (*it)->functionName;
		}
		fullMessage += "'\n";
		level++;
	}
	
	return fullMessage.c_str();
};

