#include "Base.hpp"
#include <cstdlib>
#include <iostream>

static Base	*generate( void )
{
	Base	*ptr;
	srand(static_cast<unsigned int>(time(0)));
	int		n = rand() % 3;

	switch( n )
	{
		case 0:
			ptr = new A;
			break ;
		case 1:
			ptr = new B;
			break ;
		case 2:
			ptr = new C;
	}
	return ( ptr );
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "The pointer is a A type." << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "The pointer is a B type." << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "The pointer is a C type." << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "The pointer is a A type." << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		B	&b = dynamic_cast<B &>(p);
		(void) b;
		std::cout << "The pointer is a B type." << std::endl;
	}
	catch(const std::exception &e) {}
	try
	{
		C	&c = dynamic_cast<C &>(p);
		(void) c;
		std::cout << "The pointer is a C type." << std::endl;
	}
	catch(const std::exception &e) {}
}

int	main( void )
{
	Base	*ptr = generate();

	identify(ptr);
	identify(*ptr);
	delete ptr;
	ptr = NULL;
	return (0);
}
