#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <vector>

static bool	isValidInteger( std::string const &input )
{
	std::stringstream	ss(input);
	int					num;

	ss >> num;
	return ( !ss.fail() && ss.eof() );
}

static void	performSort( std::vector<int> &numbers )
{
	std::cout << "Before:\t";
	PmergeMe::printCont( numbers );

	PmergeMe::sort( numbers );

	std::cout << "After:\t";
	PmergeMe::printCont( numbers );
}

int	main( int argc, char **argv )
{
	if (argc < 3)
		return ( std::cout << "Error: Must be at least 2 integer parameters." << std::endl, 1 );
	
	std::vector<int>		numbers;
	for (int i = 1; i < argc; ++i)
	{
		if (!isValidInteger(argv[i])) {
			std::cerr << "Error: Invalid input '" << argv[i] << "'. All inputs must be integers." << std::endl;
			return 1;
		}
		std::stringstream ss(argv[i]);
		int num;
		ss >> num;
		numbers.push_back(num);
	}
	performSort( numbers );
	PmergeMe::compute( numbers );
	return ( 0 );
}