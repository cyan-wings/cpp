#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <vector>
# include <deque>
# include <iostream>

class PmergeMe
{
	private:
		PmergeMe( void );
		PmergeMe( PmergeMe const &pmergeme );
		PmergeMe	&operator=( PmergeMe const &other );
		~PmergeMe( void );

		static int	vectorBinarySearch( std::vector<int>& merged, int val );
		static void	vectorMerge( std::vector<int> &left, std::vector<int> &right, std::vector<int> &merged );
		static void	vectorSort( std::vector<int> &c1 );

	public:
		static void	compute( std::vector<int> const &input );
};

#endif
