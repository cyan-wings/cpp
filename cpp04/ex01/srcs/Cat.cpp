#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal( "Cat" ) { std::cout << "Cat " << _type << " created..." << std::endl; }

Cat::Cat( Cat const &cat ) : Animal( cat ) { std::cout << "Cat " << _type << " created from copy..." << std::endl; }

Cat		&Cat::operator=( Cat const &other )
{
	if ( this != &other )
		Animal::operator=(other);
	return ( *this );
}

Cat::~Cat() { std::cout << "Cat " << _type << " destroyed..." << std::endl; }

void	Cat::makeSound() const { std::cout << "Cat " << _type << " Meow~~~" << std::endl; }

Brain	*Cat::getBrain() const { return (_brain); }
