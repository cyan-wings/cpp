#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Brain.hpp"
# include "AAnimal.hpp"
# include <string>

class Dog: public AAnimal
{
	private:
		Brain		*_brain;

	public:
		Dog( void );
		Dog( Dog const &dog );
		Dog		&operator=( Dog const &other );
		virtual ~Dog( void );

		Brain		*getBrain( void ) const;
		virtual void	makeSound( void ) const;
};

#endif
