#include "Harl.hpp"
#include <iostream>
#include <map>

Harl::Harl() {std::cout << "Harl spawned..." << std::endl;}

Harl::~Harl() {std::cout << "Harl died..." << std::endl;}

void	Harl::debug() {std::cout << DEBUG_MSG << std::endl;}

void	Harl::info() {std::cout << INFO_MSG << std::endl;}

void	Harl::warning() {std::cout << WARNING_MSG << std::endl;}

void	Harl::error() {std::cout << ERROR_MSG << std::endl;}

void Harl::complain(std::string level)
{
	void	(Harl::*func_ptr[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string func_lst[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == func_lst[i])
		{
			(this->*func_ptr[i])();
			break;
		}
	}
}