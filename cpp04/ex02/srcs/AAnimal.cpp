#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : _type( "Random" ) { std::cout << "AAnimal " << _type << " created..." << std::endl; }

AAnimal::AAnimal( std::string const &type ) : _type( type ) { std::cout << "AAnimal " << _type << " created..." << std::endl; }

AAnimal::AAnimal( AAnimal const &aanimal ) : _type( aanimal._type ) { std::cout << "AAnimal " << _type << " created from copy..." << std::endl; }

AAnimal	&AAnimal::operator=( AAnimal const &other )
{
	if ( this != &other )
		_type = other._type;
	return ( *this );
}

AAnimal::~AAnimal() { std::cout << "AAnimal " << _type << " destroyed..." << std::endl; }

std::string	AAnimal::getType() const { return (_type); }
