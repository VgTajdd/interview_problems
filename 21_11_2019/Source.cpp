/*

Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.

*/

#include <iostream>
#include <stack>

struct Node
{
	Node( const int _value ) : value( _value ), next( nullptr ) {};
	int value;
	Node* next;
};

// All values are different.
struct LinkedList
{
	LinkedList() : head( nullptr ), size( 0 ) {};
	Node* head;
	int size;
	void addValue( const int value )
	{
		auto node = new Node( value );
		if ( head )
		{
			Node* ptr = head;
			while ( ptr->next )
			{
				ptr = ptr->next;
			}
			ptr->next = node;
		}
		else
		{
			head = node;
		}
		size++;
	}
};

int findIntersection( LinkedList* longer, LinkedList* shorter )
{
	if ( longer->size < shorter->size )
	{
		std::swap( longer, shorter );
	}
	std::stack< int > s_l, s_s;
	Node* head_l = longer->head;
	Node* head_s = shorter->head;
	for ( int i = 0; i < longer->size; i++ )
	{
		s_l.push( head_l->value );
		head_l = head_l->next;
		if ( i < shorter->size )
		{
			s_s.push( head_s->value );
			head_s = head_s->next;
		}
	}
	int ans = -1;
	for ( int i = 0; i < shorter->size; i++ )
	{
		if ( s_l.top() != s_s.top() )
		{
			break;
		}
		ans = s_l.top();
		s_l.pop();
		s_s.pop();
	}
	return ans;
}

int main()
{
	LinkedList a;
	a.addValue( 3 );
	a.addValue( 7 );
	a.addValue( 8 );
	a.addValue( 10 );

	LinkedList b;
	b.addValue( 99 );
	b.addValue( 1 );
	b.addValue( 8 );
	b.addValue( 10 );

	std::cout << findIntersection( &a, &b );

	std::cin.get();
	return 0;
}