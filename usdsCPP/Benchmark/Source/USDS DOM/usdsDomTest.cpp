#include "USDS DOM\usdsDomTest.h"

UsdsDomTest::UsdsDomTest(int counts, int size)
{
	test_counts = counts;
	parser = new UsdsDomParser();
	TestData = new TicketSales(size, true);
	CleanData = new TicketSales(size, false);

	usds_data = 0;

};

UsdsDomTest::~UsdsDomTest()
{
	delete parser;
	delete TestData;
	delete CleanData;
};

int UsdsDomTest::serializationTest()
{
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
		arrayHandle->setGoods_name(USDS_DOM_UTF8, vouchers[i].goods_name);
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

	return 0;
};

int UsdsDomTest::deserializationTest()
{
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

	return 0;
};

