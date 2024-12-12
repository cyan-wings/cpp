#ifndef __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"
# include <string>

class Ice :public AMateria
{
	public:
		Ice( void );
		Ice( Ice const &ice );
		Ice					&operator=( Ice const &other );
		~Ice( void );

		virtual AMateria	*clone( void ) const;
		virtual void		use( ICharacter &target );
};

#endif