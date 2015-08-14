#include "XML\xmlTest.h"

XmlTest::XmlTest(int counts, int size)
{
	test_counts = counts;
	TestData = new TicketSales(size, true);
	CleanData = new TicketSales(size, false);
	xml_data = 0;
	serializer = new tinyxml2::XMLDocument();


};

XmlTest::~XmlTest()
{
	if (xml_data != 0)
		delete[] xml_data;
	if (serializer != 0)
		delete serializer;
	delete TestData;
	delete CleanData;

};

int XmlTest::serializationTest()
{
	tinyxml2::XMLNode* pRoot = serializer->NewElement("T");
	serializer->InsertFirstChild(pRoot);
	
	tinyxml2::XMLElement* xml_shift = serializer->NewElement("S");
	xml_shift->SetAttribute("n", TestData->getShiftNumber());
	xml_shift->SetAttribute("r", TestData->getCashRegister());
	
	char dt_buf[30];
	time_t dt_tmp = TestData->getStartShift();
	strftime(dt_buf, 30, "%Y.%m.%d %H:%M:%S", localtime(&dt_tmp));
	xml_shift->SetAttribute("s", dt_buf);

	dt_tmp = TestData->getEndShift();
	strftime(dt_buf, 30, "%Y.%m.%d %H:%M:%S", localtime(&dt_tmp));
	xml_shift->SetAttribute("e", dt_buf);

	pRoot->InsertEndChild(xml_shift);

	int num_vouchers = TestData->getNumVouchers();
	voucher * vouchers = 0;
	vouchers = TestData->getVouchers();
	if (vouchers == 0)
		return -1;

	tinyxml2::XMLElement* xml_vouchers = serializer->NewElement("V");
	pRoot->InsertEndChild(xml_vouchers);

	for (int i = 0; i < num_vouchers; i++)
	{
		tinyxml2::XMLElement* xml_voucher = serializer->NewElement("I");
		xml_voucher->SetAttribute("n", vouchers[i].voucher_number);
		xml_voucher->SetAttribute("s", vouchers[i].summ);
		xml_voucher->SetAttribute("g", vouchers[i].goods_name);
		
		dt_tmp = vouchers[i].time_of_sell;
		strftime(dt_buf, 30, "%Y.%m.%d %H:%M:%S", localtime(&dt_tmp));
		xml_voucher->SetAttribute("t", dt_buf);

		xml_voucher->SetAttribute("b", vouchers[i].status);

		xml_vouchers->InsertEndChild(xml_voucher);
	}

	serializer->Accept(&printer);
	serialization_data_size = printer.CStrSize();

	if (xml_data == 0)
		xml_data = new char[serialization_data_size + 1];

	strcpy_s(xml_data, serialization_data_size+1, printer.CStr());

	//serializer->Print();

	serializer->Clear();
	printer.ClearBuffer();

	return 0;
};


int XmlTest::deserializationTest()
{
	if (serializer->Parse(xml_data, serialization_data_size + 1)!=0)
		return -1;

	tinyxml2::XMLNode* pRoot = serializer->FirstChild();
	if (pRoot == 0)
		return -2;

	tinyxml2::XMLElement* xml_shift = pRoot->FirstChildElement("S");
	if (xml_shift == 0)
		return -3;

	int int_buff = 0;
	if(xml_shift->QueryIntAttribute("n", &int_buff)!=0)
		return -4;
	CleanData->setShiftNumber(int_buff);
	
	if(xml_shift->QueryIntAttribute("r", &int_buff)!=0)
		return -5;
	CleanData->setCashRegister(int_buff);

	const char* char_buff;
	char_buff = xml_shift->Attribute("s");
	if (char_buff == 0)
		return -6;
	struct tm tm = { 0 };
	if (sscanf_s(char_buff, "%d.%d.%d %d:%d:%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec) == EOF)
		return -7;
	tm.tm_year = tm.tm_year - 1900;
	tm.tm_mon = tm.tm_mon - 1;
	time_t time_buff;
	time_buff = mktime(&tm);
	if (time_buff == -1)
		return -21;
	CleanData->setStartShift(time_buff);
	
	char_buff = xml_shift->Attribute("e");
	if (char_buff == 0)
		return -8;
	if (sscanf_s(char_buff, "%d.%d.%d %d:%d:%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec) == EOF)
		return -9;
	tm.tm_year = tm.tm_year - 1900;
	tm.tm_mon = tm.tm_mon - 1;
	time_buff = mktime(&tm);
	if (time_buff == -1)
		return -22;
	CleanData->setEndShift(time_buff);

	tinyxml2::XMLElement* xml_vouchers = pRoot->FirstChildElement("V");
	if (xml_vouchers == 0)
		return -10;

	voucher * vouchers = CleanData->getVouchers();
	if (vouchers == 0)
		return -11;

	int size_array = CleanData->getNumVouchers();

	tinyxml2::XMLElement* xml_voucher = xml_vouchers->FirstChildElement("I");
	if (xml_voucher == 0)
		return -14;
	
	int step = 0;
	while (xml_voucher != 0)
	{
		if (step > size_array)
			return -21;

		if (xml_voucher->QueryIntAttribute("n", &(vouchers[step].voucher_number)) != 0)
			return -15;
		
		if (xml_voucher->QueryDoubleAttribute("s", &(vouchers[step].summ)) != 0)
			return -16;
		 
		char_buff = xml_voucher->Attribute("g");
		if (char_buff == 0)
			return -17;
		strcpy(vouchers[step].goods_name, char_buff);

		char_buff = xml_voucher->Attribute("t");
		if (char_buff == 0)
			return -18;
		if (sscanf_s(char_buff, "%d.%d.%d %d:%d:%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec) == EOF)
			return -19;
		tm.tm_year = tm.tm_year - 1900;
		tm.tm_mon = tm.tm_mon - 1;
		vouchers[step].time_of_sell = mktime(&tm);
		if (vouchers[step].time_of_sell == -1)
			return -22;
		
		if (xml_voucher->QueryBoolAttribute("b", &(vouchers[step].status)) != 0)
			return -20;

		xml_voucher = xml_voucher->NextSiblingElement("I");

		step++;
	}

	serializer->Clear();
	
	return 0;
};