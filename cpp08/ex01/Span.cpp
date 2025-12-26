#include "Span.hpp"
#include <climits>
#include <iostream>

Span::Span( unsigned int n ) : _maxSize( n ), _size( 0 ) { _array.reserve( n ); }

Span::Span( Span const &s ) : _maxSize( s._maxSize ), _array( s._array ), _size( s._size ) {}

Span			&Span::operator=( Span const &other )
{
	if (this == &other)
		return ( *this );
	_array.clear();
	_maxSize = other._maxSize;
	_array = other._array;
	_size = other._size;
	return ( *this );
}

Span::~Span( void ) {}

unsigned int	Span::getMaxSize( void ) const { return ( _maxSize ); }

unsigned int	Span::getSize( void ) const { return ( _size ); }

std::vector<int>	Span::getArray( void ) const { return (_array); }

char const		*Span::AddToFullSpanException::what( void ) const throw() { return ( "Cannot add to full span." ); }

void			Span::addNumber( int number )
{
	if (_size >= _maxSize)
		throw ( Span::AddToFullSpanException() );
	_array.push_back( number );
	++_size;
}

void			Span::addRandomNumbers( unsigned int amount )
{
	srand(static_cast<unsigned int>(time(0)));
	unsigned int	i = -1;

	while (++i < amount)
	{
		try
		{
			addNumber(rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

char const		*Span::CannotGetSpanException::what( void ) const throw() { return ( "Not enough elements to find span." ); }


unsigned int	Span::shortestSpan( void ) const
{
	if (_size < 2)
		throw ( Span::CannotGetSpanException() );

	std::vector<int>	sorted = _array;
	std::sort(sorted.begin(), sorted.end());

	unsigned int		minSpan = UINT_MAX;

	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int	diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return ( minSpan );
}

unsigned int	Span::longestSpan( void ) const
{
	if (_size < 2)
		throw ( Span::CannotGetSpanException() );
	return ( *std::max_element(_array.begin(), _array.end()) - *std::min_element(_array.begin(), _array.end()) );
}

std::ostream				&operator<<( std::ostream &out, Span const &s )
{
	out << "Span of size " << s.getSize() << "/" << s.getMaxSize() << ": [";
	for (unsigned int i = 0; i < s.getSize(); ++i)
	{
		out << s.getArray()[i];
		if (i != s.getSize() - 1)
			out << ", ";
	}
	out << "]";
    return ( out );
}
