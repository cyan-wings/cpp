#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria( std::string const &type ) : _type( type ) {}

AMateria::AMateria( AMateria const &amateria ) : _type( amateria._type ) {}

AMateria	&AMateria::operator=( AMateria const &other )
{
	if ( this == &other )
		return ( *this );
	_type = other._type;
	return ( *this );
}

AMateria::~AMateria() {}

std::string const	&AMateria::getType() const { return (_type); }

void	AMateria::use( ICharacter &target ) { std::cout << "Unknown materia thrown at " << target.getName() << std::endl; }