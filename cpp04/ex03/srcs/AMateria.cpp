#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria( std::string const &type ) : _type( type ) {}

AMateria::AMateria( AMateria const &amateria ) : _type( amateria._type ) {}

AMateria	&AMateria::operator=( AMateria const &other )
{
	if (this != &other)
		_type = other._type;
	return ( *this );
}

AMateria::~AMateria() {}

std::string const	&AMateria::getType() const { return (_type); }

void	AMateria::use( ICharacter &target ) { std::cout << "* Materia is used on " << target.getName() << ". *" << std::endl; }
