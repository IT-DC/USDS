#include "base\usdsErrors.h"

#include <Windows.h>

using namespace usds;

ErrorMessage::ErrorMessage(errorCode err_code, wchar_t* err_message)
{
	level = 0;
	code = err_code;
	message = err_message;
	fullMessage = L"Error: ";
	fullMessage += err_message;
	fullMessage += L"\n";

	utf8Message = 0;
	utf8FullMessage = 0;
};

ErrorMessage::ErrorMessage(errorCode err_code, std::stringstream* err_message_utf8)
{
	level = 0;
	code = err_code;

	// covert message from utf-8 to utf-16
	int message_size = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, err_message_utf8->str().c_str(), err_message_utf8->str().size(), 0, 0);
	if (message_size == 0)
		message = L"Invalid error message, can not convert from utf8 to utf16";
	else
	{
		wchar_t* message_buff = new wchar_t[message_size + 1];
		int final_size = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, err_message_utf8->str().c_str(), err_message_utf8->str().size(), message_buff, message_size);
		if (final_size == 0)
			message = L"Invalid error message, can not convert from utf8 to utf16";
		else
		{
			message_buff[message_size] = 0;
			message = message_buff;
		}
		delete[] message_buff;
	};

	fullMessage = L"Error: ";
	fullMessage += message;
	fullMessage += L"\n";

	utf8Message = 0;
	utf8FullMessage = 0;
};

ErrorMessage::ErrorMessage(errorCode err_code, std::wstringstream* err_message)
{
	level = 0;
	code = err_code;
	message = err_message->str();
	fullMessage = L"Error: ";
	fullMessage += err_message->str();
	fullMessage += L"\n";

	utf8Message = 0;
	utf8FullMessage = 0;
};

ErrorMessage::ErrorMessage(errorCode err_code, wchar_t* err_message, wchar_t* err_path)
{
	level = 0;
	code = err_code;
	message = err_message;
	fullMessage = L"Error: ";
	fullMessage += err_message;
	fullMessage += L"\nModule: ";
	fullMessage += err_path;
	fullMessage += L"\n";

	utf8Message = 0;
	utf8FullMessage = 0;
};

ErrorMessage::ErrorMessage(errorCode err_code, std::stringstream* err_message_utf8, wchar_t* err_path)
{
	level = 0;
	code = err_code;
	
	// covert message from utf-8 to utf-16
	int message_size = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, err_message_utf8->str().c_str(), err_message_utf8->str().size(), 0, 0);
	if (message_size == 0)
		message = L"Invalid error message, can not convert from utf8 to utf16";
	else
	{
		wchar_t* message_buff = new wchar_t[message_size+1];
		int final_size = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, err_message_utf8->str().c_str(), err_message_utf8->str().size(), message_buff, message_size);
		if (final_size == 0)
			message = L"Invalid error message, can not convert from utf8 to utf16";
		else
		{
			message_buff[message_size] = 0;
			message = message_buff;
		}
		delete [] message_buff;
	};

	fullMessage = L"Error: ";
	fullMessage += message;
	fullMessage += L"\nModule: ";
	fullMessage += err_path;
	fullMessage += L"\n";

	utf8Message = 0;
	utf8FullMessage = 0;
};


ErrorMessage::ErrorMessage(errorCode err_code, std::wstringstream* err_message, wchar_t* err_path)
{
	level = 0;
	code = err_code;
	message = err_message->str();
	fullMessage = L"Error: ";
	fullMessage += err_message->str();
	fullMessage += L"\nModule: ";
	fullMessage += err_path;
	fullMessage += L"\n";
	
	utf8Message = 0;
	utf8FullMessage = 0;
};
//===============================================================================================================
ErrorMessage::~ErrorMessage()
{
	if (utf8Message != 0)
		delete[] utf8Message;
	if (utf8FullMessage != 0)
		delete[] utf8FullMessage;
};


//===============================================================================================================

void ErrorMessage::addMessage(wchar_t* err_message)
{
	level++;
	message += L"\n<- ";
	message += err_message;
	fullMessage.append(level, L'\t');
	fullMessage += L"Message: ";
	fullMessage += err_message;
	fullMessage += L"\n";
};

void ErrorMessage::addMessage(std::wstringstream* err_message)
{
	level++;
	message += L"\n<- ";
	message += err_message->str();
	fullMessage.append(level, L'\t');
	fullMessage += L"Message: ";
	fullMessage += err_message->str();
	fullMessage += L"\n";
};

void ErrorMessage::addMessage(wchar_t* err_message, wchar_t* err_path)
{
	level++;
	message += L"\n<- ";
	message += err_message;
	fullMessage.append(level, L'\t');
	fullMessage += L"Message: ";
	fullMessage += err_message;
	fullMessage += L"\n";
	fullMessage.append(level, L'\t');
	fullMessage += L"Module: ";
	fullMessage += err_path;
	fullMessage += L"\n";
};

void ErrorMessage::addMessage(std::wstringstream* err_message, wchar_t* err_path)
{
	level++;
	message += L"\n<- ";
	message += err_message->str();
	fullMessage.append(level, L'\t');
	fullMessage += L"Message: ";
	fullMessage += err_message->str();
	fullMessage += L"\n";
	fullMessage.append(level, L'\t');
	fullMessage += L"Module: ";
	fullMessage += err_path;
	fullMessage += L"\n";
};

void ErrorMessage::setMessage(wchar_t* err_message)
{
	message = err_message;

};

void ErrorMessage::setMessage(std::wstringstream* err_message)
{
	message = err_message->str();

};

void ErrorMessage::setPath(wchar_t* err_path)
{
	level = 0;
	fullMessage = L"Error: ";
	fullMessage += message;
	fullMessage += L"\nModule: ";
	fullMessage += err_path;
	fullMessage += L"\n";

};

void ErrorMessage::addPath(wchar_t* err_path)
{
	level++;
	fullMessage.append(level, L'\t');
	fullMessage += L"Module: ";
	fullMessage += err_path;
	fullMessage += L"\n";
};

const char* ErrorMessage::getMessageUTF8()
{
	if (utf8Message != 0)
	{
		delete[] utf8Message;
		utf8Message = 0;
	}

	int new_size = WideCharToMultiByte(CP_UTF8, 0, message.c_str(), message.size(), 0, 0, 0, 0);
	if (new_size == 0)
		return "Invalid error message, can not convert from utf16 to utf8";
	else
	{
		utf8Message = new char[new_size+1];
		int final_size = WideCharToMultiByte(CP_UTF8, 0, message.c_str(), message.size(), utf8Message, new_size, 0, 0);
		if (final_size == 0)
			return "Invalid error message, can not convert from utf16 to utf8";
	}
	utf8Message[new_size] = 0;
	return utf8Message;
};

const char* ErrorMessage::getFullMessageUTF8()
{
	if (utf8FullMessage != 0)
	{
		delete[] utf8FullMessage;
		utf8FullMessage = 0;
	}

	int new_size = WideCharToMultiByte(CP_UTF8, 0, fullMessage.c_str(), fullMessage.size(), 0, 0, 0, 0);
	if (new_size == 0)
		return "Invalid error message, can not convert from utf16 to utf8";
	else
	{
		utf8FullMessage = new char[new_size+1];
		int final_size = WideCharToMultiByte(CP_UTF8, 0, fullMessage.c_str(), fullMessage.size(), utf8FullMessage, new_size, 0, 0);
		if (final_size == 0)
			return "Invalid error message, can not convert from utf16 to utf8";
	}
	utf8FullMessage[new_size] = 0;
	return utf8FullMessage;
};



