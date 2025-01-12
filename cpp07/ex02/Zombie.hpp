#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <string>
# include <iostream>

class Zombie
{
	private:
		static unsigned int	_count;
		unsigned int const	_id;
		std::string			_name;

	public:
		Zombie( void );
		Zombie( std::string const &name );
		Zombie				&operator=( Zombie const &other );
		Zombie( Zombie const &z );
		~Zombie( void );

		unsigned int const	&getId( void ) const;
		std::string const	&getName( void ) const;
};

std::ostream				&operator<<( std::ostream &out, Zombie const &z );

#endif
