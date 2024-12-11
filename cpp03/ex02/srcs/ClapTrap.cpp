#include "ClapTrap.hpp"
#include <iostream>

void		ClapTrap::printBorder() { std::cout << "----------" << std::endl; }

bool		ClapTrap::checkStatus()
{
	if (_hp <= 0)
	{
		std::cout << _name << " is dead.";
		return ( false );
	}
	if (_ep <= 0)
	{
		std::cout << _name << " has no energy points left.";
		return ( false );
	}
	return ( true );
}

void		ClapTrap::printHp() { std::cout << _name << " has " << _hp << " health points." << std::endl; }

void		ClapTrap::printEp() { std::cout << _name << " has " << _ep << " energy points." << std::endl; }

ClapTrap::ClapTrap() : _name( "sample" ), _hp( 10 ), _ep( 10 ), _att( 0 )
{
	std::cout << "ClapTrap " << _name << " is created..." << std::endl;
	printHp();
	printEp();
	printBorder();
}

ClapTrap::ClapTrap( std::string const &name ) : _name( name ), _hp( 10 ), _ep( 10 ), _att( 0 )
{
	std::cout << "ClapTrap " << _name << " is created..." << std::endl;
	printHp();
	printEp();
	printBorder();
}

ClapTrap::ClapTrap( ClapTrap const &ct ) : _name( ct._name ), _hp( ct._hp ), _ep( ct._ep ), _att( ct._att ) {}

ClapTrap	&ClapTrap::operator=( ClapTrap const &other )
{
	if (this == &other)
	{
		std::cout << "Nothing happened to ClapTrap " << _name << "." << std::endl;
		printBorder();
		return ( *this );
	}
	std::cout << "ClapTrap " << _name;
	_name = other._name;
	_hp = other._hp;
	_ep = other._ep;
	_att = other._att;
	std::cout << " miraculously became " << _name << "." << std::endl;
	printHp();
	printEp();
	std::cout << "ClapTrap " << _name << " can do " << _att << " attack damage." << std::endl;
	printBorder();
	return ( *this );
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is destroyed..." << std::endl;
	printBorder();
}

void		ClapTrap::attack( std::string const &target )
{
	if (!checkStatus())
	{
		std::cout << " ClapTrap " << _name << " can't attack." << std::endl;
		printBorder();
		return ;
	}
	--_ep;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _att << " points of damage!" << std::endl;
	printEp();
	printBorder();
}

void		ClapTrap::takeDamage( unsigned int amount )
{
	_hp -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " of damage." << std::endl;
	printHp();
	printBorder();
}

void		ClapTrap::beRepaired( unsigned int amount )
{
	if (!checkStatus())
	{
		std::cout << " ClapTrap " << _name << " can't be repaired." << std::endl;
		printBorder();
		return ;
	}
	--_ep;
	_hp += amount;
	std::cout << "ClapTrap " << _name << " repairs itself with " << amount << " of hp." << std::endl;
	printHp();
	printEp();
	printBorder();
}
