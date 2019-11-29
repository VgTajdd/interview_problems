/*

This problem was asked by Palantir.

Write an algorithm to justify text.

Given a sequence of words and an integer line length k, return a list of strings which represents each line, fully justified.

More specifically, you should have as many words as possible in each line. There should be at least one space between each word.

Pad extra spaces when necessary so that each line has exactly length k.

Spaces should be distributed as equally as possible, with the extra spaces, if any, distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly

*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> getJustifiedText( const std::vector<std::string>& text, const size_t k )
{
	std::vector< std::string > ans;

	std::vector< std::vector<std::string> > lines;
	std::vector< int > lineSizes;

	{
		std::vector<std::string> line;
		size_t lineSize = 0;
		for ( const auto& word : text )
		{
			if ( line.empty() )
			{
				line.push_back( word );
				lineSize += word.size();
			}
			else
			{
				if ( lineSize + word.size() + 1 > k )
				{
					lines.push_back( std::move( line ) );
					lineSizes.push_back( int( lineSize ) );
					line.clear();
					line.push_back( word );
					lineSize = word.size();
				}
				else
				{
					line.push_back( word );
					lineSize += word.size() + 1;
				}
			}
		}

		if ( !line.empty() )
		{
			lines.push_back( std::move( line ) );
			lineSizes.push_back( int( lineSize ) );
		}
	}

	for ( unsigned int i = 0; i < lines.size(); i++ )
	{
		const auto& line = lines[i];
		const int lineSize = lineSizes[i];

		if ( line.size() == 1 )
		{
			std::string t = line[0] + std::string( k - lineSize, ' ' );
			ans.push_back( std::move( t ) );
			continue;
		}
		int lineSizeNoSpaces = ( lineSize - ( line.size() - 1 ) );
		const size_t baseSpacing = ( k - lineSizeNoSpaces ) / ( line.size() - 1 );
		std::vector< int > spacings( line.size() - 1, baseSpacing );
		int toFill = k - lineSizeNoSpaces - ( baseSpacing * ( line.size() - 1 ) );
		for ( int j = 0; j < toFill; j++ )
		{
			spacings[j]++;
		}
		std::string t;
		t.reserve( k );
		t = line[0];
		for ( int j = 0; j < spacings.size(); j++ )
		{
			t.append( std::string( spacings[j], ' ' ) );
			t.append( line[j+1] );
		}
		ans.push_back( std::move( t ) );
	}

	return ans;
}

int main()
{
	int k = 16;
	std::vector< std::string > words = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
	auto justifiedText = getJustifiedText( words, k );

	std::cout << std::string( k, '*' ) << std::endl;

	for ( const auto& jt : justifiedText )
	{
		std::cout << jt.c_str() << std::endl;
	}

	std::cin.get();
	return 0;
}