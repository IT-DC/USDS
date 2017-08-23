#include "dictionary/dataTypes/dictionaryEnum.h"

#include "dictionary/usdsDictionary.h"

using namespace usds;

DictionaryEnum::DictionaryEnum(Dictionary* dict) : DictionaryBaseType(dict)
{
	enumerators = 0;
	enumeratorBufferSize = 16;
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
	if (enumeratorNumbers != 0)
		throw ErrorMessage(DIC_ENUM__TOO_LONG_ENUMERATOR_NAME, "Can not set Subtype: enumerators were already initialized");
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
	if (name == 0)
		throw ErrorMessage(DIC_ENUM__NULL_NAME, "Name can not be NULL");

	if (enumeratorNumbers == 0)
	{
		enumeratorMinValue = value;
		enumeratorMaxValue = value;
	}

	if (enumeratorBufferSize < enumeratorNumbers + 1)
	{
		Enumerator* new_buffer = new Enumerator[enumeratorBufferSize + 16];
		memcpy(new_buffer, enumerators, sizeof(Enumerator)*enumeratorBufferSize);
		delete[] enumerators;
		enumerators = new_buffer;
	}

	enumerators[enumeratorNumbers].value = 0;
	usdsTypeWrite(value, subType, (uint8_t*)(&(enumerators[enumeratorNumbers].value));

	if (name_size != 0)
	{
		if (name_size > 512 - sizeof(int64_t) - 1)
			throw ErrorMessage(DIC_ENUM__TOO_LONG_ENUMERATOR_NAME, "To long enumerator name: ") << name_size << ". Max = " << (512 - sizeof(int64_t) - 1);
		if (name[name_size] == 0)
			name_size = name_size - 1;
		if (name_size == 0)
			throw ErrorMessage(DIC_ENUM__NULL_NAME, "Name can not be empty");
		strncpy(enumerators[enumeratorNumbers].name, name, name_size);
		enumerators[enumeratorNumbers].name[name_size] = 0;
	}
	else
	{
		if (strlen(name) > 512 - sizeof(int64_t) - 1)
			throw ErrorMessage(DIC_ENUM__TOO_LONG_ENUMERATOR_NAME, "To long enumerator name: ") << name_size << ". Max = " << (512 - sizeof(int64_t) - 1);
		strcpy(enumerators[enumeratorNumbers].name, name);
	}

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


void DictionaryEnum::setDefaultValue(int64_t value)
try
{
	if (subType != USDS_VARINT)
	{
		defaultValue = 0;
		usdsTypeWrite(value, subType, (uint8_t*)(&defaultValue));
	}
	else
		defaultValue = value;

	isDefault = true;
}
catch (ErrorStack err)
{
	err.addLevel("DictionaryEnum::setDefaultValue") << value;
	throw;
}

int64_t DictionaryEnum::getDefaultValue()
{
	return defaultValue;
}

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
	isIndexUsed = false;
};

