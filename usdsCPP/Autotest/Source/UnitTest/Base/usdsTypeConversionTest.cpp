#include "usdsAutotest.h"

#include "usdsTypeConverter.h"

void UsdsTypeConversionTest::test_1()
{
	uint8_t value = 100;

	// step 1
	int8_t dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		if (value != dest_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	value = 200;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t dest_uint8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, &dest_uint8_value);
		if (value != dest_uint8_value)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	};


	// step 4
	int32_t dest_int32_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		if (value != dest_int32_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	int64_t dest_int64_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_LONG, (uint8_t*)&dest_int64_value);
		if (value != dest_int64_value)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	};
	
	// step 6
	try
	{
		usdsTypeWrite(value, usds::USDS_DOUBLE, (uint8_t*)&dest_int64_value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 6\n";
		}
	}
}

void UsdsTypeConversionTest::test_2()
{
	int8_t value = 100;

	// step 1
	int8_t dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		if (value != dest_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	uint8_t dest_uint8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, &dest_uint8_value);
		if (value != dest_uint8_value)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	};

	// step 3
	value = -5;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, (uint8_t*)&dest_uint8_value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	int32_t dest_int32_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		if (value != dest_int32_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	int64_t dest_int64_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_LONG, (uint8_t*)&dest_int64_value);
		if (value != dest_int64_value)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	};

	// step 6
	try
	{
		usdsTypeWrite(value, usds::USDS_DOUBLE, (uint8_t*)&dest_int64_value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 6\n";
		}
	}
};

void UsdsTypeConversionTest::test_3()
{
	int16_t value = 100;

	// step 1
	int8_t dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		if (value != dest_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	value = -1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	value = 200;
	uint8_t dest_uint8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, &dest_uint8_value);
		if (value != dest_uint8_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, (uint8_t*)&dest_uint8_value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	value = -1;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, (uint8_t*)&dest_uint8_value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	int32_t dest_int32_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		if (value != dest_int32_value)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	};

	// step 8
	int64_t dest_int64_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_LONG, (uint8_t*)&dest_int64_value);
		if (value != dest_int64_value)
			throw "Failed at the step 8\n";
	}
	catch (...)
	{
		throw "Failed at the step 8\n";
	};

	// step 9
	try
	{
		usdsTypeWrite(value, usds::USDS_DOUBLE, (uint8_t*)&dest_int64_value);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 9\n";
		}
	}
};

void UsdsTypeConversionTest::test_4()
{
	uint16_t value = 100;

	// step 1
	int8_t dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		if (value != dest_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	value = 200;
	uint8_t dest_uint8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, &dest_uint8_value);
		if (value != dest_uint8_value)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	};

	// step 4
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, (uint8_t*)&dest_uint8_value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	int32_t dest_int32_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		if (value != dest_int32_value)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	};

	// step 6
	int64_t dest_int64_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_LONG, (uint8_t*)&dest_int64_value);
		if (value != dest_int64_value)
			throw "Failed at the step 6\n";
	}
	catch (...)
	{
		throw "Failed at the step 6\n";
	};

	// step 7
	try
	{
		usdsTypeWrite(value, usds::USDS_DOUBLE, (uint8_t*)&dest_int64_value);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 7\n";
		}
	}
};

void UsdsTypeConversionTest::test_5()
{
	int32_t value = 100;

	// step 1
	int8_t dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		if (value != dest_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	value = -1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	value = 200;
	uint8_t dest_uint8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, &dest_uint8_value);
		if (value != dest_uint8_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, (uint8_t*)&dest_uint8_value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	value = -1;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, (uint8_t*)&dest_uint8_value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	int32_t dest_int32_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		if (value != dest_int32_value)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	};

	// step 8
	int64_t dest_int64_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_LONG, (uint8_t*)&dest_int64_value);
		if (value != dest_int64_value)
			throw "Failed at the step 8\n";
	}
	catch (...)
	{
		throw "Failed at the step 8\n";
	};

	// step 9
	try
	{
		usdsTypeWrite(value, usds::USDS_DOUBLE, (uint8_t*)&dest_int64_value);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 9\n";
		}
	}
};

void UsdsTypeConversionTest::test_6()
{
	uint32_t value = 100;

	// step 1
	int8_t dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		if (value != dest_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	value = 200;
	uint8_t dest_uint8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, &dest_uint8_value);
		if (value != dest_uint8_value)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	};

	// step 4
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, (uint8_t*)&dest_uint8_value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	int32_t dest_int32_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		if (value != dest_int32_value)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	};

	// step 6
	value = UINT32_MAX;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	int64_t dest_int64_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_LONG, (uint8_t*)&dest_int64_value);
		if (value != dest_int64_value)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	};

	// step 8
	try
	{
		usdsTypeWrite(value, usds::USDS_DOUBLE, (uint8_t*)&dest_int64_value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 8\n";
		}
	}
};

void UsdsTypeConversionTest::test_7()
{
	int64_t value = 100;

	// step 1
	int8_t dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		if (value != dest_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	value = -1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	value = 200;
	uint8_t dest_uint8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, &dest_uint8_value);
		if (value != dest_uint8_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, (uint8_t*)&dest_uint8_value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	value = -1;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, (uint8_t*)&dest_uint8_value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	int32_t dest_int32_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		if (value != dest_int32_value)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	};

	// step 8
	value = INT64_MAX;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 9
	value = INT64_MIN;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 9\n";
		}
	}

	// step 10
	int64_t dest_int64_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_LONG, (uint8_t*)&dest_int64_value);
		if (value != dest_int64_value)
			throw "Failed at the step 10\n";
	}
	catch (...)
	{
		throw "Failed at the step 10\n";
	};

	// step 11
	try
	{
		usdsTypeWrite(value, usds::USDS_DOUBLE, (uint8_t*)&dest_int64_value);
		throw "Failed at the step 11\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 11\n";
		}
	}
};

void UsdsTypeConversionTest::test_8()
{
	uint64_t value = 100;

	// step 1
	int8_t dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		if (value != dest_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_BYTE, (uint8_t*)&dest_int8_value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	value = 200;
	uint8_t dest_uint8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, &dest_uint8_value);
		if (value != dest_uint8_value)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	};

	// step 4
	value = 1000;
	dest_int8_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_UBYTE, (uint8_t*)&dest_uint8_value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	int32_t dest_int32_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		if (value != dest_int32_value)
			throw "Failed at the step 5\n";
	}
	catch (...)
	{
		throw "Failed at the step 5\n";
	};

	// step 6
	value = UINT32_MAX;
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_int32_value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	int64_t dest_int64_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_LONG, (uint8_t*)&dest_int64_value);
		if (value != dest_int64_value)
			throw "Failed at the step 7\n";
	}
	catch (...)
	{
		throw "Failed at the step 7\n";
	};

	// step 8
	value = UINT64_MAX;
	try
	{
		usdsTypeWrite(value, usds::USDS_LONG, (uint8_t*)&dest_int64_value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 9
	try
	{
		usdsTypeWrite(value, usds::USDS_DOUBLE, (uint8_t*)&dest_int64_value);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 9\n";
		}
	}
};

void UsdsTypeConversionTest::test_9()
{
	float value = 1.25F;

	// step 1
	float dest_float_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_FLOAT, (uint8_t*)&dest_float_value);
		if (value != dest_float_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	double dest_double_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_DOUBLE, (uint8_t*)&dest_double_value);
		if (value != dest_double_value)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	};

	// step 3
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_float_value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}

};

void UsdsTypeConversionTest::test_10()
{
	double value = 1.25;

	// step 1
	double dest_double_value = 0;
	try
	{
		usdsTypeWrite(value, usds::USDS_DOUBLE, (uint8_t*)&dest_double_value);
		if (value != dest_double_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	try
	{
		usdsTypeWrite(value, usds::USDS_FLOAT, (uint8_t*)&dest_double_value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	try
	{
		usdsTypeWrite(value, usds::USDS_INT, (uint8_t*)&dest_double_value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}

}

void UsdsTypeConversionTest::test_11()
{
	int8_t value = 0;

	// step 1
	int8_t source_int8_value = 100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		if (value != source_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	uint8_t source_uint8_value = 101;
	try
	{
		usdsTypeRead((uint8_t*)&source_uint8_value, usds::USDS_UBYTE, &value);
		if (value != source_uint8_value)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	};

	// step 3
	source_uint8_value = 200;
	try
	{
		usdsTypeRead((uint8_t*)&source_uint8_value, usds::USDS_UBYTE, &value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}

	// step 4
	int32_t source_int32_value = 102;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		if (value != source_int32_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	source_int32_value = 200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	source_int32_value = -200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	int64_t source_int64_value = 103;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		if (value != source_int64_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 8
	source_int64_value = 200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 9
	source_int64_value = -200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 9\n";
		}
	}

	// step 10
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_DOUBLE, &value);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 10\n";
		}
	}

}


void UsdsTypeConversionTest::test_12()
{
	uint8_t value = 0;

	// step 1
	int8_t source_int8_value = 100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		if (value != source_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	source_int8_value = -100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t source_uint8_value = 200;
	try
	{
		usdsTypeRead((uint8_t*)&source_uint8_value, usds::USDS_UBYTE, &value);
		if (value != source_uint8_value)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	};

	// step 4
	int32_t source_int32_value = 102;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		if (value != source_int32_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	source_int32_value = 300;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	source_int32_value = -200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	int64_t source_int64_value = 103;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		if (value != source_int64_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 8
	source_int64_value = 300;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 9
	source_int64_value = -200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 9\n";
		}
	}

	// step 10
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_DOUBLE, &value);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 10\n";
		}
	}

}

void UsdsTypeConversionTest::test_13()
{
	int16_t value = 0;

	// step 1
	int8_t source_int8_value = 100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		if (value != source_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	uint8_t source_uint8_value = 101;
	try
	{
		usdsTypeRead((uint8_t*)&source_uint8_value, usds::USDS_UBYTE, &value);
		if (value != source_uint8_value)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	};

	// step 3
	int32_t source_int32_value = 102;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		if (value != source_int32_value)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	};

	// step 4
	source_int32_value = 200000;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		throw "Failed at the step 4\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 4\n";
		}
	}

	// step 5
	source_int32_value = -200000;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	int64_t source_int64_value = 10003;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		if (value != source_int64_value)
			throw "Failed at the step 6\n";
	}
	catch (...)
	{
		throw "Failed at the step 6\n";
	};

	// step 7
	source_int64_value = 200000;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 7\n";
		}
	}

	// step 8
	source_int64_value = -200000;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 9
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_DOUBLE, &value);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 9\n";
		}
	}
}

void UsdsTypeConversionTest::test_14()
{
	uint16_t value = 0;

	// step 1
	int8_t source_int8_value = 100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		if (value != source_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	source_int8_value = -100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t source_uint8_value = 200;
	try
	{
		usdsTypeRead((uint8_t*)&source_uint8_value, usds::USDS_UBYTE, &value);
		if (value != source_uint8_value)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	};

	// step 4
	int32_t source_int32_value = 10002;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		if (value != source_int32_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	source_int32_value = 300000;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	source_int32_value = -200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		throw "Failed at the step 6\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 6\n";
		}
	}

	// step 7
	int64_t source_int64_value = 10003;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		if (value != source_int64_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 8
	source_int64_value = 300000;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 9
	source_int64_value = -200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 9\n";
		}
	}

	// step 10
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_DOUBLE, &value);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 10\n";
		}
	}

}

void UsdsTypeConversionTest::test_15()
{
	int32_t value = 0;

	// step 1
	int8_t source_int8_value = 100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		if (value != source_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	uint8_t source_uint8_value = 101;
	try
	{
		usdsTypeRead((uint8_t*)&source_uint8_value, usds::USDS_UBYTE, &value);
		if (value != source_uint8_value)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	};

	// step 3
	int32_t source_int32_value = 100000002;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		if (value != source_int32_value)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	};

	// step 4
	int64_t source_int64_value = 100000003;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		if (value != source_int64_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	source_int64_value = INT64_MAX;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 8
	source_int64_value = INT64_MIN;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 9
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_DOUBLE, &value);
		throw "Failed at the step 9\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 9\n";
		}
	}
}

void UsdsTypeConversionTest::test_16()
{
	uint32_t value = 0;

	// step 1
	int8_t source_int8_value = 100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		if (value != source_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	source_int8_value = -100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t source_uint8_value = 200;
	try
	{
		usdsTypeRead((uint8_t*)&source_uint8_value, usds::USDS_UBYTE, &value);
		if (value != source_uint8_value)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	};

	// step 4
	int32_t source_int32_value = 10002;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		if (value != source_int32_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	source_int32_value = -200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	int64_t source_int64_value = 4000000000;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		if (value != source_int64_value)
			throw "Failed at the step 6\n";
	}
	catch (...)
	{
		throw "Failed at the step 6\n";
	};

	// step 7
	source_int64_value = INT64_MAX;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 7\n";
		}
	}

	// step 8
	source_int64_value = -200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 8\n";
		}
	}

	// step 10
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_DOUBLE, &value);
		throw "Failed at the step 10\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 10\n";
		}
	}
}

void UsdsTypeConversionTest::test_17()
{
	int64_t value = 0;

	// step 1
	int8_t source_int8_value = 100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		if (value != source_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	uint8_t source_uint8_value = 101;
	try
	{
		usdsTypeRead((uint8_t*)&source_uint8_value, usds::USDS_UBYTE, &value);
		if (value != source_uint8_value)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	};

	// step 3
	int32_t source_int32_value = 100000002;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		if (value != source_int32_value)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	};

	// step 4
	int64_t source_int64_value = 100000003;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		if (value != source_int64_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_DOUBLE, &value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}
}

void UsdsTypeConversionTest::test_18()
{
	uint64_t value = 0;

	// step 1
	int8_t source_int8_value = 100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		if (value != source_int8_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	source_int8_value = -100;
	try
	{
		usdsTypeRead((uint8_t*)&source_int8_value, usds::USDS_BYTE, &value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	uint8_t source_uint8_value = 200;
	try
	{
		usdsTypeRead((uint8_t*)&source_uint8_value, usds::USDS_UBYTE, &value);
		if (value != source_uint8_value)
			throw "Failed at the step 3\n";
	}
	catch (...)
	{
		throw "Failed at the step 3\n";
	};

	// step 4
	int32_t source_int32_value = 10002;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		if (value != source_int32_value)
			throw "Failed at the step 4\n";
	}
	catch (...)
	{
		throw "Failed at the step 4\n";
	};

	// step 5
	source_int32_value = -200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int32_value, usds::USDS_INT, &value);
		throw "Failed at the step 5\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 5\n";
		}
	}

	// step 6
	int64_t source_int64_value = 4000000000;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		if (value != source_int64_value)
			throw "Failed at the step 6\n";
	}
	catch (...)
	{
		throw "Failed at the step 6\n";
	};

	// step 7
	source_int64_value = -200;
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_LONG, &value);
		throw "Failed at the step 7\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::ERROR_VALUE_CONVERSION)
		{
			throw "Failed at the step 7\n";
		}
	}

	// step 8
	try
	{
		usdsTypeRead((uint8_t*)&source_int64_value, usds::USDS_DOUBLE, &value);
		throw "Failed at the step 8\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 8\n";
		}
	}
}

void UsdsTypeConversionTest::test_19()
{
	float value = 0;

	// step 1
	float source_float_value = 1.25F;
	try
	{
		usdsTypeRead((uint8_t*)&source_float_value, usds::USDS_FLOAT, &value);
		if (value != source_float_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	try
	{
		usdsTypeRead((uint8_t*)&source_float_value, usds::USDS_DOUBLE, &value);
		throw "Failed at the step 2\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 2\n";
		}
	}

	// step 3
	try
	{
		usdsTypeRead((uint8_t*)&source_float_value, usds::USDS_LONG, &value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}
}

void UsdsTypeConversionTest::test_20()
{
	double value = 0;

	// step 1
	float source_float_value = 1.25F;
	try
	{
		usdsTypeRead((uint8_t*)&source_float_value, usds::USDS_FLOAT, &value);
		if (value != source_float_value)
			throw "Failed at the step 1\n";
	}
	catch (...)
	{
		throw "Failed at the step 1\n";
	};

	// step 2
	double source_double_value = 1.125;
	try
	{
		usdsTypeRead((uint8_t*)&source_double_value, usds::USDS_DOUBLE, &value);
		if (value != source_double_value)
			throw "Failed at the step 2\n";
	}
	catch (...)
	{
		throw "Failed at the step 2\n";
	};

	// step 3
	try
	{
		usdsTypeRead((uint8_t*)&source_float_value, usds::USDS_LONG, &value);
		throw "Failed at the step 3\n";
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::UNSUPPORTED_TYPE_CONVERSION)
		{
			throw "Failed at the step 3\n";
		}
	}
}



