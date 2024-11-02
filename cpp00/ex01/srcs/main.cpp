#include "PhoneBook.hpp"
#include <iostream>

static void	routine(PhoneBook& p)
{
	std::string	cmd;

	while (1)
	{
		std::cout << "PHONEBOOK - Select a command: " << std::endl;
		std::cin >> cmd;
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
