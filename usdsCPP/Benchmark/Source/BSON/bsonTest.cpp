#include "bsonTest.h"

BsonTest::BsonTest(int counts, int size)
{
	test_counts = counts;
	TestData = new TicketSales(size, true);
	CleanData = new TicketSales(size, false);
	bson_data = 0;
	
};

BsonTest::~BsonTest()
{
	if (bson_data != 0)
		delete[] bson_data;
	delete TestData;
	delete CleanData;

};

int BsonTest::serializationTest()
{
	//int start_test = clock();
	
	mongo::BSONObjBuilder root;
	mongo::BSONObjBuilder T;
	
	T.append("n", TestData->getShiftNumber());
	T.append("r", TestData->getCashRegister());
	T.append("s", TestData->getStartShift());
	T.append("e", TestData->getEndShift());

	int num_vouchers = TestData->getNumVouchers();
	voucher * vouchers = 0;
	vouchers = TestData->getVouchers();
	if (vouchers == 0)
		return -1;

	mongo::BSONArrayBuilder V;
	for (int i = 0; i < num_vouchers; i++)
	{
		mongo::BSONObjBuilder I;
		I.append("u", vouchers[i].voucher_number);
		I.append("s", vouchers[i].summ);
		I.append("g", vouchers[i].goods_name);
		I.append("t", vouchers[i].time_of_sell);
		I.append("b", vouchers[i].status);
		V.append(I.obj());

	}

	T.append("V", V.arr());

	root.append("T", T.obj());
	

	mongo::BSONObj p = root.obj();
	//cout << p.jsonString() << endl;

	serialization_data_size = p.objsize();
	if (bson_data == 0)
		bson_data = new char[serialization_data_size];
	memcpy(bson_data, p.objdata(), serialization_data_size);
	
	//int end_test = clock();
	//std::cout << "time: " << end_test - start_test << "\n";

	return 0;
};


int BsonTest::deserializationTest()
{
	mongo::BSONObj root(bson_data);
	mongo::BSONObj T = root.getField("T").Obj();
	int int_buff = 0;
	T.getField("n").Val(int_buff);
	CleanData->setShiftNumber(int_buff);
	T.getField("r").Val(int_buff);
	CleanData->setCashRegister(int_buff);
	
	time_t time_buff;
	T.getField("s").Val(time_buff);
	CleanData->setStartShift(time_buff);
	T.getField("e").Val(time_buff);
	CleanData->setEndShift(time_buff);

	vector<mongo::BSONElement> V = T.getField("V").Array();
	int size_array = V.size();
	if (size_array != CleanData->getNumVouchers())
		return -1;
	
	voucher * vouchers = CleanData->getVouchers();
	if (vouchers == 0)
		return -2;

	int step = 0;
	for (vector<mongo::BSONElement>::iterator it = V.begin(); it != V.end(); ++it)
	{
		it->Obj().getField("u").Val(vouchers[step].voucher_number);
		it->Obj().getField("s").Val(vouchers[step].summ);
		
		string str_buff;
		it->Obj().getField("g").Val(str_buff);
		strcpy(vouchers[step].goods_name, str_buff.c_str());

		it->Obj().getField("t").Val(vouchers[step].time_of_sell);
		it->Obj().getField("b").Val(vouchers[step].status);

		step++;
	}

	return 0;
};
