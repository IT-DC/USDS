#include "base\usdsTypes.h"

namespace usds
{

	const char* typeNames[] =
	{
		"NO TYPE",
		"TAG",
		"BOOLEAN",
		"BYTE",
		"UNSIGNED BYTE",
		"SHORT",
		"UNSIGNED SHORT",
		"BIGENDIAN SHORT",
		"BIGENDIAN UNSIGNED SHORT",
		"INT",
		"UNSIGNED INT",
		"BIGENDIAN INT",
		"BIGENDIAN UNSIGNED INT",
		"LONG",
		"UNSIGNED LONG",
		"BIGENDIAN LONG",
		"BIGENDIAN UNSIGNED LONG",
		"INT128",
		"UNSIGNED INT128",
		"BIGENDIAN INT128",
		"BIGENDIAN UNSIGNED INT128",
		"FLOAT",
		"BIGENDIAN FLOAT",
		"DOUBLE",
		"BIGENDIAN DOUBLE",
		"VARINT",
		"UNSIGNED VARINT",
		"STRING",
		"ARRAY",
		"LIST",
		"MAP",
		"POLYMORPH",
		"STRUCT",
		"FUNCTION",
		"NO TYPE"
	};

	const char* typeName(usdsTypes code) throw(...)
	{
		if (code <= 0 || code >= USDS_LAST_TYPE)
			throw ErrorStack("typeName") << code << (ErrorMessage(USDS_TYPES__ERROR_TYPE_CODE) << "Unknown type code " << code);

		return typeNames[code];

	};

	int typeSizes[] =
	{
		USDS_NO_TYPE_SIZE,
		USDS_TAG_SIZE,
		USDS_BOOLEAN_SIZE,
		USDS_BYTE_SIZE,
		USDS_UNSIGNED_BYTE_SIZE,
		USDS_SHORT_SIZE,
		USDS_UNSIGNED_SHORT_SIZE,
		USDS_BIGENDIAN_SHORT_SIZE,
		USDS_BIGENDIAN_UNSIGNED_SHORT_SIZE,
		USDS_INT_SIZE,
		USDS_UNSIGNED_INT_SIZE,
		USDS_BIGENDIAN_INT_SIZE,
		USDS_BIGENDIAN_UNSIGNED_INT_SIZE,
		USDS_LONG_SIZE,
		USDS_UNSIGNED_LONG_SIZE,
		USDS_BIGENDIAN_LONG_SIZE,
		USDS_BIGENDIAN_UNSIGNED_LONG_SIZE,
		USDS_INT128_SIZE,
		USDS_UNSIGNED_INT128_SIZE,
		USDS_BIGENDIAN_INT128_SIZE,
		USDS_BIGENDIAN_UNSIGNED_INT128_SIZE,
		USDS_FLOAT_SIZE,
		USDS_BIGENDIAN_FLOAT_SIZE,
		USDS_DOUBLE_SIZE,
		USDS_USDS_BIGENDIAN_DOUBLE_SIZE,
		USDS_VARINT_SIZE,
		USDS_UNSIGNED_VARINT_SIZE,
		USDS_STRING_SIZE,
		USDS_ARRAY_SIZE,
		USDS_LIST_SIZE,
		USDS_MAP_SIZE,
		USDS_POLYMORPH_SIZE,
		USDS_STRUCT_SIZE,
		USDS_FUNCTION_SIZE,
		USDS_LAST_TYPE_SIZE
	};

	int typeSize(usdsTypes code) throw(...)
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

	const char* encodeName(usdsEncodes code) throw(...)
	{
		if (code < 0 || code >= USDS_LAST_ENCODE)
			throw ErrorStack("typeSize") << code << (ErrorMessage(USDS_TYPES__ERROR_ENCODE) << "Unknown encode " << code);

		return  encodeNames[code];
	};

}

