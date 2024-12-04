#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	ct = ClapTrap();
	DiamondTrap	ct1 = DiamondTrap( "Second guy" );
	DiamondTrap	ct2 = DiamondTrap( "Robot" );
	DiamondTrap	ct3 = DiamondTrap( "Test" );
	DiamondTrap	ct4 = DiamondTrap( "Real Frag" );

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
	ct4.highFivesGuys();
	ct4.highFivesGuys();
	ct4.attack( "Sahni" );
	ct4.beRepaired( 100 );
	ct4.highFivesGuys();
	ct4.highFivesGuys();
	ct4.highFivesGuys();
	ct4.highFivesGuys();
	ct4.highFivesGuys();
	ct4.attack( "Zombie" );
	ct4.beRepaired( 100 );
	ct4.takeDamage( 1000 );
	ct4.attack( "Zombie" );
	ct4.highFivesGuys();
	ct4.beRepaired( 100 );
	ct1.whoAmI();
	ct2.whoAmI();
	ct3.whoAmI();
	ct4.whoAmI();
	return (0);
}
