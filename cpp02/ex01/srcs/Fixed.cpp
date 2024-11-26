#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _val(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed( Fixed const &f )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed			&Fixed::operator=( Fixed const &other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_val = other._val;
	return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int				Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

void			Fixed::setRawBits( int const raw ) { this->_val = raw; }

Fixed::Fixed( int const n ) : _val(n << BITS) { std::cout << "Int constructor called" << std::endl; }

Fixed::Fixed( float const d ) : _val(roundf(d * (1 << BITS))) { std::cout << "Float constructor called" << std::endl; }

int				Fixed::toInt() const { return (_val >> BITS); }

float			Fixed::toFloat() const { return ((float)_val / (float)(1 << BITS)); }

std::ostream	&operator<<( std::ostream &out, Fixed const &f )
{
	out << f.toFloat();
	return (out);
}