#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <ICharacter.hpp>
# include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string			_type;

	public:
		AMateria( std::string const &type );
		AMateria( AMateria const &amateria );
		AMateria	&operator=(AMateria const &other );
		virtual ~AMateria( void );

		std::string const	&getType( void ) const;

		virtual AMateria	*clone( void ) const = 0;
		virtual void		use( ICharacter &target );
};

#endif