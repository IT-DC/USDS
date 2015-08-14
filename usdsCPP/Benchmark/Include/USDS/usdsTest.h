#ifndef USDS_TEST
#define USDS_TEST

#include "baseTest.h"
#include "USDS\usdsSerializer.h"
#include "USDS\usdsDeserializer.h"

class UsdsTest: public BaseTest
{
public:
	UsdsTest(int counts, int size);
	~UsdsTest();
	
private:
	int serializationTest();
	int deserializationTest();
		
	UsdsSerializer* Serializer;
	UsdsDeserializer* Deserializer;

	unsigned char* usds_data;

};


#endif