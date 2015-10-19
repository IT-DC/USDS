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
		/*
		//int id_I = parser->getTagID("I");
		int id_n = 1; // parser->getFieldID(id_I, "n");
		int id_s = 2; // parser->getFieldID(id_I, "s");
		int id_g = 3; // parser->getFieldID(id_I, "g");
		int id_t = 4; // parser->getFieldID(id_I, "t");
		int id_b = 5; // parser->getFieldID(id_I, "b");

		StructTag* tag = parser->addStructTag("S");
		tag->setFieldValue("n", TestData->getShiftNumber());
		tag->setFieldValue("m", TestData->getCashRegister());
		tag->setFieldValue("s", TestData->getStartShift());
		tag->setFieldValue("e", TestData->getEndShift());
		ArrayField* field = tag->getArrayField("v");

		int voucher_number = TestData->getNumVouchers();
		voucher* vouchers = 0;
		vouchers = TestData->getVouchers();
		if (vouchers == 0)
			return -1;

		for (int i = 0; i < voucher_number; i++)
		{
			StructTag* tag_I = (StructTag*)(field->addTagElement());
			tag_I->setFieldValue(id_n, vouchers[i].voucher_number);
			tag_I->setFieldValue(id_s, vouchers[i].summ);
			tag_I->setFieldValue(id_g, vouchers[i].goods_name);
			tag_I->setFieldValue(id_t, vouchers[i].time_of_sell);
			tag_I->setFieldValue(id_b, vouchers[i].status);
		}
		*/
		usds_data.clear();
		parser->encode(&usds_data, true, true, false);
		serialization_data_size = usds_data.getSize();
		parser->clearBody();
	}
	catch (ErrorMessage& msg)
	{
		int code = msg.getCode();
		const char* mess = msg.getFullMessageUTF8();
		std::cout << "Serialization was not finished!\nError code: " << code << "\nMessage:\n" << mess << std::endl;
		return -1;
	};

	return 0;
};

int UsdsBasicTest::deserializationTest()
{
	try
	{
		parser->clear();
		parser->decode(usds_data.getBinary(), serialization_data_size);

		std::string dict;
		parser->CurrentDictionaryToText(USDS_UTF8, &dict);
		std::cout << "\n" << dict << "\n";


		parser->clearBody();
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
