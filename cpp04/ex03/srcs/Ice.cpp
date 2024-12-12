#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria::AMateria( "ice" ) {}

Ice::Ice( Ice const &ice ) : AMateria::AMateria( ice ) {}

Ice::~Ice() {}

Ice			&Ice::operator=( Ice const &other )
{
	if (this != &other)
		_type = other._type;
	return ( *this );
}

AMateria	*Ice::clone() const { return ( new Ice() ); }

void		Ice::use(ICharacter &target) { std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }
