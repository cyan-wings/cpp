#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon& weapon) {_weapon = &weapon;}

void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType()
				<< std::endl;
	else
		std::cout << _name << " swinged his hand." << std::endl;
}