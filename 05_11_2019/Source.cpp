
/*
This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

#include <iostream>
#include <vector>

int findPositiveIntegerMissing( std::vector< int >& v )
{
	int max = 0, index = 0;
	while ( index < v.size() )
	{
		if ( index != 0 )
		{
			std::swap( v[index], v[0] );
		}
		if ( max < v[0] )
		{
			max = v[0];
		}
		if ( ( v[0] > 0 ) && ( std::find( v.begin() + 1, v.end(), v[0] - 1 ) == v.end() ) )
		{
			return v[0] - 1;
		}
		index++;
	}
	return max + 1;
}

int main()
{
	std::vector< int > v = { -1, 3, 4, 2, -1, 0, 1, 5 };
	//std::vector< int > v = { 1, 2, 3 };
	std::cout << findPositiveIntegerMissing( v );

	std::cin.get();
	return 0;
}