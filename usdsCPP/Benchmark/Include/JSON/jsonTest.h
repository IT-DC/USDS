#ifndef JSON_TEST
#define JSON_TEST

#include "baseTest.h"
#include "rapidjson\writer.h"
#include "rapidjson\stringbuffer.h"
#include "rapidjson\reader.h"

#include <iostream>

using namespace rapidjson;
using namespace std;

class Handler {
	
public:

	Handler(TicketSales* out) { output_class = out; last_key = 0; arr_pos = -1; };
	virtual ~Handler() {};

	inline bool Null() { return false; };
	inline bool Bool(bool b);
	inline bool Int(int i);
	inline bool Uint(unsigned i);
	inline bool Int64(int64_t i) { return false; };
	inline bool Uint64(uint64_t i) { return false; };
	inline bool Double(double d);
	inline bool String(const char* str, SizeType length, bool copy);
	inline bool StartObject();
	inline bool Key(const char* str, SizeType length, bool copy);
	inline bool EndObject(SizeType memberCount);
	inline bool StartArray();
	inline bool EndArray(SizeType elementCount);

private:
	TicketSales* output_class;
	char last_key;
	int arr_pos;


};


class JsonTest : public BaseTest
{
public:
	JsonTest(int counts, int size);
	~JsonTest();

private:
	int serializationTest();
	int deserializationTest();

	char* json_data;

	Writer<StringBuffer> *serializer;
	Reader* deserializer;
	StringBuffer* json_buff;
	
	Handler* json_ticket_sales;

};


#endif