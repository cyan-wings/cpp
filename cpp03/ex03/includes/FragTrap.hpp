#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

# include "ClapTrap.hpp"
# include <string>

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap( std::string const &name );
		FragTrap( FragTrap const &st );
		FragTrap	&operator=( FragTrap const &other );
		~FragTrap( void );

		void		highFivesGuys( void );
		void		attack( std::string const &target );
};

#endif