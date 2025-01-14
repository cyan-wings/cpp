#include "PmergeMe.hpp"

int	PmergeMe::vectorBinarySearch( std::vector<int>& merged, int val )
{
	int		low = 0;
	int		high = merged.size();
	int		mid;

	while (low < high)
	{
		mid = low + (high - low) / 2;
		if ( merged[mid] < val )
			low = mid + 1;
		else
			high = mid;
	}
	return ( low );
}

void	PmergeMe::vectorMerge( std::vector<int> &left, std::vector<int> &right, std::vector<int> &merged )
{
	merged.clear();


	for (unsigned int i = 0; i < left.size(); ++i)
	{
		int pos = vectorBinarySearch(merged, left[i]);
		merged.insert(merged.begin() + pos, left[i]);
	}

	for (unsigned int i = 0; i < right.size(); ++i)
	{
		int pos = vectorBinarySearch(merged, right[i]);
		merged.insert(merged.begin() + pos, right[i]);
	}
}

void	PmergeMe::vectorSort( std::vector<int> &c1 )
{
	if (c1.size() <= 1)
		return ;

	std::vector<int>	left(c1.begin(), c1.begin() + c1.size() / 2);
	std::vector<int>	right(c1.begin() + c1.size() / 2, c1.end());

	vectorSort( left );
	vectorSort( right );
	vectorMerge( left, right, c1 );
}

void	PmergeMe::compute( std::vector<int> const &input )
{
	std::vector<int>	c1 = input;
	std::deque<int>		c2(input.begin(), input.end());

	std::cout << "Before sorting: ";
	for (unsigned int i = 0; i < c1.size(); i++) {
		std::cout << c1[i] << " ";
	}
	std::cout << std::endl;

	vectorSort(c1);

	std::cout << "After sorting: ";
	for (unsigned int i = 0; i < c1.size(); i++) {
		std::cout << c1[i] << " ";
	}
	std::cout << std::endl;
	return ;
}