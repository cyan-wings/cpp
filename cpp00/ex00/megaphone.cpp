#include <iostream>
#include <string>

int	main( int argc, char *argv[] )
{
	std::string	buf = "";
	int			i;

	if ( argc == 1 )
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return ( 0 );
	}
	i = 0;
	while ( ++i < argc )
		buf.append( argv[i] );
	i = -1;
	while ( buf[++i] )
		buf[i] = toupper( buf[i] );
	std::cout << buf << std::endl;
	return ( 0 );
}
