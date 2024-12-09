#include "Zombie.hpp"

int main( void )
{
	Zombie	*nz = newZombie( "yellow" );
	nz->announce();
	randomChump( "random chump" );
	delete ( nz );
	return ( 0 );
}
