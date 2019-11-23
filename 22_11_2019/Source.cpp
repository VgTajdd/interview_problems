/*

This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.

*/

#include <iostream>
#include <vector>

struct Segment
{
	Segment( const int _min, const int _max ) :min( _min ), max( _max ) {}
	int min;
	int max;
};

bool areOverlapped( const Segment& a, const Segment& b )
{
	if ( a.max > b.min && b.min > a.min )
	{
		return true;
	}
	if ( a.max > b.max && b.max > a.min )
	{
		return true;
	}
	return false;
}

int countNecessaryClassrooms( const std::vector< Segment >& segments )
{
	std::vector < std::vector< Segment > > spaces;
	for ( const auto& segment : segments )
	{
		bool inserted = false;
		for ( auto& space : spaces )
		{
			bool isPossibleToInsert = true;
			for ( const auto& s : space )
			{
				if ( areOverlapped( s, segment ) )
				{
					isPossibleToInsert = false;
					break;
				}
			}
			if ( isPossibleToInsert )
			{
				space.push_back( segment );
				inserted = true;
				break;
			}
		}
		if ( !inserted )
		{
			std::vector< Segment > newSpace;
			newSpace.push_back( segment );
			spaces.push_back( std::move( newSpace ) );
		}
	}
	return spaces.size();
}

int main()
{
	std::vector< Segment > segments;
	Segment a( 30, 75 );
	Segment b( 0, 50 );
	Segment c( 60, 150 );
	segments.push_back( a );
	segments.push_back( b );
	segments.push_back( c );

	std::cout << countNecessaryClassrooms( segments ) << std::endl;

	std::cin.get();
	return 0;
}