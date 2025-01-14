#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <vector>
# include <deque>
# include <list>
# include <iostream>

class PmergeMe
{
	private:
		PmergeMe( void );
		PmergeMe( PmergeMe const &pmergeme );
		PmergeMe	&operator=( PmergeMe const &other );
		~PmergeMe( void );

		template <typename Cont>
		static typename Cont::iterator	binarySearch(Cont &cont, const typename Cont::value_type &val);

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
typename Cont::iterator	PmergeMe::binarySearch(Cont &cont, const typename Cont::value_type &val)
{
	typename Cont::iterator	low = cont.begin();
	typename Cont::iterator	high = cont.end();
	typename Cont::iterator	mid;

	while (low != high)
	{
		mid = low;
		std::advance( mid, std::distance( low, high ) / 2 );
		
		if ( *mid < val )
			low = ++mid;
		else
			high = mid;
	}
	return ( low );
}

template <typename Cont>
void	PmergeMe::merge( Cont &left, Cont &right, Cont &merged )
{
	merged.clear();

	typename Cont::iterator it_left = left.begin();
	typename Cont::iterator it_right = right.begin();

	while (it_left != left.end())
	{
		typename Cont::iterator	pos = binarySearch(merged, *it_left);
		merged.insert(pos, *it_left);
		++it_left;
	}

	while (it_right != right.end())
	{
		typename Cont::iterator	pos = binarySearch(merged, *it_right);
		merged.insert(pos, *it_right);
		++it_right;
	}
}

template <typename Cont>
void	PmergeMe::sort( Cont &cont )
{
	if ( cont.size() <= 1 )
		return ;

	typename Cont::iterator	mid = cont.begin();
	size_t					midIndex = cont.size() / 2;
	for (size_t i = 0; i < midIndex; ++i)
		++mid;

	Cont left(cont.begin(), mid);
	Cont right(mid, cont.end());

	sort( left );
	sort( right );
	merge( left, right, cont );
}

template <typename Cont>
void	PmergeMe::printCont( Cont &cont )
{
	for (typename Cont::iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif
