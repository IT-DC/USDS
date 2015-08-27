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
		DicBaseField();
		virtual ~DicBaseField();

		void init(const char* name, int id, bool optional) throw(...);
		
		virtual usdsTypes getType() = 0;
		std::string* getName();
		int getID();

		virtual void writeToBinary(BinaryOutput buff) throw (...) = 0;

		DicBaseField* getNextField();

	protected:
		std::string fieldName;
		int fieldID;
		bool isOptional;
		
	private:
		DicStructTag* parentTag;
		DicBaseField* nextField;
		DicBaseField* previousField;

	};

	//====================================================================================================================
	// Simple types
	//====================================================================================================================

	class DicIntField : public DicBaseField
	{
	public:
		DicIntField();
		~DicIntField();

	private:
		bool isDefault;
		int defaultValue;

	};

	class DicLongField : public DicBaseField
	{
	public:
		DicLongField();
		~DicLongField();

	private:
		bool isDefault;
		long long defaultValue;

	};

	class DicDoubleField : public DicBaseField
	{
	public:
		DicDoubleField();
		~DicDoubleField();

	private:
		bool isDefault;
		double defaultValue;

	};

	class DicUVarintField : public DicBaseField
	{
	public:
		DicUVarintField();
		~DicUVarintField();

	private:
		bool isDefault;
		unsigned long long defaultValue;

	};

	//====================================================================================================================
	// String
	//====================================================================================================================

	class DicStringField : public DicBaseField
	{
	public:
		DicStringField();
		~DicStringField();

		void setEncode(usdsEncodes encode) throw(...);

	private:
		bool isDefault;
		std::string defaultValue;
		usdsEncodes defaultEncode;

	};

	//====================================================================================================================
	// Array
	//====================================================================================================================

	class DicArrayField : public DicBaseField
	{
	public:
		DicArrayField();
		~DicArrayField();

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

};

#endif