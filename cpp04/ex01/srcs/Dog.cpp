#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal( "Dog" )
{
	_brain = new Brain();
	std::cout << "Dog " << _type << " created..." << std::endl;
}

Dog::Dog( Dog const &dog ) : Animal( dog )
{
	_brain = new Brain(*dog._brain);
	std::cout << "Dog " << _type << " created from copy..." << std::endl;
}

Dog		&Dog::operator=( Dog const &other )
{
	delete _brain;
	_type = other.getType();
	_brain = new Brain(*other._brain);
	return ( *this );
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog " << _type << " destroyed..." << std::endl;
}

void	Dog::makeSound() const { std::cout << "Dog " << _type << " Woof~~~" << std::endl; }

Brain	*Dog::getBrain() const { return (_brain); }

