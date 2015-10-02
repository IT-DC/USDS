#include "base\usdsTypes.h"

namespace usds
{
	const char* typeName(usdsTypes code)
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
			"TAG"
		};

		if (code < 0 || code >32)
			return "ERROR TYPE";

		return typeNames[code];

	};

	const char* encodeName(usdsEncodes code)
	{
		const char* encodeNames[] = { "NO_ENCODE", "NO_ENCODE", "UTF-8", "UTF-16", "UTF-32", "UTF-7" };

		if (code < 0 || code > 4)
			return "ERROR ENCODE";

		return  encodeNames[code];
	};

}

