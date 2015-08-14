#include "JSON\jsonTest.h"

JsonTest::JsonTest(int counts, int size)
{
	test_counts = counts;
	TestData = new TicketSales(size, true);
	CleanData = new TicketSales(size, false);
	json_data = 0;
	json_buff = new StringBuffer();
	serializer = new Writer<StringBuffer>(*json_buff);
	deserializer = new Reader();
	json_ticket_sales = new Handler(CleanData);

};

JsonTest::~JsonTest()
{
	if (json_data != 0)
		delete[] json_data;
	if (serializer != 0)
		delete serializer;
	if (json_buff != 0)
		delete json_buff;

	delete TestData;
	delete CleanData;

};

int JsonTest::serializationTest()
{
	
	char dt_buf[30];
	time_t dt_tmp;

	serializer->StartObject();
	serializer->Key("T");
	{
		serializer->StartObject();
		serializer->Key("n");
		serializer->Int(TestData->getShiftNumber());
		serializer->Key("r");
		serializer->Int(TestData->getCashRegister());

		serializer->Key("s");
		dt_tmp = TestData->getStartShift();
		strftime(dt_buf, 30, "%Y.%m.%d %H:%M:%S", localtime(&dt_tmp));
		serializer->String(dt_buf);

		serializer->Key("e");
		dt_tmp = TestData->getEndShift();
		strftime(dt_buf, 30, "%Y.%m.%d %H:%M:%S", localtime(&dt_tmp));
		serializer->String(dt_buf);
			
		serializer->Key("V");
		{
			voucher * vouchers = 0;
			vouchers = TestData->getVouchers();
			if (vouchers == 0)
				return -1;
			int num_vouchers = TestData->getNumVouchers();

			serializer->StartArray();
			for (int i = 0; i < num_vouchers; i++)
			{
				serializer->StartObject();
				
				serializer->Key("u");
				serializer->Int(vouchers[i].voucher_number);

				serializer->Key("m");
				serializer->Double(vouchers[i].summ);

				serializer->Key("g");
				serializer->String(vouchers[i].goods_name);

				serializer->Key("t");
				dt_tmp = vouchers[i].time_of_sell;
				strftime(dt_buf, 30, "%Y.%m.%d %H:%M:%S", localtime(&dt_tmp));
				serializer->String(dt_buf);
				
				serializer->Key("b");
				serializer->Bool(vouchers[i].status);

				serializer->EndObject();
			}
			serializer->EndArray();
		}

		serializer->EndObject();
	}
	
	serializer->EndObject();

	serialization_data_size = json_buff->GetSize();

	if (json_data == 0)
		json_data = new char[serialization_data_size + 1];

	strcpy_s(json_data, serialization_data_size + 1, json_buff->GetString());

	// cout << json_buff->GetString();

	json_buff->Clear();

	return 0;
};


int JsonTest::deserializationTest()
{
	
	StringStream ss(json_data);
	deserializer->Parse(ss, *json_ticket_sales);
	int i = deserializer->GetParseErrorCode();
	if (deserializer->GetErrorOffset() != 0)
		return -1;

	return 0;
};

bool Handler::Bool(bool b)
{
	if (last_key == 'b')
		output_class->getVouchers()[arr_pos].status = b;
	else
		return false;

	return true;
};

bool Handler::Int(int i)
{
	
	if (last_key == 'n')
		output_class->setShiftNumber(i);
	else if (last_key == 'r')
		output_class->setCashRegister(i);
	else if (last_key == 'u')
		output_class->getVouchers()[arr_pos].voucher_number = i;
	else
		return false;
		
	return true;
};

bool Handler::Uint(unsigned i)
{
	return Int(i);
};

bool Handler::Double(double d)
{
	if (last_key == 'm')
		output_class->getVouchers()[arr_pos].summ = d;
	else 
		return false;

	return true;
};

bool Handler::String(const char* str, SizeType length, bool copy)
{
	if (last_key == 's' || last_key == 'e' || last_key == 't')
	{
		struct tm tm = { 0 };
		if (sscanf_s(str, "%d.%d.%d %d:%d:%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec) == EOF)
			return false;
		tm.tm_year = tm.tm_year - 1900;
		tm.tm_mon = tm.tm_mon - 1;
		time_t time_buff;
		time_buff = mktime(&tm);
		if (time_buff == -1)
			return false;

		if (last_key == 's')
			output_class->setStartShift(time_buff);
		else if (last_key == 'e')
			output_class->setEndShift(time_buff);
		else
		{
			if (arr_pos < 0)
				return false;
			output_class->getVouchers()[arr_pos].time_of_sell = time_buff;
		}
	}
	else if (last_key == 'g')
		strcpy(output_class->getVouchers()[arr_pos].goods_name, str);
	else
		return false;

	return true;
};

bool Handler::StartObject()
{
	return true;
};

bool Handler::Key(const char* str, SizeType length, bool copy)
{
	if (length < 1)
		return false;
	last_key = str[0];

	return true;
};

bool Handler::EndObject(SizeType memberCount)
{

	if (arr_pos >= 0)
		arr_pos++;

	return true;
};

bool Handler::StartArray()
{
	if (last_key != 'V')
		return false;
	arr_pos = 0;

	return true;
};

bool Handler::EndArray(SizeType elementCount)
{

	arr_pos = -1;

	return true;
};