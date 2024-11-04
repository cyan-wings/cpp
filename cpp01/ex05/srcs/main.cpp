#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl	harl;

	std::cout << RED << "-----------INFO----------" << std::endl;
	harl.complain("INFO");
	std::cout << YELLOW << "--------WARNING----------" << std::endl;
	harl.complain("WARNING");
	std::cout << MAGENTA << "----------DEBUG---------" << std::endl;
	harl.complain("DEBUG");
	std::cout << GRAY << "----------ERROR---------" << std::endl;
	harl.complain("ERROR");
	std::cout << DEFAULT << "test complete" << std::endl;
}
