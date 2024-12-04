#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal( "WrongCat" ) { std::cout << "WrongCat " << _type << " created..." << std::endl; }

WrongCat::WrongCat( WrongCat const &wrongcat ) : WrongAnimal( wrongcat ) { std::cout << "WrongCat " << _type << " created from copy..." << std::endl; }

WrongCat		&WrongCat::operator=( WrongCat const &other )
{
	if ( this != &other )
		WrongAnimal::operator=(other);
	return ( *this );
}

WrongCat::~WrongCat() { std::cout << "WrongCat " << _type << " destroyed..." << std::endl; }

void	WrongCat::makeSound() const { std::cout << "WrongCat " << _type << " Meow~~~" << std::endl; }
