#include "USDS\usdsTest.h"

UsdsTest::UsdsTest(int counts, int size)
{
	test_counts = counts;
	Serializer = new UsdsSerializer(100000);
	Deserializer = new UsdsDeserializer();
	TestData = new TicketSales(size, true);
	CleanData = new TicketSales(size, false);

	usds_data = 0;

};

UsdsTest::~UsdsTest()
{
	delete Serializer;
	delete Deserializer;
	delete TestData;
	delete CleanData;
};

int UsdsTest::serializationTest()
{
	if (Serializer->addHead() != 0)
		return -1;
	if(Serializer->addDictionary()!=0)
		return -2;
	if (Serializer->addToBody(TestData) != 0)
		return -3;
	if (Serializer->getUSDS(&usds_data, &serialization_data_size) != 0)
		return -4;
	if (Serializer->clean()!=0)
		return -5;
	
	return 0;
};

int UsdsTest::deserializationTest()
{
	//Deserializer->setUsdsVersion(1, 0);
	//Deserializer->setDictionaryVersion(1, 0);
	
	int err_code = Deserializer->setBinary(usds_data, serialization_data_size);
	if (err_code != 0)
		return -1;
	err_code = Deserializer->findFirstAndInit(CleanData);
	if (err_code != 0)
		return -2;
	
	Deserializer->clean();
	
	return 0;
};

