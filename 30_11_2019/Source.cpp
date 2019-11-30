/*

This problem was asked by Amazon.

Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.

*/

#include <iostream>
#include <string>
#include <sstream>

std::string RLEncode( const std::string& str )
{
	std::string ans;

	char currentChar = '*';
	int currentSize = 0;

	for ( const auto& c : str )
	{
		if ( currentChar != c )
		{
			if ( currentSize != 0 )
			{
				ans.append( std::to_string( currentSize ) );
				ans.append( std::string( 1, currentChar ) );
			}
			currentChar = c;
			currentSize = 0;
		}
		currentSize++;
	}

	if ( currentSize != 0 )
	{
		ans.append( std::to_string( currentSize ) );
		ans.append( std::string( 1, currentChar ) );
	}

	return ans;
}

std::string RLDecode( const std::string& str )
{
	std::string ans;

	for ( int i = 0; i < str.size() / 2; i++ )
	{
		std::stringstream stream;
		stream << str[2 * i];
		int times;
		stream >> times;
		ans.append( std::string( times, str[( 2 * i ) + 1] ) );
	}

	return ans;
}

int main()
{
	std::string str = "AAAABBBCCDAA";

	std::string encoded = RLEncode( str );
	std::cout << encoded.c_str() << std::endl;

	std::string decoded = RLDecode( encoded );
	std::cout << decoded.c_str() << std::endl;

	std::cin.get();
	return 0;
}