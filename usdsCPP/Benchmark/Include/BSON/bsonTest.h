#ifndef BSON_TEST
#define BSON_TEST

#include "baseTest.h"

#include <winsock2.h>
#include "mongo\bson\bson.h"

#include <iostream>

using namespace std;

class BsonTest : public BaseTest
{
public:
	BsonTest(int counts, int size);
	~BsonTest();

private:
	int serializationTest();
	int deserializationTest();

	char* bson_data;

};


#endif