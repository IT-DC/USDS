#include "tags\dicStructFields.h"
#include "tags\dicBaseField.h"
#include "tags\dicBaseTag.h"
#include "base\usdsBinaryOutput.h"
#include "tags\dicStructTag.h"
#include "base\usdsObjectPool.h"

using namespace usds;

//====================================================================================================================
// Simple types
//====================================================================================================================
// Boolean

DicBooleanField::DicBooleanField(DictionaryObjectPool* pool) : DicBaseField(pool)
{


};

void DicBooleanField::writeToBinary(BinaryOutput* buff) throw (...)
{

};

void DicBooleanField::clear()
{
	isDefault = false;
	
};

void DicBooleanField::setDefault(bool value)
{
	isDefault = true;
	defaultValue = value;
};

//====================================================================================================================
// Integer

DicIntField::DicIntField(DictionaryObjectPool* pool) : DicBaseField(pool)
{


};

void DicIntField::writeToBinary(BinaryOutput* buff) throw (...)
{

};

void DicIntField::clear()
{
	isDefault = false;
};

void DicIntField::setDefault(int value)
{
	isDefault = true;
	defaultValue = value;
};

//====================================================================================================================
// Long

DicLongField::DicLongField(DictionaryObjectPool* pool) : DicBaseField(pool)
{


};

void DicLongField::writeToBinary(BinaryOutput* buff) throw (...)
{

};

void DicLongField::clear()
{
	isDefault = false;
};

void DicLongField::setDefault(long long value)
{
	isDefault = true;
	defaultValue = value;
};

//====================================================================================================================
// Double

DicDoubleField::DicDoubleField(DictionaryObjectPool* pool) : DicBaseField(pool)
{


};

void DicDoubleField::writeToBinary(BinaryOutput* buff) throw (...)
{

};

void DicDoubleField::clear()
{
	isDefault = false;
};

void DicDoubleField::setDefault(double value)
{
	isDefault = true;
	defaultValue = value;
};

//====================================================================================================================
// Unsigned Varint

DicUVarintField::DicUVarintField(DictionaryObjectPool* pool) : DicBaseField(pool)
{


};

void DicUVarintField::writeToBinary(BinaryOutput* buff) throw (...)
{

};

void DicUVarintField::clear()
{
	isDefault = false;
};

void DicUVarintField::setDefault(long long value)
{
	isDefault = true;
	defaultValue = value;
};

//====================================================================================================================
// Array
//====================================================================================================================

DicArrayField::DicArrayField(DictionaryObjectPool* pool) : DicBaseField(pool)
{


};

void DicArrayField::writeToBinary(BinaryOutput* buff) throw (...)
{

};

void DicArrayField::clear()
{
	elementType = USDS_NO_TYPE;
	elementTagIDs.clear();
	elementTagNames.clear();
	elementDefaultEncode = USDS_NO_ENCODE;

	elementTagID = 0;
	elementTagName.clear();

};

void DicArrayField::setElementType(const char* tag_name) throw (...)
{
	elementType = USDS_TAG;
	elementTagName = tag_name;
};

usdsTypes DicArrayField::getElementType() throw (...)
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_INITIALIZED, L"Array field not initialized", L"DicArrayField::getElementType");

	return elementType;
};

int DicArrayField::getElementTagID() throw (...)
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_INITIALIZED, L"Array field isn't initialized", L"DicArrayField::getElementTagID");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_ELEMENT_NOT_TAG, L"Array element isn't tag", L"DicArrayField::getElementTagID");
	if (elementTagID == 0)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_FINISHED, L"Array isn't finished", L"DicArrayField::getElementTagID");
	
	return elementTagID;
};

const char* DicArrayField::getElementTagName() throw (...)
{
	if (elementType == USDS_NO_TYPE)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_NOT_INITIALIZED, L"Array field isn't initialized", L"DicArrayField::getElementTagName");
	if (elementType != USDS_TAG)
		throw ErrorMessage(DIC_STRUCT_FIELD_ARRAY_ELEMENT_NOT_TAG, L"Array element isn't tag", L"DicArrayField::getElementTagName");

	return elementTagName.c_str();
};

void DicArrayField::finalizeField(DicBaseTag* first_tag) throw (...)
{


};


//====================================================================================================================
// String
//====================================================================================================================

DicStringField::DicStringField(DictionaryObjectPool* pool) : DicBaseField(pool)
{


};

void DicStringField::writeToBinary(BinaryOutput* buff) throw (...)
{


};

void DicStringField::clear()
{
	isDefault = false;
	defaultEncode = USDS_NO_ENCODE;

};

void DicStringField::setDefault(const char* value)
{
	isDefault = true;
	defaultValue = value;
};

void DicStringField::setEncode(usdsEncodes encode) throw(...)
{
	defaultEncode = encode;
};

usdsEncodes DicStringField::getEncode() throw(...)
{

	return defaultEncode;
};