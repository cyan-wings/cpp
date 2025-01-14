#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"
# include <string>

class Cat: public Animal
{
	public:
		Cat( void );
		Cat( Cat const &cat );
		Cat				&operator=( Cat const &other );
		virtual ~Cat( void );

		virtual void	makeSound( void ) const;
};

#endif
