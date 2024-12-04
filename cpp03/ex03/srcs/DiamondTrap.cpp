#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( std::string const &name ) : ClapTrap( name + "_clap_name" ), FragTrap( name ), ScavTrap( name )
{
	_name = ClapTrap::_name;
	_hp = FragTrap::_hp;
	_ep = ScavTrap::_ep;
	_att = FragTrap::_att;
	std::cout <<  "DiamondTrap " << _name << " is created..." << std::endl;
	printHp();
	printEp();
	printBorder();
}

DiamondTrap::DiamondTrap( DiamondTrap const &dt ) : ClapTrap( dt ), FragTrap( dt ), ScavTrap( dt ), _name( dt._name ) {}

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const &other )
{
	if (this == &other)
	{
		std::cout << "Nothing happened to DiamondTrap " << _name << "." << std::endl;
		printBorder();
		return ( *this );
	}
	std::cout << "DiamondTrap " << _name;
	_name = other._name;
	_hp = other._hp;
	_ep = other._ep;
	_att = other._att;
	std::cout << " miraculously became " << _name << "." << std::endl;
	printHp();
	printEp();
	std::cout << "DiamondTrap " << _name << " can do " << _att << " attack damage." << std::endl;
	printBorder();
	return ( *this );
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is destroyed..." << std::endl;
	printBorder();
}

void		DiamondTrap::whoAmI() { std::cout << "I am DiamondTrap " << _name << " and ClapTrap " << ClapTrap::_name << "." << std::endl; }
