#ifndef __AANIMAL_HPP__
# define __AANIMAL_HPP__

# include "Brain.hpp"
# include <string>

class AAnimal
{
	protected:
		std::string		_type;

	public:
		AAnimal( void );
		AAnimal( std::string const &type );
		AAnimal( AAnimal const &aanimal );
		AAnimal		&operator=( AAnimal const &other );
		virtual ~AAnimal( void );

		std::string	getType( void ) const;
		virtual Brain	*getBrain( void ) const = 0;
		virtual void	makeSound( void ) const = 0;
};

#endif
