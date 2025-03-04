#include "Point.hpp"

//Explicit type conversion for performance
Point::Point() : _x(Fixed(0.0f)), _y(Fixed(0.0f)) {}

Point::Point( float const &x, float const &y ) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point( Point const &point ) : _x(point._x), _y(point._y) {}

Point::~Point() {}

Fixed const		&Point::getX(void) const { return (_x); }

Fixed const		&Point::getY(void) const { return (_y); }

std::ostream	&operator<<( std::ostream &out, Point const &p )
{
	out << "x is " << p.getX().toFloat() << '\n';
	out << "y is " << p.getY().toFloat() << '\n';
	return (out);
}