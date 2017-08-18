#ifndef BASE_TEST_CLASS_H
#define BASE_TEST_CLASS_H

#include <cstdint>

namespace testSaxParser
{
	struct Package
	{
		uint8_t* body;
		size_t size;
	};

	class BaseTest
	{

	public:
		virtual Package SaxGetBinary() = 0;
		virtual Package SaxGetXml() = 0;
		virtual Package SaxGetJson() = 0;

		virtual Package BasicGetBinary() = 0;
		virtual Package BasicGetXml() = 0;
		virtual Package BasicGetJson() = 0;

		virtual bool SaxSetBinary(Package input) = 0;
		virtual bool SaxSetXml(Package input) = 0;
		virtual bool SaxSetJson(Package input) = 0;

	};

}

#endif


