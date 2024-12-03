#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int	main( void )
{
	Point	p[] = {
        Point(4, 6),	// a
        Point(-7, 1),	// b
        Point(2, -4),	// c
        Point(0, 0),	// Inside the triangle
		Point(2, -2),	// Inside the triangle
        Point(5, 5),	// Outside the triangle
        Point(3, 1),	// On edge AB
        Point(6, 4),	// Outside in the first quadrant
        Point(-5, -5)	// Outside in the third quadrant
    };

	for (size_t i = 0; i < sizeof(p) / sizeof(p[0]); ++i)
		std::cout << "Test case " << i << ": " << (bsp(p[0], p[1], p[2], p[i]) ? "Inside" : "Outside") << std::endl;
	return 0;
}
