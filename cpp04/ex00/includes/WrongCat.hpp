#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

# include "WrongAnimal.hpp"
# include <string>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat( void );
		WrongCat( WrongCat const &wrongcat );
		WrongCat	&operator=( WrongCat const &other );
		~WrongCat( void );

		void		makeSound() const;
};

#endif
