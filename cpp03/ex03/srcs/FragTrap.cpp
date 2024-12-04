#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( std::string const &name ) : ClapTrap( name )
{
	_hp = 100;
	_ep = 100;
	_att = 30;
	std::cout <<  "FragTrap " << _name << " is created..." << std::endl;
	printHp();
	printEp();
	printBorder();
}

FragTrap::FragTrap( FragTrap const &st ) : ClapTrap( st ) {}

FragTrap	&FragTrap::operator=( FragTrap const &other )
{
	if (this == &other)
	{
		std::cout << "Nothing happened to FragTrap " << _name << "." << std::endl;
		printBorder();
		return ( *this );
	}
	std::cout << "FragTrap " << _name;
	_name = other._name;
	_hp = other._hp;
	_ep = other._ep;
	_att = other._att;
	std::cout << " miraculously became " << _name << "." << std::endl;
	printHp();
	printEp();
	std::cout << "FragTrap " << _name << " can do " << _att << " attack damage." << std::endl;
	printBorder();
	return ( *this );
}


FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " is destroyed..." << std::endl;
	printBorder();
}

void		FragTrap::highFivesGuys( void )
{
	if (!checkStatus() || _ep < 30)
	{
		std::cout << "FragTrap " << _name << " can't high five." << std::endl;
		printBorder();
		return ;
	}
	_ep -= 30;
	std::cout << "FragTrap " << _name << " says congrats!!!" << std::endl;
	printEp();
	printBorder();
}