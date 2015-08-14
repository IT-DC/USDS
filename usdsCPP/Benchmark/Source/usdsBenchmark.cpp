#include "usdsBenchmark.h"

using namespace std;

int main(int argc, char* argv[])
{
	int test_counts = 1000000;
	int test_size = 2;
	
	BaseTest* Tests;
	int err_code = 0;

	cout << "USDS-benchmark for C++" << endl;
	Tests = new UsdsTest(test_counts, test_size);
	err_code = Tests->beginTest();

	if (err_code != 0)
	{
		cout << "1a) USDS SAX Test error! Error code: " << err_code << endl;
		cout << "Press Enter";
		cin.ignore();
		return -1;
	};
	cout << "1a) USDS SAX" << endl << 
		"Serialization: " << Tests->getSerializationTime() << " ms." << endl <<
		"Deserialization: " << Tests->getDeserializationTime() << " ms." << endl <<
		"Data size: " << Tests->getSerializationDataSize() << " byte" << endl << endl;
	delete Tests;
	
	Tests = new UsdsDomTest(test_counts, test_size);
	err_code = Tests->beginTest();

	if (err_code != 0)
	{
		cout << "1b) USDS DOM Test error! Error code: " << err_code << endl;
		cout << "Press Enter";
		cin.ignore();
		return -1;
	};
	cout << "1b) USDS DOM"  << endl <<
		"Serialization: " << Tests->getSerializationTime() << " ms." << endl <<
		"Deserialization: " << Tests->getDeserializationTime() << " ms." << endl <<
		"Data size: " << Tests->getSerializationDataSize() << " byte" << endl << endl;
	delete Tests;


	Tests = new ProtobufTest(test_counts, test_size);
	err_code = Tests->beginTest();

	if (err_code != 0)
	{
		cout << "2) Protobuf Test error! Error code : " << err_code << endl;
		cout << "Press Enter";
		cin.ignore();
		return -1;
	};
	cout << "2) Protobuf" << endl <<
		"Serialization: " << Tests->getSerializationTime() << " ms." << endl <<
		"Deserialization: " << Tests->getDeserializationTime() << " ms." << endl <<
		"Data size: " << Tests->getSerializationDataSize() << " byte" << endl << endl;
	delete Tests;
	

	Tests = new XmlTest(test_counts, test_size);
	err_code = Tests->beginTest();

	if (err_code != 0)
	{
		cout << "3) XML Test error! Error code : " << err_code << endl;
		cout << "Press Enter";
		cin.ignore();
		return -1;
	};
	cout << "3) XML" << endl <<
		"Serialization: " << Tests->getSerializationTime() << " ms." << endl <<
		"Deserialization: " << Tests->getDeserializationTime() << " ms." << endl <<
		"Data size: " << Tests->getSerializationDataSize() << " byte" << endl << endl;
	delete Tests;
	

	Tests = new JsonTest(test_counts, test_size);
	err_code = Tests->beginTest();

	if (err_code != 0)
	{
		cout << "4) JSON Test error! Error code : " << err_code << endl;
		cout << "Press Enter";
		cin.ignore();
		return -1;
	};
	cout << "4) JSON" << endl <<
		"Serialization: " << Tests->getSerializationTime() << " ms." << endl <<
		"Deserialization: " << Tests->getDeserializationTime() << " ms." << endl <<
		"Data size: " << Tests->getSerializationDataSize() << " byte" << endl << endl;
	delete Tests;

	Tests = new BsonTest(test_counts, test_size);
	err_code = Tests->beginTest();

	if (err_code != 0)
	{
		cout << "5) BSON Test error! Error code : " << err_code << endl;
		cout << "Press Enter";
		cin.ignore();
		return -1;
	};
	cout << "5) BSON" << endl <<
		"Serialization: " << Tests->getSerializationTime() << " ms." << endl <<
		"Deserialization: " << Tests->getDeserializationTime() << " ms." << endl <<
		"Data size: " << Tests->getSerializationDataSize() << " byte" << endl << endl;
	delete Tests;

	Tests = new AsnTest(test_counts, test_size);
	err_code = Tests->beginTest();

	if (err_code != 0)
	{
		cout << "6) ASN.1 Test error! Error code : " << err_code << endl;
		cout << "Press Enter";
		cin.ignore();
		return -1;
	};
	cout << "6) ASN.1" << endl <<
		"Serialization: " << Tests->getSerializationTime() << " ms." << endl <<
		"Deserialization: " << Tests->getDeserializationTime() << " ms." << endl <<
		"Data size: " << Tests->getSerializationDataSize() << " byte" << endl << endl;
	delete Tests;

	cout << "Press Enter";
	cin.ignore();

	return 0;
}