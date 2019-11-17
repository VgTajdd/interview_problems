/*

This problem was asked by Twitter.

You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.

*/

#include <iostream>

struct Node
{
	Node( const int _value ) : value( _value ), previous( nullptr ) {};
	int value;
	Node* previous;
};

struct OrderDatabase
{
	OrderDatabase() : top( nullptr ), countItems( 0 ) {};
	Node* top;
	int countItems;
	void record( const int order_id )
	{
		Node* newTop = new Node( order_id );
		if ( top == nullptr )
		{
			top = newTop;
		}
		else
		{
			newTop->previous = top;
			top = newTop;
		}
		countItems++;
	}

	const int get_last( const int t )
	{
		int i = t;
		auto ptr = top;
		if ( top == nullptr || countItems < t )
			return -1;
		while ( --i > 0 )
		{
			ptr = ptr->previous;
		}
		return ptr->value;
	}
};

int main()
{
	OrderDatabase db;

	db.record( 1234 );
	db.record( 2345 );
	db.record( 666 );
	db.record( 777 );

	std::cout << db.get_last( 1 ) << std::endl;
	std::cout << db.get_last( 2 ) << std::endl;
	std::cout << db.get_last( 3 ) << std::endl;
	std::cout << db.get_last( 4 ) << std::endl;

	std::cin.get();
	return 0;
}