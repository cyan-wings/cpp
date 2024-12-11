#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal( "Cat" )
{
	_brain = new Brain();
	std::cout << "Cat " << _type << " created..." << std::endl;
}

Cat::Cat( Cat const &cat ) : AAnimal( cat )
{
	_brain = new Brain();
	std::cout << "Cat " << _type << " created from copy..." << std::endl;
}

Cat		&Cat::operator=( Cat const &other )
{
	delete _brain;
	_type = other.getType();
	_brain = new Brain(*other._brain);
	return ( *this );
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat " << _type << " destroyed..." << std::endl;
}

void	Cat::makeSound() const { std::cout << "Cat " << _type << " Meow~~~" << std::endl; }

Brain	*Cat::getBrain() const { return (_brain); }
