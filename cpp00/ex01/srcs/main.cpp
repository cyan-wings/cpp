static void	routine(std::string cmd, PhoneBook p)
{
	while (1)
	{
		std::cout << "PHONEBOOK - Select a command: " << std::endl;
		std::cin >> cmd;
		if (cmd)
		{
			cmd = std::toupper(cmd);
			if (cmd == "SEARCH")
				p.search();
			else if (cmd == "ADD")
				p.add();
			else if (cmd == "EXIT")
				return ;
		}
		std::cout << "Please enter a valid command." << std::endl;
	}
}


int	main(void)
{
	std::string	cmd = NULL;
	PhoneBook	p;

	routine(cmd, p);
	return (0);
}
