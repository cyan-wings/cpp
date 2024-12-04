#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <string>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal( void );
		Animal( Animal const &animal );
		Animal	&operator=( Animal const &other );
		~Animal( void );

		void		makeSound( void );

};

#endif
