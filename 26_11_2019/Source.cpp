/*

This problem was asked by Facebook.

Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular expression and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray", your function should return true. The same regular expression on the string "raymond" should return false.

Given the regular expression ".*at" and the string "chat", your function should return true. The same regular expression on the string "chats" should return false.

*/

#include <iostream>
#include <string>
#include <vector>

struct RegExpRule
{
	RegExpRule( const bool _uniqueValue, const bool _multiple, const char _value ) :
		uniqueValue( _uniqueValue ), multiple( _multiple ), value( _value ) {}
	bool uniqueValue;
	bool multiple;
	char value;
};

struct RegExp
{
	RegExp( const std::string& expression ) : m_expression( expression ) { createRules(); }
	void createRules()
	{
		for ( const auto& c : m_expression )
		{
			if ( c == '.' )
			{
				auto rule = RegExpRule( false, false, 'a' );
				m_rules.push_back( rule );
			}
			else if ( c == '*' && !m_rules.empty() )
			{
				m_rules.back().multiple = true;
			}
			else
			{
				auto rule = RegExpRule( true, false, c );
				m_rules.push_back( rule );
			}
		}
	}
	void helper( const std::string& word, bool& found, int indexWord, int indexRule )
	{
		if ( found )
		{
			return;
		}
		if ( indexRule == m_rules.size() && indexWord == word.size() )
		{
			found = true;
			return;
		}
		if ( indexRule == m_rules.size() || indexWord == word.size() )
		{
			return;
		}

		const auto& rule = m_rules[indexRule];
		if ( rule.multiple )
		{
			if ( !rule.uniqueValue )
			{
				for ( int i = indexWord; i <= word.size(); i++ )
				{
					helper( word, found, i, indexRule + 1 );
				}
			}
			else if ( rule.value == word[indexWord] )
			{
				helper( word, found, indexWord, indexRule + 1 );
				for ( int i = indexWord + 1; i <= word.size(); i++ )
				{
					auto findStr = std::string( i - indexWord, rule.value );
					if ( word.find( findStr, indexWord ) == indexWord )
					{
						helper( word, found, i, indexRule + 1 );
					}
				}
			}
		}
		else
		{
			if ( !rule.uniqueValue )
			{
				helper( word, found, indexWord + 1, indexRule + 1 );
			}
			else if ( rule.value == word[indexWord] )
			{
				helper( word, found, indexWord + 1, indexRule + 1 );
			}
		}
	}
	bool matches( const std::string& word )
	{
		bool found = false;
		helper( word, found, 0, 0 );
		return found;
	}
	std::string m_expression;
	std::vector< RegExpRule > m_rules;
};

int main()
{
	std::cout << RegExp( "ra." ).matches( "ray" ) << std::endl;
	std::cout << RegExp( "ra." ).matches( "raymond" ) << std::endl;
	std::cout << RegExp( "ra.*" ).matches( "raymond" ) << std::endl;
	std::cout << RegExp( ".*at" ).matches( "chat" ) << std::endl;
	std::cout << RegExp( ".*at" ).matches( "cheaeaat" ) << std::endl;
	std::cout << RegExp( "..a*t" ).matches( "chaabaat" ) << std::endl;
	std::cout << RegExp( "..a*t" ).matches( "chaaaaat" ) << std::endl;
	std::cout << RegExp( ".*at" ).matches( "chats" ) << std::endl;

	std::cin.get();
	return 0;
}