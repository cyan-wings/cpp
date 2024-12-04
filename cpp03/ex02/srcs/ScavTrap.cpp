#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( std::string const &name ) : ClapTrap( name )
{
	_hp = 100;
	_ep = 50;
	_att = 20;
	std::cout <<  "ScavTrap " << _name << " is created..." << std::endl;
	printHp();
	printEp();
	printBorder();
}

ScavTrap::ScavTrap( ScavTrap const &st ) : ClapTrap( st ) {}

ScavTrap	&ScavTrap::operator=( ScavTrap const &other )
{
	if (this == &other)
	{
		std::cout << "Nothing happened to ScavTrap " << _name << "." << std::endl;
		printBorder();
		return ( *this );
	}
	std::cout << "ScavTrap " << _name;
	_name = other._name;
	_hp = other._hp;
	_ep = other._ep;
	_att = other._att;
	std::cout << " miraculously became " << _name << "." << std::endl;
	printHp();
	printEp();
	std::cout << "ScavTrap " << _name << " can do " << _att << " attack damage." << std::endl;
	printBorder();
	return ( *this );
}


ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " is destroyed..." << std::endl;
	printBorder();
}

void	ScavTrap::guardGate()
{
	if (!checkStatus() || _ep < 10)
	{
		std::cout << "ScavTrap " << _name << " can't use guard gate." << std::endl;
		printBorder();
		return ;
	}
	_ep -= 10;
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
	printEp();
	printBorder();
}