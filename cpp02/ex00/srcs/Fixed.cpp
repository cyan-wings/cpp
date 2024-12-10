#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _val(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed( Fixed const &f )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed	&Fixed::operator=( Fixed const &other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &other )
		this->_val = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return ( _val );
}

void	Fixed::setRawBits( int const raw ) { _val = raw; }