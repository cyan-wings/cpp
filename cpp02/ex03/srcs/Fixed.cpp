#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _val(0) {}

Fixed::Fixed( Fixed const &f ) { *this = f; }

Fixed			&Fixed::operator=( Fixed const &other )
{
	if (this != &other)
		this->_val = other._val;
	return (*this);
}

Fixed::~Fixed() {}

int				Fixed::getRawBits( void ) const { return (this->_val); }

void			Fixed::setRawBits( int const raw ) { this->_val = raw; }

Fixed::Fixed( int const n ) : _val(n << BITS) {}

Fixed::Fixed( float const d ) : _val(roundf(d * (1 << BITS))) {}

int				Fixed::toInt() const { return (_val >> BITS); }

float			Fixed::toFloat() const { return ((float)_val / (float)(1 << BITS)); }

std::ostream	&operator<<( std::ostream &out, Fixed const &f )
{
	out << f.toFloat();
	return (out);
}

bool			Fixed::operator>( Fixed const &other ) const { return (this->toFloat() > other.toFloat()); };

bool			Fixed::operator<( Fixed const &other ) const { return (this->toFloat() < other.toFloat()); };

bool			Fixed::operator>=( Fixed const &other ) const { return (this->toFloat() >= other.toFloat()); };

bool			Fixed::operator<=( Fixed const &other ) const { return (this->toFloat() <= other.toFloat()); };

bool			Fixed::operator==( Fixed const &other ) const { return (this->toFloat() == other.toFloat()); };

bool			Fixed::operator!=( Fixed const &other ) const { return (this->toFloat() != other.toFloat()); };

Fixed			Fixed::operator+( Fixed const &other ) const { return (Fixed(this->toFloat() + other.toFloat())); }

Fixed			Fixed::operator-( Fixed const &other ) const { return (Fixed(this->toFloat() - other.toFloat())); }

Fixed			Fixed::operator*( Fixed const &other ) const { return (Fixed(this->toFloat() * other.toFloat())); }

Fixed			Fixed::operator/( Fixed const &other ) const
{
	if (other.toFloat() == 0.0f)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed			&Fixed::operator++()
{
	++_val;
	return (*this);
}

Fixed			Fixed::operator++( int )
{
	Fixed	tmp = *this;
	++_val;
	return (*this);
}

Fixed			&Fixed::operator--()
{
	--_val;
	return (*this);
}

Fixed			Fixed::operator--( int )
{
	Fixed	tmp = *this;
	--_val;
	return (*this);
}

Fixed			&Fixed::min( Fixed &f1, Fixed &f2 )
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed const		&Fixed::min( Fixed const &f1, Fixed const &f2 )
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed			&Fixed::max( Fixed &f1, Fixed &f2 )
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed const		&Fixed::max( Fixed const &f1, Fixed const &f2 )
{
	if (f1 > f2)
		return (f1);
	return (f2);
}
