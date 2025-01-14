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

		template <typename Cont>
		static int	binarySearch( Cont &merged, int val );

		template <typename Cont>
		static void	merge( Cont &left, Cont &right, Cont &merged );

	public:
		template <typename Cont>
		static void printCont( Cont &cont );
		
		template <typename Cont>
		static void	sort( Cont &cont );

		static void	compute( std::vector<int> const &input );
};

template <typename Cont>
int	PmergeMe::binarySearch( Cont &merged, int val )
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

template <typename Cont>
void	PmergeMe::merge( Cont &left, Cont &right, Cont &merged )
{
	merged.clear();

	for (unsigned int i = 0; i < left.size(); ++i)
	{
		int pos = binarySearch(merged, left[i]);
		merged.insert(merged.begin() + pos, left[i]);
	}

	for (unsigned int i = 0; i < right.size(); ++i)
	{
		int pos = binarySearch(merged, right[i]);
		merged.insert(merged.begin() + pos, right[i]);
	}
}

template <typename Cont>
void	PmergeMe::sort( Cont &cont )
{
	if ( cont.size() <= 1 )
		return ;

	Cont	left( cont.begin(), cont.begin() + cont.size() / 2 );
	Cont	right( cont.begin() + cont.size() / 2, cont.end() );

	sort( left );
	sort( right );
	merge( left, right, cont );
}

template <typename Cont>
void	PmergeMe::printCont( Cont &cont )
{
	for ( unsigned int i = 0; i < cont.size(); ++i )
		std::cout << cont[i] << " ";
	std::cout << std::endl;
}

#endif
