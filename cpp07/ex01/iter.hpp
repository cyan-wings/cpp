#ifndef __ITER_HPP__
# define __ITER_HPP__

template<typename T>
void	iter( T *addr, int size, void (*f)(T &) )
{
	for (int i = 0; i < size; ++i)
		f(addr[i]);
}

#endif
