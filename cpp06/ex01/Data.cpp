#include "Data.hpp"

Data::Data( std::string const &meta ) : _meta( meta ) {}

Data::Data( Data const &d ) : _meta( d._meta ) {}

Data const			&Data::operator=( Data const &other )
{
	if (_meta != other._meta)
		_meta = other._meta;
	return ( *this );
}

Data::~Data( void ) {}

std::string const	&Data::getData( void ) const { return (_meta); }

std::ostream		&operator<<( std::ostream &out, Data const &d )
{
	out << "The data contents: [" << d.getData() << "]" << std::endl;
	return ( out );
}
