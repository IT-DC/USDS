#ifndef DIC_STRUCT_FIELDS
#define DIC_STRUCT_FIELDS

#include <string>
#include <vector>

#include "tags\usdsTypes.h"
#include "base\usdsErrors.h"

#include "tags\dicBaseField.h"

namespace usds
{
	class DictionaryObjectPool;
	class BinaryOutput;

	//====================================================================================================================
	// Simple types
	//====================================================================================================================

	class DicBooleanField : public DicBaseField
	{
	public:
		DicBooleanField(DictionaryObjectPool* pool);
		~DicBooleanField() {  };

		virtual usdsTypes getType() { return USDS_BOOLEAN; };
		virtual const char* getTypeName() { return "boolean"; };
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
		DicIntField(DictionaryObjectPool* pool);
		~DicIntField() {  };

		virtual usdsTypes getType() { return USDS_INT; };
		virtual const char* getTypeName() { return "int"; };
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
		DicLongField(DictionaryObjectPool* pool);
		~DicLongField() {  };

		virtual usdsTypes getType() { return USDS_LONG; };
		virtual const char* getTypeName() { return "long"; };
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
		DicDoubleField(DictionaryObjectPool* pool);
		~DicDoubleField() {  };

		virtual usdsTypes getType() { return USDS_DOUBLE; };
		virtual const char* getTypeName() { return "double"; };
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
		DicUVarintField(DictionaryObjectPool* pool);
		~DicUVarintField() {  };

		virtual usdsTypes getType() { return USDS_UNSIGNED_VARINT; };
		virtual const char* getTypeName() { return "unsigned varint"; };
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
		DicArrayField(DictionaryObjectPool* pool);
		~DicArrayField() {  };

		virtual usdsTypes getType() { return USDS_ARRAY; };
		virtual const char* getTypeName() { return "array"; };
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
		DicStringField(DictionaryObjectPool* pool);
		~DicStringField() {  };

		virtual usdsTypes getType() { return USDS_STRING; };
		virtual const char* getTypeName() { return "string"; };
		virtual void writeToBinary(BinaryOutput* buff) throw (...);
		virtual void clear();

		void setDefault(const char* value);
		void setEncode(usdsEncodes encode) throw(...);

		usdsEncodes getEncode() throw(...);


	private:
		bool isDefault;
		std::string defaultValue;
		usdsEncodes defaultEncode;

	};


};

#endif