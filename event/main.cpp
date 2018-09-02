/* events from

	https://www.codeproject.com/Articles/1256352/CppEvent-How-to-implement-events-using-standard-cp

article. */

#include <algorithm>
#include <atomic>
#include <functional>
#include <mutex>
#include <future>
#include <list>
#include <iostream>
#include "event.hpp"

using std::function;
using std::list;
using std::cout;
using std::cin;


class player  // publisher
{
public:
	void start();
	void join();

	event<> eos_signal;

private:
	void loop();

	std::thread _th;
};

void player::start()
{
	_th = std::thread{&player::loop, this};
}

void player::join()
{
	_th.join();
}

void player::loop()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds{1});
		eos_signal.call();
	}
}


class cout_interface  // subscriber
{
public:
	cout_interface(player * p);
};

cout_interface::cout_interface(player * p)
{
	p->eos_signal.add(
		[](){cout << "End Of Stream received." << std::endl;}
	);
}


void foo()
{
	cout << "foo()" << std::endl;
}

void test_event_handler()
{
	event_handler<> h{foo};
	h();
}

void test_event()
{
	event_handler<> h{foo};

	event<> e;
	auto id = e.add(h);
	cout << "id=" << id << "\n";
	e.call();
	e();
	e.call_async();
	e.remove(h);
}

int main(int argc, char * argv[])
{
	player p;
	cout_interface iface{&p};

	p.start();

	cout << "press <enter> to end" << std::endl;
	cin.get();

	return 0;
}
