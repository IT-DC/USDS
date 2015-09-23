#include "tags\usdsTypes.h"

namespace usds
{
	const char* typeName(usdsTypes code)
	{
		const char* typeNames[] =
		{
			"NO TYPE",
			"boolean",
			"byte",
			"unsigned byte",
			"short",
			"unsigned short",
			"bigendian short",
			"bigendian unsigned short",
			"int",
			"unsigned int",
			"bigendian int",
			"bigendian unsigned int",
			"long",
			"unsigned long",
			"bigendian long",
			"bigendian unsigned long",
			"int128",
			"unsigned int128",
			"bigendian int128",
			"bigendian unsigned int128",
			"float",
			"bigendian float",
			"double",
			"bigendian double",
			"varint",
			"unsigned varint",
			"struct",
			"array",
			"string",
			"list",
			"map",
			"polymorph",
			"tag"
		};

		if (code < 0 || code >32)
			return "ERROR TYPE";

		return typeNames[code];

	};

	const char* encodeName(usdsEncodes code)
	{
		const char* encodeNames[] = { "NO_ENCODE", "utf-8", "utf-16", "utf-32", "utf-7" };

		if (code < 0 || code > 4)
			return "ERROR TYPE";

		return  encodeNames[code];
	};

}

