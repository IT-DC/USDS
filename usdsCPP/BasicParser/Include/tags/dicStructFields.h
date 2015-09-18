#ifndef DIC_STRUCT_FIELDS
#define DIC_STRUCT_FIELDS

#include <string>
#include <vector>

#include "base\usdsErrors.h"
#include "base\usdsBinaryOutput.h"

#include "tags\usdsTypes.h"
#include "tags\dicStructTag.h"

namespace usds
{
	class DicStructTag;

	class DicBaseField
	{
	public:
		DicBaseField(DictionaryObjectPool* pull) { objectPull = pull; };
		virtual ~DicBaseField();

		void init(const char* name, int id, bool optional) throw(...);
		
		std::string* getName();
		int getID();

		virtual usdsTypes getType() = 0;
		virtual void writeToBinary(BinaryOutput buff) throw (...) = 0;

		DicBaseField* getNextField();

	protected:
		std::string fieldName;
		int fieldID;
		bool isOptional;
		
	private:
		DictionaryObjectPool* objectPull;

		DicStructTag* parentTag;
		DicBaseField* nextField;
		DicBaseField* previousField;

	};

	//====================================================================================================================
	// Simple types
	//====================================================================================================================

	class DicBooleanField : public DicBaseField
	{
	public:
		DicBooleanField(DictionaryObjectPool* pull);
		~DicBooleanField();

		usdsTypes getType() { return USDS_BOOLEAN; }
		void writeToBinary(BinaryOutput buff) throw (...);

	private:
		bool isDefault;
		int defaultValue;

	};


	class DicIntField : public DicBaseField
	{
	public:
		DicIntField(DictionaryObjectPool* pull);
		~DicIntField();

		usdsTypes getType() { return USDS_INT; }
		void writeToBinary(BinaryOutput buff) throw (...);

	private:
		bool isDefault;
		int defaultValue;

	};

	class DicLongField : public DicBaseField
	{
	public:
		DicLongField(DictionaryObjectPool* pull);
		~DicLongField();

		usdsTypes getType() { return USDS_LONG; }
		void writeToBinary(BinaryOutput buff) throw (...);

	private:
		bool isDefault;
		long long defaultValue;

	};

	class DicDoubleField : public DicBaseField
	{
	public:
		DicDoubleField(DictionaryObjectPool* pull);
		~DicDoubleField();

		usdsTypes getType() { return USDS_DOUBLE; }
		void writeToBinary(BinaryOutput buff) throw (...);

	private:
		bool isDefault;
		double defaultValue;

	};

	class DicUVarintField : public DicBaseField
	{
	public:
		DicUVarintField(DictionaryObjectPool* pull);
		~DicUVarintField();

		usdsTypes getType() { return USDS_UNSIGNED_VARINT; }
		void writeToBinary(BinaryOutput buff) throw (...);

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
		DicArrayField(DictionaryObjectPool* pull);
		~DicArrayField();

		usdsTypes getType() { return USDS_ARRAY; }
		void writeToBinary(BinaryOutput buff) throw (...);

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
		DicStringField(DictionaryObjectPool* pull);
		~DicStringField();

		usdsTypes getType() { return USDS_STRING; }
		void writeToBinary(BinaryOutput buff) throw (...);

		void setEncode(usdsEncodes encode) throw(...);

	private:
		bool isDefault;
		std::string defaultValue;
		usdsEncodes defaultEncode;

	};


};

#endif