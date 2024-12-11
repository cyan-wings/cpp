#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type( "Random" ) { std::cout << "WrongAnimal " << _type << " created..." << std::endl; }

WrongAnimal::WrongAnimal( std::string const &type ) : _type( type ) { std::cout << "WrongAnimal " << _type << " created..." << std::endl; }

WrongAnimal::WrongAnimal( WrongAnimal const &wronganimal ) : _type( wronganimal._type ) { std::cout << "WrongAnimal " << _type << " created from copy..." << std::endl; }

WrongAnimal		&WrongAnimal::operator=( WrongAnimal const &other )
{
	if ( this != &other )
		_type = other._type;
	return ( *this );
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal " << _type << " destroyed..." << std::endl; }

std::string	WrongAnimal::getType() const { return (_type); }

void		WrongAnimal::makeSound() const { std::cout << "WrongAnimal " << _type << " ~~~" << std::endl; }
