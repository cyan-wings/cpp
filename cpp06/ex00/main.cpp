#include "ScalarConverter.hpp"

void	convertEndl( std::string const &param )
{
	ScalarConverter::convert( param );
	std::cout << std::endl;
}

int	main( void )
{
	convertEndl( "" );
	convertEndl( "f" );
	convertEndl( "-" );
	convertEndl( "+" );
	convertEndl( "." );
	convertEndl( "+." );
	convertEndl( "+f" );
	convertEndl( ".f" );
	convertEndl( "+.f" );
	convertEndl( "Fail" );
	convertEndl( "-inf" );
	convertEndl( "-inff" );
	convertEndl( "+inf" );
	convertEndl( "+inff" );
	convertEndl( "nan" );
	convertEndl( "nanf" );
	convertEndl( "-0" );
	convertEndl( "-0.00f" );
	convertEndl( "-0.000" );
	convertEndl( "0" );
	convertEndl( "0.00f" );
	convertEndl( "0.000" );
	convertEndl( "+0" );
	convertEndl( "+0.00f" );
	convertEndl( "+0.000" );
	convertEndl( "-23.45f" );
	convertEndl( "-23.45" );
	convertEndl( "23.45f" );
	convertEndl( "23.45" );
	convertEndl( "2147483648" );
	convertEndl( "-2147483649" );
	convertEndl( "97" );
	convertEndl( "-97" );
	convertEndl( "97.0f" );
	convertEndl( "97.00" );
	return ( 0 );
}