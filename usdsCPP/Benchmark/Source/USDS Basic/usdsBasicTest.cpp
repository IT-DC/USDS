#include "USDS Basic\usdsBasicTest.h"

using namespace usds;

UsdsBasicTest::UsdsBasicTest(int counts, int size)
{
	test_counts = counts;
	TestData = new TicketSales(size, true);
	CleanData = new TicketSales(size, false);

	try
	{
		parser = new BasicParser();
		const char* dict = "USDS Dictionary ID=888 v.1.0	\n\
															\n\
							1: struct I						\n\
							{								\n\
								1: varint n;				\n\
								2: double s;				\n\
								3: string(utf-8) g;			\n\
								4: long t;					\n\
								5: bool b;					\n\
							};								\n\
							2: root struct S				\n\
							{								\n\
								1: varint n;				\n\
								2: int m;					\n\
								3: long s;					\n\
								4: long e;					\n\
								5: array<I> v;				\n\
							};";
		parser->initDictionaryFromText(dict, strlen(dict), UTF8);
	}
	catch (ErrorMessage& msg)
	{
		int code = msg.getCode();
		const wchar_t* mess = msg.getFullMessage();
	};

	usds_data = 0;

};

UsdsBasicTest::~UsdsBasicTest()
{
	delete parser;
	delete TestData;
	delete CleanData;
};

int UsdsBasicTest::serializationTest()
{
	
	/*
	UsdsTicketSales* handle = parser->addUsdsTicketSales();
	handle->shiftNumber = TestData->getShiftNumber();
	handle->cashRegister = TestData->getCashRegister();
	handle->startShift = TestData->getStartShift();
	handle->endShift = TestData->getEndShift();
	int voucher_number = TestData->getNumVouchers();

	voucher * vouchers = 0;
	vouchers = TestData->getVouchers();
	if (vouchers == 0)
		return -1;

	for (int i = 0; i < voucher_number; i++)
	{
		UsdsVoucher* arrayHandle = handle->addToVouchers();
		arrayHandle->voucher_number = vouchers[i].voucher_number;
		arrayHandle->summ = vouchers[i].summ;
		arrayHandle->setGoods_name(USDS_UTF8, vouchers[i].goods_name);
		arrayHandle->time_of_sell = vouchers[i].time_of_sell;
		arrayHandle->status = vouchers[i].status;
	}

	//	if (parser->addHead() != 0)
	//		return -2;
	//	if (parser->addDictionary() != 0)
	//		return -3;

	if (parser->addBody() != 0)
		return -4;
	if (parser->getUSDS(&usds_data, &serialization_data_size) != 0)
		return -5;

	parser->clean();

	*/

	return 0;
};

int UsdsBasicTest::deserializationTest()
{

	/*

	int result = parser->parse(usds_data, serialization_data_size);
	if (result != 0)
		return -1;

	UsdsTicketSales* handle = parser->getFirstUsdsTicketSales();
	CleanData->setShiftNumber(handle->shiftNumber);
	CleanData->setCashRegister(handle->cashRegister);
	CleanData->setStartShift(handle->startShift);
	CleanData->setEndShift(handle->endShift);
	int voucher_number = handle->getVouchersSize();
	if (CleanData->getNumVouchers() != voucher_number)
		return -2;

	voucher * vouchers = 0;
	vouchers = CleanData->getVouchers();
	if (vouchers == 0)
		return -3;

	UsdsVoucher* arrayHandle = handle->getFirstInVouchers();
	for (int i = 0; i < voucher_number; i++)
	{
		vouchers[i].voucher_number = arrayHandle->voucher_number;
		vouchers[i].summ = arrayHandle->summ;
		strcpy(vouchers[i].goods_name, arrayHandle->getGoods_name());
		vouchers[i].time_of_sell = arrayHandle->time_of_sell;
		vouchers[i].status = arrayHandle->status;
		arrayHandle = (UsdsVoucher*)arrayHandle->getNextObject();
	};

	parser->clean();

	*/

	return 0;
};
