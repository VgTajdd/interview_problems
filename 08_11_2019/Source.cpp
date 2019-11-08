/*

This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.

*/

#include <iostream>

int helper( char message[], int n )
{
	if ( n == 0 ) return 0;
	if ( n == 1 ) return 1;
	if ( n == 2 )
	{
		if ( ( message[n - 2] < '2' ) || ( message[n - 2] == '2' && message[n - 1] < '7' ) )
		{
			return 2;
		}
		return 1;
	}
	int count = 0;
	if ( ( message[n - 2] < '2' ) || ( message[n - 2] == '2' && message[n - 1] < '7' ) )
	{
		count += helper( message, n - 2 );
	}
	count += helper( message, n - 1 );
	return count;
}

int waysToDecode( char message[], int n )
{
	return helper( message, n );
}

int main()
{
	char message[] = "111";
	int n = ( sizeof( message ) / sizeof( message[0] ) ) - 1;

	std::cout << waysToDecode( message, n ) << std::endl;

	std::cin.get();
	return 0;
}