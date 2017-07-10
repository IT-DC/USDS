#include "usdsTypes.h"

namespace usds
{

	const char* typeNames[] =
	{
		"TAG",
		"BOOLEAN",
		"BYTE",
		"UBYTE",
		"SHORT",
		"USHORT",
		"INT",
		"UINT",
		"LONG",
		"ULONG",
		"INT128",
		"UINT128",
		"FLOAT",
		"DOUBLE",
		"VARINT",
		"UVARINT",
		"STRING",
		"ARRAY",
		"STRUCT",
		"GUID",
		"MAP",
		"DATE",
		"TIME",
		"DATETIME",
		"FUNCTION",
		"NO TYPE"
	};

	const char* usdsTypeName(usdsTypes code) throw(...)
	{
		if (code <= 0 || code >= USDS_LAST_TYPE)
			throw ErrorStack("usdsTypeName") << code << (ErrorMessage(USDS_TYPES__ERROR_TYPE_CODE) << "Unknown type code " << code);

		return typeNames[code];

	};

	int32_t typeSizes[] =
	{
		USDS_TAG_SIZE,
		USDS_BOOLEAN_SIZE,
		USDS_BYTE_SIZE,
		USDS_UBYTE_SIZE,
		USDS_SHORT_SIZE,
		USDS_USHORT_SIZE,
		USDS_INT_SIZE,
		USDS_UINT_SIZE,
		USDS_LONG_SIZE,
		USDS_ULONG_SIZE,
		USDS_INT128_SIZE,
		USDS_UINT128_SIZE,
		USDS_FLOAT_SIZE,
		USDS_DOUBLE_SIZE,
		USDS_VARINT_SIZE,
		USDS_UVARINT_SIZE,
		USDS_STRING_SIZE,
		USDS_ARRAY_SIZE,
		USDS_STRUCT_SIZE,
		USDS_GUID_SIZE,
		USDS_MAP_SIZE,
		USDS_DATE_SIZE,
		USDS_TIME_SIZE,
		USDS_DATETIME_SIZE,
		USDS_FUNCTION_SIZE,
		USDS_LAST_TYPE_SIZE
	};

	int32_t usdsTypeSize(usdsTypes code) throw(...)
	{
		if (code <= 0 || code >= USDS_LAST_TYPE)
			throw ErrorStack("typeSize") << code << (ErrorMessage(USDS_TYPES__ERROR_TYPE_CODE) << "Unknown type code " << code);

		return typeSizes[code];
	};
	
	const char* encodeNames[] = 
	{
		"NO_DEFAULT_ENCODE",
		"UTF-8",
		"UTF-16LE",
		"UTF-16BE",
		"UTF-32LE",
		"UTF-32BE",
		"NO_ENCODE",
	};

	const char* usdsEncodeName(usdsEncodes code) throw(...)
	{
		if (code < 0 || code >= USDS_LAST_ENCODE)
			throw ErrorStack("typeSize") << code << (ErrorMessage(USDS_TYPES__ERROR_ENCODE) << "Unknown encode " << code);

		return  encodeNames[code];
	};

}

