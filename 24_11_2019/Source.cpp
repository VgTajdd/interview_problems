/*

This problem was asked by Google.

You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start.

If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]

and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7,
since we would need to go through (1, 2) because there is a wall everywhere else on the second row.

*/

#include <iostream>
#include <vector>

struct Maze
{
	Maze( const int _m, const int _n ) : m( _m ), n( _n )
	{
		a = new bool*[m];
		for ( int i = 0; i < m; i++ )
		{
			a[i] = new bool[n];
			for ( int j = 0; j < n; j++ )
			{
				a[i][j] = false;
			}
		}
		init();
	}
	void init()
	{
		a[1][0] = true;
		a[1][1] = true;
		a[1][3] = true;
	}
	bool getValue( const int r, const int c, bool& inside )
	{
		inside = false;
		if ( r > m - 1 || r < 0 ) return true;
		if ( c > n - 1 || c < 0 ) return true;
		inside = true;
		return a[r][c];
	}
	std::vector< int > findPath( const int startR, const int startC, const int endR, const int endC )
	{
		std::vector< int > path;

		bool foundPath = false;

		std::vector< int > directions = { -1,0,0,-1,1,0,0,1 };

		std::vector< bool > visitedNodes( m*n, false );
		std::vector< int > parents( m*n, -1 );
		std::vector< int > queue;
		queue.push_back( startC + startR * m );
		bool inside = false;
		int r, c, nr, nc;

		while ( !foundPath )
		{
			if ( queue.empty() )
			{
				break;
			}
			auto currentIndex = queue.front();
			r = currentIndex / m;
			c = currentIndex % m;
			visitedNodes[currentIndex] = true;
			for ( int d = 0; d < 4; d++ )
			{
				nr = r + directions[d * 2];
				nc = c + directions[( d * 2 ) + 1];

				bool occupied = getValue( nr, nc, inside );
				if ( !inside || occupied ) continue;
				if ( visitedNodes[(m * nr) + nc] ) continue;
				parents[(m * nr + nc)] = (r * m) + c;
				if ( nr == endR && nc == endC )
				{
					foundPath = true;
					break;
				}
				queue.push_back( ( nr*m ) + nc );
			}
			queue.erase( queue.begin() );
		}

		if ( foundPath )
		{
			c = endC;
			r = endR;
			while ( parents[( r *m ) + c] != ( startR *m ) + startC )
			{
				path.push_back( ( r *m ) + c );
				r = parents[( r *m ) + c] / m;
				c = parents[( r *m ) + c] % m;
			}
		}

		return path;
	}
	bool** a;
	int m;
	int n;
};

int main()
{
	Maze a( 4, 4 );
	auto path = a.findPath( 3, 0, 0, 0 );

	std::cout << path.size() + 2 << std::endl;

	std::cin.get();
	return 0;
}