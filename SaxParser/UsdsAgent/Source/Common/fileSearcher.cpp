#include "Common/fileSearcher.h"

#include "boost/filesystem.hpp"
#include "boost/filesystem/fstream.hpp"
#include "BasicParser/Include/common/errorMessage.h"

#include <string>
#include <iostream>

using namespace usdsAgent;
using namespace boost::filesystem;

list<pair<string, string>>* FileSearcher::findDictFiles(string& rootPath, string& ext)
try
{
	path p(rootPath.c_str());
	if (!exists(p))
		throw usds::ErrorStack("FileSearcher::findDictFiles") << rootPath.c_str() << ext.c_str() << (usds::ErrorMessage(3, "Directory '") << rootPath.c_str() << "' does not exist");
	if (!is_directory(p))
		throw usds::ErrorStack("FileSearcher::findDictFiles") << rootPath.c_str() << ext.c_str() << (usds::ErrorMessage(4, "Path '") << rootPath.c_str() << "' is not a directory");
	
	// find all files recursively
	recursive_directory_iterator it(p);
	recursive_directory_iterator endit;

	list<pair<string, string>>* outList = new list<pair<string, string>>;

	while (it != endit)
	{
		if (is_regular_file(*it) && it->path().extension() == ext)
		{
			boost::filesystem::ifstream file(it->path());
			// read file to output list
			string content
			(
				(std::istreambuf_iterator<char>(file)),
				(std::istreambuf_iterator<char>())
			);
			outList->push_back(make_pair(it->path().string(), content));
		}
		it++;
	}
	
	if (outList->size() == 0)
		throw usds::ErrorStack("FileSearcher::findDictFiles") << rootPath.c_str() << ext.c_str() << (usds::ErrorMessage(5, "Dictionary files not found in '") << rootPath.c_str() << "' (***." << ext.c_str() << ")");

	return outList;

}
catch (filesystem_error err)
{
	throw usds::ErrorStack("FileSearcher::findDictFiles") << rootPath.c_str() << ext.c_str() << usds::ErrorMessage(3, err.what());
}



