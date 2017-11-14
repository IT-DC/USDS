#ifndef FILE_SEARCHER_H
#define FILE_SEARCHER_H

#include <list>
#include <string>
#include <vector>
#include <memory>

using namespace std;

namespace usdsAgent
{
	class FileSearcher
	{
	public:
		virtual void f() = 0;

		static unique_ptr<list<pair<string, string>>> findDictFiles(string& rootPath, string& ext);
		static unique_ptr<list<pair<string, string>>> findCodeFiles(string& rootPath, vector<string>& ext, string& annotation);

	};

}

#endif
