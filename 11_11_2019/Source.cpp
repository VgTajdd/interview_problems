/*

This problem was asked by Apple.

Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.

*/

#include <iostream>
#include <functional>
#include <thread>

void threadedMethod( std::function< void() > function, int n )
{
	std::this_thread::sleep_for( std::chrono::milliseconds( n ) );
	function();
}

void jobScheduler( std::function<void( void )> function, int n )
{
	std::thread method( threadedMethod, function, n );
	method.join();
}

void sayHello()
{
	std::cout << "Hello!" << std::endl;
}

void sayBye()
{
	std::cout << "Bye!" << std::endl;
}

int main()
{
	jobScheduler( sayHello, 1000 );
	jobScheduler( sayBye, 2000 );

	std::cout << "\nDone!";

	std::cin.get();

	return 0;
}