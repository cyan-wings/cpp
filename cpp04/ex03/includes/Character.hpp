#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character( std::string const &name );
		Character( Character const &character );
		Character	&operator=( Character const &other );
		~Character( void );

		std::string const	&getName( void ) const;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;

};

#endif