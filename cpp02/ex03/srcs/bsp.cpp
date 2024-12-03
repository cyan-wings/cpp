#include "Point.hpp"

/**
 * This formula calculates the signed area of the parallelogram formed by the two vectors.
 * The sign of the result tells you the relative orientation of "point" with respect to the edge/vector "ab"
 * 
 * @note The vectors are b -> a and b -> point
 * @note If result is 0, it means "point" lies in edge/vector "ab"
 */
static Fixed	calcOrientation( Point const a, Point const b, Point const point )
{
	return ( ((point.getX() - b.getX()) * (a.getY() - b.getY())) - ((point.getY() - b.getY()) * (a.getX() - b.getX())) );
}

/**
 * This formula checks the signs of the results.
 * Positive means counterclockwise (left) of the vector.
 * Negative means clockwise (right) of the vector.
 * Point is inside if all orientations of "point" relative to the vector (edges of the triangle) has the same sign.
 * 
 * @note 
 */
bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	ab = calcOrientation(a, b, point);
	Fixed	bc = calcOrientation(b, c, point);
	Fixed	ca = calcOrientation(c, a, point);

	if (ab > 0 && bc > 0 && ca > 0)
		return (true);
	if (ab < 0 && bc < 0 && ca < 0)
		return (true);
	return (false);
}