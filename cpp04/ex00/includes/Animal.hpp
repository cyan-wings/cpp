#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <string>

class Animal
{
	protected:
		std::string		_type;

	public:
		Animal( void );
		Animal( std::string const &type );
		Animal( Animal const &animal );
		Animal			&operator=( Animal const &other );
		virtual ~Animal( void );

		std::string		getType() const;
		virtual void	makeSound( void ) const;
};

#endif