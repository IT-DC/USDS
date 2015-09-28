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
	class DicBaseTag;

	//====================================================================================================================
	// Simple types
	//====================================================================================================================

	class DicBooleanField : public DicBaseField
	{
	public:
		DicBooleanField();
		~DicBooleanField() {  };

		virtual usdsTypes getType() { return USDS_BOOLEAN; };
		virtual const char* getTypeName() { return typeName(USDS_BOOLEAN); };
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
		DicIntField();
		~DicIntField() {  };

		virtual usdsTypes getType() { return USDS_INT; };
		virtual const char* getTypeName() { return typeName(USDS_INT); };
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
		DicLongField();
		~DicLongField() {  };

		virtual usdsTypes getType() { return USDS_LONG; };
		virtual const char* getTypeName() { return typeName(USDS_LONG); };
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
		DicDoubleField();
		~DicDoubleField() {  };

		virtual usdsTypes getType() { return USDS_DOUBLE; };
		virtual const char* getTypeName() { return typeName(USDS_DOUBLE); };
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
		DicUVarintField();
		~DicUVarintField() {  };

		virtual usdsTypes getType() { return USDS_UNSIGNED_VARINT; };
		virtual const char* getTypeName() { return typeName(USDS_UNSIGNED_VARINT); };
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
		DicArrayField();
		~DicArrayField() {  };

		virtual usdsTypes getType() { return USDS_ARRAY; };
		virtual const char* getTypeName() { return typeName(USDS_ARRAY); };
		virtual void writeToBinary(BinaryOutput* buff) throw (...);
		virtual void clear();

		void setElementAsTag(const char* tag_name, size_t name_size) throw (...);
		void setElementAsTag(int tag_id) throw (...);

		usdsTypes getElementType() throw (...);
		int getElementTagID() throw (...);
		const char* getElementTagName() throw (...);

		void finalizeField() throw (...);

	private:
		int arraySize;
		
		// simple type, USDS_STRING, USDS_TAG or USDS_POLYMORPH
		usdsTypes elementType;
		
		// if it's polymorph array (USDS_POLYMORPH)
		std::vector<int> elementTagIDs;
		std::vector<std::string> elementTagNames;

		// if elements is USDS_STRING
		usdsEncodes elementDefaultEncode;

		// if elements is USDS_TAG
		int elementTagID;
		std::string elementTagName;
		bool elementTagNeedID;
		bool elementTagNeedName;

	};

	//====================================================================================================================
	// String
	//====================================================================================================================

	class DicStringField : public DicBaseField
	{
	public:
		DicStringField();
		~DicStringField() {  };

		virtual usdsTypes getType() { return USDS_STRING; };
		virtual const char* getTypeName() { return typeName(USDS_STRING); };
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