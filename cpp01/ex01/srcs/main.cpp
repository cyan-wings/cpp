#include "Zombie.hpp"

int main( void )
{
	Zombie	*nz = newZombie( "yellow" );
	nz->announce();
	randomChump( "random chump" );
	delete (nz);

	int	n = 5;
	Zombie	*zh = zombieHorde( n, "blue" );
	delete[] zh;
	return (0);
}
