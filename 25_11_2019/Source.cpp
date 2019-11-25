/*

This problem was asked by Google.

Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:

is_locked, which returns whether the node is locked
lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.
You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.

*/

#include <iostream>
#include <unordered_map>

struct Node
{
	Node( const int _value, Node* _parent = nullptr ) : value( _value ), parent( _parent ), lockedChilds( 0 ) {};
	int value;
	Node* parent;
	bool isLocked;
	int lockedChilds;
};

struct BT
{
	BT() : head( nullptr ) {};
	std::unordered_map< int, Node* > hashTable;
	Node* head;
	Node* addNode( const int value, Node* parent )
	{
		Node* node = new Node( value, parent );
		hashTable[value] = node;
		return node;
	}
	void init()
	{
		head = addNode( 1, nullptr );
		Node* left = addNode( 2, head );
		Node* right = addNode( 3, head );
		Node* leftleft = addNode( 4, left );
		Node* leftright = addNode( 5, left );
		Node* rightleft = addNode( 6, right );
		Node* rightright = addNode( 7, right );
	}
	bool is_locked( const int value )
	{
		if ( hashTable.find( value ) == hashTable.end() )
		{
			return false;
		}
		return hashTable[value]->isLocked;
	}
	bool lock( const int value )
	{
		if ( hashTable.find( value ) == hashTable.end() )
		{
			return false;
		}
		if ( hashTable[value]->lockedChilds == 0 )
		{
			hashTable[value]->isLocked = true;
			Node* parent = hashTable[value]->parent;
			while ( parent )
			{
				parent->lockedChilds++;
				parent = parent->parent;
			}
			return true;
		}
		return false;
	}
	bool unlock( const int value )
	{
		if ( hashTable.find( value ) == hashTable.end() )
		{
			return false;
		}
		if ( hashTable[value]->lockedChilds == 0 )
		{
			hashTable[value]->isLocked = false;
			Node* parent = hashTable[value]->parent;
			while ( parent )
			{
				parent->lockedChilds--;
				parent = parent->parent;
			}
			return true;
		}
		return false;
	}
};

int main()
{
	BT tree;
	tree.init();
	std::cout << tree.lock( 7 ) << std::endl;
	std::cout << tree.lock( 3 ) << std::endl;
	std::cout << tree.unlock( 7 ) << std::endl;
	std::cout << tree.lock( 3 ) << std::endl;
	std::cin.get();
	return 0;
}