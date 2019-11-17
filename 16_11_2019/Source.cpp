/*

Find the Running Median

Given an input stream of  integers, you must perform the following task for each  integer:

Add the  integer to a running list of integers.
Find the median of the updated list (i.e., for the first element through the  element).
Print the list's updated median on a new line. The printed value must be a double-precision number scaled to 1 decimal place (i.e., 1.4 format).

*/

#include <iostream>
#include <iomanip>
#include <vector>

void printRunningMedian( const std::vector< int >& v ) // Linear time.
{
	std::cout << std::fixed << std::setprecision( 1 );
	
	std::vector< int > buffer;

	int countOfNumbers = 1;
	double sum = .0;

	for ( auto n : v )
	{
		sum += n;
		std::cout << sum / double( countOfNumbers++ ) << std::endl;
	}
}

int main()
{
	std::vector< int > v = { 2,3,4,5,6,10 };
	printRunningMedian( v );
	std::cin.get();
	return 0;
}