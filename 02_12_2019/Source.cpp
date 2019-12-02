/*

This problem was asked by Google.

The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other.

For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int getScore( const std::string& longStr, const std::string& shortStr, const std::vector< int >& deletions )
{
	int ans = 0;
	int j = 0;
	for ( int i = 0; i < longStr.size(); i++ )
	{
		if ( std::find( deletions.begin(), deletions.end(), i ) == deletions.end() )
		{
			if ( longStr[i] == shortStr[j++] )
			{
				ans++;
			}
		}
	}
	return ans;
}

void helper( const std::string& longStr, const std::string& shortStr, const std::vector< int >& deletions, std::vector< int >& bestDeletions, int& maxScore )
{
	if ( longStr.size() - shortStr.size() == deletions.size() )
	{
		int score = getScore( longStr, shortStr, deletions );
		if ( score > maxScore )
		{
			maxScore = score;
			bestDeletions = deletions;
		}
	}
	else
	{
		for ( int i = 0; i < longStr.size(); i++ )
		{
			if ( std::find( deletions.begin(), deletions.end(), i ) != deletions.end() )
				continue;
			auto newDeletions = deletions;
			newDeletions.push_back( i );
			helper( longStr, shortStr, newDeletions, bestDeletions, maxScore );
		}
	}
}

int getEditDistance( const std::string& str1, const std::string& str2 )
{
	int maxScore = 0;
	std::vector< int > deletions, bestDeletions;
	size_t minSize = std::min( str2.size(), str1.size() );
	if ( str1.size() > str2.size() )
	{
		helper( str1, str2, deletions, bestDeletions, maxScore );
	}
	else
	{
		helper( str2, str1, deletions, bestDeletions, maxScore );
	}
	return bestDeletions.size() + ( minSize - maxScore );
}

int main()
{
	std::cout << getEditDistance( "kitten", "sitting" ) << std::endl;
	std::cout << getEditDistance( "ted", "edi" ) << std::endl;

	std::cin.get();
	return 0;
}