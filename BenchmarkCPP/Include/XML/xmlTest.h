#ifndef XML_TEST
#define XML_TEST

#include "baseTest.h"
#include "XML\tinyxml2.h"

class XmlTest : public BaseTest
{
public:
	XmlTest(int counts, int size);
	virtual ~XmlTest();

private:
	int serializationTest();
	int deserializationTest();

	char* xml_data;

	tinyxml2::XMLDocument* serializer;
	tinyxml2::XMLPrinter printer;

};


#endif