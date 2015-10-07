#include "USDS Basic\usdsBasicTest.h"
#include <iostream>

using namespace usds;

UsdsBasicTest::UsdsBasicTest(int counts, int size)
{
	test_counts = counts;
	TestData = new TicketSales(size, true);
	CleanData = new TicketSales(size, false);

	parser = 0;

	try
	{
		parser = new BasicParser();
		const char* dict = "USDS DICTIONARY ID=888 v.1.0		\n\
						   	{									\n\
								1: STRUCT I						\n\
								{								\n\
									1: UNSIGNED VARINT n;		\n\
									2: DOUBLE s;				\n\
									3: STRING<UTF-8> g;			\n\
									4: LONG t;					\n\
									5: BOOLEAN b;				\n\
								} RESTRICT {root=false;}		\n\
								2: STRUCT S						\n\
								{								\n\
									1: UNSIGNED VARINT n;		\n\
									2: INT m;					\n\
									3: LONG s;					\n\
									4: LONG e;					\n\
									5: ARRAY<I> v;				\n\
								}								\n\
							}";
		parser->addDictionaryFromText(dict, strlen(dict), USDS_UTF8);

	}
	catch (ErrorMessage& msg)
	{
		parser = 0;
		int code = msg.getCode();
		const char* mess = msg.getFullMessageUTF8();
		std::cout << "USDS Basic parser was not created!\nError code: " << code << "\nMessage:\n" << mess << std::endl;
	};

};

UsdsBasicTest::~UsdsBasicTest()
{
	if(parser !=0)
		delete parser;
	delete TestData;
	delete CleanData;
};

int UsdsBasicTest::serializationTest()
{
	if (parser == 0)
		return -1;

	try
	{
		usds_data.clear();
		parser->encode(&usds_data, true, true, false);
		serialization_data_size = usds_data.getSize();
		parser->clear();
	}
	catch (ErrorMessage& msg)
	{
		int code = msg.getCode();
		const char* mess = msg.getFullMessageUTF8();
		std::cout << "Serialization was not finished!\nError code: " << code << "\nMessage:\n" << mess << std::endl;
		return -1;
	};

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
	try
	{
		parser->decode(usds_data.getBinary(), serialization_data_size);

		std::string text_dict;
		parser->CurrentDictionaryToText(USDS_UTF8, &text_dict);
		std::cout << text_dict;

	}
	catch (ErrorMessage& msg)
	{
		int code = msg.getCode();
		const char* mess = msg.getFullMessageUTF8();
		std::cout << "Deserialization was not finished!\nError code: " << code << "\nMessage:\n" << mess << std::endl;
		return -1;
	};

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
