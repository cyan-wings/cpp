#include "functions.hpp"
#include <iostream>

void	given( void )
{
	int			a = 2;
	int			b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string	c = "chaine1";
	std::string	d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int		main( void )
{
	std::cout << "Given:" << std::endl;
	given();
	std::cout << "__________________" << std::endl << std::endl;
	std::cout << "Own Tests:" << std::endl;
	int			x = 5, y = 10;
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
	
	std::cout << "Min of 5 and 10: " << min(x, y) << std::endl;
	std::cout << "Max of 5 and 10: " << max(x, y) << std::endl;

	double		a = 3.14, b = 2.71;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	
	std::cout << "Min of 3.14 and 2.71: " << min(a, b) << std::endl;
	std::cout << "Max of 3.14 and 2.71: " << max(a, b) << std::endl;

	std::string	str1 = "apple", str2 = "banana";
	std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
	swap(str1, str2);
	std::cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
	
	std::cout << "Min of apple and banana: " << min(str1, str2) << std::endl;
	std::cout << "Max of apple and banana: " << max(str1, str2) << std::endl;

	return (0);
}