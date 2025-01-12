#include "Zombie.hpp"

unsigned int		Zombie::_count = 1;

Zombie::Zombie( void ) : _id(_count), _name( "No Name" ) { ++_count; }

Zombie::Zombie( std::string const &name ) : _id(_count), _name( name ) { ++_count; }

Zombie::Zombie( Zombie const &z ) : _id(_count), _name( z._name ) { ++_count; }

Zombie				&Zombie::operator=( Zombie const &other )
{
	if (_name != other._name)
		_name = other._name;
	return ( *this );
}

Zombie::~Zombie( void ) { --_count; }

unsigned int const	&Zombie::getId( void ) const { return ( _id ); }

std::string const	&Zombie::getName( void ) const { return ( _name ); }

std::ostream		&operator<<( std::ostream &out, Zombie const &z )
{
	out << "Zombie of ID (" << z.getId() << ") : " << z.getName();
	return ( out );
}
