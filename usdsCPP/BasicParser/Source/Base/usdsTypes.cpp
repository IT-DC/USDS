#include "base\usdsTypes.h"

namespace usds
{

	const char* typeNames[] =
	{
		"NO TYPE",
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
		"TAG",
		"NO TYPE"
	};

	const char* typeName(usdsTypes code)
	{
		if (code <= 0 || code >= USDS_LAST_TYPE)
			return "ERROR TYPE";

		return typeNames[code];

	};

	int typeSizes[] =
	{
		-1, // No type
		1,
		1,
		1,
		2,
		2,
		2,
		2,
		4,
		4,
		4,
		4,
		8,
		8,
		8,
		8,
		16,
		16,
		16,
		16,
		4,
		4,
		8,
		8,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		-1
	};

	int typeSize(usdsTypes code)
	{
		if (code <= 0 || code >= USDS_LAST_TYPE)
			return 0;

		return typeSizes[code];
	};

	
	const char* encodeNames[] = { "NO_ENCODE", "NO_ENCODE", "UTF-8", "UTF-16", "UTF-32", "UTF-7" };

	const char* encodeName(usdsEncodes code)
	{
		if (code < 0 || code >= USDS_LAST_ENCODE)
			return "ERROR ENCODE";

		return  encodeNames[code];
	};

}

