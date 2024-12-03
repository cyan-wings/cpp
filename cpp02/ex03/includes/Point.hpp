#ifndef __POINT_HPP__
# define __POINT_HPP__

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

		Point	&operator=( Point const &other );

	public:
		Point( void );
		Point( float const &x, float const &y );
		Point( Point const &point );
		~Point( void );
		Fixed const	&getX(void) const;
		Fixed const	&getY(void) const;
};

std::ostream	&operator<<(std::ostream &out, Point const &point);

#endif