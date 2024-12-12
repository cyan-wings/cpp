#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria::AMateria( "cure" ) {}

Cure::Cure( Cure const &cure ) : AMateria::AMateria( cure ) {}

Cure::~Cure() {}

Cure		&Cure::operator=( Cure const &other )
{
	if (this != &other)
		_type = other._type;
	return ( *this );
}

AMateria	*Cure::clone() const { return ( new Cure() ); }

void		Cure::use(ICharacter &target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }
