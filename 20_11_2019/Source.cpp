/*

This problem was asked by Facebook.

A builder is looking to build a row of N houses that can be of K different colors.

He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the minimum cost which achieves this goal.

*/

#include <iostream>
#include <vector>

int getCost( int theArray[], const int colorsCount, const int housesCount )
{
	int lastHouseColor = -1;
	int cost = 0;
	for ( int h = 0; h < housesCount; h++ )
	{
		int index = ( h * colorsCount ) + ( lastHouseColor % colorsCount == 0 ? 1 : 0 );
		for ( int c = 0; c < colorsCount; c++ )
		{
			if ( c == lastHouseColor % colorsCount ) continue;
			if ( theArray[h*colorsCount + c] < theArray[index] )
			{
				index = h * colorsCount + c;
			}
		}
		cost += theArray[index];
		lastHouseColor = index;
	}
	return cost;
}

int main()
{
	int colorsCount = 3;
	int housesCount = 5;
	int theArray[] = {
		1,2,3,
		4,5,6,
		7,8,9,
		10,11,12,
		13,14,15
	};

	std::cout << getCost( theArray, colorsCount, housesCount ) << std::endl;

	std::cin.get();
	return 0;
}