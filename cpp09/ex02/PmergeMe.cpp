#include "PmergeMe.hpp"

void	PmergeMe::compute( std::vector<int> const &input )
{
	std::vector<int>	c1 = input;
	std::deque<int>		c2(input.begin(), input.end());
	std::list<int>		c3(input.begin(), input.end());
	clock_t				start;
	double				duration;

	start = clock();
	sort(c1);
	duration = ( double )( clock() - start ) / CLOCKS_PER_SEC * 1000000;

	//std::cout << "After sorting using Vector: ";
	//printCont( c1 );
	std::cout << "Time to process a range of " << c1.size() << " elements with std::vector<int>\t: ";
	std::cout << duration << " us" << std::endl;

	start = clock();
	sort(c2);
	duration = ( double )( clock() - start ) / CLOCKS_PER_SEC * 1000000;

	//std::cout << "After sorting using Deque: ";
	//printCont( c2 );
	std::cout << "Time to process a range of " << c2.size() << " elements with std::deque<int>\t: ";
	std::cout << duration << " us" << std::endl;

	start = clock();
	sort(c3);
	duration = ( double )( clock() - start ) / CLOCKS_PER_SEC * 1000000;

	//std::cout << "After sorting using List: ";
	//printCont( c3 );
	std::cout << "Time to process a range of " << c3.size() << " elements with std::list<int>\t: ";
	std::cout << duration << " us" << std::endl;
}
