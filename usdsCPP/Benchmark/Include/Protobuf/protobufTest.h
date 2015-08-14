#ifndef PROTOBUF_TEST
#define PROTOBUF_TEST

#include "baseTest.h"
#include "Protobuf\protobufTicketSales.h"

class ProtobufTest : public BaseTest
{
public:
	ProtobufTest(int counts, int size);
	~ProtobufTest();

private:
	int serializationTest();
	int deserializationTest();

	ProtobufTicketSales* serializer;

	void* serialized_data;

};


#endif