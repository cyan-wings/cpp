#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	ct = ClapTrap();
	ScavTrap	ct1 = ScavTrap( "Second guy" );
	ScavTrap	ct2 = ScavTrap( "Robot" );
	ScavTrap	ct3 = ScavTrap( "Test" );
	ScavTrap	ct4 = ScavTrap( "Real Scav" );

	for (int i = 0; i < 15; ++i)
		ct.attack( "dummy " );
	for (int i = 0; i < 15; ++i)
		ct1.beRepaired( 10 );
	ct2.beRepaired( 50 );
	ct2.takeDamage( 100 );
	ct2.attack( "random chump" );
	ct2.beRepaired( 100 );
	ct3 = ct2;
	ct3.attack( "something" );
	ct4.guardGate();
	ct4.guardGate();
	ct4.attack( "Sahni" );
	ct4.beRepaired( 100 );
	ct4.guardGate();
	ct4.guardGate();
	ct4.guardGate();
	ct4.guardGate();
	ct4.guardGate();
	ct4.attack( "Zombie" );
	ct4.beRepaired( 100 );
	ct4.takeDamage( 1000 );
	ct4.attack( "Zombie" );
	ct4.guardGate();
	ct4.beRepaired( 100 );
	return (0);
}
