/*

This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

*/

#include <iostream>
#include <string>

std::string getLongestSubString( std::string& s, const int k )
{
	std::string ans, t;
	const int strSize = s.size();
	for ( int i = 0; i < strSize - k; i++ )
	{
		t.clear();
		t = s.substr( i, k );
		for ( int j = i + k; j < strSize; j++ )
		{
			if ( t.find( s[j] ) != std::string::npos )
			{
				t.append( std::string( 1, s[j] ) );
			}
			else
			{
				break;
			}
		}
		if ( t.size() > ans.size() )
		{
			ans = t;
		}
	}
	return ans;
}

int main()
{
	std::string s = "abcba";
	int k = 2;
	std::cout << getLongestSubString( s, k ).c_str() << std::endl;

	std::cin.get();
	return 0;
}