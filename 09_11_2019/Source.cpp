/*

This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
	/ \
   1   0
  / \
 1   1

*/

#include <iostream>

struct Node
{
	explicit Node( const int _value ) : value( _value ), left( nullptr ), right( nullptr ) {}
	int value;
	Node* left;
	Node* right;
};

bool isUnival( Node* node )
{
	if ( node->left == nullptr && node->right == nullptr )
	{
		return true;
	}
	bool isLeft = true, isRight = true;
	if ( node->left )
	{
		isLeft = isUnival( node->left );
		isLeft = isLeft && ( node->left->value == node->value );
	}
	if ( node->right )
	{
		isRight = isUnival( node->right );
		isRight = isRight && ( node->right->value == node->value );
	}
	if ( isLeft && isRight )
	{
		return true;
	}
}

int helper( Node* node )
{
	if ( node->left == nullptr && node->right == nullptr )
	{
		return 1;
	}
	int countLeft = 0, countRight = 0, total = 0;
	if ( node->left )
	{
		countLeft = helper( node->left );
	}
	if ( node->right )
	{
		countRight = helper( node->right );
	}
	if ( isUnival( node ) )
	{
		total = 1;
	}
	total += ( countLeft + countRight );
	return total;
}

int numberOfUnivalSubTrees( Node* head )
{
	return helper( head );
}

int main()
{
	Node* head = new Node( 0 );
	head->left = new Node( 1 );
	head->right = new Node( 0 );
	head->right->left = new Node( 1 );
	head->right->right = new Node( 0 );
	head->right->left->left = new Node( 1 );
	head->right->left->right = new Node( 1 );

	std::cout << numberOfUnivalSubTrees( head );

	std::cin.get();
	return 0;
}