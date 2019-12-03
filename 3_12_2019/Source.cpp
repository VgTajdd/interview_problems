/*

This problem was asked by Facebook.

Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
	Output : "bab"
	Note : "aba" is also a valid answer.
	Example 2 :

	Input : "cbbd"
	Output : "bb"

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void longestPalindromeHelper( const string& s, const int& position, const bool& useDoubleChar, int& lPropagation, int& rPropagation )
{
	lPropagation = position;
	rPropagation = position;
	if ( useDoubleChar )
	{
		lPropagation++;
	}
	while ( lPropagation - 1 >= 0 && rPropagation + 1 < s.size() )
	{
		if ( s[lPropagation - 1] != s[rPropagation + 1] )
		{
			break;
		}
		lPropagation--;
		rPropagation++;
	}
}

string longestPalindrome( const string& s )
{
	int maxLength = 0;
	int startMaxLength = 0;
	int l, r;
	for ( int i = 0; i < s.size(); i++ )
	{
		longestPalindromeHelper( s, i, false, l, r );
		if ( r - l + 1 > maxLength )
		{
			maxLength = r - l + 1;
			startMaxLength = l;
		}
		if ( i < s.size() - 1 )
		{
			longestPalindromeHelper( s, i, true, l, r );
			if ( r - l + 1 > maxLength )
			{
				maxLength = r - l + 1;
				startMaxLength = l;
			}
		}
	}
	if ( maxLength <= 0 )
	{
		return "";
	}
	return s.substr( startMaxLength, maxLength );
}

int main()
{
	std::vector< std::string > strings = { "abba", "abbd", "abax", "xyz", "a", "", "reconocer" };

	for ( const auto& str : strings )
	{
		std::cout << "[" << str.c_str() << "] -> [" << longestPalindrome( str ) << "]" << std::endl;
	}

	std::cin.get();
	return 0;
}