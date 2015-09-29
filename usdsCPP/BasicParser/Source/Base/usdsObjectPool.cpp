#include "base\usdsObjectPool.h"

#include "tags\dicStructTag.h"
#include "tags\dicStructFields.h"

using namespace usds;

//========================================================================================================

DictionaryObjectPool::DictionaryObjectPool()
{
	tagPoolIndex[USDS_NO_TYPE] = 0;
	tagPoolIndex[USDS_BOOLEAN] = 0;
	tagPoolIndex[USDS_BYTE] = 0;
	tagPoolIndex[USDS_UNSIGNED_BYTE] = 0;
	tagPoolIndex[USDS_SHORT] = 0;
	tagPoolIndex[USDS_UNSIGNED_SHORT] = 0;
	tagPoolIndex[USDS_BIGENDIAN_SHORT] = 0;
	tagPoolIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	tagPoolIndex[USDS_INT] = 0;
	tagPoolIndex[USDS_UNSIGNED_INT] = 0;
	tagPoolIndex[USDS_BIGENDIAN_INT] = 0;
	tagPoolIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	tagPoolIndex[USDS_LONG] = 0;
	tagPoolIndex[USDS_UNSIGNED_LONG] = 0;
	tagPoolIndex[USDS_BIGENDIAN_LONG] = 0;
	tagPoolIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	tagPoolIndex[USDS_INT128] = 0;
	tagPoolIndex[USDS_UNSIGNED_INT128] = 0;
	tagPoolIndex[USDS_BIGENDIAN_INT128] = 0;
	tagPoolIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	tagPoolIndex[USDS_FLOAT] = 0;
	tagPoolIndex[USDS_BIGENDIAN_FLOAT] = 0;
	tagPoolIndex[USDS_DOUBLE] = 0;
	tagPoolIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	tagPoolIndex[USDS_VARINT] = 0;
	tagPoolIndex[USDS_UNSIGNED_VARINT] = 0;
	tagPoolIndex[USDS_STRUCT] = &DictionaryObjectPool::addStructTag;
	tagPoolIndex[USDS_ARRAY] = 0;
	tagPoolIndex[USDS_STRING] = 0;
	tagPoolIndex[USDS_LIST] = 0;
	tagPoolIndex[USDS_MAP] = 0;
	tagPoolIndex[USDS_POLYMORPH] = 0;
	tagPoolIndex[USDS_TAG] = 0;
	
	
	fieldPoolIndex[USDS_NO_TYPE] = 0;
	fieldPoolIndex[USDS_BOOLEAN] = &DictionaryObjectPool::addBooleanField;
	fieldPoolIndex[USDS_BYTE] = 0;
	fieldPoolIndex[USDS_UNSIGNED_BYTE] = 0;
	fieldPoolIndex[USDS_SHORT] = 0;
	fieldPoolIndex[USDS_UNSIGNED_SHORT] = 0;
	fieldPoolIndex[USDS_BIGENDIAN_SHORT] = 0;
	fieldPoolIndex[USDS_BIGENDIAN_UNSIGNED_SHORT] = 0;
	fieldPoolIndex[USDS_INT] = &DictionaryObjectPool::addIntField;
	fieldPoolIndex[USDS_UNSIGNED_INT] = 0;
	fieldPoolIndex[USDS_BIGENDIAN_INT] = 0;
	fieldPoolIndex[USDS_BIGENDIAN_UNSIGNED_INT] = 0;
	fieldPoolIndex[USDS_LONG] = &DictionaryObjectPool::addLongField;
	fieldPoolIndex[USDS_UNSIGNED_LONG] = 0;
	fieldPoolIndex[USDS_BIGENDIAN_LONG] = 0;
	fieldPoolIndex[USDS_BIGENDIAN_UNSIGNED_LONG] = 0;
	fieldPoolIndex[USDS_INT128] = 0;
	fieldPoolIndex[USDS_UNSIGNED_INT128] = 0;
	fieldPoolIndex[USDS_BIGENDIAN_INT128] = 0;
	fieldPoolIndex[USDS_BIGENDIAN_UNSIGNED_INT128] = 0;
	fieldPoolIndex[USDS_FLOAT] = 0;
	fieldPoolIndex[USDS_BIGENDIAN_FLOAT] = 0;
	fieldPoolIndex[USDS_DOUBLE] = &DictionaryObjectPool::addDoubleField;
	fieldPoolIndex[USDS_USDS_BIGENDIAN_DOUBLE] = 0;
	fieldPoolIndex[USDS_VARINT] = 0;
	fieldPoolIndex[USDS_UNSIGNED_VARINT] = &DictionaryObjectPool::addUVarintField;
	fieldPoolIndex[USDS_STRUCT] = 0;
	fieldPoolIndex[USDS_ARRAY] = &DictionaryObjectPool::addArrayField;
	fieldPoolIndex[USDS_STRING] = &DictionaryObjectPool::addStringField;
	fieldPoolIndex[USDS_LIST] = 0;
	fieldPoolIndex[USDS_MAP] = 0;
	fieldPoolIndex[USDS_POLYMORPH] = 0;
	fieldPoolIndex[USDS_TAG] = 0;

};

DictionaryObjectPool::~DictionaryObjectPool()
{

};

DicBaseTag* DictionaryObjectPool::addTag(usdsTypes tag_type, Dictionary* dict, bool root, int id, const char* name, size_t name_size)
{
	return (this->*(tagPoolIndex[tag_type]))(dict, root, id, name, name_size);
};

DicBaseField* DictionaryObjectPool::addField(usdsTypes field_type, Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional)
{
	return (this->*(fieldPoolIndex[field_type]))(dict, tag, id, name, name_size, is_optional);

};

//========================================================================================================

DicBaseTag* DictionaryObjectPool::addStructTag(Dictionary* dict, bool root, int id, const char* name, size_t name_size)
{
	DicStructTag* tag = structTags.addObject();
	tag->init(dict, root, id, name, name_size);
	return tag;
};

//========================================================================================================

DicBaseField* DictionaryObjectPool::addBooleanField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional)
{
	DicBooleanField* field = booleanFields.addObject();
	field->init(dict, tag, id, name, name_size, is_optional);
	return field;
};

DicBaseField* DictionaryObjectPool::addIntField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional)
{
	DicIntField* field = intFields.addObject();
	field->init(dict, tag, id, name, name_size, is_optional);
	return field;
};

DicBaseField* DictionaryObjectPool::addLongField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional)
{
	DicLongField* field = longFields.addObject();
	field->init(dict, tag, id, name, name_size, is_optional);
	return field;
};

DicBaseField* DictionaryObjectPool::addDoubleField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional)
{
	DicDoubleField* field = doubleFields.addObject();
	field->init(dict, tag, id, name, name_size, is_optional);
	return field;
};

DicBaseField* DictionaryObjectPool::addUVarintField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional)
{
	DicUVarintField* field = uVarintFields.addObject();
	field->init(dict, tag, id, name, name_size, is_optional);
	return field;
};

DicBaseField* DictionaryObjectPool::addArrayField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional)
{
	DicArrayField* field = arrayFields.addObject();
	field->init(dict, tag, id, name, name_size, is_optional);
	return field;
};

DicBaseField* DictionaryObjectPool::addStringField(Dictionary* dict, DicStructTag* tag, int id, const char* name, size_t name_size, bool is_optional)
{
	DicStringField* field = stringFields.addObject();
	field->init(dict, tag, id, name, name_size, is_optional);
	return field;
};

//========================================================================================================
void DictionaryObjectPool::clear()
{
	structTags.clearPool();
	
	booleanFields.clearPool();
	intFields.clearPool();
	longFields.clearPool();
	doubleFields.clearPool();
	arrayFields.clearPool();
	stringFields.clearPool();

};