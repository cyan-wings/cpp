#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

# include <stdexcept>

template<typename T>
class Array
{
	private:
		unsigned int		_size;
		T					*_data;

	public:
		Array( void );
		Array( unsigned int n );
		Array( Array const &a );
		Array<T>			&operator=( Array const &other );
		~Array( void );

		T					&operator[]( unsigned int idx );
		T const				&operator[]( unsigned int idx ) const;
		unsigned int		size( void ) const;

		class OutOfBoundException : public std::exception
		{
			public:
				char const	*what( void ) const throw();
		};
};

template<typename T>
std::ostream				&operator<<( std::ostream &out, Array<T> const &array );

# include "Array.tpp"

#endif
