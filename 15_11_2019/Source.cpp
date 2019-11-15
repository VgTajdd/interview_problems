/*

This problem was asked by Google.

The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.

*/

#include <iostream>
#include <time.h>

double getRandomNumber() // 0 - 1
{
	return double( rand() ) / RAND_MAX;
}

double calculatePi( const int decimals )
{
	const int totalPoints = std::pow( 10, decimals );
	int pointsInsideCircle = 0;
	double x, y;
	for ( int i = 0; i < totalPoints; i++ )
	{
		x = getRandomNumber() * 2 - 1;
		y = getRandomNumber() * 2 - 1;
		x = x * x + y * y;
		x = std::pow( x, 0.5 );
		if ( x <= 1 )
		{
			pointsInsideCircle++;
		}
	}
	return double( 4 * pointsInsideCircle ) / totalPoints;
}

int main()
{
	/* initialize random seed: */
	srand( time( 0 ) );

	std::cout << calculatePi( 3 ) << std::endl;

	std::cin.get();
	return 0;
}