#ifndef __ARRAY_TPP__
# define __ARRAY_TPP__

# include <iostream>

template<typename T>
Array<T>::Array( void ) : _size( 0 ), _data( NULL ) {}

template<typename T>
Array<T>::Array( unsigned int n ) : _size( n ), _data( new T[n] )
{
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = T();
}

template<typename T>
Array<T>::Array( Array const &a ) : _size( a._size ), _data( new T[a._size] )
{
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = a._data[i];
}

template<typename T>
Array<T>		&Array<T>::operator=( Array const &other )
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
	return ( *this );
}

template<typename T>
Array<T>::~Array( void ) { delete[] _data; }

template<typename T>
T 				&Array<T>::operator[]( unsigned int idx )
{
	if (idx >= _size)
		throw Array<T>::OutOfBoundException();
	return ( _data[idx] );
}

template<typename T>
T const			&Array<T>::operator[]( unsigned int idx ) const
{
	if (idx >= _size)
		throw Array<T>::OutOfBoundException();
	return ( _data[idx] );
}

template<typename T>
unsigned int	Array<T>::size( void ) const { return (_size); }

template<typename T>
char const *Array<T>::OutOfBoundException::what( void ) const throw() { return ( "Index out of bounds." ); }

template <typename T>
std::ostream	&operator<<( std::ostream& out, Array<T> const &array )
{
	unsigned int	size = array.size();

	out << "Array = { ";
	for (unsigned int i = 0; i < size; ++i)
	{
		out << array[i];
		if (i != size - 1)
			out << ", ";
	}
	out << " }";
	return ( out );
}

#endif
