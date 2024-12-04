#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( std::string const &name );
		ScavTrap( ScavTrap const &st );
		ScavTrap	&operator=( ScavTrap const &other );
		~ScavTrap( void );

		void		guardGate( void );

};

#endif