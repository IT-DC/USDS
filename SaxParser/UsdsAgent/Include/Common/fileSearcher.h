#ifndef FILE_SEARCHER_H
#define FILE_SEARCHER_H

#include <list>
#include <string>
#include <vector>

using namespace std;

namespace usdsAgent
{
	class FileSearcher
	{
	public:
		FileSearcher();
		~FileSearcher();
		virtual void f() = 0;

		static list<pair<string, string>>* findDictFiles(string& rootPath, string& ext);
		static list<pair<string, string>>* findDictFiles(string& rootPath, vector<string>& ext);

	};

}

#endif
