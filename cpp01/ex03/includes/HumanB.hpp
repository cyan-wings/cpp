#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;

	public:
		HumanB( const std::string& name );
		~HumanB( void );
		void	setWeapon( Weapon& weapon );
		void	attack( void );
};

#endif