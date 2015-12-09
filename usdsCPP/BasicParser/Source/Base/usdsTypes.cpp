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
		-1, // No type
		0,	// Tag
		1,	// BOOLEAN
		1,	// BYTE
		1,	// UNSIGNED BYTE
		2,	// SHORT
		2,	// UNSIGNED SHORT
		2,	// BIGENDIAN SHORT
		2,	// BIGENDIAN UNSIGNED SHORT
		4,	// INT
		4,	// UNSIGNED INT
		4,	// BIGENDIAN INT
		4,	// BIGENDIAN UNSIGNED INT
		8,	// LONG
		8,	// UNSIGNED LONG
		8,	// BIGENDIAN LONG
		8,	// BIGENDIAN UNSIGNED LONG
		16,	// INT128
		16,	// UNSIGNED INT128
		16,	// BIGENDIAN INT128
		16,	// BIGENDIAN UNSIGNED INT128
		4,	// FLOAT
		4,	// BIGENDIAN FLOAT
		8,	// DOUBLE
		8,	// BIGENDIAN DOUBLE
		0,	// VARINT
		0,	// UNSIGNED VARINT
		0,	// STRING
		0,	// ARRAY
		0,	// LIST
		0,	// MAP
		0,	// POLYMORPH
		0,	// STRUCT
		0,	// FUNCTION
		-1
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

