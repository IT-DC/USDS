#include "ASN\asnTest.h"

AsnTest::AsnTest(int counts, int size)
{
	test_counts = counts;
	TestData = new TicketSales(size, true);
	CleanData = new TicketSales(size, false);
	asn_data = 0;

	/* Handle ASN.1/C++ runtime errors with C++ exceptions */
	//asn1_set_error_handling(throw_error, TRUE);
	asn1_set_error_handling(asn1_legacy_error_handler);

	ctl = 0;

	ctl = new asn_bench_Control();
	const char * mess = ctl->getErrorMsg();

	ctl->setEncodingFlags(ctl->getEncodingFlags() | AUTOMATIC_ENCDEC);
	ctl->setDecodingFlags(ctl->getDecodingFlags() | AUTOMATIC_ENCDEC);
	ctl->setEncodingRules(OSS_XER); /* OSS_BER or OSS_PER_ALIGNED or OSS_DER or OSS_XER  or OSS_OER */
	ctl->setDebugFlags(ctl->getDebugFlags() | PRINT_ENCODER_OUTPUT);

	serializer = new AsnTicketSales_PDU();
	asn_buff = new EncodedBuffer();
	


};

AsnTest::~AsnTest()
{
	if (asn_data != 0)
		delete[] asn_data;
	delete TestData;
	delete CleanData;
	delete asn_buff;
	delete serializer;
	delete ctl;

};

int AsnTest::serializationTest()
{
	AsnTicketSales buf;
	buf.set_shiftNumber(TestData->getShiftNumber());
	buf.set_cashRegister(TestData->getCashRegister());
	
	time_t dt_tmp = TestData->getStartShift();
	struct tm* time_buf = localtime(&dt_tmp);
	buf.set_startShift(OssUTCTime(time_buf->tm_year, time_buf->tm_mon + 1, time_buf->tm_mday, time_buf->tm_hour, time_buf->tm_min, time_buf->tm_sec, 0, 0));
	
	dt_tmp = TestData->getEndShift();
	time_buf = localtime(&dt_tmp);
	buf.set_endShift(OssUTCTime(time_buf->tm_year, time_buf->tm_mon + 1, time_buf->tm_mday, time_buf->tm_hour, time_buf->tm_min, time_buf->tm_sec, 0, 0));

	int num_vouchers = TestData->getNumVouchers();
	voucher * vouchers = 0;
	vouchers = TestData->getVouchers();
	if (vouchers == 0)
		return -1;

	AsnTicketSales::vouchers buf_vouchers;
	time_buf = localtime(&vouchers[0].time_of_sell);

	OssIndex iterator = buf_vouchers.prepend(AsnVoucher(
		vouchers[0].voucher_number,
		vouchers[0].summ,
		OssString(vouchers[0].goods_name),
		OssUTCTime(time_buf->tm_year, time_buf->tm_mon + 1, time_buf->tm_mday, time_buf->tm_hour, time_buf->tm_min, time_buf->tm_sec, 0, 0),
		vouchers[0].status)
		);

	for (int i = 1; i < num_vouchers; i++)
	{
		time_buf = localtime(&vouchers[i].time_of_sell);
		iterator = buf_vouchers.insert_after(iterator, AsnVoucher(
			vouchers[i].voucher_number,
			vouchers[i].summ,
			OssString(vouchers[i].goods_name),
			OssUTCTime(time_buf->tm_year, time_buf->tm_mon + 1, time_buf->tm_mday, time_buf->tm_hour, time_buf->tm_min, time_buf->tm_sec, 0, 0),
			vouchers[i].status)
			);
	}
	buf.set_vouchers(buf_vouchers);

	serializer->set_data(buf);
	const char * mess = ctl->getErrorMsg();
	if (mess[0] != 0)
		return -2;
	serializer->encode(*ctl, *asn_buff);
	mess = ctl->getErrorMsg();
	if (mess[0] != 0)
		return -3;
	serialization_data_size = asn_buff->get_data_size();
	if (serialization_data_size == 0)
		return -4;
	if (asn_data == 0)
		asn_data = new char[serialization_data_size];
	memcpy(asn_data, asn_buff->get_data(), serialization_data_size);
	
	serializer->release_data();
	asn_buff->reset();

	return 0;
};


int AsnTest::deserializationTest()
{
	asn_buff->set_buffer(serialization_data_size, asn_data);
	serializer->decode(*ctl, *asn_buff);
	const char * mess = ctl->getErrorMsg();
	if (mess[0] != 0)
		return -1;

	AsnTicketSales* buffer = serializer->get_data();

	CleanData->setShiftNumber(buffer->get_shiftNumber());
	CleanData->setCashRegister(buffer->get_cashRegister());

	struct tm tm = { 0 };
	OssUTCTime buff_time = buffer->get_startShift();
	tm.tm_year = buff_time.get_year();
	tm.tm_mon = buff_time.get_month() - 1;
	tm.tm_mday = buff_time.get_day();
	tm.tm_hour = buff_time.get_hour();
	tm.tm_min = buff_time.get_minute();
	tm.tm_sec = buff_time.get_second();
	time_t time_buf = mktime(&tm);
	CleanData->setStartShift(time_buf);
	
	buff_time = buffer->get_endShift();
	tm.tm_year = buff_time.get_year();
	tm.tm_mon = buff_time.get_month() - 1;
	tm.tm_mday = buff_time.get_day();
	tm.tm_hour = buff_time.get_hour();
	tm.tm_min = buff_time.get_minute();
	tm.tm_sec = buff_time.get_second();
	time_buf = mktime(&tm);
	CleanData->setEndShift(time_buf);

	int size_array = CleanData->getNumVouchers();
	voucher * vouchers = CleanData->getVouchers();
	if (vouchers == 0)
		return -2;

	AsnTicketSales::vouchers & vouchers_buf = buffer->get_vouchers();
	if (vouchers_buf.empty())
		return -3;

	OssIndex index;
	int step = 0;

	for (index = vouchers_buf.first(); index != OSS_NOINDEX; index = vouchers_buf.next(index))
	{
		if (step > size_array)
			return -4;
		AsnVoucher *voucher_buf = vouchers_buf.at(index);
		
		vouchers[step].voucher_number = voucher_buf->get_voucherNumber();
		vouchers[step].summ = voucher_buf->get_summ();
		
		const OssString & str_buff = voucher_buf->get_goodsName();
		strncpy(vouchers[step].goods_name, str_buff.get_buffer(), str_buff.length());
		vouchers[step].goods_name[str_buff.length()] = 0;

		buff_time = voucher_buf->get_timeOfSell();
		tm.tm_year = buff_time.get_year();
		tm.tm_mon = buff_time.get_month() - 1;
		tm.tm_mday = buff_time.get_day();
		tm.tm_hour = buff_time.get_hour();
		tm.tm_min = buff_time.get_minute();
		tm.tm_sec = buff_time.get_second();
		vouchers[step].time_of_sell = mktime(&tm);

		vouchers[step].status = (voucher_buf->get_status() ? true : false);

		step++;
	}

	serializer->release_data();

	return 0;
};