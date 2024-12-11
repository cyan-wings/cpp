#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include <string>
# include "AMateria.hpp"

class Character
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


};

#endif