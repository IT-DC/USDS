#ifndef USDS_DOM_TEST
#define USDS_DOM_TEST

#include "baseTest.h"
#include "USDS DOM\usdsDomParser.h"

class UsdsDomTest : public BaseTest
{
public:
	UsdsDomTest(int counts, int size);
	~UsdsDomTest();

private:
	int serializationTest();
	int deserializationTest();

	UsdsDomParser* parser;

	unsigned char* usds_data;

};


#endif