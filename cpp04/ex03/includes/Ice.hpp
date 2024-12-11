#ifndef __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"
# include <string.h>

class Ice :public AMateria
{
	public:
		Ice( void );
		Ice( Ice const &ice );
		Ice				&operator=(Ice const &other );
		~Ice( void );

		virtual Ice		*clone() const;
		virtual void	use( ICharacter &target );
};

#endif