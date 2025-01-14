#include "BitcoinExchange.hpp"

bool	pError( std::string const &msg )
{
	std::cerr << "Error: " << msg << std::endl;
	return ( false );
}

bool	parse( int argc )
{
	if ( argc < 2 )
		return ( pError("could not open file.") );
	if ( argc != 2 )
		return ( pError("too many args.") );
	return ( true );
}

int	main( int argc, char **argv )
{
	if (!parse( argc ))
		return (0);
	try
	{
		BitcoinExchange::run( "data.csv", argv[1] );
	}
	catch ( std::exception const &e )
	{
		return ( pError(e.what()) );
	}
	return ( 0 );
}
