// main functions for tests
#ifndef BASE_TEST
#define BASE_TEST

#include <time.h>
#include <cstring>
#include "ticketSales.h"

class BaseTest
{
public:
	BaseTest();
	virtual ~BaseTest();

	int beginTest();

	clock_t getSerializationTime() { return serialization_time; };
	clock_t getDeserializationTime() { return deserialization_time; };
	int getSerializationDataSize() { return serialization_data_size; };
	bool getCheckData() { return checkData; };

protected:
	virtual int serializationTest() = 0;
	virtual int deserializationTest() = 0;

	TicketSales* TestData;
	TicketSales* CleanData;
	int serialization_data_size;
	bool checkData;
	int test_counts;

private:
	clock_t serialization_time;
	clock_t deserialization_time;

	bool checkDataTest();
};



#endif
