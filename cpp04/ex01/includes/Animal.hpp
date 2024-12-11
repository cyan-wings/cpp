#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include "Brain.hpp"
# include <string>

class Animal
{
	protected:
		std::string		_type;

	public:
		Animal( void );
		Animal( std::string const &type );
		Animal( Animal const &animal );
		Animal		&operator=( Animal const &other );
		virtual ~Animal( void );

		std::string	getType( void ) const;
		virtual Brain	*getBrain( void ) const = 0;
		virtual void	makeSound( void ) const;
};

#endif
