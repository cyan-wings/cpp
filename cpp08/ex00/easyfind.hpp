#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

# include <algorithm>
# include <iostream>

template<typename T>
typename T::iterator	easyfind( T &container, int value );

class TargetNotFoundException : public std::exception
{
	public:
		char const		*what( void ) const throw();
};

# include "easyfind.tpp"

#endif
