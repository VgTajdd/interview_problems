/*

This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.

*/

#include <iostream>
#include <vector>
#include <algorithm>

void solveProblem( int data[], const int n, const int k )
{
	std::vector< int > t1( k, 0 );
	std::vector< int > t2( k, 0 );
	int tt = 0;
	for ( int i = 0; i < n; i++ )
	{
		tt = data[i];
		t2[0] = data[i];
		for ( int j = 1; j < k; j++ )
		{
			t2[j] = std::max( t1[j - 1], tt );
			tt = t2[j];
		}
		t1 = t2;
		if ( i >= k - 1 )
		{
			std::cout << tt << std::endl;
		}
	}
}

int main()
{
	int data[] = { 10, 5, 2, 7, 8, 7 };
	const int n = sizeof( data ) / sizeof( data[0] );
	const int k = 3;
	solveProblem( data, n, k );
	std::cin.get();
	return 0;
}