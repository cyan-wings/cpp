#include "Span.hpp"

void	givenTest( void )
{
	Span	sp = Span(100);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp << std::endl;
}

void	addRandomNumbers( Span &sp, unsigned int amount )
{
	srand(static_cast<unsigned int>(time(0)));
	unsigned int	i = -1;

	while (++i < amount)
		sp.addNumber(rand());
}

void	selfTest( void )
{
	Span	sp = Span(10000);
	Span	copy = Span(10);

	std::cout << sp << std::endl;
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch ( std::exception const &e )
	{
		std::cerr << e.what() << std::endl;
	}
	addRandomNumbers(sp, 10000);
	std::cout << sp << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	addRandomNumbers(copy, 10);
	

	try
	{
		addRandomNumbers(copy, 11);
	}
	catch ( std::exception const &e )
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << copy << std::endl;
	std::cout << copy.shortestSpan() << std::endl;
	std::cout << copy.longestSpan() << std::endl;
	sp = copy;
	std::cout << sp << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span	test = sp;
	std::cout << test << std::endl;
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
}

int	main( void )
{
	std::cout << "Given test by assignment:" << std::endl;
	givenTest();
	std::cout << "_________________________" << std::endl << std::endl;
	selfTest();
	return ( 0 );
}