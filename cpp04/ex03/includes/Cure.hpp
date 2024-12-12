#ifndef __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"
# include <string>

class Cure :public AMateria
{
	public:
		Cure( void );
		Cure( Cure const &Cure );
		Cure					&operator=( Cure const &other );
		~Cure( void );

		virtual AMateria	*clone( void ) const;
		virtual void		use( ICharacter &target );
};

#endif