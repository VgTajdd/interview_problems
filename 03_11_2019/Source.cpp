/*

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was[1, 2, 3, 4, 5], the expected output would be[120, 60, 40, 30, 24].If our input was[3, 2, 1], the expected output would be[2, 3, 6].

Follow - up: what if you can't use division?

*/

#include <iostream>
#include <vector>

std::vector< int > getNewArray( const std::vector< int >& v )
{
	int product = 1;
	for ( unsigned int i = 0; i < v.size(); i++ )
	{
		product *= v[i];
	}
	std::vector< int > ans;
	ans.resize( v.size(), product );
	for ( unsigned int i = 0; i < v.size(); i++ )
	{
		ans[i] /= v[i];
	}
	return ans;
}

int main()
{
	std::vector< int > v = { 1, 2, 3, 4, 5 };
	v = getNewArray( v );

	std::cout << "Result of input : [1, 2, 3, 4, 5] is: " << std::endl;
	for ( unsigned int i = 0; i < v.size(); i++ )
	{
		std::cout << v[i] << " ";
	}

	std::cin.get();
	return 0;
}