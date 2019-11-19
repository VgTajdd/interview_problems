/*

This problem was asked by Google.

Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
	subdir1
	subdir2
		file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
	subdir1
		file1.ext
		subsubdir1
	subdir2
		subsubdir2
			file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system.

For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.

Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.

*/

#include <iostream>
#include <vector>
#include <string>

struct Node
{
	Node( const std::string& s ) : name( s ), parent( nullptr ) {};
	std::string name;
	std::string abs_path;
	std::vector< Node* > children;
	Node* parent;
	bool isFile()
	{
		return name.find( '.' ) != std::string::npos;
	}
};

void helper_maxLength( Node* node, int& maxLength )
{
	if ( node->isFile() )
	{
		if ( maxLength < node->abs_path.size() )
		{
			maxLength = node->abs_path.size();
		}
		return;
	}

	if ( !node->children.empty() && !node->isFile() )
	{
		for ( auto n : node->children )
			helper_maxLength( n, maxLength );
	}
}

int getLongestPathLength( Node* node )
{
	int ans = 0;
	helper_maxLength( node, ans );
	return ans;
}

Node* nodify( const std::string& str )
{
	auto pos = str.find( '\n' );
	if ( pos == std::string::npos )
	{
		return new Node( str );
	}
	int last_t = 1;
	Node* root = new Node( str.substr( 0, pos ) );
	root->abs_path = root->name;
	Node* current_parent = root;
	Node* last_node = root;
	while ( pos != std::string::npos )
	{
		auto new_pos = str.find( '\n', pos + 1 );
		int t = 0;
		for ( int i = pos + 1; i < new_pos; i++ )
		{
			if ( str[i] == '\t' )
			{
				t++;
			}
			else
			{
				break;
			}
		}

		auto new_node = new Node( str.substr( pos + t + 1, new_pos - pos - t - 1 ) );

		if ( last_t < t )
		{
			current_parent = last_node;
		}
		else if ( last_t > t )
		{
			for ( int tt = t; tt < last_t; tt++ )
			{
				current_parent = current_parent->parent;
			}
		}
		current_parent->children.push_back( new_node );
		new_node->parent = current_parent;
		new_node->abs_path = current_parent->abs_path + "/" + new_node->name;

		last_t = t;
		last_node = new_node;
		pos = new_pos;
	}
	return root;
}

int main()
{
	std::string str = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";

	std::cout << getLongestPathLength( nodify( str ) ) << std::endl;

	std::cin.get();
	return 0;
}