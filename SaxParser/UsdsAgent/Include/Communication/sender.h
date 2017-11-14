#ifndef SENDER_H
#define SENDER_H

#include <string>
#include <memory>

using namespace std;

namespace usdsAgent
{
	class Sender
	{
	public:
		virtual void f() = 0;

		static std::unique_ptr<string> sent(uint8_t* binary, size_t size);
		static void wait(std::unique_ptr<string>& session_id);

	};


}

#endif
