#include "Harl.hpp"
#include <iostream>
#include <map>

Harl::Harl() {std::cout << "Harl spawned..." << std::endl;}

Harl::~Harl() {std::cout << "Harl died..." << std::endl;}

void	Harl::debug() {std::cout << "[ DEBUG ]" << '\n' << DEBUG_MSG << std::endl;}

void	Harl::info() {std::cout << "[ INFO ]" << '\n' << INFO_MSG << std::endl;}

void	Harl::warning() {std::cout << "[ WARNING ]" << '\n' << WARNING_MSG << std::endl;}

void	Harl::error() {std::cout << "[ ERROR ]" << '\n' << ERROR_MSG << std::endl;}

void Harl::complain(std::string level)
{
	std::string	func_lst[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = -1;

	while (++i < 4)
		if (level == func_lst[i])
			break ;
	switch( i )
	{
		case 0:
			debug();
			FALLTHROUGH;
		case 1:
			info();
			FALLTHROUGH;
		case 2:
			warning();
			FALLTHROUGH;
		case 3:
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}