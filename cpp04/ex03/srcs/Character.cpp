#include "Character.hpp"
#include <iostream>

Character::Character( std::string const &name ) : _name( name ), _totalmateria( 0 )
{
	int	i = -1;

	while ( ++i < MAX_MATERIA )
		_inventory[i] = NULL;
}

Character::Character( Character const &character ) : _name( character._name ), _totalmateria( character._totalmateria )
{
	int	i = -1;
	while ( ++i < MAX_MATERIA )
		_inventory[i] = character._inventory[i];
}

Character &	Character::operator=( Character const &other )
{
	int	i = -1;
	
	_totalmateria = other._totalmateria;
	_name = other._name;
	while ( ++i < MAX_MATERIA )
	{
		delete _inventory[i];
		_inventory[i] = other._inventory[i];
	}
	return ( *this );
}

Character::~Character()
{
	int	i = -1;

	while ( ++i < MAX_MATERIA )
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}

std::string const	&Character::getName() const { return (_name); }

void	Character::equip( AMateria *m )
{
	int	i = -1;

	if ( _totalmateria == MAX_MATERIA )
	{
		std::cout << _name << ": Inventory full! Unequip a Materia to equip : " << m->getType() << std::endl;
		return ;
	}
	while ( ++i < 4 )
	{
		if ( _inventory[i] == NULL )
		{
			_inventory[i] = m;
			++_totalmateria;
			std::cout << _name << " equipped AMateria " << m->getType() << " at index: " << i << "." << std::endl;
			break ;
		}
	}
}

void	Character::unequip( int idx )
{
	if ( idx < 0 || idx > MAX_MATERIA )
	{
		std::cout << idx << " is an invalid index." << std::endl;
		return ;
	}
	if ( _inventory[idx] == NULL )
	{
		std::cout << _name << "'s inventory is already empty! Nothing to unequip." << std::endl;
		return ;
	}
	std::string	tmp = _inventory[idx]->getType();
	_inventory[idx] = NULL;
	--_totalmateria;
	std::cout << _name << " succesfully unequip Materia " << tmp << " at index: " << idx << "." << std::endl;
}

void	Character::use( int idx, ICharacter &target )
{
	if ( idx < 0 || idx > MAX_MATERIA )
	{
		std::cout << idx << " is an invalid index." << std::endl;
		return ;
	}
	if ( _inventory[idx] == NULL )
	{
		std::cout << _name << "'s inventory is empty! Cannot use Materia." << std::endl;
		return ;
	}
	std::cout << _name;
	_inventory[idx]->use(target);
}