/*

This problem was asked by Google.

Given the root to a binary tree, implement serialize( root ), which serializes the tree into a string, and deserialize( s ), which deserializes the string back into the tree.

For example, given the following Node class

class Node :
	def __init__( self, val, left = None, right = None ) :
	self.val = val
	self.left = left
	self.right = right
	The following test should pass :

node = Node( 'root', Node( 'left', Node( 'left.left' ) ), Node( 'right' ) )
assert deserialize( serialize( node ) ).left.left.val == 'left.left'

*/

#include <iostream>
#include <string>
#include <assert.h>

class Node
{
public:
	Node( const std::string& _value, Node* _left = nullptr, Node* _right = nullptr ):
		value( _value ), left( _left ), right( _right ) {}
	std::string value;
	Node* left;
	Node* right;
};

std::string serialize_helper( Node* node )
{
	std::string ans;
	ans.append( "[" );
	ans.append( node->value );
	ans.append( "," );
	if ( node->left ) { ans.append( serialize_helper( node->left ) ); }
	ans.append( "," );
	if ( node->right ) { ans.append( serialize_helper( node->right ) ); }
	ans.append( "]" );
	return ans;
}

std::string serialize( Node* node )
{
	std::string serialized = serialize_helper( node );
	return serialized;

	/* [root,[left,[left.left,,],],[right,,]] */
}

Node* deserialize_helper( const std::string serialized, int& index )
{
	Node* node = nullptr;
	index = serialized.find( '[', index );
	if ( index != std::string::npos )
	{
		index++;
		int i_c1 = serialized.find( ',', index );
		if ( i_c1 != std::string::npos )
		{
			node = new Node( serialized.substr( index, i_c1 - index ) );

			index = i_c1 + 1;
			if ( serialized.find( '[', index ) == index )
			{
				node->left = deserialize_helper( serialized, index );
			}
			index++;
			if ( serialized.find( '[', index ) == index )
			{
				node->right = deserialize_helper( serialized, index );
			}
			else if ( serialized.find( ']', index ) == index )
			{
				index++;
			}
		}
	}
	return node;
}

Node* deserialize( const std::string serialized )
{
	int i = 0;
	Node* deserialized = deserialize_helper( serialized, i );
	return deserialized;
}

int main()
{
	Node* node = new Node( "root", new Node( "left", new Node( "left.left" ) ), new Node( "right" ) );
	assert( deserialize( serialize( node ) )->left->left->value == "left.left" );
	std::cin.get();
	return 0;
}