/*

This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?

*/

#include <iostream>
#include <algorithm>

int rec( int arr[], int n )
{
	if ( n == 0 ) return 0;
	if ( n == 1 ) return arr[0];
	if ( n == 2 ) return std::max( arr[0], arr[1] );
	return std::max( arr[n - 1] + rec( arr, n - 2 ), arr[n - 2] + rec( arr, n - 3 ) );
}

int result( int arr[], int n )
{
	return rec( arr, n );
}

int main()
{
	int arr[] = { 2, 4, 6, 2, 5 };
	//int arr[] = { 5, 1, 1, 5 };
	int n = sizeof( arr ) / sizeof( arr[0] );

	std::cout << result( arr, n ) << std::endl;

	std::cin.get();
	return 0;
}