#include "usdsTypes.h"

namespace usds
{

	const char* typeNames[] =
	{
		"NO TYPE",
		"TAG",
		"BOOLEAN",
		"BYTE",
		"UBYTE",
		"SHORT",
		"USHORT",
		"BIGENDIAN SHORT",
		"BIGENDIAN USHORT",
		"INT",
		"UINT",
		"BIGENDIAN INT",
		"BIGENDIAN UINT",
		"LONG",
		"ULONG",
		"BIGENDIAN LONG",
		"BIGENDIAN ULONG",
		"INT128",
		"UINT128",
		"BIGENDIAN INT128",
		"BIGENDIAN UINT128",
		"FLOAT",
		"BIGENDIAN FLOAT",
		"DOUBLE",
		"BIGENDIAN DOUBLE",
		"VARINT",
		"UVARINT",
		"STRING",
		"ARRAY",
		"LIST",
		"MAP",
		"POLYMORPH",
		"STRUCT",
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
		USDS_NO_TYPE_SIZE,
		USDS_TAG_SIZE,
		USDS_BOOLEAN_SIZE,
		USDS_BYTE_SIZE,
		USDS_UBYTE_SIZE,
		USDS_SHORT_SIZE,
		USDS_USHORT_SIZE,
		USDS_BIGENDIAN_SHORT_SIZE,
		USDS_BIGENDIAN_USHORT_SIZE,
		USDS_INT_SIZE,
		USDS_UINT_SIZE,
		USDS_BIGENDIAN_INT_SIZE,
		USDS_BIGENDIAN_UINT_SIZE,
		USDS_LONG_SIZE,
		USDS_ULONG_SIZE,
		USDS_BIGENDIAN_LONG_SIZE,
		USDS_BIGENDIAN_ULONG_SIZE,
		USDS_INT128_SIZE,
		USDS_UINT128_SIZE,
		USDS_BIGENDIAN_INT128_SIZE,
		USDS_BIGENDIAN_UINT128_SIZE,
		USDS_FLOAT_SIZE,
		USDS_BIGENDIAN_FLOAT_SIZE,
		USDS_DOUBLE_SIZE,
		USDS_BIGENDIAN_DOUBLE_SIZE,
		USDS_VARINT_SIZE,
		USDS_UVARINT_SIZE,
		USDS_STRING_SIZE,
		USDS_ARRAY_SIZE,
		USDS_LIST_SIZE,
		USDS_MAP_SIZE,
		USDS_POLYMORPH_SIZE,
		USDS_STRUCT_SIZE,
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
		"NO_ENCODE", 
		"NO_ENCODE", 
		"UTF-8", 
		"UTF-16", 
		"UTF-32", 
		"UTF-7" 
	};

	const char* usdsEncodeName(usdsEncodes code) throw(...)
	{
		if (code < 0 || code >= USDS_LAST_ENCODE)
			throw ErrorStack("typeSize") << code << (ErrorMessage(USDS_TYPES__ERROR_ENCODE) << "Unknown encode " << code);

		return  encodeNames[code];
	};

}

