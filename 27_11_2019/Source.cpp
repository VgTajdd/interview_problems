/*

This problem was asked by Google.

Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.

*/

#include <iostream>

struct Node {
	Node( const int _value ) : value( _value ), previous( nullptr ) {}
	int value;
	Node* previous;
};

struct SingleLinkedList // stack
{
	Node* top;
	SingleLinkedList() : top( nullptr ) {};
	void removeKthLastElement( int k ) // O(k)
	{
		Node* currentNode = top;
		Node* lastElement = nullptr;
		while ( --k > 0 )
		{
			lastElement = currentNode;
			currentNode = currentNode->previous;
		}
		lastElement->previous = currentNode->previous;
		delete currentNode;
	}
	void addValue( const int value ) // O(1)
	{
		Node* newTop = new Node( value );
		if ( top )
		{
			newTop->previous = top;
		}
		top = newTop;
	}
};

int main()
{
	SingleLinkedList list;
	list.addValue( 3 );
	list.addValue( 4 );
	list.addValue( 5 );
	list.addValue( 6 );
	list.addValue( 7 );
	list.addValue( 8 );
	list.removeKthLastElement( 6 );
	list.removeKthLastElement( 2 );
	std::cin.get();
	return 0;
}