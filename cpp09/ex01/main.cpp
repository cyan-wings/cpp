#include "RPN.hpp"

int	main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout << "No input." << std::endl;
		return ( 0 );
	}
	try
	{
		RPN::compute( argv[1] );
	}
	catch ( RPN::RPNInputException const &e )
	{
		std::cout << e.what() << std::endl;
	}
	return ( 0 );
}