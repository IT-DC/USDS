#ifndef SENDER_H
#define SENDER_H

#include <string>

using namespace std;

namespace usdsAgent
{
	class Sender
	{
	public:
		Sender();
		~Sender();
		virtual void f() = 0;

		static string* sent(uint8_t* binary, size_t size);
		static void wait(string* session_id);

	};


}

#endif
