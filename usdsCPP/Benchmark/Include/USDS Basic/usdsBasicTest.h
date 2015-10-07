#ifndef USDS_BASIC_TEST
#define USDS_BASIC_TEST

#include "baseTest.h"
#include "usdsBasicParser.h"

class UsdsBasicTest : public BaseTest
{
public:
	UsdsBasicTest(int counts, int size);
	~UsdsBasicTest();

private:
	int serializationTest();
	int deserializationTest();

	usds::BasicParser* parser;

	usds::BinaryOutput usds_data;

};




#endif