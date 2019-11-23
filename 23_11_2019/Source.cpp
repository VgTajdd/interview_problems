/*

This problem was asked by Microsoft.

Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list.

If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].

*/

#include <iostream>
#include <vector>
#include <string>

std::vector< std::string > getOriginalSentence( const std::vector< std::string >& parts, const std::string& allTogether )
{
	std::vector< std::string > ans;
	int index = 0;
	while ( index != allTogether.size() )
	{
		bool found = false;
		for ( const auto& str : parts )
		{
			if ( allTogether.find( str, index ) == index )
			{
				found = true;
				ans.push_back( str );
				index += str.size();
				break;
			}
		}
		if ( !found )
		{
			return {};
		}
	}
	return ans;
}

int main()
{
	std::vector< std::string > parts;
	parts.push_back( "quick" );
	parts.push_back( "brown" );
	parts.push_back( "the" );
	parts.push_back( "fox" );
	std::string allTogether = "thequickbrownfox";
	auto ans = getOriginalSentence( parts, allTogether );
	for ( const auto& str : ans )
	{
		std::cout << str.c_str() << " ";
	}
	std::cin.get();
	return 0;
}