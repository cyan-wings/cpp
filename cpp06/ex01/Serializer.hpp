#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__

# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer( void );
		Serializer( Serializer const &s );
		Serializer			&operator=( Serializer const &other );
		~Serializer( void );

	public:
		static uintptr_t	serialize( Data *ptr);
		static Data			*deserialize( uintptr_t raw );
};

#endif
