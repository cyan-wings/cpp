#include "Bureaucrat.hpp"
#include <iostream>

int	main( void )
{
	Bureaucrat	*matthew = NULL;
	Bureaucrat	*joe = NULL;

	try
	{
		matthew = new Bureaucrat( "Matthew", 150 );
		matthew->decrementGrade();
	}
	catch ( std::exception const &e )
	{
		std::cerr << e.what() << std::endl;
	}
	joe = new Bureaucrat( *matthew );
	std::cout << *matthew << std::endl;
	std::cout << *joe << std::endl;
	delete matthew;
}