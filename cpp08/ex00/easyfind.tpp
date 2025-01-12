#ifndef __EASYFIND_TPP__
# define __EASYFIND_TPP__

template<typename T>
typename T::iterator	easyfind( T &container, int value )
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);

	if ( it == container.end() )
		throw ( TargetNotFoundException() );
	return ( it );
}

char const				*TargetNotFoundException::what( void ) const throw()
{ return ( "No such target in container." ); }

#endif