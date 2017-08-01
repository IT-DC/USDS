#include "baseTest.h"

BaseTest::BaseTest()
{
	serialization_time = 0;
	deserialization_time = 0;
	checkData = false;

};

BaseTest::~BaseTest() { };

int BaseTest::beginTest()
{
	int start_test = clock();
	for (int i = 0; i < test_counts; i++)
		if (serializationTest()!=0)
			return -1;
	int end_test = clock();
	serialization_time = end_test - start_test;

	start_test = clock();
	for (int i = 0; i < test_counts; i++)
	{
		int ret_code = deserializationTest();
		if (ret_code != 0)
			return -2;
	}
	end_test = clock();
	deserialization_time = end_test - start_test;

	if (!checkDataTest())
		return -3;

	return 0;
};

bool BaseTest::checkDataTest()
{
	if (TestData->getShiftNumber() != CleanData->getShiftNumber())
		return false;

	if (TestData->getCashRegister() != CleanData->getCashRegister())
		return false;

	if (TestData->getStartShift() != CleanData->getStartShift())
		return false;

	if (TestData->getEndShift() != CleanData->getEndShift())
		return false;

	if (TestData->getNumVouchers() != CleanData->getNumVouchers())
		return false;

	for (int i = 0; i < TestData->getNumVouchers(); i++)
	{
		if (TestData->getVouchers()[i].voucher_number != CleanData->getVouchers()[i].voucher_number)
			return false;

		if (TestData->getVouchers()[i].summ != CleanData->getVouchers()[i].summ)
			return false;

		if(std::strcmp(TestData->getVouchers()[i].goods_name, CleanData->getVouchers()[i].goods_name)!=0)
			return false;

		if (TestData->getVouchers()[i].time_of_sell != CleanData->getVouchers()[i].time_of_sell)
			return false;

		if (TestData->getVouchers()[i].status != CleanData->getVouchers()[i].status)
			return false;
	}


	return true;
};