#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

static void	routine(PhoneBook& p)
{
	std::string	cmd;

	while (1)
	{
		std::cout << "PHONEBOOK - Select a command: " << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cout << "Exit..." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return ;
		}
		for (size_t i = 0; i < cmd.size(); ++i)
			cmd[i] = std::toupper(cmd[i]);
		if (cmd == "SEARCH")
			p.search();
		else if (cmd == "ADD")
			p.add();
		else if (cmd == "EXIT")
			return ;
		else
			std::cout << "Please enter a valid command." << std::endl;
	}
}


int	main(void)
{
	PhoneBook	p;

	routine(p);
	return (0);
}
