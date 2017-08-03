#ifndef FILE_SEARCHER_H
#define FILE_SEARCHER_H

#include <list>
#include <string>

using namespace std;

namespace usdsAgent
{
	class FileSearcher
	{
	public:
		FileSearcher();
		~FileSearcher();
		virtual void f() = 0;

		static list<string>* findDictFiles(string& rootPath, string& ext);

	};

}

#endif
