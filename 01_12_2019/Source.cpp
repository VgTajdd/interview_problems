/*

This problem was asked by Facebook.

You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.

*/

#include <iostream>
#include <algorithm>
/*

maxA	x	x	x	maxB
waterbetween maxA and maxB = min(maxA, maxB) * (indexMaxB-indexMaxA-1) - (x+x+x)

*/
int getUnitsOfWater( int walls[], const int size )
{
	int ans = 0;
	int maxA = 0, maxB = 0;
	int indexMaxA = 0, indexMaxB = -1;
	int sum = 0;
	for ( int i = 0; i < size; i++ )
	{
		if ( i == 0 )
		{
			maxA = walls[i];
		}
		else if ( i == size - 1 )
		{
			maxB = walls[i];
			indexMaxB = size - 1;
			ans += ( std::min( maxA, maxB )*( indexMaxB - indexMaxA - 1 ) - sum );
		}
		else
		{
			if ( walls[i] >= maxA )
			{
				maxB = walls[i];
				indexMaxB = i;
				ans += ( std::min( maxA, maxB )*( indexMaxB - indexMaxA - 1 ) - sum );
				maxA = maxB;
				indexMaxA = i;
				sum = 0;
			}
			else
			{
				sum += walls[i];
			}
		}
	}
	return ans;
}

int main()
{
	{
		int walls[] = { 3, 0, 1, 3, 0, 5 };
		const int size = sizeof( walls ) / sizeof( walls[0] );

		std::cout << getUnitsOfWater( walls, size ) << std::endl;
	}

	{
		int walls[] = { 2, 1, 2 };
		const int size = sizeof( walls ) / sizeof( walls[0] );

		std::cout << getUnitsOfWater( walls, size ) << std::endl;
	}

	std::cin.get();
	return 0;
}