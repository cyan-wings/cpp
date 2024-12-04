#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap( std::string const &name );
		DiamondTrap( DiamondTrap const &dt );
		DiamondTrap	&operator=( DiamondTrap const &other );
		~DiamondTrap( void );

		void		whoAmI( void );
};

#endif