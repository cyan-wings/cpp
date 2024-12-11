#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type( "Random" ) { std::cout << "Animal " << _type << " created..." << std::endl; }

Animal::Animal( std::string const &type ) : _type( type ) { std::cout << "Animal " << _type << " created..." << std::endl; }

Animal::Animal( Animal const &animal ) : _type( animal._type ) { std::cout << "Animal " << _type << " created from copy..." << std::endl; }

Animal	&Animal::operator=( Animal const &other )
{
	if ( this != &other )
		_type = other._type;
	return ( *this );
}

Animal::~Animal() { std::cout << "Animal " << _type << " destroyed..." << std::endl; }

std::string	Animal::getType() const { return (_type); }

void	Animal::makeSound() const { std::cout << "Animal " << _type << " ~~~" << std::endl; }
