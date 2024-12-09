#include "Harl.hpp"
#include <iostream>

int main( int argc __attribute((unused)), char **argv )
{
	Harl	harl;

	if (argc != 2)
	{
		harl.complain( "bla" );
		return (0);
	}
	harl.complain( argv[1] );
	return (0);
}
