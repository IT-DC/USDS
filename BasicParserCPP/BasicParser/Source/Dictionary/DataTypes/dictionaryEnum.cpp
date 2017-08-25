#include "dictionary/dataTypes/dictionaryEnum.h"

#include "dictionary/usdsDictionary.h"

// for strcmp
#pragma warning(disable : 4996)

using namespace usds;

DictionaryEnum::DictionaryEnum(Dictionary* dict) : DictionaryBaseType(dict)
{
	enumerators = 0;
	enumeratorBufferSize = 32;
	enumerators = new Enumerator[enumeratorBufferSize];
	enumeratorNumbers = 0;

	index = 0;
	indexBufferSize = 0;
};

DictionaryEnum::~DictionaryEnum()
{
	if (enumerators != 0)
		delete[] enumerators;
	if (index != 0)
		delete[] index;
};

void DictionaryEnum::setSubtype(usdsType subtype, bool is_bigendian)
try
{
	if (isFinalized)
		throw ErrorMessage(DIC_ENUM__ALREADY_FINALIZED, "Object is already finalized");

	if (enumeratorNumbers != 0 || isDefault == true)
		throw ErrorMessage(DIC_ENUM__ENUMERATORS_ALREADY_INITIALIZED, "Can not set Subtype: enumerators or Default value were already initialized");

	if ((subtype < USDS_BYTE || subtype > USDS_LONG) && subtype != USDS_VARINT)
		throw ErrorMessage(DIC_ENUM__UNSUPPORTED_SUBTYPE, "Unsupported subtype '") << UsdsTypes::typeName(subtype) << "'. Use: BYTE, UBYTE, SHORT, USHORT, INT, UINT, LONG or VARINT";

	if (subtype == USDS_VARINT && is_bigendian == true)
		throw ErrorMessage(DIC_ENUM__UNSUPPORTED_SUBTYPE, "VARINT can not be BIGENDIAN");

	subType = subtype;
	isBigendian = is_bigendian;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryEnum::setSubtype") << subtype << is_bigendian << msg;
};

usdsType DictionaryEnum::getSubtype()
{
	return subType;
};

bool DictionaryEnum::isSubtypeBigendian()
{
	return isBigendian;
};

void DictionaryEnum::addEnumerator(int64_t value, const char* name, size_t name_size) throw(...)
try
{
	if (isFinalized)
		throw ErrorMessage(DIC_ENUM__ALREADY_FINALIZED, "Object is already finalized");
	
	if (name == 0)
		throw ErrorMessage(DIC_ENUM__NULL_NAME, "Name can not be NULL");

	// check value for subtype
	// It will throw if a value error
	if (subType != USDS_VARINT && subType != USDS_LONG)
	{
		int64_t tmp = 0;
		usdsTypeWrite(value, subType, (uint8_t*)(&tmp));
	}

	if (enumeratorNumbers == 0)
	{
		enumeratorMinValue = value;
		enumeratorMaxValue = value;
	}
	else
	{
		for (size_t i = 0; i < enumeratorNumbers; i++)
			if (enumerators[i].value == value)
				throw ErrorMessage(DIC_ENUM__NOT_UNIQUE_VALUE, "Value is not unique: ") << value;
		
		if (value > enumeratorMaxValue)
			enumeratorMaxValue = value;
		if (value < enumeratorMinValue)
			enumeratorMinValue = value;
	}

	if (enumeratorBufferSize < enumeratorNumbers + 1)
	{
		size_t new_buffer_size = enumeratorBufferSize + 32;
		Enumerator* new_buffer = 0;
		try
		{
			new_buffer = new Enumerator[new_buffer_size];
		}
		catch(...)
		{
			throw ErrorMessage(DIC_ENUM__OUT_OF_MEMORY, "Out of memory (heap)");
		}
		memcpy(new_buffer, enumerators, sizeof(Enumerator)*enumeratorBufferSize);
		delete[] enumerators;
		enumerators = new_buffer;
		enumeratorBufferSize = new_buffer_size;
	}

	enumerators[enumeratorNumbers].value = value;

	if (name_size != 0)
	{
		if (name_size > 512 - sizeof(int64_t) - 1)
			throw ErrorMessage(DIC_ENUM__TOO_LONG_ENUMERATOR_NAME, "To long enumerator name: ") << name_size << ". Max = " << (512 - sizeof(int64_t) - 1);

		for (size_t i = 0; i < enumeratorNumbers; i++)
			if (strncmp(name, enumerators[i].name, name_size) == 0)
				throw ErrorMessage(DIC_ENUM__NOT_UNIQUE_NAME, "Name is not unique: '").addString(name, name_size) << "'";

		strncpy(enumerators[enumeratorNumbers].name, name, name_size);
		enumerators[enumeratorNumbers].name[name_size] = 0;
		if (strlen(enumerators[enumeratorNumbers].name) == 0)
			throw ErrorMessage(DIC_ENUM__NULL_NAME, "Name can not be empty");
	}
	else
	{
		if (strlen(name) > 512 - sizeof(int64_t) - 1)
			throw ErrorMessage(DIC_ENUM__TOO_LONG_ENUMERATOR_NAME, "To long enumerator name: ") << name_size << ". Max = " << (512 - sizeof(int64_t) - 1);

		for (size_t i = 0; i < enumeratorNumbers; i++)
			if (strcmp(name, enumerators[i].name) == 0)
				throw ErrorMessage(DIC_ENUM__NOT_UNIQUE_NAME, "Name is not unique: '") << name << "'";

		strcpy(enumerators[enumeratorNumbers].name, name);
	}

	lastAddedEnumerator = value;
	enumeratorNumbers++;
}
catch (ErrorMessage& msg)
{
	throw (ErrorStack("DictionaryEnum::addEnumerator") << value).addStringAndSize(name, name_size) << msg;
}
catch (ErrorStack err)
{
	(err.addLevel("DictionaryEnum::addEnumerator") << value).addStringAndSize(name, name_size);
	throw;
};

int64_t DictionaryEnum::addEnumerator(const char* name, size_t name_size) throw(...)
try
{
	addEnumerator(lastAddedEnumerator + 1, name, name_size);
	return lastAddedEnumerator;
}
catch (ErrorStack err)
{
	err.addLevel("DictionaryEnum::addEnumerator").addStringAndSize(name, name_size);
	throw;
};

const char* DictionaryEnum::getEnumerator(int64_t value)
try
{
	if (enumeratorNumbers == 0)
		throw ErrorMessage(DIC_ENUM__ENUMERATORS_NOT_INITIALIZED, "Enumerators are not initialized");

	if (value > enumeratorMaxValue || value < enumeratorMinValue)
		return 0;

	if (isIndexUsed)
	{
		Enumerator* val = index[value - enumeratorMinValue];
		if (val == 0)
			return 0;
		else
			return val->name;
	}
	else
	{
		for (size_t i = 0; i < enumeratorNumbers; i++)
			if (enumerators[i].value == value)
				return enumerators[i].name;
	}

	return 0;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryEnum::getEnumerator") << value << msg;
}
catch (ErrorStack err)
{
	err.addLevel("DictionaryEnum::getEnumerator") << value;
	throw;
};

int64_t DictionaryEnum::getValue(const char* name)
try
{
	for (size_t i = 0; i < enumeratorNumbers; i++)
		if (strcmp(enumerators[i].name, name) == 0)
			return enumerators[i].value;

	throw ErrorMessage(DIC_ENUM__ENUMERATOR_NOT_FOUND, "Enumerator '") << name << "' not found";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryEnum::getValue") << name << msg;
}
catch (ErrorStack err)
{
	err.addLevel("DictionaryEnum::getValue") << name;
	throw;
};

int64_t DictionaryEnum::getValue(const char* name, size_t name_size)
try
{
	for (size_t i = 0; i < enumeratorNumbers; i++)
		if (strncmp(enumerators[i].name, name, name_size) == 0)
			return enumerators[i].value;

	throw ErrorMessage(DIC_ENUM__ENUMERATOR_NOT_FOUND, "Enumerator '").addString(name, name_size) << "' not found";
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryEnum::getValue").addStringAndSize(name, name_size) << msg;
}
catch (ErrorStack err)
{
	err.addLevel("DictionaryEnum::getValue").addStringAndSize(name, name_size);
	throw;
};

void DictionaryEnum::finalize() throw (...)
try
{
	if (isFinalized)
		throw ErrorMessage(DIC_ENUM__ALREADY_FINALIZED, "Object is already finalized");

	if (enumeratorNumbers == 0)
		throw ErrorMessage(DIC_ENUM__ENUMERATORS_NOT_INITIALIZED, "Enumerators are not initialized");

	isFinalized = true;

	size_t index_new_size = (size_t)(enumeratorMaxValue - enumeratorMinValue + 1);

	// too rarefied for indexing
	if (index_new_size > 1024)
		if (index_new_size > (enumeratorNumbers * 4))
			return;

	if (index_new_size > indexBufferSize)
	{
		if (index != 0)
			delete[] index;
		indexBufferSize = index_new_size;
		try
		{
			index = new Enumerator*[indexBufferSize];
		}
		catch (...)
		{
			throw ErrorMessage(DIC_ENUM__OUT_OF_MEMORY, "Out of memory (heap)");
		}
	}
	
	for (size_t i = 0; i < indexBufferSize; i++)
		index[i] = 0;

	for (size_t i = 0; i < enumeratorNumbers; i++)
		index[(enumerators[i].value - enumeratorMinValue)] = &(enumerators[i]);

	isIndexUsed = true;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryEnum::finalize") << msg;
}
catch (ErrorStack err)
{
	err.addLevel("DictionaryEnum::finalize");
	throw;
};

bool DictionaryEnum::isIndexed()
{
	return isIndexUsed;
}

void DictionaryEnum::setDefaultValue(int64_t value)
try
{
	if (isFinalized)
		throw ErrorMessage(DIC_ENUM__ALREADY_FINALIZED, "Object is already finalized");

	// check value for subtype
	// It will throw if a value error
	if (subType != USDS_VARINT && subType != USDS_LONG)
	{
		int64_t tmp = 0;
		usdsTypeWrite(value, subType, (uint8_t*)(&tmp));
	}

	defaultValue = value;
	isDefault = true;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryEnum::setDefaultValue") << value << msg;
}
catch (ErrorStack err)
{
	err.addLevel("DictionaryEnum::setDefaultValue") << value;
	throw;
}

void DictionaryEnum::setDefaultFromUTF8(const char* name)
try
{
	if (isFinalized)
		throw ErrorMessage(DIC_ENUM__ALREADY_FINALIZED, "Object is already finalized");

	defaultValue = getValue(name);
	isDefault = true;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryEnum::setDefaultFromUTF8") << name << msg;
}
catch (ErrorStack err)
{
	err.addLevel("DictionaryEnum::setDefaultFromUTF8") << name;
	throw;
};

void DictionaryEnum::setDefaultFromUTF8(const char* name, size_t size)
try
{
	if (isFinalized)
		throw ErrorMessage(DIC_ENUM__ALREADY_FINALIZED, "Object is already finalized");

	defaultValue = getValue(name, size);
	isDefault = true;
}
catch (ErrorMessage& msg)
{
	throw ErrorStack("DictionaryEnum::setDefaultFromUTF8").addStringAndSize(name, size) << msg;
}
catch (ErrorStack err)
{
	err.addLevel("DictionaryEnum::setDefaultFromUTF8").addStringAndSize(name, size);
	throw;
};


int64_t DictionaryEnum::getDefaultValue()
{
	return defaultValue;
}

const char* DictionaryEnum::getDefaultAsUTF8() throw (...)
try
{
	return getEnumerator(defaultValue);
}
catch (ErrorStack err)
{
	err.addLevel("DictionaryEnum::getDefaultAsUTF8");
	throw;
};

const char* DictionaryEnum::getDefaultAsUTF8(size_t* byte_size) throw (...)
try
{
	const char* value = getEnumerator(defaultValue);
	if (value == 0)
	{
		byte_size = 0;
		return 0;
	}
	else
	{
		*byte_size = strlen(value);
		return value;
	}
}
catch (ErrorStack err)
{
	err.addLevel("DictionaryEnum::getDefaultAsUTF8");
	throw;
};

bool DictionaryEnum::hasDefaultValue()
{
	return isDefault;
}


void DictionaryEnum::additionalInitType()
{
	if (dictionary != 0)
	{
		subType = dictionary->getDefaultEnumSubtype();
		isBigendian = dictionary->isDefaultEnumSubtypeBigendian();
	}
	else
	{
		subType = USDS_VARINT;
		isBigendian = false;
	}

	isDefault = false;
	
	enumeratorNumbers = 0;
	lastAddedEnumerator = 0;
	isIndexUsed = false;

	isFinalized = false;
};

