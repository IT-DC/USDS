#include "base\usdsErrors.h"

using namespace usds;

ErrorMessage::ErrorMessage(errorCode err_code, wchar_t* err_message)
{
	level = 0;
	code = err_code;
	message = err_message;
	fullMessage = L"Error: ";
	fullMessage += err_message;
	fullMessage += L"\n";

};

ErrorMessage::ErrorMessage(errorCode err_code, std::wstringstream* err_message)
{
	level = 0;
	code = err_code;
	message = err_message->str();
	fullMessage = L"Error: ";
	fullMessage += err_message->str();
	fullMessage += L"\n";

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