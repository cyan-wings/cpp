#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# include <string>

class WrongAnimal
{
	protected:
		std::string		_type;

	public:
		WrongAnimal( void );
		WrongAnimal( std::string const &type );
		WrongAnimal( WrongAnimal const &wronganimal );
		WrongAnimal		&operator=( WrongAnimal const &other );
		virtual ~WrongAnimal( void );

		std::string		getType( void ) const;
		void	makeSound( void ) const;
};

#endif
