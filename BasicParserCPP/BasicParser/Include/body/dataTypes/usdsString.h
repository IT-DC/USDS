#ifndef USDS_STRING_H
#define USDS_STRING_H

#include "body\usdsBaseType.h"

namespace usds
{
	class UsdsString : public UsdsBaseType
	{
	public:
		UsdsString(Body* parent_body);
		virtual ~UsdsString();

		usdsType getType() { return USDS_STRING; };
		const char* getTypeName() { return "STRING"; };

		void setEncode(usdsEncode encode) throw(...);
		usdsEncode getEncode() throw(...);

		void setFromUTF8(const char* value) throw (...);
		void setFromUTF8(const char* value, size_t byte_size) throw (...);

		const char* getUTF8Value() throw (...);
		const char* getUTF8Value(size_t* byte_size) throw (...);

		// For binary body parser
		const uint8_t* getByteValue() throw (...);
		size_t getByteSize() throw (...);

		uint8_t* reserveBinaryForValue(size_t byte_size);

	private:

		void additionalInitObject() throw (...);

		usdsEncode textEncode;

		uint8_t* objectValue;
		size_t valueSize;
		size_t valueBufferSize;


	};

}

#endif