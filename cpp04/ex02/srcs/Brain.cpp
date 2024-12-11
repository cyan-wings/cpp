#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "Brain created..." << std::endl; }

Brain::Brain( Brain const &brain )
{
	*this = brain;
	std::cout << "Brain copy created..." << std::endl;
}

Brain	&Brain::operator=( Brain const &other )
{
	for ( int i = 0; i < 100; i++ )
		_ideas[i] = other._ideas[i];
	return ( *this );
}

Brain::~Brain() { std::cout << "Brain destroyed..." << std::endl; }
