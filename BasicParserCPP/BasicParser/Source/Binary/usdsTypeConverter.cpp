#include "binary\usdsTypeConverter.h"

#include "common\errorMessage.h"

namespace usds
{
	void usdsTypeWrite(uint8_t value, usdsType usds_type, uint8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			if (value > 127)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			destination[0] = value;
			break;
		}
		case USDS_UBYTE:
		{
			destination[0] = value;
			break;
		}
		case USDS_SHORT:
		{
			int16_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_SHORT_SIZE);
			break;
		}
		case USDS_USHORT:
		{
			uint16_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_USHORT_SIZE);
			break;
		}
		case USDS_INT:
		{
			int32_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_INT_SIZE);
			break;
		}
		case USDS_UINT:
		{
			uint32_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_UINT_SIZE);
			break;
		}
		case USDS_LONG:
		{
			int64_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_LONG_SIZE);
			break;
		}
		case USDS_ULONG:
		{
			uint64_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_ULONG_SIZE);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from uint8_t to " << UsdsTypes::typeName(usds_type);
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeWrite") << value << usds_type << destination << msg;
	};

	void usdsTypeWrite(int8_t value, usdsType usds_type, uint8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			destination[0] = value;
			break;
		}
		case USDS_UBYTE:
		{
			if (value < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			destination[0] = value;
			break;
		}
		case USDS_SHORT:
		{
			int16_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_SHORT_SIZE);
			break;
		}
		case USDS_USHORT:
		{
			if (value < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint16_t proxy_value = (uint16_t)value;
			memcpy(destination, &proxy_value, USDS_USHORT_SIZE);
			break;
		}
		case USDS_INT:
		{
			int32_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_INT_SIZE);
			break;
		}
		case USDS_UINT:
		{
			if (value < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, (2^32-1)] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint32_t proxy_value = (uint32_t)value;
			memcpy(destination, &proxy_value, USDS_UINT_SIZE);
			break;
		}
		case USDS_LONG:
		{
			int64_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_LONG_SIZE);
			break;
		}
		case USDS_ULONG:
		{
			if (value < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, (2^64-1)] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint64_t proxy_value = (uint64_t)value;
			memcpy(destination, &proxy_value, USDS_ULONG_SIZE);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from int8_t to " << UsdsTypes::typeName(usds_type);
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeWrite") << value << usds_type << destination << msg;
	};

	void usdsTypeWrite(int16_t value, usdsType usds_type, uint8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			if (value > 127 || value < -128)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((int8_t*)destination) = (int8_t)value;
			break;
		}
		case USDS_UBYTE:
		{
			if (value < 0 || value > 255)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((uint8_t*)destination) = (uint8_t)value;
			break;
		}
		case USDS_SHORT:
		{
			memcpy(destination, &value, USDS_SHORT_SIZE);
			break;
		}
		case USDS_USHORT:
		{
			if (value < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint16_t proxy_value = (uint16_t)value;
			memcpy(destination, &proxy_value, USDS_USHORT_SIZE);
			break;
		}
		case USDS_INT:
		{
			int32_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_INT_SIZE);
			break;
		}
		case USDS_UINT:
		{
			if (value < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, (2^32-1)] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint32_t proxy_value = (uint32_t)value;
			memcpy(destination, &proxy_value, USDS_UINT_SIZE);
			break;
		}
		case USDS_LONG:
		{
			int64_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_LONG_SIZE);
			break;
		}
		case USDS_ULONG:
		{
			if (value < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, (2^64-1)] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint64_t proxy_value = (uint64_t)value;
			memcpy(destination, &proxy_value, USDS_ULONG_SIZE);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from int16_t to " << UsdsTypes::typeName(usds_type);
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeWrite") << value << usds_type << destination << msg;
	};

	void usdsTypeWrite(uint16_t value, usdsType usds_type, uint8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			if (value > 127)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((int8_t*)destination) = (int8_t)value;
			break;
		}
		case USDS_UBYTE:
		{
			if (value > 255)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((uint8_t*)destination) = (uint8_t)value;
			break;
		}
		case USDS_SHORT:
		{
			if (value > 32767)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			int16_t proxy_value = (int16_t)value;
			memcpy(destination, &proxy_value, USDS_SHORT_SIZE);
			break;
		}
		case USDS_USHORT:
		{
			memcpy(destination, &value, USDS_USHORT_SIZE);
			break;
		}
		case USDS_INT:
		{
			int32_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_INT_SIZE);
			break;
		}
		case USDS_UINT:
		{
			uint32_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_UINT_SIZE);
			break;
		}
		case USDS_LONG:
		{
			int64_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_LONG_SIZE);
			break;
		}
		case USDS_ULONG:
		{
			uint64_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_ULONG_SIZE);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from uint16_t to " << UsdsTypes::typeName(usds_type);
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeWrite") << value << usds_type << destination << msg;
	};
	
	void usdsTypeWrite(int32_t value, usdsType usds_type, uint8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			if (value > 127 || value < -128)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((int8_t*)destination) = (int8_t)value;
			break;
		}
		case USDS_UBYTE:
		{
			if (value < 0 || value > 255)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((uint8_t*)destination) = (uint8_t)value;
			break;
		}
		case USDS_SHORT:
		{
			if (value < -32768 || value > 32767)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			int16_t proxy_value = (int16_t)value;
			memcpy(destination, &proxy_value, USDS_SHORT_SIZE);
			break;
		}
		case USDS_USHORT:
		{
			if (value < 0 || value > 65535)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint16_t proxy_value = (uint16_t)value;
			memcpy(destination, &proxy_value, USDS_USHORT_SIZE);
			break;
		}
		case USDS_INT:
		{
			memcpy(destination, &value, USDS_INT_SIZE);
			break;
		}
		case USDS_UINT:
		{
			if (value < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, (2^32-1)] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint32_t proxy_value = (uint32_t)value;
			memcpy(destination, &proxy_value, USDS_UINT_SIZE);
			break;
		}
		case USDS_LONG:
		{
			int64_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_LONG_SIZE);
			break;
		}
		case USDS_ULONG:
		{
			if (value < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, (2^64-1)] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint64_t proxy_value = (uint64_t)value;
			memcpy(destination, &proxy_value, USDS_ULONG_SIZE);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from int32_t to " << UsdsTypes::typeName(usds_type);
		}

	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeWrite") << value << usds_type << destination << msg;
	};


	void usdsTypeWrite(uint32_t value, usdsType usds_type, uint8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			if (value > 127)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((int8_t*)destination) = (int8_t)value;
			break;
		}
		case USDS_UBYTE:
		{
			if (value > 255)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((uint8_t*)destination) = (uint8_t)value;
			break;
		}
		case USDS_SHORT:
		{
			if (value > 32767)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			int16_t proxy_value = (int16_t)value;
			memcpy(destination, &proxy_value, USDS_SHORT_SIZE);
			break;
		}
		case USDS_USHORT:
		{
			if (value > 65535)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint16_t proxy_value = (uint16_t)value;
			memcpy(destination, &proxy_value, USDS_USHORT_SIZE);
			break;
		}
		case USDS_INT:
		{
			if (value > INT32_MAX)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [-2147483648, 2147483647] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			int32_t proxy_value = (int32_t)value;
			memcpy(destination, &proxy_value, USDS_INT_SIZE);
			break;
		}
		case USDS_UINT:
		{
			memcpy(destination, &value, USDS_UINT_SIZE);
			break;
		}
		case USDS_LONG:
		{
			int64_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_LONG_SIZE);
			break;
		}
		case USDS_ULONG:
		{
			uint64_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_ULONG_SIZE);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from uint32_t to " << UsdsTypes::typeName(usds_type);
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeWrite") << value << usds_type << destination << msg;
	};

	void usdsTypeWrite(int64_t value, usdsType usds_type, uint8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			if (value > 127 || value < -128)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [-128, 127] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((int8_t*)destination) = (int8_t)value;
			break;
		}
		case USDS_UBYTE:
		{
			if (value < 0 || value > 255)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, 255] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((uint8_t*)destination) = (uint8_t)value;
			break;
		}
		case USDS_SHORT:
		{
			if (value < -32768 || value > 32767)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			int16_t proxy_value = (int16_t)value;
			memcpy(destination, &proxy_value, USDS_SHORT_SIZE);
			break;
		}
		case USDS_USHORT:
		{
			if (value < 0 || value > 65535)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint16_t proxy_value = (uint16_t)value;
			memcpy(destination, &proxy_value, USDS_USHORT_SIZE);
			break;
		}
		case USDS_INT:
		{
			if (value < INT32_MIN || value > INT32_MAX)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [-2147483648, 2147483647] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			int32_t proxy_value = (int32_t)value;
			memcpy(destination, &proxy_value, USDS_INT_SIZE);
			break;
		}
		case USDS_UINT:
		{
			if (value < 0 || value > UINT32_MAX)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, (2^32-1)] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint32_t proxy_value = (uint32_t)value;
			memcpy(destination, &proxy_value, USDS_UINT_SIZE);
			break;
		}
		case USDS_LONG:
		{
			memcpy(destination, &value, USDS_LONG_SIZE);
			break;
		}
		case USDS_ULONG:
		{
			if (value < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, (2^64-1)] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint64_t proxy_value = (uint64_t)value;
			memcpy(destination, &proxy_value, USDS_ULONG_SIZE);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from int64_t to " << UsdsTypes::typeName(usds_type);
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeWrite") << value << usds_type << destination << msg;
	};

	void usdsTypeWrite(uint64_t value, usdsType usds_type, uint8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			if (value > 127)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [-128, 127] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((int8_t*)destination) = (int8_t)value;
			break;
		}
		case USDS_UBYTE:
		{
			if (value > 255)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, 255] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			*((uint8_t*)destination) = (uint8_t)value;
			break;
		}
		case USDS_SHORT:
		{
			if (value > 32767)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			int16_t proxy_value = (int16_t)value;
			memcpy(destination, &proxy_value, USDS_SHORT_SIZE);
			break;
		}
		case USDS_USHORT:
		{
			if (value > 65535)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint16_t proxy_value = (uint16_t)value;
			memcpy(destination, &proxy_value, USDS_USHORT_SIZE);
			break;
		}
		case USDS_INT:
		{
			if (value > INT32_MAX)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [-2147483648, 2147483647] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			int32_t proxy_value = (int32_t)value;
			memcpy(destination, &proxy_value, USDS_INT_SIZE);
			break;
		}
		case USDS_UINT:
		{
			if (value > UINT32_MAX)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, (2^32-1)] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			uint32_t proxy_value = (uint32_t)value;
			memcpy(destination, &proxy_value, USDS_UINT_SIZE);
			break;
		}
		case USDS_LONG:
		{
			if (value > INT64_MAX)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [-(2^63), (2^63–1)] for type " << UsdsTypes::typeName(usds_type) << ". Current value: " << value;
			int64_t proxy_value = value;
			memcpy(destination, &proxy_value, USDS_LONG_SIZE);
			break;
		}
		case USDS_ULONG:
		{
			memcpy(destination, &value, USDS_ULONG_SIZE);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from uint64_t to " << UsdsTypes::typeName(usds_type);
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeWrite") << value << usds_type << destination << msg;
	};

	void usdsTypeWrite(float value, usdsType usds_type, uint8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_FLOAT:
		{
			memcpy(destination, &value, USDS_FLOAT_SIZE);
			break;
		}
		case USDS_DOUBLE:
		{
			double proxy_value = value;
			memcpy(destination, &proxy_value, USDS_DOUBLE_SIZE);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from float to " << UsdsTypes::typeName(usds_type);
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeWrite") << value << usds_type << destination << msg;
	};

	void usdsTypeWrite(double value, usdsType usds_type, uint8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_DOUBLE:
		{
			memcpy(destination, &value, USDS_DOUBLE_SIZE);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from double to " << UsdsTypes::typeName(usds_type);
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeWrite") << value << usds_type << destination << msg;
	};

	void usdsTypeRead(uint8_t* source, usdsType usds_type, int8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			*destination = (int8_t)(*source);
			break;
		}
		case USDS_UBYTE:
		{
			if (*source > 127)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type int8_t. Value in USDS binary: " << *source;
			*destination = (int8_t)(*source);
			break;
		}
		case USDS_SHORT:
		{
			if (*((int16_t*)source) > 127 || *((int16_t*)source) < -128)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type int8_t. Value in USDS binary: " << *((int16_t*)source);
			*destination = (int8_t)(*((int16_t*)source));
			break;
		}
		case USDS_USHORT:
		{
			if (*((uint16_t*)source) > 127)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type int8_t. Value in USDS binary: " << *((uint16_t*)source);
			*destination = (int8_t)(*((uint16_t*)source));
			break;
		}
		case USDS_INT:
		{
			if (*((int32_t*)source) > 127 || *((int32_t*)source) < -128)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type int8_t. Value in USDS binary: " << *((int32_t*)source);
			*destination = (int8_t)(*((int32_t*)source));
			break;
		}
		case USDS_UINT:
		{
			if (*((uint32_t*)source) > 127)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type int8_t. Value in USDS binary: " << *((uint32_t*)source);
			*destination = (int8_t)(*((uint32_t*)source));
			break;
		}
		case USDS_LONG:
		{
			if (*((int64_t*)source) > 127 || *((int64_t*)source) < -128)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type int8_t. Value in USDS binary: " << *((int64_t*)source);
			*destination = (int8_t)(*((int64_t*)source));
			break;
		}
		case USDS_ULONG:
		{
			if (*((uint64_t*)source) > 127)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-128, 127] for type int8_t. Value in USDS binary: " << *((uint64_t*)source);
			*destination = (int8_t)(*((uint64_t*)source));
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from " << UsdsTypes::typeName(usds_type) << " to int8_t";
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeRead") << source << usds_type << destination << msg;
	};

	void usdsTypeRead(uint8_t* source, usdsType usds_type, uint8_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			if (*((int8_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type uint8_t. Value in USDS binary: " << *((int8_t*)source);
			*destination = *source;
			break;
		}
		case USDS_UBYTE:
		{
			*destination = *source;
			break;
		}
		case USDS_SHORT:
		{
			if (*((int16_t*)source) > 255 || *((int16_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type uint8_t. Value in USDS binary: " << *((int16_t*)source);
			*destination = (uint8_t)(*((int16_t*)source));
			break;
		}
		case USDS_USHORT:
		{
			if (*((uint16_t*)source) > 255)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type uint8_t. Value in USDS binary: " << *((uint16_t*)source);
			*destination = (uint8_t)(*((uint16_t*)source));
			break;
		}
		case USDS_INT:
		{
			if (*((int32_t*)source) > 255 || *((int32_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type uint8_t. Value in USDS binary: " << *((int32_t*)source);
			*destination = (uint8_t)(*((int32_t*)source));
			break;
		}
		case USDS_UINT:
		{
			if (*((uint32_t*)source) > 255)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type uint8_t. Value in USDS binary: " << *((uint32_t*)source);
			*destination = (uint8_t)(*((uint32_t*)source));
			break;
		}
		case USDS_LONG:
		{
			if (*((int64_t*)source) > 255 || *((int64_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type uint8_t. Value in USDS binary: " << *((int64_t*)source);
			*destination = (uint8_t)(*((int64_t*)source));
			break;
		}
		case USDS_ULONG:
		{
			if (*((uint64_t*)source) > 255)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 255] for type uint8_t. Value in USDS binary: " << *((uint64_t*)source);
			*destination = (uint8_t)(*((uint64_t*)source));
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from " << UsdsTypes::typeName(usds_type) << " to uint8_t";
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeRead") << source << usds_type << destination << msg;
	};

	void usdsTypeRead(uint8_t* source, usdsType usds_type, int16_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			*destination = *((int8_t*)source);
			break;
		}
		case USDS_UBYTE:
		{
			*destination = *source;
			break;
		}
		case USDS_SHORT:
		{
			*destination = *((int16_t*)source);
			break;
		}
		case USDS_USHORT:
		{
			if (*((uint16_t*)source) > 32767)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type int16_t. Value in USDS binary: " << *((uint16_t*)source);
			*destination = (int16_t)(*((uint16_t*)source));
			break;
		}
		case USDS_INT:
		{
			if (*((int32_t*)source) > 32767 || *((int32_t*)source) < -32768)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type int16_t. Value in USDS binary: " << *((int32_t*)source);
			*destination = (int16_t)(*((int32_t*)source));
			break;
		}
		case USDS_UINT:
		{
			if (*((uint32_t*)source) > 32767)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type int16_t. Value in USDS binary: " << *((uint32_t*)source);
			*destination = (int16_t)(*((uint32_t*)source));
			break;
		}
		case USDS_LONG:
		{
			if (*((int64_t*)source) > 32767 || *((int64_t*)source) < -32768)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type int16_t. Value in USDS binary: " << *((int64_t*)source);
			*destination = (int16_t)(*((int64_t*)source));
			break;
		}
		case USDS_ULONG:
		{
			if (*((uint64_t*)source) > 32767)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[-32768, 32767] for type int16_t. Value in USDS binary: " << *((uint64_t*)source);
			*destination = (int16_t)(*((uint64_t*)source));
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from " << UsdsTypes::typeName(usds_type) << " to int16_t";
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeRead") << source << usds_type << destination << msg;
	};

	void usdsTypeRead(uint8_t* source, usdsType usds_type, uint16_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			if (*((int8_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type uint16_t. Value in USDS binary: " << *((int8_t*)source);
			*destination = (uint16_t)*((int8_t*)source);
			break;
		}
		case USDS_UBYTE:
		{
			*destination = *source;
			break;
		}
		case USDS_SHORT:
		{
			if (*((int16_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type uint16_t. Value in USDS binary: " << *((int16_t*)source);
			*destination = (uint16_t)(*((int16_t*)source));
			break;
		}
		case USDS_USHORT:
		{
			*destination = *((uint16_t*)source);
			break;
		}
		case USDS_INT:
		{
			if (*((int32_t*)source) > 65535 || *((int32_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type uint16_t. Value in USDS binary: " << *((int32_t*)source);
			*destination = (uint16_t)(*((int32_t*)source));
			break;
		}
		case USDS_UINT:
		{
			if (*((uint32_t*)source) > 65535)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type uint16_t. Value in USDS binary: " << *((uint32_t*)source);
			*destination = (uint16_t)(*((uint32_t*)source));
			break;
		}
		case USDS_LONG:
		{
			if (*((int64_t*)source) > 65535 || *((int64_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type uint16_t. Value in USDS binary: " << *((int64_t*)source);
			*destination = (uint16_t)(*((int64_t*)source));
			break;
		}
		case USDS_ULONG:
		{
			if (*((uint64_t*)source) > 65535)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range[0, 65535] for type uint16_t. Value in USDS binary: " << *((uint64_t*)source);
			*destination = (uint16_t)(*((uint64_t*)source));
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from " << UsdsTypes::typeName(usds_type) << " to uint16_t";
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeRead") << source << usds_type << destination << msg;
	};

	void usdsTypeRead(uint8_t* source, usdsType usds_type, int32_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			*destination = *((int8_t*)source);
			break;
		}
		case USDS_UBYTE:
		{
			*destination = *source;
			break;
		}
		case USDS_SHORT:
		{
			*destination = *((int16_t*)source);
			break;
		}
		case USDS_USHORT:
		{
			*destination = *((uint16_t*)source);
			break;
		}
		case USDS_INT:
		{
			*destination = *((int32_t*)source);
			break;
		}
		case USDS_UINT:
		{
			if (*((uint32_t*)source) > INT32_MAX)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [-2147483648, 2147483647] for type int32_t. Value in USDS binary: " << *((uint32_t*)source);
			*destination = (int32_t)(*((uint32_t*)source));
			break;
		}
		case USDS_LONG:
		{
			if (*((int64_t*)source) > INT32_MAX || *((int64_t*)source) < INT32_MIN)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [-2147483648, 2147483647] for type int32_t. Value in USDS binary: " << *((int64_t*)source);
			*destination = (int32_t)(*((int64_t*)source));
			break;
		}
		case USDS_ULONG:
		{
			if (*((uint64_t*)source) > INT32_MAX)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [-2147483648, 2147483647] for type int32_t. Value in USDS binary: " << *((uint64_t*)source);
			*destination = (int32_t)(*((uint64_t*)source));
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from " << UsdsTypes::typeName(usds_type) << " to int32_t";
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeRead") << source << usds_type << destination << msg;
	};

	void usdsTypeRead(uint8_t* source, usdsType usds_type, uint32_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			if (*((int8_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, 4294967295] for type uint32_t. Value in USDS binary: " << *((int8_t*)source);
			*destination = (uint32_t)*((int8_t*)source);
			break;
		}
		case USDS_UBYTE:
		{
			*destination = *source;
			break;
		}
		case USDS_SHORT:
		{
			if (*((int16_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, 4294967295] for type uint32_t. Value in USDS binary: " << *((int16_t*)source);
			*destination = (uint32_t)(*((int16_t*)source));
			break;
		}
		case USDS_USHORT:
		{
			*destination = *((uint16_t*)source);
			break;
		}
		case USDS_INT:
		{
			if (*((int32_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, 4294967295] for type uint32_t. Value in USDS binary: " << *((int32_t*)source);
			*destination = (uint32_t)(*((int32_t*)source));
			break;
		}
		case USDS_UINT:
		{
			*destination = *((uint32_t*)source);
			break;
		}
		case USDS_LONG:
		{
			if (*((int64_t*)source) > UINT32_MAX || *((int64_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, 4294967295] for type uint32_t. Value in USDS binary: " << *((int64_t*)source);
			*destination = (uint32_t)(*((int64_t*)source));
			break;
		}
		case USDS_ULONG:
		{
			if (*((uint64_t*)source) > UINT32_MAX)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, 4294967295] for type uint32_t. Value in USDS binary: " << *((uint64_t*)source);
			*destination = (uint32_t)(*((uint64_t*)source));
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from " << UsdsTypes::typeName(usds_type) << " to uint32_t";

		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeRead") << source << usds_type << destination << msg;
	};

	void usdsTypeRead(uint8_t* source, usdsType usds_type, int64_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			*destination = *((int8_t*)source);
			break;
		}
		case USDS_UBYTE:
		{
			*destination = *source;
			break;
		}
		case USDS_SHORT:
		{
			*destination = *((int16_t*)source);
			break;
		}
		case USDS_USHORT:
		{
			*destination = *((uint16_t*)source);
			break;
		}
		case USDS_INT:
		{
			*destination = *((int32_t*)source);
			break;
		}
		case USDS_UINT:
		{
			*destination = *((uint32_t*)source);
			break;
		}
		case USDS_LONG:
		{
			*destination = *((int64_t*)source);
			break;
		}
		case USDS_ULONG:
		{
			if (*((uint64_t*)source) > INT64_MAX)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [-(2^63), (2^63–1)] for type int64_t. Value in USDS binary: " << *((uint64_t*)source);
			*destination = (int64_t)(*((uint64_t*)source));
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from " << UsdsTypes::typeName(usds_type) << " to int64_t";

		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeRead") << source << usds_type << destination << msg;
	};

	void usdsTypeRead(uint8_t* source, usdsType usds_type, uint64_t* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_BYTE:
		{
			if (*((int8_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, (2^64-1)] for type uint64_t. Value in USDS binary: " << *((int8_t*)source);
			*destination = (uint64_t)*((int8_t*)source);
			break;
		}
		case USDS_UBYTE:
		{
			*destination = *source;
			break;
		}
		case USDS_SHORT:
		{
			if (*((int16_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, (2^64-1)] for type uint64_t. Value in USDS binary: " << *((int16_t*)source);
			*destination = (uint64_t)(*((int16_t*)source));
			break;
		}
		case USDS_USHORT:
		{
			*destination = *((uint16_t*)source);
			break;
		}
		case USDS_INT:
		{
			if (*((int32_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, (2^64-1)] for type uint64_t. Value in USDS binary: " << *((int32_t*)source);
			*destination = (uint64_t)(*((int32_t*)source));
			break;
		}
		case USDS_UINT:
		{
			*destination = *((uint32_t*)source);
			break;
		}
		case USDS_LONG:
		{
			if (*((int64_t*)source) < 0)
				throw ErrorMessage(ERROR_VALUE_CONVERSION) << "Value must be in range [0, (2^64-1)] for type uint64_t. Value in USDS binary: " << *((int64_t*)source);
			*destination = (uint64_t)(*((int64_t*)source));
			break;
		}
		case USDS_ULONG:
		{
			*destination = *((uint64_t*)source);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from " << UsdsTypes::typeName(usds_type) << " to int64_t";
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeRead") << source << usds_type << destination << msg;
	};

	void usdsTypeRead(uint8_t* source, usdsType usds_type, float* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_FLOAT:
		{
			*destination = *((float*)source);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from " << UsdsTypes::typeName(usds_type) << " to float";
		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeRead") << source << usds_type << destination << msg;
	};

	void usdsTypeRead(uint8_t* source, usdsType usds_type, double* destination) throw(...)
	try
	{
		switch (usds_type)
		{
		case USDS_FLOAT:
		{
			*destination = *((float*)source);
			break;
		}
		case USDS_DOUBLE:
		{
			*destination = *((double*)source);
			break;
		}
		default:
			throw ErrorMessage(UNSUPPORTED_TYPE_CONVERSION) << "Unsupported conversion: from " << UsdsTypes::typeName(usds_type) << " to double";

		}
	}
	catch (ErrorMessage& msg)
	{
		throw ErrorStack("usdsTypeRead") << source << usds_type << destination << msg;
	};
}
