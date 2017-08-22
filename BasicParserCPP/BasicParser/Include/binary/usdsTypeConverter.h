#ifndef USDS_TYPE_CONVERTER_H
#define USDS_TYPE_CONVERTER_H

#include "usdsTypes.h"

namespace usds
{
	enum typeConverterErrorCodes
	{
		UNSUPPORTED_TYPE_CONVERSION = 201,
		ERROR_VALUE_CONVERSION = 202
	};

	extern void usdsTypeWrite(uint8_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeWrite(int8_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeWrite(uint16_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeWrite(int16_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeWrite(uint32_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeWrite(int32_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeWrite(uint64_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeWrite(int64_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeWrite(float value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeWrite(double value, usdsType usds_type, uint8_t* destination) throw(...);

	extern void usdsTypeRead(uint8_t* source, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeRead(uint8_t* source, usdsType usds_type, int8_t* destination) throw(...);
	extern void usdsTypeRead(uint8_t* source, usdsType usds_type, uint16_t* destination) throw(...);
	extern void usdsTypeRead(uint8_t* source, usdsType usds_type, int16_t* destination) throw(...);
	extern void usdsTypeRead(uint8_t* source, usdsType usds_type, uint32_t* destination) throw(...);
	extern void usdsTypeRead(uint8_t* source, usdsType usds_type, int32_t* destination) throw(...);
	extern void usdsTypeRead(uint8_t* source, usdsType usds_type, uint64_t* destination) throw(...);
	extern void usdsTypeRead(uint8_t* source, usdsType usds_type, int64_t* destination) throw(...);
	extern void usdsTypeRead(uint8_t* source, usdsType usds_type, float* destination) throw(...);
	extern void usdsTypeRead(uint8_t* source, usdsType usds_type, double* destination) throw(...);

	//TODO for bigendian
	extern void usdsTypeRotateAndWrite(uint8_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeRotateAndWrite(int8_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeRotateAndWrite(uint16_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeRotateAndWrite(int16_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeRotateAndWrite(uint32_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeRotateAndWrite(int32_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeRotateAndWrite(uint64_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeRotateAndWrite(int64_t value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeRotateAndWrite(float value, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeRotateAndWrite(double value, usdsType usds_type, uint8_t* destination) throw(...);

	extern void usdsTypeRotateAndRead(uint8_t* source, usdsType usds_type, uint8_t* destination) throw(...);
	extern void usdsTypeRotateAndRead(uint8_t* source, usdsType usds_type, int8_t* destination) throw(...);
	extern void usdsTypeRotateAndRead(uint8_t* source, usdsType usds_type, uint16_t* destination) throw(...);
	extern void usdsTypeRotateAndRead(uint8_t* source, usdsType usds_type, int16_t* destination) throw(...);
	extern void usdsTypeRotateAndRead(uint8_t* source, usdsType usds_type, uint32_t* destination) throw(...);
	extern void usdsTypeRotateAndRead(uint8_t* source, usdsType usds_type, int32_t* destination) throw(...);
	extern void usdsTypeRotateAndRead(uint8_t* source, usdsType usds_type, uint64_t* destination) throw(...);
	extern void usdsTypeRotateAndRead(uint8_t* source, usdsType usds_type, int64_t* destination) throw(...);
	extern void usdsTypeRotateAndRead(uint8_t* source, usdsType usds_type, float* destination) throw(...);
	extern void usdsTypeRotateAndRead(uint8_t* source, usdsType usds_type, double* destination) throw(...);

}

#endif
