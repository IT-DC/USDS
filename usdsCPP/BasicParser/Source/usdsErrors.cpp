#include "base\usdsErrors.h"

using namespace usds;

ErrorMessage::ErrorMessage(errorCode err_code, std::string* err_message, const char* err_path)
{
	level = 0;
	code = err_code;
	message = *err_message;
	full_message = "Error:\nModule: ";
	full_message += err_path;
	full_message += "\nMessage: ";
	full_message += *err_message;
	full_message += "\n";
	
};

void ErrorMessage::addMessage(std::string* err_message, const char* err_path)
{
	level++;
	full_message.append(level, '\t');
	full_message += "Module: ";
	full_message += err_path;
	full_message += "\n";
	full_message.append(level, '\t');
	full_message += "Module: ";
	full_message += *err_message;
	full_message += "\n";

};

void ErrorMessage::addMessage(const char* err_path)
{
	level++;
	full_message.append(level, '\t');
	full_message += "Module: ";
	full_message += err_path;
	full_message += "\n";
};