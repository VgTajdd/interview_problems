/*

This problem was asked by Twitter.

Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.

*/

#include <string>
#include <vector>
#include <iostream>

struct Node
{
	Node( const char& c = '*' ) : value( c ) {};
	char value;
	std::vector< Node* > children;
	Node* getChildWithValue( const char& c )
	{
		for ( const auto& child : children )
		{
			if ( child->value == c )
			{
				return child;
			}
		}
		return nullptr;
	}
};

void getAllString( Node* node, std::vector< char > current, std::vector< std::string >& result )
{
	if ( node->children.empty() )
	{
		current.push_back( '\0' );
		result.push_back( current.data() );
		return;
	}
	for ( auto child : node->children )
	{
		std::vector< char > newCurrent = current;
		newCurrent.push_back( child->value );
		getAllString( child, newCurrent, result );
	}
}

std::vector< std::string > autoCompleteProcess( const std::vector< const char* >& set, const char* query )
{
	std::vector< std::string > ans;

	int indexSize = 0;
	Node* head = new Node();
	for ( const auto& str : set )
	{
		const int strLength = strlen( str );
		Node* parent = head;
		for ( int i = 0; i < strLength; i++ )
		{
			if ( auto ch = parent->getChildWithValue( str[i] ) )
			{
				parent = ch;
			}
			else
			{
				Node* child = new Node( str[i] );
				parent->children.push_back( child );
				parent = child;
			}
		}
	}

	Node* root = head;
	const int strLength = strlen( query );
	std::vector< char > word;
	for ( int i = 0; i < strLength; i++ )
	{
		word.push_back( query[i] );
		auto child = root->getChildWithValue( query[i] );
		if ( child )
		{
			root = child;
		}
		else
		{
			root = nullptr;
			break;
		}
	}

	if ( root )
	{
		getAllString( root, word, ans );
	}

	return ans;
}

int main()
{

	std::vector < const char* > set = { "dog", "deer", "deal" };
	const char* query = "de";

	auto ans = autoCompleteProcess( set, query );
	for ( const auto& word : ans )
	{
		std::cout << word << std::endl;
	}

	std::cin.get();
	return 0;
}