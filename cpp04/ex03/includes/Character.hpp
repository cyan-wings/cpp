#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include <string>
# include "ICharacter.hpp"

# define MAX_MATERIA 4

class Character : public ICharacter
{
	private:
		std::string	_name;
		int			_totalmateria;
		AMateria	*_inventory[MAX_MATERIA];

	public:
		Character( std::string const &name );
		Character( Character const &character );
		Character					&operator=( Character const &other );
		virtual ~Character( void );

		virtual std::string const	&getName( void ) const;
		virtual void				equip( AMateria* m );
		virtual void				unequip( int idx );
		virtual void				use( int idx, ICharacter& target );

};

#endif