#include "ClapTrap.hpp"
#include <iostream>

int	main( void )
{
	ClapTrap	ct = ClapTrap();
	ClapTrap	ct1 = ClapTrap( "Second guy" );
	ClapTrap	ct2 = ClapTrap( "Robot" );
	ClapTrap	ct3 = ClapTrap( "Test" );

	for ( int i = 0; i < 15; ++i )
		ct.attack( "dummy " );
	for ( int i = 0; i < 15; ++i )
		ct1.beRepaired( 10 );
	ct2.beRepaired( 50 );
	ct2.takeDamage( 100 );
	ct2.attack( "random chump" );
	ct2.beRepaired( 100 );
	ct3 = ct2;
	ct3.attack( "something" );
	return ( 0 );
}
