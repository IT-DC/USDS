#include "Protobuf\protobufTest.h"

ProtobufTest::ProtobufTest(int counts, int size)
{
	test_counts = counts;
	serializer = new ProtobufTicketSales();
	TestData = new TicketSales(size, true);
	CleanData = new TicketSales(size, false);
	serialized_data = 0;


};

ProtobufTest::~ProtobufTest()
{
	if (serializer != 0)
		delete serializer;
	if (serialized_data != 0)
		delete[] serialized_data;
	delete TestData;
	delete CleanData;

};

int ProtobufTest::serializationTest()
{
	serializer->set_shiftnumber(TestData->getShiftNumber());
	serializer->set_cashregister(TestData->getCashRegister());
	serializer->set_start_shift(TestData->getStartShift());
	serializer->set_end_shift(TestData->getEndShift());
	int num_vouchers = TestData->getNumVouchers();
	voucher * vouchers = 0;
	vouchers = TestData->getVouchers();
	if (vouchers == 0)
		return -1;
	for (int i = 0; i < num_vouchers; i++)
	{
		ProtobufTicketSales_ProtobufVoucher* proto_voucher = 0;
		proto_voucher = serializer->add_vouchers();
		if (proto_voucher == 0)
			return -2;
		proto_voucher->set_voucher_number(vouchers[i].voucher_number);
		proto_voucher->set_summ(vouchers[i].summ);
		proto_voucher->set_goods_name(vouchers[i].goods_name);
		proto_voucher->set_time_of_sell(vouchers[i].time_of_sell);
		proto_voucher->set_status(vouchers[i].status);
	}

	serialization_data_size = serializer->ByteSize();

	if (serialized_data == 0)
		serialized_data = new unsigned char[serialization_data_size];

	if(!serializer->SerializeToArray(serialized_data, serialization_data_size))
		return -3;

	serializer->Clear();

	return 0;
};


int ProtobufTest::deserializationTest()
{
	if(!serializer->ParseFromArray(serialized_data, serialization_data_size))
		return -1;
	CleanData->setShiftNumber(serializer->shiftnumber());
	CleanData->setCashRegister(serializer->cashregister());
	CleanData->setStartShift(serializer->start_shift());
	CleanData->setEndShift(serializer->end_shift());

	voucher * vouchers = 0;
	vouchers = CleanData->getVouchers();
	if (vouchers == 0)
		return -2;
	int size_array = serializer->vouchers_size();
	if (size_array != CleanData->getNumVouchers())
		return -3;

	for (int i = 0; i < size_array; i++)
	{
		ProtobufTicketSales_ProtobufVoucher proto_voucher = serializer->vouchers(i);
		vouchers[i].voucher_number = proto_voucher.voucher_number();
		vouchers[i].summ = proto_voucher.summ();
		strcpy(vouchers[i].goods_name, proto_voucher.goods_name().c_str());
		vouchers[i].time_of_sell = proto_voucher.time_of_sell();
		vouchers[i].status = proto_voucher.status();
	}

	serializer->Clear();

	return 0;
};