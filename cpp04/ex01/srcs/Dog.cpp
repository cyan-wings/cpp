#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal( "Dog" ) { std::cout << "Dog " << _type << " created..." << std::endl; }

Dog::Dog( Dog const &Dog ) : Animal( Dog ) { std::cout << "Dog " << _type << " created from copy..." << std::endl; }

Dog		&Dog::operator=( Dog const &other )
{
	if ( this != &other )
		Animal::operator=(other);
	return ( *this );
}

Dog::~Dog() { std::cout << "Dog " << _type << " destroyed..." << std::endl; }

void	Dog::makeSound() const { std::cout << "Dog " << _type << " Woof~~~" << std::endl; }

Brain	*Dog::getBrain() const { return (_brain); }

