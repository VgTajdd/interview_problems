/*

This problem was asked by Facebook.

Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.

*/

#include <iostream>
#include <stack>
#include <unordered_map>

bool areBracketsBalanced( const std::string& str ) // O(n)
{
	std::unordered_map< char, char > closingCharacters;
	closingCharacters['['] = ']';
	closingCharacters['{'] = '}';
	closingCharacters['('] = ')';
	std::stack< char > charStack;
	for ( const auto& c : str )
	{
		if ( charStack.empty() )
		{
			charStack.push( c );
		}
		else if ( closingCharacters.find( charStack.top() ) != closingCharacters.end()
			&& closingCharacters[charStack.top()] == c )
		{
			charStack.pop();
		}
		else
		{
			charStack.push( c );
		}
	}
	return charStack.empty();
}

int main()
{
	std::cout << areBracketsBalanced( "([])[]({})" ) << std::endl;
	std::cout << areBracketsBalanced( "([)]" ) << std::endl;
	std::cout << areBracketsBalanced( "((()" ) << std::endl;

	std::cin.get();
	return 0;
}