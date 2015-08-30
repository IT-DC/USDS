#include "usdsBasicParser.h"

using namespace usds;

BasicParser::BasicParser()
{
	// default versions
	usds_major = 1;
	usds_minor = 0;
	dictionary_major = 1;
	dictionary_minor = 0;
	full_dictionary_version = dictionary_major * 256 + dictionary_minor;

	// current status
	out_head_added = false;
	out_dictionary_added = false;
	out_body_added = false;
	in_head_included = false;
	in_dictionary_included = false;




}

BasicParser::~BasicParser()
{
	

}

//====================================================================================================================
// Settings
void BasicParser::setDictionaryVersion(unsigned char major, unsigned char minor)
{
	dictionary_major = major;
	dictionary_minor = minor;
	full_dictionary_version = dictionary_major * 256 + dictionary_minor;
	
};

void BasicParser::getUsdsVersion(int* major, int* minor)
{


};
void BasicParser::getDictionaryVersion(int* major, int* minor)
{



};

//====================================================================================================================
// Dictionary constructors

void BasicParser::initDictionaryFromText(const char* text_dictionary, int size, usdsEncodes encode) throw(...)
try 
{
	if (encode != UTF8)
		throw ErrorMessage(BASIC_PARSER_UNSUPPORTABLE_ENCODE, L"Unsupportable encode for dictionary");
	dict.initFromText(text_dictionary, size);
}
catch (ErrorMessage& msg)
{
	msg.addPath(L"BasicParser::initDictionaryFromText");
	throw msg;
};