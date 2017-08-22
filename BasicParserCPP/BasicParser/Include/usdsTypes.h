#ifndef USDS_TYPES_H
#define USDS_TYPES_H

#include "common\errorMessage.h"

namespace usds
{
	enum usdsType
	{
		USDS_TAG = 0,
		USDS_BOOLEAN = 1,
		USDS_BYTE = 2,
		USDS_UBYTE = 3,
		USDS_SHORT = 4,
		USDS_USHORT = 5,
		USDS_INT = 6,
		USDS_UINT = 7,
		USDS_LONG = 8,
		USDS_ULONG = 9,
		USDS_INT128 = 10,
		USDS_UINT128 = 11,
		USDS_FLOAT = 12,
		USDS_DOUBLE = 13,
		USDS_VARINT = 14,
		USDS_UVARINT = 15,
		USDS_STRING = 16,
		USDS_ARRAY = 17,
		USDS_STRUCT = 18,
		USDS_ENUM = 19,
		USDS_POLYMORPH = 20,
		USDS_LAST_TYPE = 21
	};

	enum usdsTypeSize
	{
		USDS_TAG_SIZE = 0,
		USDS_BOOLEAN_SIZE = 1,
		USDS_BYTE_SIZE = 1,
		USDS_UBYTE_SIZE = 1,
		USDS_SHORT_SIZE = 2,
		USDS_USHORT_SIZE = 2,
		USDS_INT_SIZE = 4,
		USDS_UINT_SIZE = 4,
		USDS_LONG_SIZE = 8,
		USDS_ULONG_SIZE = 8,
		USDS_INT128_SIZE = 16,
		USDS_UINT128_SIZE = 16,
		USDS_FLOAT_SIZE = 4,
		USDS_DOUBLE_SIZE = 8,
		USDS_VARINT_SIZE = 0,
		USDS_UVARINT_SIZE = 0,
		USDS_STRING_SIZE = 0,
		USDS_ARRAY_SIZE = 0,
		USDS_STRUCT_SIZE = 0,
		USDS_ENUM_SIZE = 0,
		USDS_POLYMORPH_SIZE = 0
	};

	enum usdsEncode
	{
		USDS_NO_DEFAULT_ENCODE = 0,
		USDS_UTF8 = 1,
		USDS_UTF16LE = 2,
		USDS_UTF16BE = 3,
		USDS_UTF32LE = 4,
		USDS_UTF32BE = 5,
		USDS_LAST_ENCODE = 6
	};

	enum usdsSignature
	{
		USDS_MAJOR_SIGNATURE = '$',
		USDS_MINOR_SIGNATURE = 'S',
		USDS_MAJOR_VERSION = 1,
		USDS_MINOR_VERSION = 0,
		USDS_DICTIONARY_SIGNATURE = 'd',
		USDS_DICTIONARY_SIGNATURE_WITH_SIZE = 'D',
		USDS_TAG_SIGNATURE = 't',
		USDS_FIELD_SIGNATURE = 'f',
		USDS_TAG_RESTRICTION_SIGNATURE = 'R',
		USDS_TAG_RESTRICTION_NOT_ROOT_SIGNATURE = 'r',
		USDS_BODY_SIGNATURE = 'b',
		USDS_BODY_SIGNATURE_WITH_SIZE = 'B'
	};

	class UsdsTypes
	{
	public:
		// abstract class
		virtual void f() = 0;


		static const char* typeName(usdsType code) throw(...);

		// returns 0 if unfixed
		static int32_t typeSize(usdsType code) throw(...);

		static const char* encodeName(usdsEncode code) throw(...);
	};

};


#endif