/*

This problem was asked by Google.

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

*/

#include <iostream>
#include <vector>
#include <string>

std::string convert( const std::string& s, int numRows )
{
	if ( numRows == 1 || s.empty() )
		return s;
	int sizeOfSubArray = ( numRows * 2 ) - 2;
	int numOfSubArrays = s.size() / sizeOfSubArray;
	std::vector<std::string> rows;
	rows.resize( numRows );
	for ( int i = 0; i <= numOfSubArrays; i++ )
	{
		int offset = i * sizeOfSubArray;
		for ( int j = 0; j < sizeOfSubArray; j++ )
		{
			if ( s.size() == offset + j )
			{
				break;
			}
			if ( j < numRows )
			{
				rows[j].push_back( s[offset + j] );
			}
			else
			{
				rows[( 2 * numRows ) - j - 2].push_back( s[offset + j] );
			}
		}
	}
	std::string ans;
	for ( int i = 0; i < numRows; i++ )
	{
		ans += rows[i];
	}
	return ans;
}

int main()
{
	std::cout << convert( "PAYPALISHIRING", 3 ).c_str() << std::endl;
	std::cout << convert( "PAYPALISHIRING", 4 ).c_str() << std::endl;
	std::cin.get();
	return 0;
}