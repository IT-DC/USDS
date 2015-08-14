#ifndef ASN_TEST
#define ASN_TEST

#include "baseTest.h"

//#define USE_MD_LIB
#include "asn_bench.h"

#include <iostream>

class AsnTest : public BaseTest
{
public:
	AsnTest(int counts, int size);
	~AsnTest();

private:
	int serializationTest();
	int deserializationTest();

	char* asn_data;

	EncodedBuffer* asn_buff;
	AsnTicketSales_PDU* serializer;
	asn_bench_Control* ctl;

};




#endif