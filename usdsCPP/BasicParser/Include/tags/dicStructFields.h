#ifndef DIC_STRUCT_FIELDS
#define DIC_STRUCT_FIELDS

#include <string>
#include <vector>

#include "base\usdsErrors.h"
#include "base\usdsBinaryOutput.h"

#include "tags\usdsTypes.h"
#include "tags\dicStructTag.h"
#include "tags\dicBaseField.h"
#include "base\usdsObjectPool.h"

namespace usds
{
	class DicStructTag;
	class DictionaryObjectPool;

	//====================================================================================================================
	// Simple types
	//====================================================================================================================

	class DicBooleanField : public DicBaseField
	{
	public:
		DicBooleanField(DictionaryObjectPool* pool) : DicBaseField(pool) {  };
		~DicBooleanField() {  };

		virtual usdsTypes getType() { return USDS_BOOLEAN; }
		virtual void writeToBinary(BinaryOutput* buff) throw (...);
		virtual void clear();

		void setDefault(bool value);

	private:
		bool isDefault;
		bool defaultValue;

	};


	class DicIntField : public DicBaseField
	{
	public:
		DicIntField(DictionaryObjectPool* pool) : DicBaseField(pool) {  };
		~DicIntField() {  };

		virtual usdsTypes getType() { return USDS_INT; }
		virtual void writeToBinary(BinaryOutput* buff) throw (...);
		virtual void clear();

		void setDefault(int value);

	private:
		bool isDefault;
		int defaultValue;

	};

	class DicLongField : public DicBaseField
	{
	public:
		DicLongField(DictionaryObjectPool* pool) : DicBaseField(pool) {  };
		~DicLongField() {  };

		virtual usdsTypes getType() { return USDS_LONG; }
		virtual void writeToBinary(BinaryOutput* buff) throw (...);
		virtual void clear();

		void setDefault(long long value);

	private:
		bool isDefault;
		long long defaultValue;

	};

	class DicDoubleField : public DicBaseField
	{
	public:
		DicDoubleField(DictionaryObjectPool* pool) : DicBaseField(pool) {  };
		~DicDoubleField() {  };

		virtual usdsTypes getType() { return USDS_DOUBLE; }
		virtual void writeToBinary(BinaryOutput* buff) throw (...);
		virtual void clear();

		void setDefault(double value);

	private:
		bool isDefault;
		double defaultValue;

	};

	class DicUVarintField : public DicBaseField
	{
	public:
		DicUVarintField(DictionaryObjectPool* pool) : DicBaseField(pool) {  };
		~DicUVarintField() {  };

		virtual usdsTypes getType() { return USDS_UNSIGNED_VARINT; }
		virtual void writeToBinary(BinaryOutput* buff) throw (...);
		virtual void clear();

		void setDefault(long long value);

	private:
		bool isDefault;
		unsigned long long defaultValue;

	};

	//====================================================================================================================
	// Array
	//====================================================================================================================

	class DicArrayField : public DicBaseField
	{
	public:
		DicArrayField(DictionaryObjectPool* pool) : DicBaseField(pool) {  };
		~DicArrayField() {  };

		virtual usdsTypes getType() { return USDS_ARRAY; }
		virtual void writeToBinary(BinaryOutput* buff) throw (...);
		virtual void clear();

	private:
		int arraySize;
		
		// if it's polymorph array
		bool isPolymorhp;
		std::vector<int> tagIDs;
		
		//if it isn't polymorph
		usdsTypes elementType;

		// if elements is string
		usdsEncodes defaultEncode;

		// if elements is other tag
		int tagID;

	};

	//====================================================================================================================
	// String
	//====================================================================================================================

	class DicStringField : public DicBaseField
	{
	public:
		DicStringField(DictionaryObjectPool* pool) : DicBaseField(pool) {  };
		~DicStringField() {  };

		virtual usdsTypes getType() { return USDS_STRING; }
		virtual void writeToBinary(BinaryOutput* buff) throw (...);
		virtual void clear();

		void setDefault(const char* value);
		void setEncode(usdsEncodes encode) throw(...);


	private:
		bool isDefault;
		std::string defaultValue;
		usdsEncodes defaultEncode;

	};


};

#endif