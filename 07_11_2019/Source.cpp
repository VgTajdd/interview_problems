/*

This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node.
Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.

*/

#include <iostream>

struct Node
{
	int value;
	Node* both;
};

Node* XOR( Node *a, Node *b )
{
	return (Node*) ( (uintptr_t) ( a ) ^ (uintptr_t) ( b ) );
}

struct XORLinkedList
{
	Node* head = nullptr;

	void add( int newValue )
	{
		auto n = new Node();
		n->value = newValue;
		if ( head == nullptr )
		{
			head = n;
			return;
		}

		Node* previous = nullptr;
		Node* current = head;
		Node* next = XOR( current->both, previous );

		while ( current != nullptr )
		{
			if ( next != nullptr )
			{
				previous = current;
				current = next;
				next = XOR( current->both, previous );
			}
			else
			{
				break;
			}
		}

		n->both = XOR( current, next );
		current->both = XOR( previous, n );
	}

	Node* get( int index )
	{
		Node* previous = nullptr;
		Node* current = head;
		Node* next = XOR( current->both, previous );
		int currentIndex = 0;

		while ( index != currentIndex )
		{
			previous = current;
			current = next;
			next = XOR( current->both, previous );

			currentIndex++;
		}

		return current;
	}
};

int main()
{
	XORLinkedList list;

	list.add( 10 );
	list.add( 20 );
	list.add( 30 );
	list.add( 40 );

	std::cout << list.get( 0 )->value << std::endl;
	std::cout << list.get( 1 )->value << std::endl;
	std::cout << list.get( 2 )->value << std::endl;
	std::cout << list.get( 3 )->value << std::endl;

	std::cin.get();
	return 0;
}