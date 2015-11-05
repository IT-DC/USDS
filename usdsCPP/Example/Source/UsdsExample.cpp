#include <iostream>
#include <string>

#include "usdsBasicParser.h"
using namespace usds;

int main(int argc, char* argv[])
{
	try
	{

		//================================================================================================================
		// Client side
		//================================================================================================================

		// Create objects for work
		BasicParser* clientParser = new BasicParser();
		BinaryOutput* usds_binary_doc = new BinaryOutput();

		// Init parser by the dictionary
		const char* text_dictionary =
			"USDS DICTIONARY ID=1000000 v.1.0			\
			{											\
				1: STRUCT internalObject				\
				{										\
					1: UNSIGNED VARINT varintField;		\
					2: DOUBLE doubleField;				\
					3: STRING<UTF-8> stringField;		\
					4: BOOLEAN booleanField;			\
				} RESTRICT {notRoot;}					\
														\
				2: STRUCT rootObject					\
				{										\
					1: INT intField;					\
					2: LONG longField;					\
					3: ARRAY<internalObject> arrayField;\
				}										\
		}";

		clientParser->addDictionaryFromText(text_dictionary, strlen(text_dictionary), USDS_UTF8);

		// Create DOM-object

		// Add new structure to the DOM object
		UsdsStruct* tag = clientParser->addStructTag("rootObject");
		// Init simple fields
		tag->setFieldValue("intField", 1234);
		tag->setFieldValue("longField", 5000000000);
		// Init array field, get link from the struct
		UsdsArray* array_field = tag->getArrayField("arrayField");
		for (int i = 0; i < 2; i++)
		{
			// Add new element to the array, get link to this element
			UsdsStruct* struct_element = (UsdsStruct*)(array_field->addTagElement());
			// Init element
			struct_element->setFieldValue("varintField", i);
			struct_element->setFieldValue("doubleField", i / 2.0);
			struct_element->setFieldValue("stringField", "String value");
			struct_element->setFieldValue("booleanField", i == 0);
		}

		// Add second structure to the DOM object
		// Let's optimise performance
		// Get tag's and fields' IDs from the dictionary
		int internalObject_id = clientParser->getTagID("internalObject");
		int internalObject_varintField_id = clientParser->getFieldID(internalObject_id, "varintField");
		int internalObject_doubleField_id = clientParser->getFieldID(internalObject_id, "doubleField");
		int internalObject_stringField_id = clientParser->getFieldID(internalObject_id, "stringField");
		int internalObject_booleanField_id = clientParser->getFieldID(internalObject_id, "booleanField");
		
		int rootObject_id = clientParser->getTagID("rootObject");
		int rootObject_intField_id = clientParser->getFieldID(rootObject_id, "intField");
		int rootObject_longField_id = clientParser->getFieldID(rootObject_id, "longField");
		int rootObject_arrayField_id = clientParser->getFieldID(rootObject_id, "arrayField");
		
		// Now use these IDs
		// Add second structure to the DOM object
		tag = clientParser->addStructTag(rootObject_id);
		// Init simple fields
		tag->setFieldValue(rootObject_intField_id, 4321);
		tag->setFieldValue(rootObject_longField_id, 6000000000);
		// Init array field, get link from the struct
		array_field = tag->getArrayField(rootObject_arrayField_id);
		for (int i = 0; i < 2; i++)
		{
			// Add new element to the array, get link to this element
			UsdsStruct* struct_element = (UsdsStruct*)(array_field->addTagElement());
			// Init element
			struct_element->setFieldValue(internalObject_varintField_id, i * 2);
			struct_element->setFieldValue(internalObject_doubleField_id, i / 3.0);
			struct_element->setFieldValue(internalObject_stringField_id, "Second root object");
			struct_element->setFieldValue(internalObject_booleanField_id, i != 0);
		}

		// Let's look what we have in DOM-object
		std::string json;
		clientParser->getJSON(USDS_UTF8, &json);
		std::cout << "Client side\n==========================================================\n\n";
		std::cout << "JSON:\n" << json << "\n";
		std::cout << "JSON string size: " << json.size() << " symbols\n\n";

		// Create USDS binary document with Head, Dictionary and Body inside
		clientParser->encode(usds_binary_doc, true, true, true);
		std::cout << "USDS binary document size: " << usds_binary_doc->getSize() << " bytes\n\n";

		// Clean only Body in Client parser. You can use it later without Dictionary initialisation
		clientParser->clearBody();

		//================================================================================================================
		// Server side
		//================================================================================================================

		// Create object for work
		BasicParser* serverParser = new BasicParser();
		const unsigned char* binary_data = usds_binary_doc->getBinary();
		size_t binary_size = usds_binary_doc->getSize();

		// Dictionary initialization is not necessary, we will get dictionary from USDS Binary document automatically
		// Let's do it
		serverParser->decode(binary_data, binary_size);
		
		// DOM object created from the binary
		// Let's look what we have in it
		json.clear();
		serverParser->getJSON(USDS_UTF8, &json);
		std::cout << "Server side\n==========================================================\n\n";
		std::cout << "JSON:\n" << json << "\n";
		std::cout << "JSON string size: " << json.size() << " symbols\n\n";

		// Extract first root object
		UsdsBaseType* someTag = serverParser->getFirstTag();
		std::cout << "The type of the first Tag: '" << someTag->getTypeName() << "'\n";
		std::cout << "The name of the first Tag: '" << someTag->getName() << "'\nFields:\n";
		if (someTag->getType() != USDS_STRUCT)
			return 1;
		else
			tag = (UsdsStruct*)someTag;

		// buffers for the field values
		int int_value = 0;
		long long long_value = 0;
		long long varint_value = 0;
		double double_value = 0.0;
		const char* string_value = 0;
		bool boolean_value = false;

		// Extract the fields by the names
		tag->getFieldValue("intField", &int_value);
		std::cout << "\tintField = " << int_value << "\n";
		tag->getFieldValue("longField", &long_value);
		std::cout << "\tlongField = " << long_value << "\n";
		
		// Extract array field
		array_field = tag->getArrayField("arrayField");
		int array_size = array_field->getElementNumber();
		for (int i = 0; i < array_size; i++)
		{
			// Get the element from the array
			UsdsStruct* struct_element = (UsdsStruct*)(array_field->getTagElement(i));
			// Init element
			struct_element->getFieldValue("varintField", &varint_value);
			std::cout << "\tarrayField[" << i << "].varintField = " << varint_value << "\n";
			struct_element->getFieldValue("doubleField", &double_value);
			std::cout << "\tarrayField[" << i << "].doubleField = " << double_value << "\n";
			struct_element->getFieldValue("stringField", &string_value);
			std::cout << "\tarrayField[" << i << "].stringField = " << string_value << "\n";
			struct_element->getFieldValue("booleanField", &boolean_value);
			std::cout << "\tarrayField[" << i << "].booleanField = " << boolean_value << "\n";
		}

		// Get second tag from 
		tag = (UsdsStruct*)(tag->getNext());
		std::cout << "\nThe name of the second Tag: '" << tag->getName() << "'\nFields:\n";

		// Let's optimise performance
		// Get tag's and fields' IDs from the dictionary
		internalObject_id = serverParser->getTagID("internalObject");
		internalObject_varintField_id = serverParser->getFieldID(internalObject_id, "varintField");
		internalObject_doubleField_id = serverParser->getFieldID(internalObject_id, "doubleField");
		internalObject_stringField_id = serverParser->getFieldID(internalObject_id, "stringField");
		internalObject_booleanField_id = serverParser->getFieldID(internalObject_id, "booleanField");

		rootObject_id = serverParser->getTagID("rootObject");
		rootObject_intField_id = serverParser->getFieldID(rootObject_id, "intField");
		rootObject_longField_id = serverParser->getFieldID(rootObject_id, "longField");
		rootObject_arrayField_id = serverParser->getFieldID(rootObject_id, "arrayField");


		// Extract the fields by the IDs
		tag->getFieldValue(rootObject_intField_id, &int_value);
		std::cout << "\tintField = " << int_value << "\n";
		tag->getFieldValue(rootObject_longField_id, &long_value);
		std::cout << "\tlongField = " << long_value << "\n";

		// Extract array field
		array_field = tag->getArrayField(rootObject_arrayField_id);
		array_size = array_field->getElementNumber();
		for (int i = 0; i < array_size; i++)
		{
			// Get the element from the array
			UsdsStruct* struct_element = (UsdsStruct*)(array_field->getTagElement(i));
			// Init element
			struct_element->getFieldValue(internalObject_varintField_id, &varint_value);
			std::cout << "\tarrayField[" << i << "].varintField = " << varint_value << "\n";
			struct_element->getFieldValue(internalObject_doubleField_id, &double_value);
			std::cout << "\tarrayField[" << i << "].doubleField = " << double_value << "\n";
			struct_element->getFieldValue(internalObject_stringField_id, &string_value);
			std::cout << "\tarrayField[" << i << "].stringField = " << string_value << "\n";
			struct_element->getFieldValue(internalObject_booleanField_id, &boolean_value);
			std::cout << "\tarrayField[" << i << "].booleanField = " << boolean_value << "\n";
		}

		// Clean only Body in Server parser. You can use it later without Dictionary initialisation
		clientParser->clearBody();

		//================================================================================================================
		// Destroy all objects

		delete clientParser;
		delete serverParser;
		delete usds_binary_doc;

	}
	catch (ErrorMessage& msg)
	{
		std::cout << "Error code: " << msg.getCode() << "\nError message: " << msg.getFullMessageUTF8();
		std::cout << "Press any key";
		std::cin.ignore();
		return 1;
	}

	std::cout << "\nPress any key";
	std::cin.ignore();

	return 0;

}