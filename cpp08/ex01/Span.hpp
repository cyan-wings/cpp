#ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_array;
		unsigned int		_size;

	public:
		Span( unsigned int n );
		Span( Span const &s );
		Span 				&operator=( Span const &other );
		~Span( void );

		unsigned int		getMaxSize( void ) const;
		unsigned int		getSize( void ) const;
		std::vector<int>	getArray( void ) const;

		class AddToFullSpanException : public std::exception
		{
			public:
				char const	*what( void ) const throw();
		};
		void				addNumber( int number );
		void				addRandomNumbers( unsigned int amount );

		class CannotGetSpanException : public std::exception
		{
			public:
				char const	*what( void ) const throw();
		};
		unsigned int		shortestSpan( void ) const;
		unsigned int		longestSpan( void ) const;
};

std::ostream				&operator<<( std::ostream &out, Span const &s );

#endif
