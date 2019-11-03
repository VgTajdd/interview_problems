/*

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass ?

*/

#include <iostream>
#include <vector>
#include <algorithm>

bool isPossibleToSumUp( const std::vector< int >& numbers, const int sum )
{
	bool isPossible = false;
	for ( unsigned int i = 0; i < numbers.size(); i++ )
	{
		if ( isPossible ) break;
		for ( unsigned int j = 1; j < numbers.size(); j++ )
		{
			if ( numbers[i] + numbers[j] == sum )
			{
				isPossible = true;
				break;
			}
		}
	}
	return isPossible;
}

bool isPossibleToSumUpOptimized( const std::vector< int >& numbers, const int sum )
{
	bool isPossible = false;
	std::vector< int > buffer;
	for ( unsigned int i = 0; i < numbers.size(); i++ )
	{
		if ( std::find( buffer.begin(), buffer.end(), numbers[i] ) != buffer.end() )
		{
			isPossible = true;
			break;
		}
		buffer.push_back( sum - numbers[i] );
	}
	return isPossible;
}

int main()
{
	std::vector< int > v = { 10, 15, 3, 7 };
	const int sum = 10;

	std::cout << ( isPossibleToSumUpOptimized( v, sum ) ? "True" : "False" );

	std::cin.get();
	return 0;
}