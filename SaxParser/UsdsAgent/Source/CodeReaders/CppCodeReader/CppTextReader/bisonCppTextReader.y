%{
	#include "flexCppTextReader.h"

%}

%code requires
{
	#include "BasicParser/Include/usdsBasicParser.h"
	#include <memory>
}

%require "3.0.4"
%skeleton "lalr1.cc"
%debug

%define api.prefix {cpp_text}
%define api.namespace {cppTextReader}
%define parser_class_name {BisonCppTextReader}
%locations

%parse-param {class FlexCppTextReader* scanner}
%parse-param {const char* input_text}
%parse-param {std::unique_ptr<usds::BasicParser>& output}
%parse-param {usds::UsdsStruct* code_description}

%error-verbose

%union {
//	bool  				boolVal;
	int8_t  			int8Val;
//	uint8_t  			uInt8Val;
//	int16_t  			int16Val;
//	uint16_t  			uInt16Val;
//	int32_t  			int32Val;
//	uint32_t  			uInt32Val;
//	int64_t  			int64Val;
	uint64_t  			uInt64Val;
//	float 				floatVal;
//    double 				doubleVal;
//	struct				floatDigits { double value; double digits; } floatDigits;
    size_t				stringVal[2];
	usds::usdsEncode	encodeVal;
}

// Tokens
%token USDS_ANNOTATION
%token USDS_ENCODE
%token<encodeVal> STRING_ENCODE "Text encode"

%token DIRECTIVES
%token COMMENTS
%token NAMESPACE
%token STRUCT
%token CLASS

%token<stringVal> TEXT_NAME "Object name"

//%token<boolVal> BOOLEAN_VALUE "true or false"
%token<int8Val> POSITIVE_NUMBER "Digit"
%token<int8Val> NEGATIVE_NUMBER "-Digit"
%token<int8Val> POSITIVE_EXPONENT_NUMBER "Positive float exponent digit"
%token<int8Val> NEGATIVE_EXPONENT_NUMBER "Negative float exponent digit"
//%type<int8Val> INT8_T "int8_t"
//%type<uInt8Val> UINT8_T "uint8_t"
//%type<int16Val> INT16_T "int16_t"
//%type<uInt16Val> UINT16_T "uint16_t"
//%type<int32Val> INT32_T "int32_t"
//%type<uInt32Val> UINT32_T "uint32_t"
//%type<int64Val> INT64_T "int64_t"
%type<uInt64Val> UINT64_T "uint64_t"
//%type<doubleVal> FLOAT_VALUE "Float value"
//%type<doubleVal> positive_major_float_digits "Positive major float value"
//%type<doubleVal> negative_major_float_digits "Negative major float value"
//%type<floatDigits> minor_float_digits "Minor float value"
//%type<doubleVal> float_exponent "Float exponent"

%{
#undef yylex
#define yylex scanner->scan
%}

//=================================================================================================
// Rules
%%

code: block | block code;

block:
//=================================================================================================
// Some C++ code
	DIRECTIVES
	{
		
	}
	|COMMENTS
	{

	}
	|NAMESPACE TEXT_NAME '{' code '}'
	{
	
	
	}
	|element
	{
		code_description = 0;
	}
	;

//=================================================================================================
// Elements

element:
	main_annotations element_description;
	
//=================================================================================================
// Annotations
	
main_annotations: main_annotation | main_annotation main_annotations;
	
main_annotation:
	USDS_ANNOTATION TEXT_NAME
	{
		if (code_description == 0)
		{
			code_description = output->addStruct("CodeDescription");
			code_description->addArray("mainAnnotations");
		};
		
		usds::UsdsArray* annotations = (usds::UsdsArray*)code_description->getField("mainAnnotations");
		usds::UsdsStruct* annotation = (usds::UsdsStruct*)annotations->pushElementBack();
	
		annotation->setFromUTF8("dictionaryName", input_text + $2[0], $2[1]);
	
	}
	;

//=================================================================================================
// Element description

element_description: struct_description | class_description;

//=================================================================================================
// Struct description

struct_description:
	STRUCT TEXT_NAME
	{
		usds::UsdsStruct* struct_description = code_description->addStruct("typeDescription", "StructDescription");
		struct_description->setFromUTF8("cppName", input_text + $2[0], $2[1]);
		struct_description->addArray("Elements");
	}
	'{' struct_elements '}'
	{
		
	
	}
	;


//=================================================================================================
// C++ struct	

struct_elements:
	struct_field
	|struct_element_annotations struct_field
	|struct_element_annotations struct_field struct_elements
	|COMMENTS struct_elements
	|struct_field struct_elements
	;

struct_element_annotations:
	struct_element_annotation | struct_element_annotation struct_element_annotations;
	
struct_element_annotation:
	USDS_ANNOTATION USDS_ENCODE ':' STRING_ENCODE 
	{
		usds::UsdsStruct* struct_description = (usds::UsdsStruct*)code_description->getField("typeDescription");
		usds::UsdsArray* elements = (usds::UsdsArray*)struct_description->getField("Elements");
		usds::UsdsStruct* current_field = 0;
		if (elements->getSize() == 0)
		{
			current_field = (usds::UsdsStruct*)elements->pushElementBack();
		}
		else
		{
			usds::UsdsStruct* last_field = (usds::UsdsStruct*)elements->getLastElement();
			if (last_field->isNull("ElementDescription"))
				current_field = last_field;
			else
				current_field = (usds::UsdsStruct*)elements->pushElementBack();
		};
		
		usds::UsdsStruct* current_annotation = 0;
		if (current_field->isNull("additionalAnnotations"))
			current_annotation = (usds::UsdsStruct*)current_field->addArray("additionalAnnotations")->pushElementBack();
		else
			current_annotation = (usds::UsdsStruct*)((usds::UsdsArray*)current_field->getField("additionalAnnotations"))->pushElementBack();
	
		current_annotation->addStruct("attribute", "StringEncode")->setValue("encodeId", $4);
	
	}
	;
	
struct_field:
	TEXT_NAME TEXT_NAME ';'
	{
		usds::UsdsStruct* struct_description = (usds::UsdsStruct*)code_description->getField("typeDescription");
		usds::UsdsArray* elements = (usds::UsdsArray*)struct_description->getField("Elements");
		usds::UsdsStruct* current_field = 0;
		if (elements->getSize() == 0)
		{
			current_field = (usds::UsdsStruct*)elements->pushElementBack();
		}
		else
		{
			usds::UsdsStruct* last_field = (usds::UsdsStruct*)elements->getLastElement();
			if (last_field->isNull("ElementDescription"))
				current_field = last_field;
			else
				current_field = (usds::UsdsStruct*)elements->pushElementBack();
		};
		
		usds::UsdsStruct* current_field_description = current_field->addStruct("ElementDescription", "FieldDescription");
		
		current_field_description->setFromUTF8("fieldName", input_text + $2[0], $2[1]);
		current_field_description->setFromUTF8("typeName", input_text + $1[0], $1[1]);
		current_field_description->setFromUTF8("fieldKind", "simple");
	}
	|TEXT_NAME '*' TEXT_NAME ';'
	{
		usds::UsdsStruct* struct_description = (usds::UsdsStruct*)code_description->getField("typeDescription");
		usds::UsdsArray* elements = (usds::UsdsArray*)struct_description->getField("Elements");
		usds::UsdsStruct* current_field = 0;
		if (elements->getSize() == 0)
		{
			current_field = (usds::UsdsStruct*)elements->pushElementBack();
		}
		else
		{
			usds::UsdsStruct* last_field = (usds::UsdsStruct*)elements->getLastElement();
			if (last_field->isNull("ElementDescription"))
				current_field = last_field;
			else
				current_field = (usds::UsdsStruct*)elements->pushElementBack();
		};
		
		usds::UsdsStruct* current_field_description = current_field->addStruct("ElementDescription", "FieldDescription");
		
		current_field_description->setFromUTF8("fieldName", input_text + $3[0], $3[1]);
		current_field_description->setFromUTF8("typeName", input_text + $1[0], $1[1]);
		current_field_description->setFromUTF8("fieldKind", "link");
		current_field_description->setValue("linksNumber", 1);
	}
	|TEXT_NAME TEXT_NAME '[' UINT64_T ']' ';'
	{
		usds::UsdsStruct* struct_description = (usds::UsdsStruct*)code_description->getField("typeDescription");
		usds::UsdsArray* elements = (usds::UsdsArray*)struct_description->getField("Elements");
		usds::UsdsStruct* current_field = 0;
		if (elements->getSize() == 0)
		{
			current_field = (usds::UsdsStruct*)elements->pushElementBack();
		}
		else
		{
			usds::UsdsStruct* last_field = (usds::UsdsStruct*)elements->getLastElement();
			if (last_field->isNull("ElementDescription"))
				current_field = last_field;
			else
				current_field = (usds::UsdsStruct*)elements->pushElementBack();
		};
		
		usds::UsdsStruct* current_field_description = current_field->addStruct("ElementDescription", "FieldDescription");
		
		current_field_description->setFromUTF8("fieldName", input_text + $2[0], $2[1]);
		current_field_description->setFromUTF8("typeName", input_text + $1[0], $1[1]);
		current_field_description->setFromUTF8("fieldKind", "simple");
		usds::UsdsArray* array_sizes = current_field_description->addArray("arraySizes");
		array_sizes->pushBack($4);		
	}
	;

//=================================================================================================
// Classes

class_description:
	CLASS TEXT_NAME
	{
	
	}
	;
	
	
//=================================================================================================
// Digits 8 bit

// INT8_T:
	// POSITIVE_NUMBER
	// {
		// $$ = (int8_t)$1;
	// }
	// |NEGATIVE_NUMBER
	// {
		// $$ = (int8_t)$1;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = (int8_t)$1 * (int8_t)10 + (int8_t)$2;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = (int8_t)$1 * (int8_t)10 - (int8_t)$2;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// if ($1 > (int8_t)1)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << " to int8_t: too big value";

		// $$ = (int8_t)$2  * (int8_t)10 + (int8_t)$3;
		
		// if ($1 == (int8_t)1 && $$ >= (int8_t)28)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << " to int8_t: too big value";
		
		// $$ = (int8_t)$1 * (int8_t)100 + $$;
		
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// if ($1 < (int8_t)-1)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << " to int8_t: too big value";

		// $$ = (int8_t)$2  * (int8_t)10 + (int8_t)$3;
		
		// if ($1 == (int8_t)-1 && $$ > (int8_t)28)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << " to int8_t: too big value";
		
		// $$ = (int8_t)$1 * (int8_t)100 - $$;
		
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << "... to int8_t: too big value";
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << "... to int8_t: too big value";
	// }
	// ;

// UINT8_T:
	// POSITIVE_NUMBER
	// {
		// $$ = (uint8_t)$1;
	// }
	// |NEGATIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << " to uint8_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = (uint8_t)$1 * (uint8_t)10 + (uint8_t)$2;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << " to uint8_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// if ($1 > (int8_t)2)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << " to uint8_t: too big value";

		// $$ = (uint8_t)$2  * (uint8_t)10 + (uint8_t)$3;
		
		// if ($1 == (int8_t)2 && $$ >= (uint8_t)56)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << " to uint8_t: too big value";
		
		// $$ = (uint8_t)$1 * (uint8_t)100 + $$;
		
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << " to uint8_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << "... to uint8_t: too big value";
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << "... to uint8_t: too big value";
	// }
	// ;

// //=================================================================================================
// // Digits 16 bit

// INT16_T:
	// POSITIVE_NUMBER
	// {
		// $$ = (int16_t)$1;
	// }
	// |NEGATIVE_NUMBER
	// {
		// $$ = (int16_t)$1;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int16_t)$1 * (int16_t)10 + 
		// (int16_t)$2;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int16_t)$1 * (int16_t)10 - 
		// (int16_t)$2;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int16_t)$1 * (int16_t)100 + 
		// (int16_t)$2 * (int16_t)10 + 
		// (int16_t)$3;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int16_t)$1 * (int16_t)100 - 
		// (int16_t)$2 * (int16_t)10 - 
		// (int16_t)$3;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int16_t)$1 * (int16_t)1000 + 
		// (int16_t)$2 * (int16_t)100 + 
		// (int16_t)$3 * (int16_t)10 + 
		// (int16_t)$4;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int16_t)$1 * (int16_t)1000 - 
		// (int16_t)$2 * (int16_t)100 - 
		// (int16_t)$3 * (int16_t)10 - 
		// (int16_t)$4;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// if ($1 > (int8_t)3)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to int16_t: too big value";
		
		// $$ = 
		// (int16_t)$2 * (int16_t)1000 + 
		// (int16_t)$3 * (int16_t)100 + 
		// (int16_t)$4 * (int16_t)10 + 
		// (int16_t)$5;

		// if ($1 == (int8_t)3 && $$ >= (int16_t)2768)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to int16_t: too big value";
			
		// $$ = $$ + (int16_t)$1 * (int16_t)10000;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// if ($1 < (int8_t)-3)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to int16_t: too big value";
		
		// $$ = 
		// (int16_t)$2 * (int16_t)1000 + 
		// (int16_t)$3 * (int16_t)100 + 
		// (int16_t)$4 * (int16_t)10 + 
		// (int16_t)$5;

		// if ($1 == (int8_t)-3 && $$ > (int16_t)2768)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to int16_t: too big value";
			
		// $$ = (int16_t)$1 * (int16_t)10000 - $$;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << "... to int16_t: too big value";
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << "... to int16_t: too big value";
	// }
	// ;

// UINT16_T:
	// POSITIVE_NUMBER
	// {
		// $$ = (uint16_t)$1;
	// }
	// |NEGATIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << " to uint16_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (uint16_t)$1 * (uint16_t)10 + 
		// (uint16_t)$2;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << " to uint16_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (uint16_t)$1 * (uint16_t)100 + 
		// (uint16_t)$2 * (uint16_t)10 + 
		// (uint16_t)$3;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << " to uint16_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (uint16_t)$1 * (uint16_t)1000 + 
		// (uint16_t)$2 * (uint16_t)100 + 
		// (uint16_t)$3 * (uint16_t)10 + 
		// (uint16_t)$4;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << " to uint16_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// if ($1 > (int8_t)6)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to uint16_t: too big value";
		
		// $$ = 
		// (uint16_t)$2 * (uint16_t)1000 + 
		// (uint16_t)$3 * (uint16_t)100 + 
		// (uint16_t)$4 * (uint16_t)10 + 
		// (uint16_t)$5;

		// if ($1 == (int8_t)6 && $$ >= (uint16_t)5536)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to uint16_t: too big value";
			
		// $$ = $$ + (uint16_t)$1 * (uint16_t)10000;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to uint16_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << "... to uint16_t: too big value";
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << "... to uint16_t: too big value";
	// }
	// ;
	
// //=================================================================================================
// // Digits 32 bit

// INT32_T:
	// POSITIVE_NUMBER
	// {
		// $$ = (int32_t)$1;
	// }
	// |NEGATIVE_NUMBER
	// {
		// $$ = (int32_t)$1;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)10 + 
		// (int32_t)$2;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)10 - 
		// (int32_t)$2;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)100 + 
		// (int32_t)$2 * (int32_t)10 + 
		// (int32_t)$3;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)100 - 
		// (int32_t)$2 * (int32_t)10 - 
		// (int32_t)$3;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)1000 + 
		// (int32_t)$2 * (int32_t)100 + 
		// (int32_t)$3 * (int32_t)10 + 
		// (int32_t)$4;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)1000 - 
		// (int32_t)$2 * (int32_t)100 - 
		// (int32_t)$3 * (int32_t)10 - 
		// (int32_t)$4;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)10000 + 
		// (int32_t)$2 * (int32_t)1000 + 
		// (int32_t)$3 * (int32_t)100 + 
		// (int32_t)$4 * (int32_t)10 + 
		// (int32_t)$5;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)10000 - 
		// (int32_t)$2 * (int32_t)1000 - 
		// (int32_t)$3 * (int32_t)100 - 
		// (int32_t)$4 * (int32_t)10 - 
		// (int32_t)$5;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)100000 + 
		// (int32_t)$2 * (int32_t)10000 + 
		// (int32_t)$3 * (int32_t)1000 + 
		// (int32_t)$4 * (int32_t)100 + 
		// (int32_t)$5 * (int32_t)10 + 
		// (int32_t)$6;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)100000 - 
		// (int32_t)$2 * (int32_t)10000 - 
		// (int32_t)$3 * (int32_t)1000 - 
		// (int32_t)$4 * (int32_t)100 - 
		// (int32_t)$5 * (int32_t)10 - 
		// (int32_t)$6;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)1000000 + 
		// (int32_t)$2 * (int32_t)100000 + 
		// (int32_t)$3 * (int32_t)10000 + 
		// (int32_t)$4 * (int32_t)1000 + 
		// (int32_t)$5 * (int32_t)100 + 
		// (int32_t)$6 * (int32_t)10 + 
		// (int32_t)$7;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)1000000 - 
		// (int32_t)$2 * (int32_t)100000 - 
		// (int32_t)$3 * (int32_t)10000 - 
		// (int32_t)$4 * (int32_t)1000 - 
		// (int32_t)$5 * (int32_t)100 - 
		// (int32_t)$6 * (int32_t)10 - 
		// (int32_t)$7;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)10000000 + 
		// (int32_t)$2 * (int32_t)1000000 + 
		// (int32_t)$3 * (int32_t)100000 + 
		// (int32_t)$4 * (int32_t)10000 + 
		// (int32_t)$5 * (int32_t)1000 + 
		// (int32_t)$6 * (int32_t)100 + 
		// (int32_t)$7 * (int32_t)10 + 
		// (int32_t)$8;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)10000000 - 
		// (int32_t)$2 * (int32_t)1000000 - 
		// (int32_t)$3 * (int32_t)100000 - 
		// (int32_t)$4 * (int32_t)10000 - 
		// (int32_t)$5 * (int32_t)1000 - 
		// (int32_t)$6 * (int32_t)100 - 
		// (int32_t)$7 * (int32_t)10 - 
		// (int32_t)$8;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)100000000 + 
		// (int32_t)$2 * (int32_t)10000000 + 
		// (int32_t)$3 * (int32_t)1000000 + 
		// (int32_t)$4 * (int32_t)100000 + 
		// (int32_t)$5 * (int32_t)10000 + 
		// (int32_t)$6 * (int32_t)1000 + 
		// (int32_t)$7 * (int32_t)100 + 
		// (int32_t)$8 * (int32_t)10 + 
		// (int32_t)$9;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int32_t)$1 * (int32_t)100000000 - 
		// (int32_t)$2 * (int32_t)10000000 - 
		// (int32_t)$3 * (int32_t)1000000 - 
		// (int32_t)$4 * (int32_t)100000 - 
		// (int32_t)$5 * (int32_t)10000 - 
		// (int32_t)$6 * (int32_t)1000 - 
		// (int32_t)$7 * (int32_t)100 - 
		// (int32_t)$8 * (int32_t)10 - 
		// (int32_t)$9;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// if ($1 > (int8_t)2)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to int32_t: too big value";
		
		// $$ = 
		// (int32_t)$2 * (int32_t)100000000 + 
		// (int32_t)$3 * (int32_t)10000000 + 
		// (int32_t)$4 * (int32_t)1000000 + 
		// (int32_t)$5 * (int32_t)100000 + 
		// (int32_t)$6 * (int32_t)10000 + 
		// (int32_t)$7 * (int32_t)1000 + 
		// (int32_t)$8 * (int32_t)100 + 
		// (int32_t)$9 * (int32_t)10 + 
		// (int32_t)$10;

		// if ($1 == (int8_t)2 && $$ >= (int32_t)147483648)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to int32_t: too big value";
			
		// $$ = $$ + (int32_t)$1 * (int32_t)1000000000;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// if ($1 < (int8_t)-2)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to int32_t: too big value";
		
		// $$ = 
		// (int32_t)$2 * (int32_t)100000000 + 
		// (int32_t)$3 * (int32_t)10000000 + 
		// (int32_t)$4 * (int32_t)1000000 + 
		// (int32_t)$5 * (int32_t)100000 + 
		// (int32_t)$6 * (int32_t)10000 + 
		// (int32_t)$7 * (int32_t)1000 + 
		// (int32_t)$8 * (int32_t)100 + 
		// (int32_t)$9 * (int32_t)10 + 
		// (int32_t)$10;

		// if ($1 == (int8_t)-2 && $$ > (int32_t)147483648)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to int32_t: too big value";
			
		// $$ = (int32_t)$1 * (int32_t)1000000000 - $$;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << "... to int32_t: too big value";
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << "... to int32_t: too big value";
	// }
	// ;
		
// UINT32_T:
	// POSITIVE_NUMBER
	// {
		// $$ = (uint32_t)$1;
	// }
	// |NEGATIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << " to uint32_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (uint32_t)$1 * (uint32_t)10 + 
		// (uint32_t)$2;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << " to uint32_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (uint32_t)$1 * (uint32_t)100 + 
		// (uint32_t)$2 * (uint32_t)10 + 
		// (uint32_t)$3;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << " to uint32_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (uint32_t)$1 * (uint32_t)1000 + 
		// (uint32_t)$2 * (uint32_t)100 + 
		// (uint32_t)$3 * (uint32_t)10 + 
		// (uint32_t)$4;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << " to uint32_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (uint32_t)$1 * (uint32_t)10000 + 
		// (uint32_t)$2 * (uint32_t)1000 + 
		// (uint32_t)$3 * (uint32_t)100 + 
		// (uint32_t)$4 * (uint32_t)10 + 
		// (uint32_t)$5;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to uint32_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (uint32_t)$1 * (uint32_t)100000 + 
		// (uint32_t)$2 * (uint32_t)10000 + 
		// (uint32_t)$3 * (uint32_t)1000 + 
		// (uint32_t)$4 * (uint32_t)100 + 
		// (uint32_t)$5 * (uint32_t)10 + 
		// (uint32_t)$6;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << " to uint32_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (uint32_t)$1 * (uint32_t)1000000 + 
		// (uint32_t)$2 * (uint32_t)100000 + 
		// (uint32_t)$3 * (uint32_t)10000 + 
		// (uint32_t)$4 * (uint32_t)1000 + 
		// (uint32_t)$5 * (uint32_t)100 + 
		// (uint32_t)$6 * (uint32_t)10 + 
		// (uint32_t)$7;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << " to uint32_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (uint32_t)$1 * (uint32_t)10000000 + 
		// (uint32_t)$2 * (uint32_t)1000000 + 
		// (uint32_t)$3 * (uint32_t)100000 + 
		// (uint32_t)$4 * (uint32_t)10000 + 
		// (uint32_t)$5 * (uint32_t)1000 + 
		// (uint32_t)$6 * (uint32_t)100 + 
		// (uint32_t)$7 * (uint32_t)10 + 
		// (uint32_t)$8;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << " to uint32_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (uint32_t)$1 * (uint32_t)100000000 + 
		// (uint32_t)$2 * (uint32_t)10000000 + 
		// (uint32_t)$3 * (uint32_t)1000000 + 
		// (uint32_t)$4 * (uint32_t)100000 + 
		// (uint32_t)$5 * (uint32_t)10000 + 
		// (uint32_t)$6 * (uint32_t)1000 + 
		// (uint32_t)$7 * (uint32_t)100 + 
		// (uint32_t)$8 * (uint32_t)10 + 
		// (uint32_t)$9;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << " to uint32_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// if ($1 > (int8_t)4)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to uint32_t: too big value";
		
		// $$ = 
		// (uint32_t)$2 * (uint32_t)100000000 + 
		// (uint32_t)$3 * (uint32_t)10000000 + 
		// (uint32_t)$4 * (uint32_t)1000000 + 
		// (uint32_t)$5 * (uint32_t)100000 + 
		// (uint32_t)$6 * (uint32_t)10000 + 
		// (uint32_t)$7 * (uint32_t)1000 + 
		// (uint32_t)$8 * (uint32_t)100 + 
		// (uint32_t)$9 * (uint32_t)10 + 
		// (uint32_t)$10;

		// if ($1 == (int8_t)4 && $$ >= (uint32_t)294967296)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to uint32_t: too big value";
			
		// $$ = $$ + (uint32_t)$1 * (uint32_t)1000000000;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to uint32_t: negative value";
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << "... to uint32_t: too big value";
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << "... to uint32_t: negative value";
	// }
	// ;

// //=================================================================================================
// // Digits 64 bit

// INT64_T:
	// POSITIVE_NUMBER
	// {
		// $$ = (int64_t)$1;
	// }
	// |NEGATIVE_NUMBER
	// {
		// $$ = (int64_t)$1;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10 + 
		// (int64_t)$2;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10 - 
		// (int64_t)$2;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100 + 
		// (int64_t)$2 * (int64_t)10 + 
		// (int64_t)$3;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100 - 
		// (int64_t)$2 * (int64_t)10 - 
		// (int64_t)$3;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)1000 + 
		// (int64_t)$2 * (int64_t)100 + 
		// (int64_t)$3 * (int64_t)10 + 
		// (int64_t)$4;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)1000 - 
		// (int64_t)$2 * (int64_t)100 - 
		// (int64_t)$3 * (int64_t)10 - 
		// (int64_t)$4;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10000 + 
		// (int64_t)$2 * (int64_t)1000 + 
		// (int64_t)$3 * (int64_t)100 + 
		// (int64_t)$4 * (int64_t)10 + 
		// (int64_t)$5;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10000 - 
		// (int64_t)$2 * (int64_t)1000 - 
		// (int64_t)$3 * (int64_t)100 - 
		// (int64_t)$4 * (int64_t)10 - 
		// (int64_t)$5;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100000 + 
		// (int64_t)$2 * (int64_t)10000 + 
		// (int64_t)$3 * (int64_t)1000 + 
		// (int64_t)$4 * (int64_t)100 + 
		// (int64_t)$5 * (int64_t)10 + 
		// (int64_t)$6;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100000 - 
		// (int64_t)$2 * (int64_t)10000 - 
		// (int64_t)$3 * (int64_t)1000 - 
		// (int64_t)$4 * (int64_t)100 - 
		// (int64_t)$5 * (int64_t)10 - 
		// (int64_t)$6;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)1000000 + 
		// (int64_t)$2 * (int64_t)100000 + 
		// (int64_t)$3 * (int64_t)10000 + 
		// (int64_t)$4 * (int64_t)1000 + 
		// (int64_t)$5 * (int64_t)100 + 
		// (int64_t)$6 * (int64_t)10 + 
		// (int64_t)$7;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)1000000 - 
		// (int64_t)$2 * (int64_t)100000 - 
		// (int64_t)$3 * (int64_t)10000 - 
		// (int64_t)$4 * (int64_t)1000 - 
		// (int64_t)$5 * (int64_t)100 - 
		// (int64_t)$6 * (int64_t)10 - 
		// (int64_t)$7;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10000000 + 
		// (int64_t)$2 * (int64_t)1000000 + 
		// (int64_t)$3 * (int64_t)100000 + 
		// (int64_t)$4 * (int64_t)10000 + 
		// (int64_t)$5 * (int64_t)1000 + 
		// (int64_t)$6 * (int64_t)100 + 
		// (int64_t)$7 * (int64_t)10 + 
		// (int64_t)$8;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10000000 - 
		// (int64_t)$2 * (int64_t)1000000 - 
		// (int64_t)$3 * (int64_t)100000 - 
		// (int64_t)$4 * (int64_t)10000 - 
		// (int64_t)$5 * (int64_t)1000 - 
		// (int64_t)$6 * (int64_t)100 - 
		// (int64_t)$7 * (int64_t)10 - 
		// (int64_t)$8;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100000000 + 
		// (int64_t)$2 * (int64_t)10000000 + 
		// (int64_t)$3 * (int64_t)1000000 + 
		// (int64_t)$4 * (int64_t)100000 + 
		// (int64_t)$5 * (int64_t)10000 + 
		// (int64_t)$6 * (int64_t)1000 + 
		// (int64_t)$7 * (int64_t)100 + 
		// (int64_t)$8 * (int64_t)10 + 
		// (int64_t)$9;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100000000 - 
		// (int64_t)$2 * (int64_t)10000000 - 
		// (int64_t)$3 * (int64_t)1000000 - 
		// (int64_t)$4 * (int64_t)100000 - 
		// (int64_t)$5 * (int64_t)10000 - 
		// (int64_t)$6 * (int64_t)1000 - 
		// (int64_t)$7 * (int64_t)100 - 
		// (int64_t)$8 * (int64_t)10 - 
		// (int64_t)$9;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)1000000000 + 
		// (int64_t)$2 * (int64_t)100000000 + 
		// (int64_t)$3 * (int64_t)10000000 + 
		// (int64_t)$4 * (int64_t)1000000 + 
		// (int64_t)$5 * (int64_t)100000 + 
		// (int64_t)$6 * (int64_t)10000 + 
		// (int64_t)$7 * (int64_t)1000 + 
		// (int64_t)$8 * (int64_t)100 + 
		// (int64_t)$9 * (int64_t)10 + 
		// (int64_t)$10;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)1000000000 - 
		// (int64_t)$2 * (int64_t)100000000 - 
		// (int64_t)$3 * (int64_t)10000000 - 
		// (int64_t)$4 * (int64_t)1000000 - 
		// (int64_t)$5 * (int64_t)100000 - 
		// (int64_t)$6 * (int64_t)10000 - 
		// (int64_t)$7 * (int64_t)1000 - 
		// (int64_t)$8 * (int64_t)100 - 
		// (int64_t)$9 * (int64_t)10 - 
		// (int64_t)$10;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10000000000 + 
		// (int64_t)$2 * (int64_t)1000000000 + 
		// (int64_t)$3 * (int64_t)100000000 + 
		// (int64_t)$4 * (int64_t)10000000 + 
		// (int64_t)$5 * (int64_t)1000000 + 
		// (int64_t)$6 * (int64_t)100000 + 
		// (int64_t)$7 * (int64_t)10000 + 
		// (int64_t)$8 * (int64_t)1000 + 
		// (int64_t)$9 * (int64_t)100 + 
		// (int64_t)$10 * (int64_t)10 + 
		// (int64_t)$11;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10000000000 - 
		// (int64_t)$2 * (int64_t)1000000000 - 
		// (int64_t)$3 * (int64_t)100000000 - 
		// (int64_t)$4 * (int64_t)10000000 - 
		// (int64_t)$5 * (int64_t)1000000 - 
		// (int64_t)$6 * (int64_t)100000 - 
		// (int64_t)$7 * (int64_t)10000 - 
		// (int64_t)$8 * (int64_t)1000 - 
		// (int64_t)$9 * (int64_t)100 - 
		// (int64_t)$10 * (int64_t)10 - 
		// (int64_t)$11;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100000000000 + 
		// (int64_t)$2 * (int64_t)10000000000 + 
		// (int64_t)$3 * (int64_t)1000000000 + 
		// (int64_t)$4 * (int64_t)100000000 + 
		// (int64_t)$5 * (int64_t)10000000 + 
		// (int64_t)$6 * (int64_t)1000000 + 
		// (int64_t)$7 * (int64_t)100000 + 
		// (int64_t)$8 * (int64_t)10000 + 
		// (int64_t)$9 * (int64_t)1000 + 
		// (int64_t)$10 * (int64_t)100 + 
		// (int64_t)$11 * (int64_t)10 + 
		// (int64_t)$12;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100000000000 - 
		// (int64_t)$2 * (int64_t)10000000000 - 
		// (int64_t)$3 * (int64_t)1000000000 - 
		// (int64_t)$4 * (int64_t)100000000 - 
		// (int64_t)$5 * (int64_t)10000000 - 
		// (int64_t)$6 * (int64_t)1000000 - 
		// (int64_t)$7 * (int64_t)100000 - 
		// (int64_t)$8 * (int64_t)10000 - 
		// (int64_t)$9 * (int64_t)1000 - 
		// (int64_t)$10 * (int64_t)100 - 
		// (int64_t)$11 * (int64_t)10 - 
		// (int64_t)$12;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)1000000000000 + 
		// (int64_t)$2 * (int64_t)100000000000 + 
		// (int64_t)$3 * (int64_t)10000000000 + 
		// (int64_t)$4 * (int64_t)1000000000 + 
		// (int64_t)$5 * (int64_t)100000000 + 
		// (int64_t)$6 * (int64_t)10000000 + 
		// (int64_t)$7 * (int64_t)1000000 + 
		// (int64_t)$8 * (int64_t)100000 + 
		// (int64_t)$9 * (int64_t)10000 + 
		// (int64_t)$10 * (int64_t)1000 + 
		// (int64_t)$11 * (int64_t)100 + 
		// (int64_t)$12 * (int64_t)10 + 
		// (int64_t)$13;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)1000000000000 - 
		// (int64_t)$2 * (int64_t)100000000000 - 
		// (int64_t)$3 * (int64_t)10000000000 - 
		// (int64_t)$4 * (int64_t)1000000000 - 
		// (int64_t)$5 * (int64_t)100000000 - 
		// (int64_t)$6 * (int64_t)10000000 - 
		// (int64_t)$7 * (int64_t)1000000 - 
		// (int64_t)$8 * (int64_t)100000 - 
		// (int64_t)$9 * (int64_t)10000 - 
		// (int64_t)$10 * (int64_t)1000 - 
		// (int64_t)$11 * (int64_t)100 - 
		// (int64_t)$12 * (int64_t)10 - 
		// (int64_t)$13;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10000000000000 + 
		// (int64_t)$2 * (int64_t)1000000000000 + 
		// (int64_t)$3 * (int64_t)100000000000 + 
		// (int64_t)$4 * (int64_t)10000000000 + 
		// (int64_t)$5 * (int64_t)1000000000 + 
		// (int64_t)$6 * (int64_t)100000000 + 
		// (int64_t)$7 * (int64_t)10000000 + 
		// (int64_t)$8 * (int64_t)1000000 + 
		// (int64_t)$9 * (int64_t)100000 + 
		// (int64_t)$10 * (int64_t)10000 + 
		// (int64_t)$11 * (int64_t)1000 + 
		// (int64_t)$12 * (int64_t)100 + 
		// (int64_t)$13 * (int64_t)10 + 
		// (int64_t)$14;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10000000000000 - 
		// (int64_t)$2 * (int64_t)1000000000000 - 
		// (int64_t)$3 * (int64_t)100000000000 - 
		// (int64_t)$4 * (int64_t)10000000000 - 
		// (int64_t)$5 * (int64_t)1000000000 - 
		// (int64_t)$6 * (int64_t)100000000 - 
		// (int64_t)$7 * (int64_t)10000000 - 
		// (int64_t)$8 * (int64_t)1000000 - 
		// (int64_t)$9 * (int64_t)100000 - 
		// (int64_t)$10 * (int64_t)10000 - 
		// (int64_t)$11 * (int64_t)1000 - 
		// (int64_t)$12 * (int64_t)100 - 
		// (int64_t)$13 * (int64_t)10 - 
		// (int64_t)$14;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100000000000000 + 
		// (int64_t)$2 * (int64_t)10000000000000 + 
		// (int64_t)$3 * (int64_t)1000000000000 + 
		// (int64_t)$4 * (int64_t)100000000000 + 
		// (int64_t)$5 * (int64_t)10000000000 + 
		// (int64_t)$6 * (int64_t)1000000000 + 
		// (int64_t)$7 * (int64_t)100000000 + 
		// (int64_t)$8 * (int64_t)10000000 + 
		// (int64_t)$9 * (int64_t)1000000 + 
		// (int64_t)$10 * (int64_t)100000 + 
		// (int64_t)$11 * (int64_t)10000 + 
		// (int64_t)$12 * (int64_t)1000 + 
		// (int64_t)$13 * (int64_t)100 + 
		// (int64_t)$14 * (int64_t)10 + 
		// (int64_t)$15;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100000000000000 - 
		// (int64_t)$2 * (int64_t)10000000000000 - 
		// (int64_t)$3 * (int64_t)1000000000000 - 
		// (int64_t)$4 * (int64_t)100000000000 - 
		// (int64_t)$5 * (int64_t)10000000000 - 
		// (int64_t)$6 * (int64_t)1000000000 - 
		// (int64_t)$7 * (int64_t)100000000 - 
		// (int64_t)$8 * (int64_t)10000000 - 
		// (int64_t)$9 * (int64_t)1000000 - 
		// (int64_t)$10 * (int64_t)100000 - 
		// (int64_t)$11 * (int64_t)10000 - 
		// (int64_t)$12 * (int64_t)1000 - 
		// (int64_t)$13 * (int64_t)100 - 
		// (int64_t)$14 * (int64_t)10 - 
		// (int64_t)$15;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)1000000000000000 + 
		// (int64_t)$2 * (int64_t)100000000000000 + 
		// (int64_t)$3 * (int64_t)10000000000000 + 
		// (int64_t)$4 * (int64_t)1000000000000 + 
		// (int64_t)$5 * (int64_t)100000000000 + 
		// (int64_t)$6 * (int64_t)10000000000 + 
		// (int64_t)$7 * (int64_t)1000000000 + 
		// (int64_t)$8 * (int64_t)100000000 + 
		// (int64_t)$9 * (int64_t)10000000 + 
		// (int64_t)$10 * (int64_t)1000000 + 
		// (int64_t)$11 * (int64_t)100000 + 
		// (int64_t)$12 * (int64_t)10000 + 
		// (int64_t)$13 * (int64_t)1000 + 
		// (int64_t)$14 * (int64_t)100 + 
		// (int64_t)$15 * (int64_t)10 + 
		// (int64_t)$16;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)1000000000000000 - 
		// (int64_t)$2 * (int64_t)100000000000000 - 
		// (int64_t)$3 * (int64_t)10000000000000 - 
		// (int64_t)$4 * (int64_t)1000000000000 - 
		// (int64_t)$5 * (int64_t)100000000000 - 
		// (int64_t)$6 * (int64_t)10000000000 - 
		// (int64_t)$7 * (int64_t)1000000000 - 
		// (int64_t)$8 * (int64_t)100000000 - 
		// (int64_t)$9 * (int64_t)10000000 - 
		// (int64_t)$10 * (int64_t)1000000 - 
		// (int64_t)$11 * (int64_t)100000 - 
		// (int64_t)$12 * (int64_t)10000 - 
		// (int64_t)$13 * (int64_t)1000 - 
		// (int64_t)$14 * (int64_t)100 - 
		// (int64_t)$15 * (int64_t)10 - 
		// (int64_t)$16;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10000000000000000 + 
		// (int64_t)$2 * (int64_t)1000000000000000 + 
		// (int64_t)$3 * (int64_t)100000000000000 + 
		// (int64_t)$4 * (int64_t)10000000000000 + 
		// (int64_t)$5 * (int64_t)1000000000000 + 
		// (int64_t)$6 * (int64_t)100000000000 + 
		// (int64_t)$7 * (int64_t)10000000000 + 
		// (int64_t)$8 * (int64_t)1000000000 + 
		// (int64_t)$9 * (int64_t)100000000 + 
		// (int64_t)$10 * (int64_t)10000000 + 
		// (int64_t)$11 * (int64_t)1000000 + 
		// (int64_t)$12 * (int64_t)100000 + 
		// (int64_t)$13 * (int64_t)10000 + 
		// (int64_t)$14 * (int64_t)1000 + 
		// (int64_t)$15 * (int64_t)100 + 
		// (int64_t)$16 * (int64_t)10 + 
		// (int64_t)$17;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)10000000000000000 - 
		// (int64_t)$2 * (int64_t)1000000000000000 - 
		// (int64_t)$3 * (int64_t)100000000000000 - 
		// (int64_t)$4 * (int64_t)10000000000000 - 
		// (int64_t)$5 * (int64_t)1000000000000 - 
		// (int64_t)$6 * (int64_t)100000000000 - 
		// (int64_t)$7 * (int64_t)10000000000 - 
		// (int64_t)$8 * (int64_t)1000000000 - 
		// (int64_t)$9 * (int64_t)100000000 - 
		// (int64_t)$10 * (int64_t)10000000 - 
		// (int64_t)$11 * (int64_t)1000000 - 
		// (int64_t)$12 * (int64_t)100000 - 
		// (int64_t)$13 * (int64_t)10000 - 
		// (int64_t)$14 * (int64_t)1000 - 
		// (int64_t)$15 * (int64_t)100 - 
		// (int64_t)$16 * (int64_t)10 - 
		// (int64_t)$17;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100000000000000000 + 
		// (int64_t)$2 * (int64_t)10000000000000000 + 
		// (int64_t)$3 * (int64_t)1000000000000000 + 
		// (int64_t)$4 * (int64_t)100000000000000 + 
		// (int64_t)$5 * (int64_t)10000000000000 + 
		// (int64_t)$6 * (int64_t)1000000000000 + 
		// (int64_t)$7 * (int64_t)100000000000 + 
		// (int64_t)$8 * (int64_t)10000000000 + 
		// (int64_t)$9 * (int64_t)1000000000 + 
		// (int64_t)$10 * (int64_t)100000000 + 
		// (int64_t)$11 * (int64_t)10000000 + 
		// (int64_t)$12 * (int64_t)1000000 + 
		// (int64_t)$13 * (int64_t)100000 + 
		// (int64_t)$14 * (int64_t)10000 + 
		// (int64_t)$15 * (int64_t)1000 + 
		// (int64_t)$16 * (int64_t)100 + 
		// (int64_t)$17 * (int64_t)10 + 
		// (int64_t)$18;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$1 * (int64_t)100000000000000000 - 
		// (int64_t)$2 * (int64_t)10000000000000000 - 
		// (int64_t)$3 * (int64_t)1000000000000000 - 
		// (int64_t)$4 * (int64_t)100000000000000 - 
		// (int64_t)$5 * (int64_t)10000000000000 - 
		// (int64_t)$6 * (int64_t)1000000000000 - 
		// (int64_t)$7 * (int64_t)100000000000 - 
		// (int64_t)$8 * (int64_t)10000000000 - 
		// (int64_t)$9 * (int64_t)1000000000 - 
		// (int64_t)$10 * (int64_t)100000000 - 
		// (int64_t)$11 * (int64_t)10000000 - 
		// (int64_t)$12 * (int64_t)1000000 - 
		// (int64_t)$13 * (int64_t)100000 - 
		// (int64_t)$14 * (int64_t)10000 - 
		// (int64_t)$15 * (int64_t)1000 - 
		// (int64_t)$16 * (int64_t)100 - 
		// (int64_t)$17 * (int64_t)10 - 
		// (int64_t)$18;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$2 * (int64_t)100000000000000000 + 
		// (int64_t)$3 * (int64_t)10000000000000000 + 
		// (int64_t)$4 * (int64_t)1000000000000000 + 
		// (int64_t)$5 * (int64_t)100000000000000 + 
		// (int64_t)$6 * (int64_t)10000000000000 + 
		// (int64_t)$7 * (int64_t)1000000000000 + 
		// (int64_t)$8 * (int64_t)100000000000 + 
		// (int64_t)$9 * (int64_t)10000000000 + 
		// (int64_t)$10 * (int64_t)1000000000 + 
		// (int64_t)$11 * (int64_t)100000000 + 
		// (int64_t)$12 * (int64_t)10000000 + 
		// (int64_t)$13 * (int64_t)1000000 + 
		// (int64_t)$14 * (int64_t)100000 + 
		// (int64_t)$15 * (int64_t)10000 + 
		// (int64_t)$16 * (int64_t)1000 + 
		// (int64_t)$17 * (int64_t)100 + 
		// (int64_t)$18 * (int64_t)10 + 
		// (int64_t)$19;

		// if ($1 == (int8_t)9 && $$ >= (int64_t)223372036854775808)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << 
				// $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << " to int64_t: too big value";
			
		// $$ = $$ + (int64_t)$1 * (int64_t)1000000000000000000;
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = 
		// (int64_t)$2 * (int64_t)100000000000000000 + 
		// (int64_t)$3 * (int64_t)10000000000000000 + 
		// (int64_t)$4 * (int64_t)1000000000000000 + 
		// (int64_t)$5 * (int64_t)100000000000000 + 
		// (int64_t)$6 * (int64_t)10000000000000 + 
		// (int64_t)$7 * (int64_t)1000000000000 + 
		// (int64_t)$8 * (int64_t)100000000000 + 
		// (int64_t)$9 * (int64_t)10000000000 + 
		// (int64_t)$10 * (int64_t)1000000000 + 
		// (int64_t)$11 * (int64_t)100000000 + 
		// (int64_t)$12 * (int64_t)10000000 + 
		// (int64_t)$13 * (int64_t)1000000 + 
		// (int64_t)$14 * (int64_t)100000 + 
		// (int64_t)$15 * (int64_t)10000 + 
		// (int64_t)$16 * (int64_t)1000 + 
		// (int64_t)$17 * (int64_t)100 + 
		// (int64_t)$18 * (int64_t)10 + 
		// (int64_t)$19;

		// if ($1 == (int8_t)-9 && $$ > (int64_t)223372036854775808)
			// throw usds::ErrorMessage(2) << "Can not convert the number " << 
				// $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << " to int64_t: too big value";
			
		// $$ = (int64_t)$1 * (int64_t)1000000000000000000 - $$;
	// }
	// |POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << 
				// $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << "... to int64_t: too big value";
	// }
	// |NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		// POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	// {
		// throw usds::ErrorMessage(2) << "Can not convert the number " << 
				// $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << "... to int64_t: too big value";
	// }
	// ;
	
UINT64_T:
	POSITIVE_NUMBER
	{
		$$ = (uint64_t)$1;
	}
	|NEGATIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10 + 
		(uint64_t)$2;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100 + 
		(uint64_t)$2 * (uint64_t)10 + 
		(uint64_t)$3;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000 + 
		(uint64_t)$2 * (uint64_t)100 + 
		(uint64_t)$3 * (uint64_t)10 + 
		(uint64_t)$4;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10000 + 
		(uint64_t)$2 * (uint64_t)1000 + 
		(uint64_t)$3 * (uint64_t)100 + 
		(uint64_t)$4 * (uint64_t)10 + 
		(uint64_t)$5;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100000 + 
		(uint64_t)$2 * (uint64_t)10000 + 
		(uint64_t)$3 * (uint64_t)1000 + 
		(uint64_t)$4 * (uint64_t)100 + 
		(uint64_t)$5 * (uint64_t)10 + 
		(uint64_t)$6;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000000 + 
		(uint64_t)$2 * (uint64_t)100000 + 
		(uint64_t)$3 * (uint64_t)10000 + 
		(uint64_t)$4 * (uint64_t)1000 + 
		(uint64_t)$5 * (uint64_t)100 + 
		(uint64_t)$6 * (uint64_t)10 + 
		(uint64_t)$7;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10000000 + 
		(uint64_t)$2 * (uint64_t)1000000 + 
		(uint64_t)$3 * (uint64_t)100000 + 
		(uint64_t)$4 * (uint64_t)10000 + 
		(uint64_t)$5 * (uint64_t)1000 + 
		(uint64_t)$6 * (uint64_t)100 + 
		(uint64_t)$7 * (uint64_t)10 + 
		(uint64_t)$8;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100000000 + 
		(uint64_t)$2 * (uint64_t)10000000 + 
		(uint64_t)$3 * (uint64_t)1000000 + 
		(uint64_t)$4 * (uint64_t)100000 + 
		(uint64_t)$5 * (uint64_t)10000 + 
		(uint64_t)$6 * (uint64_t)1000 + 
		(uint64_t)$7 * (uint64_t)100 + 
		(uint64_t)$8 * (uint64_t)10 + 
		(uint64_t)$9;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000000000 + 
		(uint64_t)$2 * (uint64_t)100000000 + 
		(uint64_t)$3 * (uint64_t)10000000 + 
		(uint64_t)$4 * (uint64_t)1000000 + 
		(uint64_t)$5 * (uint64_t)100000 + 
		(uint64_t)$6 * (uint64_t)10000 + 
		(uint64_t)$7 * (uint64_t)1000 + 
		(uint64_t)$8 * (uint64_t)100 + 
		(uint64_t)$9 * (uint64_t)10 + 
		(uint64_t)$10;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10000000000 + 
		(uint64_t)$2 * (uint64_t)1000000000 + 
		(uint64_t)$3 * (uint64_t)100000000 + 
		(uint64_t)$4 * (uint64_t)10000000 + 
		(uint64_t)$5 * (uint64_t)1000000 + 
		(uint64_t)$6 * (uint64_t)100000 + 
		(uint64_t)$7 * (uint64_t)10000 + 
		(uint64_t)$8 * (uint64_t)1000 + 
		(uint64_t)$9 * (uint64_t)100 + 
		(uint64_t)$10 * (uint64_t)10 + 
		(uint64_t)$11;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100000000000 + 
		(uint64_t)$2 * (uint64_t)10000000000 + 
		(uint64_t)$3 * (uint64_t)1000000000 + 
		(uint64_t)$4 * (uint64_t)100000000 + 
		(uint64_t)$5 * (uint64_t)10000000 + 
		(uint64_t)$6 * (uint64_t)1000000 + 
		(uint64_t)$7 * (uint64_t)100000 + 
		(uint64_t)$8 * (uint64_t)10000 + 
		(uint64_t)$9 * (uint64_t)1000 + 
		(uint64_t)$10 * (uint64_t)100 + 
		(uint64_t)$11 * (uint64_t)10 + 
		(uint64_t)$12;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000000000000 + 
		(uint64_t)$2 * (uint64_t)100000000000 + 
		(uint64_t)$3 * (uint64_t)10000000000 + 
		(uint64_t)$4 * (uint64_t)1000000000 + 
		(uint64_t)$5 * (uint64_t)100000000 + 
		(uint64_t)$6 * (uint64_t)10000000 + 
		(uint64_t)$7 * (uint64_t)1000000 + 
		(uint64_t)$8 * (uint64_t)100000 + 
		(uint64_t)$9 * (uint64_t)10000 + 
		(uint64_t)$10 * (uint64_t)1000 + 
		(uint64_t)$11 * (uint64_t)100 + 
		(uint64_t)$12 * (uint64_t)10 + 
		(uint64_t)$13;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10000000000000 + 
		(uint64_t)$2 * (uint64_t)1000000000000 + 
		(uint64_t)$3 * (uint64_t)100000000000 + 
		(uint64_t)$4 * (uint64_t)10000000000 + 
		(uint64_t)$5 * (uint64_t)1000000000 + 
		(uint64_t)$6 * (uint64_t)100000000 + 
		(uint64_t)$7 * (uint64_t)10000000 + 
		(uint64_t)$8 * (uint64_t)1000000 + 
		(uint64_t)$9 * (uint64_t)100000 + 
		(uint64_t)$10 * (uint64_t)10000 + 
		(uint64_t)$11 * (uint64_t)1000 + 
		(uint64_t)$12 * (uint64_t)100 + 
		(uint64_t)$13 * (uint64_t)10 + 
		(uint64_t)$14;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100000000000000 + 
		(uint64_t)$2 * (uint64_t)10000000000000 + 
		(uint64_t)$3 * (uint64_t)1000000000000 + 
		(uint64_t)$4 * (uint64_t)100000000000 + 
		(uint64_t)$5 * (uint64_t)10000000000 + 
		(uint64_t)$6 * (uint64_t)1000000000 + 
		(uint64_t)$7 * (uint64_t)100000000 + 
		(uint64_t)$8 * (uint64_t)10000000 + 
		(uint64_t)$9 * (uint64_t)1000000 + 
		(uint64_t)$10 * (uint64_t)100000 + 
		(uint64_t)$11 * (uint64_t)10000 + 
		(uint64_t)$12 * (uint64_t)1000 + 
		(uint64_t)$13 * (uint64_t)100 + 
		(uint64_t)$14 * (uint64_t)10 + 
		(uint64_t)$15;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000000000000000 + 
		(uint64_t)$2 * (uint64_t)100000000000000 + 
		(uint64_t)$3 * (uint64_t)10000000000000 + 
		(uint64_t)$4 * (uint64_t)1000000000000 + 
		(uint64_t)$5 * (uint64_t)100000000000 + 
		(uint64_t)$6 * (uint64_t)10000000000 + 
		(uint64_t)$7 * (uint64_t)1000000000 + 
		(uint64_t)$8 * (uint64_t)100000000 + 
		(uint64_t)$9 * (uint64_t)10000000 + 
		(uint64_t)$10 * (uint64_t)1000000 + 
		(uint64_t)$11 * (uint64_t)100000 + 
		(uint64_t)$12 * (uint64_t)10000 + 
		(uint64_t)$13 * (uint64_t)1000 + 
		(uint64_t)$14 * (uint64_t)100 + 
		(uint64_t)$15 * (uint64_t)10 + 
		(uint64_t)$16;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)10000000000000000 + 
		(uint64_t)$2 * (uint64_t)1000000000000000 + 
		(uint64_t)$3 * (uint64_t)100000000000000 + 
		(uint64_t)$4 * (uint64_t)10000000000000 + 
		(uint64_t)$5 * (uint64_t)1000000000000 + 
		(uint64_t)$6 * (uint64_t)100000000000 + 
		(uint64_t)$7 * (uint64_t)10000000000 + 
		(uint64_t)$8 * (uint64_t)1000000000 + 
		(uint64_t)$9 * (uint64_t)100000000 + 
		(uint64_t)$10 * (uint64_t)10000000 + 
		(uint64_t)$11 * (uint64_t)1000000 + 
		(uint64_t)$12 * (uint64_t)100000 + 
		(uint64_t)$13 * (uint64_t)10000 + 
		(uint64_t)$14 * (uint64_t)1000 + 
		(uint64_t)$15 * (uint64_t)100 + 
		(uint64_t)$16 * (uint64_t)10 + 
		(uint64_t)$17;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << $17 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)100000000000000000 + 
		(uint64_t)$2 * (uint64_t)10000000000000000 + 
		(uint64_t)$3 * (uint64_t)1000000000000000 + 
		(uint64_t)$4 * (uint64_t)100000000000000 + 
		(uint64_t)$5 * (uint64_t)10000000000000 + 
		(uint64_t)$6 * (uint64_t)1000000000000 + 
		(uint64_t)$7 * (uint64_t)100000000000 + 
		(uint64_t)$8 * (uint64_t)10000000000 + 
		(uint64_t)$9 * (uint64_t)1000000000 + 
		(uint64_t)$10 * (uint64_t)100000000 + 
		(uint64_t)$11 * (uint64_t)10000000 + 
		(uint64_t)$12 * (uint64_t)1000000 + 
		(uint64_t)$13 * (uint64_t)100000 + 
		(uint64_t)$14 * (uint64_t)10000 + 
		(uint64_t)$15 * (uint64_t)1000 + 
		(uint64_t)$16 * (uint64_t)100 + 
		(uint64_t)$17 * (uint64_t)10 + 
		(uint64_t)$18;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		$$ = 
		(uint64_t)$1 * (uint64_t)1000000000000000000 + 
		(uint64_t)$2 * (uint64_t)100000000000000000 + 
		(uint64_t)$3 * (uint64_t)10000000000000000 + 
		(uint64_t)$4 * (uint64_t)1000000000000000 + 
		(uint64_t)$5 * (uint64_t)100000000000000 + 
		(uint64_t)$6 * (uint64_t)10000000000000 + 
		(uint64_t)$7 * (uint64_t)1000000000000 + 
		(uint64_t)$8 * (uint64_t)100000000000 + 
		(uint64_t)$9 * (uint64_t)10000000000 + 
		(uint64_t)$10 * (uint64_t)1000000000 + 
		(uint64_t)$11 * (uint64_t)100000000 + 
		(uint64_t)$12 * (uint64_t)10000000 + 
		(uint64_t)$13 * (uint64_t)1000000 + 
		(uint64_t)$14 * (uint64_t)100000 + 
		(uint64_t)$15 * (uint64_t)10000 + 
		(uint64_t)$16 * (uint64_t)1000 + 
		(uint64_t)$17 * (uint64_t)100 + 
		(uint64_t)$18 * (uint64_t)10 + 
		(uint64_t)$19;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		if ($1 > (int8_t)1)
			throw usds::ErrorMessage(2) << "Can not convert the number " << 
				$1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << $20 << " to uint64_t: too big value";

		$$ = 
		(uint64_t)$2 * (uint64_t)1000000000000000000 + 
		(uint64_t)$3 * (uint64_t)100000000000000000 + 
		(uint64_t)$4 * (uint64_t)10000000000000000 + 
		(uint64_t)$5 * (uint64_t)1000000000000000 + 
		(uint64_t)$6 * (uint64_t)100000000000000 + 
		(uint64_t)$7 * (uint64_t)10000000000000 + 
		(uint64_t)$8 * (uint64_t)1000000000000 + 
		(uint64_t)$9 * (uint64_t)100000000000 + 
		(uint64_t)$10 * (uint64_t)10000000000 + 
		(uint64_t)$11 * (uint64_t)1000000000 + 
		(uint64_t)$12 * (uint64_t)100000000 + 
		(uint64_t)$13 * (uint64_t)10000000 + 
		(uint64_t)$14 * (uint64_t)1000000 + 
		(uint64_t)$15 * (uint64_t)100000 + 
		(uint64_t)$16 * (uint64_t)10000 + 
		(uint64_t)$17 * (uint64_t)1000 + 
		(uint64_t)$18 * (uint64_t)100 + 
		(uint64_t)$19 * (uint64_t)10 + 
		(uint64_t)$20;

		if ($1 == (int8_t)1 && $$ >= (uint64_t)8446744073709551616)
			throw usds::ErrorMessage(2) << "Can not convert the number " << 
				$1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << $20 << " to uint64_t: too big value";
			
		$$ = $$ + (uint64_t)$1 * (uint64_t)10000000000000000000;
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << $20 << " to uint64_t: negative value";
	}
	|POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << 
				$1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 << $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << $20 << "... to uint64_t: too big value";
	}
	|NEGATIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
		POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER digits
	{
		throw usds::ErrorMessage(2) << "Can not convert the number " << $1 << $2 << $3 << $4 << $5 << $6 << $7 << $8 << $9 << $10 
			<< $11 << $12 << $13 << $14 << $15 << $16 << $17 << $18 << $19 << $20 << "... to uint64_t: negative value";
	}
	;

digits: POSITIVE_NUMBER |digits POSITIVE_NUMBER
	
	
//=================================================================================================
// Float types

// FLOAT_VALUE:
	// positive_major_float_digits
	// {
		// $$ = $1;
	// }
	// |negative_major_float_digits
	// {
		// $$ = $1;
	// }
	// |positive_major_float_digits '.' minor_float_digits
	// {
		// $$ = $1 + $3.value/$3.digits;
	// }
	// |negative_major_float_digits '.' minor_float_digits
	// {
		// $$ = $1 - $3.value/$3.digits;
	// }
	// |'-' '.' minor_float_digits
	// {
		// $$ = - $3.value/$3.digits;	
	// }
	// |'.' minor_float_digits
	// {
		// $$ = $2.value/$2.digits;
	// }
	// |positive_major_float_digits '.' minor_float_digits float_exponent
	// {
		// $$ = ($1 + $3.value/$3.digits) * pow(10.0, $4);
	// }
	// |negative_major_float_digits '.' minor_float_digits float_exponent
	// {
		// $$ = ($1 - $3.value/$3.digits) * pow(10.0, $4);
	// }
	// |'-' '.' minor_float_digits float_exponent
	// {
		// $$ = (- $3.value/$3.digits) * pow(10.0, $4);	
	// }
	// |'.' minor_float_digits float_exponent
	// {
		// $$ = ($2.value/$2.digits) * pow(10.0, $3);
	// }
	// ;

// positive_major_float_digits: 
	// POSITIVE_NUMBER
	// {
		// $$ = (double)$1;
	// }
	// |positive_major_float_digits POSITIVE_NUMBER
	// {
		// $$ = $$ * 10.0 + (double)$2;
	// }
	// ;
	
// negative_major_float_digits: 
	// NEGATIVE_NUMBER
	// {
		// $$ = (double)$1;
	// }
	// |negative_major_float_digits POSITIVE_NUMBER
	// {
		// $$ = $$ * 10.0 - (double)$2;
	// }
	// ;
	
// minor_float_digits: 
	// POSITIVE_NUMBER
	// {
		// $$.value = (double)$1;
		// $$.digits = 10.0;
	// }
	// |minor_float_digits POSITIVE_NUMBER
	// {
		// $$.value = $$.value * 10.0 + (double)$2;
		// $$.digits = $$.digits * 10.0;
	// }
	// ;

// float_exponent: 
	// POSITIVE_EXPONENT_NUMBER
	// {
		// $$ = (double)$1;
	// }
	// |NEGATIVE_EXPONENT_NUMBER
	// {
		// $$ = (double)$1;
	// }
	// |POSITIVE_EXPONENT_NUMBER POSITIVE_NUMBER
	// {
		// $$ = (double)$1 * (double)10.0 + (double)$2;
	// }
	// |NEGATIVE_EXPONENT_NUMBER POSITIVE_NUMBER
	// {
		// $$ = (double)$1 * (double)10.0 - (double)$2;
	// }
	// |POSITIVE_EXPONENT_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = (double)$1 * (double)100.0 + (double)$2 * (double)10.0 + (double)$3;
	// }
	// |NEGATIVE_EXPONENT_NUMBER POSITIVE_NUMBER POSITIVE_NUMBER
	// {
		// $$ = (double)$1 * (double)100.0 - (double)$2 * (double)10.0 - (double)$3;
	// }
	// ;
	
%%
//=================================================================================================

void cppTextReader::BisonCppTextReader::error(const cppTextReader::BisonCppTextReader::location_type &loc, const std::string &msg)
{
	throw usds::ErrorMessage(1) << "Can not read the code file\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

