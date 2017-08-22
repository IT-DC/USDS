#include "usdsTypes.h"

#include "usdsErrors.h"

using namespace usds;

const char* UsdsTypes::typeName(usdsType code) throw(...)
{
	switch(code)
	{
	case USDS_TAG: return "TAG";
	case USDS_BOOLEAN: return "BOOLEAN";
	case USDS_BYTE: return "BYTE";
	case USDS_UBYTE: return "UBYTE";
	case USDS_SHORT: return "SHORT";
	case USDS_USHORT: return "USHORT";
	case USDS_INT: return "INT";
	case USDS_UINT: return "UINT";
	case USDS_LONG: return "LONG";
	case USDS_ULONG: return "ULONG";
	case USDS_INT128: return "INT128";
	case USDS_UINT128: return "UINT128";
	case USDS_FLOAT: return "FLOAT";
	case USDS_DOUBLE: return "DOUBLE";
	case USDS_VARINT: return "VARINT";
	case USDS_UVARINT: return "UVARINT";
	case USDS_STRING: return "STRING";
	case USDS_ARRAY: return "ARRAY";
	case USDS_STRUCT: return "STRUCT";
	case USDS_ENUM: return "ENUM";
	case USDS_POLYMORPH: return "POLYMORPH";
	case USDS_LAST_TYPE: return "NO TYPE";

	default:
		throw ErrorStack("UsdsTypes::typeName") << code << (ErrorMessage(USDS_TYPES__ERROR_TYPE_CODE) << "Unknown type code " << code);
	}

};

int32_t UsdsTypes::typeSize(usdsType code) throw(...)
{
	switch (code)
	{
	case USDS_TAG: return USDS_TAG_SIZE;
	case USDS_BOOLEAN: return USDS_BOOLEAN_SIZE;
	case USDS_BYTE: return USDS_BYTE_SIZE;
	case USDS_UBYTE: return USDS_UBYTE_SIZE;
	case USDS_SHORT: return USDS_SHORT_SIZE;
	case USDS_USHORT: return USDS_USHORT_SIZE;
	case USDS_INT: return USDS_INT_SIZE;
	case USDS_UINT: return USDS_UINT_SIZE;
	case USDS_LONG: return USDS_LONG_SIZE;
	case USDS_ULONG: return USDS_ULONG_SIZE;
	case USDS_INT128: return USDS_INT128_SIZE;
	case USDS_UINT128: return USDS_UINT128_SIZE;
	case USDS_FLOAT: return USDS_FLOAT_SIZE;
	case USDS_DOUBLE: return USDS_DOUBLE_SIZE;
	case USDS_VARINT: return USDS_VARINT_SIZE;
	case USDS_UVARINT: return USDS_UVARINT_SIZE;
	case USDS_STRING: return USDS_STRING_SIZE;
	case USDS_ARRAY: return USDS_ARRAY_SIZE;
	case USDS_STRUCT: return USDS_STRUCT_SIZE;
	case USDS_ENUM: return USDS_ENUM_SIZE;
	case USDS_POLYMORPH: return USDS_POLYMORPH_SIZE;
	default:
		throw ErrorStack("UsdsTypes::typeSize") << code << (ErrorMessage(USDS_TYPES__ERROR_TYPE_CODE) << "Unknown type code " << code);
	}
};

const char* UsdsTypes::encodeName(usdsEncode code) throw(...)
{
	switch (code)
	{
	case USDS_UTF8: return "UTF-8";
	case USDS_UTF16LE: return "UTF-16LE";
	case USDS_UTF16BE: return "UTF-16BE";
	case USDS_UTF32LE: return "UTF-32LE";
	case USDS_UTF32BE: return "UTF-32BE";
	default:
		throw ErrorStack("UsdsTypes::encodeName") << code << (ErrorMessage(USDS_TYPES__ERROR_ENCODE) << "Unknown encode " << code);
	}
};

