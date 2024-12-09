#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__

# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string		_name;
		const Weapon&	_weapon;

	public:
		HumanA( const std::string& name, const Weapon& weapon );
		~HumanA( void );
		void	attack( void );
};

#endif